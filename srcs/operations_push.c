#include "../includes/push_swap.h"

/*
** pa - push a: stack b'nin en üstündeki elemanı stack a'ya taşır
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void pa(t_stack **stack_a, t_stack **stack_b, int print)
{
    if (!stack_b || !*stack_b || !stack_a)
        return;
    stack_push(stack_a, stack_b);
    if (print)
        write(1, "pa\n", 3);
}

/*
** pb - push b: stack a'nın en üstündeki elemanı stack b'ye taşır
** Eğer print 1 ise, komutu ekrana yazdırır
*/
void pb(t_stack **stack_a, t_stack **stack_b, int print)
{
    if (!stack_a || !*stack_a || !stack_b)
        return;
    stack_push(stack_b, stack_a);
    if (print)
        write(1, "pb\n", 3);
}