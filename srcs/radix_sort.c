#include "../includes/push_swap.h"

/*
** Radix sort algoritması, büyük veri setleri için optimize edilmiş
** Sayıların ikili gösterimini kullanarak bit bazlı sıralama yapar
** Önce sayıların indeks (normalize) değerlerini kullanır
*/
void radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_bits;
    int size;
    int i;
    int j;
    int num;

    if (!stack_a || !*stack_a)
        return;
    
    size = stack_size(*stack_a);
    // En büyük sayının kaç bit gerektirdiğini hesapla
    max_bits = 0;
    while ((size - 1) >> max_bits != 0)
        max_bits++;
    
    // Her bit pozisyonu için sıralama
    i = 0;
    while (i < max_bits)
    {
        j = 0;
        while (j < size)
        {
            num = (*stack_a)->value;
            // Eğer i. bit 0 ise stack_b'ye, 1 ise stack_a'da tut
            if ((num >> i) & 1)
                ra(stack_a, 1);  // i. bit 1 ise, sayıyı a'da tut
            else
                pb(stack_a, stack_b, 1);  // i. bit 0 ise, b'ye taşı
            j++;
        }
        
        // Stack_b'deki tüm elemanları stack_a'ya geri taşı
        while (stack_size(*stack_b) != 0)
            pa(stack_a, stack_b, 1);
        
        i++;
    }
}

/*
** Radix sort için alternatif bir yaklaşım (bonus)
** Daha basit bir şekilde LSD (Least Significant Digit) radix sort
*/
void simple_radix_sort(t_stack **stack_a, t_stack **stack_b)
{
    int max_num;
    int max_bits;
    int size;
    int bit;
    int i;

    size = stack_size(*stack_a);
    max_num = size - 1;  // Normalize edilmiş stack'te en büyük sayı

    // Bitlerin sayısını hesapla
    max_bits = 0;
    while ((max_num >> max_bits) != 0)
        max_bits++;

    // Her bit için sıralama
    bit = 0;
    while (bit < max_bits)
    {
        i = 0;
        while (i < size)
        {
            // Stack_a'nın en üstündeki sayının bit değerine bak
            if (((*stack_a)->value >> bit) & 1)
                ra(stack_a, 1);  // Bit 1 ise sayıyı stack_a'da alt tarafa kaydır
            else
                pb(stack_a, stack_b, 1);  // Bit 0 ise sayıyı stack_b'ye gönder
            i++;
        }

        // Tüm sayıları stack_b'den stack_a'ya geri al
        while (*stack_b)
            pa(stack_a, stack_b, 1);

        bit++;
    }
}