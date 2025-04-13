#include "../includes/push_swap.h"

/*
** rra - reverse rotate a: Stack a'nın tüm elemanlarını aşağı kaydırır
** Son eleman ilk olur
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void rra(t_stack **stack_a, int print)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    stack_reverse_rotate(stack_a);
    if (print)
        write(1, "rra\n", 4);
}

/*
** rrb - reverse rotate b: Stack b'nin tüm elemanlarını aşağı kaydırır
** Son eleman ilk olur
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void rrb(t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    stack_reverse_rotate(stack_b);
    if (print)
        write(1, "rrb\n", 4);
}

/*
** rrr - rra ve rrb komutlarını aynı anda yapar
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
    if ((!stack_a || !*stack_a || !(*stack_a)->next) && 
        (!stack_b || !*stack_b || !(*stack_b)->next))
        return;
    stack_reverse_rotate(stack_a);
    stack_reverse_rotate(stack_b);
    if (print)
        write(1, "rrr\n", 4);
}