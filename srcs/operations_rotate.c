#include "../includes/push_swap.h"

/*
** ra - rotate a: Stack a'nın tüm elemanlarını yukarı kaydırır
** İlk eleman son olur
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void ra(t_stack **stack_a, int print)
{
    if (!stack_a || !*stack_a || !(*stack_a)->next)
        return;
    stack_rotate(stack_a);
    if (print)
        write(1, "ra\n", 3);
}

/*
** rb - rotate b: Stack b'nin tüm elemanlarını yukarı kaydırır
** İlk eleman son olur
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void rb(t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !(*stack_b)->next)
        return;
    stack_rotate(stack_b);
    if (print)
        write(1, "rb\n", 3);
}

/*
** rr - ra ve rb komutlarını aynı anda yapar
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void rr(t_stack **stack_a, t_stack **stack_b, int print)
{
    if ((!stack_a || !*stack_a || !(*stack_a)->next) && 
        (!stack_b || !*stack_b || !(*stack_b)->next))
        return;
    stack_rotate(stack_a);
    stack_rotate(stack_b);
    if (print)
        write(1, "rr\n", 3);
}