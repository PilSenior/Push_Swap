#include "../includes/push_swap.h"

/*
** sa - swap a: Stack a'nın üstündeki ilk iki elemanı yer değiştirir
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void sa(t_stack **stack_a, int print)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    stack_swap(stack_a);
    if (print)
        write(1, "sa\n", 3);
}

/*
** sb - swap b: Stack b'nin üstündeki ilk iki elemanı yer değiştirir
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void sb(t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    stack_swap(stack_b);
    if (print)
        write(1, "sb\n", 3);
}

/*
** ss - sa ve sb'yi aynı anda yapar
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void ss(t_stack **stack_a, t_stack **stack_b, int print)
{
    if ((!stack_a || !*stack_a || !(*stack_a)->next) && 
        (!stack_b || !*stack_b || !(*stack_b)->next))
        return;
    stack_swap(stack_a);
    stack_swap(stack_b);
    if (print)
        write(1, "ss\n", 3);
}