#include "../includes/push_swap.h"

/*
** İki elemanlı stack'i sıralar
*/
void sort_two(t_stack **stack_a)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    if ((*stack_a)->value > (*stack_a)->next->value)
        sa(stack_a, 1);
}

/*
** Üç elemanlı stack'i sıralar
** Tüm olası durumlar için optimize edilmiş
*/
void sort_three(t_stack **stack_a)
{
    int first;
    int second;
    int third;

    if (!stack_a || !*stack_a || !(*stack_a)->next || !(*stack_a)->next->next)
        return;
    
    first = (*stack_a)->value;
    second = (*stack_a)->next->value;
    third = (*stack_a)->next->next->value;

    // Durum 1: 2-1-3
    if (first > second && first < third && second < third)
        sa(stack_a, 1);
    // Durum 2: 3-1-2
    else if (first > second && first > third && second < third)
        ra(stack_a, 1);
    // Durum 3: 3-2-1
    else if (first > second && first > third && second > third)
    {
        sa(stack_a, 1);
        rra(stack_a, 1);
    }
    // Durum 4: 1-3-2
    else if (first < second && first < third && second > third)
    {
        sa(stack_a, 1);
        ra(stack_a, 1);
    }
    // Durum 5: 2-3-1
    else if (first < second && first > third && second > third)
        rra(stack_a, 1);
    // Durum 6: 1-2-3 (zaten sıralı)
    // Hiçbir şey yapma
}

/*
** En küçük elemanı stack_a'dan stack_b'ye taşır
*/
static void push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
    int min_pos;
    int size;

    min_pos = get_min_position(*stack_a);
    size = stack_size(*stack_a);

    // En küçük elemanı stack'in üstüne getir
    if (min_pos <= size / 2) // Üst yarıdaysa, rotasyon kullan
    {
        while (min_pos > 0)
        {
            ra(stack_a, 1);
            min_pos--;
        }
    }
    else // Alt yarıdaysa, ters rotasyon kullan
    {
        while (min_pos < size)
        {
            rra(stack_a, 1);
            min_pos++;
        }
    }

    // En küçük elemanı stack_b'ye taşı
    pb(stack_a, stack_b, 1);
}

/*
** Beş elemanlı stack'i sıralar
** En küçük iki elemanı stack_b'ye taşıyıp,
** kalan üç elemanı sıralar ve sonra stack_b'deki elemanları geri alır
*/
void sort_five(t_stack **stack_a, t_stack **stack_b)
{
    int size;

    if (!stack_a || !*stack_a)
        return;
    
    size = stack_size(*stack_a);
    
    // 5 veya daha az eleman varsa işlem yap
    if (size <= 1)
        return;
    if (size == 2)
    {
        sort_two(stack_a);
        return;
    }
    
    // En küçük iki elemanı stack_b'ye taşı
    if (size > 3)
        push_min_to_b(stack_a, stack_b);
    if (size > 4)
        push_min_to_b(stack_a, stack_b);
    
    // Kalan üç elemanı sırala
    sort_three(stack_a);
    
    // stack_b'deki elemanları stack_a'ya geri al
    while (stack_size(*stack_b) > 0)
        pa(stack_a, stack_b, 1);
}

/*
** 5'ten büyük ama küçük olan stack'ler için sıralama
** En fazla 10 element için optimize edilmiş
*/
void sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
    if (size <= 5)
    {
        sort_five(stack_a, stack_b);
        return;
    }

    // Size 10'dan fazla olmadığı sürece aynı stratejiyi kullan
    // En küçük elemanları stack_b'ye taşı
    while (stack_size(*stack_a) > 3)
        push_min_to_b(stack_a, stack_b);
    
    // Kalan 3 elemanı sırala
    sort_three(stack_a);
    
    // stack_b'deki elemanları stack_a'ya geri al
    while (stack_size(*stack_b) > 0)
        pa(stack_a, stack_b, 1);
}