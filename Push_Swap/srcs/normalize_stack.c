#include "../includes/push_swap.h"

/*
** İki sayıyı takas eden yardımcı fonksiyon
*/
static void swap_int(int *a, int *b)
{
    int temp;

    temp = *a;
    *a = *b;
    *b = temp;
}

/*
** Bubble sort ile diziyi sıralar
*/
static void bubble_sort_array(int *arr, int size)
{
    int i;
    int j;

    i = 0;
    while (i < size - 1)
    {
        j = 0;
        while (j < size - i - 1)
        {
            if (arr[j] > arr[j + 1])
                swap_int(&arr[j], &arr[j + 1]);
            j++;
        }
        i++;
    }
}

/*
** Stack içindeki elemanların indeks değerlerini bulur
** Yani her eleman, sıralanmış dizideki konumuyla değiştirilir
*/
static int find_index(int *sorted_arr, int size, int value)
{
    int i;

    i = 0;
    while (i < size)
    {
        if (sorted_arr[i] == value)
            return (i);
        i++;
    }
    return (-1);  // Değer bulunamadı (bu durumda hata var demektir)
}

/*
** Stack içindeki elemanları normalize eder
** Her eleman, sıralanmış durumdaki indeksiyle değiştirilir
** Bu, radix sort algoritmasının sadece pozitif sayılarla çalışmasını sağlar
*/
void normalize_stack(t_stack **stack, int size)
{
    t_stack *current;
    int *values;
    int i;
    int index;

    if (!stack || !*stack)
        return;

    // Stack değerlerini bir diziye kopyala
    values = (int *)malloc(sizeof(int) * size);
    if (!values)
        error_exit();
    
    current = *stack;
    i = 0;
    while (current)
    {
        values[i++] = current->value;
        current = current->next;
    }

    // Diziyi sırala
    bubble_sort_array(values, size);

    // Stack içindeki değerleri indekslerle değiştir
    current = *stack;
    while (current)
    {
        index = find_index(values, size, current->value);
        current->value = index;
        current = current->next;
    }

    free(values);
}

/*
** Check fonksiyonu - stack'in normalize edilip edilmediğini kontrol eder
** Bu fonksiyon genellikle debug amaçlı kullanılır
*/
int is_normalized(t_stack *stack, int size)
{
    int i;
    t_stack *current;
    int found[10000] = {0};  // Büyük bir dizi, maksimum boyutu ayarla

    if (!stack)
        return (1);

    current = stack;
    while (current)
    {
        if (current->value < 0 || current->value >= size)
            return (0);  // Indeks sınırların dışında
        found[current->value]++;
        if (found[current->value] > 1)
            return (0);  // Tekrarlanan indeks
        current = current->next;
    }

    // Tüm indekslerin kullanıldığını kontrol et
    i = 0;
    while (i < size)
    {
        if (found[i] != 1)
            return (0);  // Eksik veya fazla indeks
        i++;
    }

    return (1);  // Stack normalize edilmiş
}