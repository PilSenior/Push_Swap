/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_rotate.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:11:51 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/20 20:11:51 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void ra(t_stack **stack_a, int print)
{
    t_stack	*last;
    t_stack	*first;

    if (!stack_a || !*stack_a || !(*stack_a)->next)
            return;
	first = *stack_a;
	last = stack_last(*stack_a);
	*stack_a = first->next;
	first->next = NULL;
	last->next = first;
    if (print)
        write(1, "ra\n", 3);
}

void rb(t_stack **stack_b, int print)
{
    t_stack	*last;
    t_stack	*first;

    if (!stack_b || !*stack_b || !(*stack_b)->next)
            return;
    
 
    first = *stack_b;
    last = stack_last(*stack_b);
    *stack_b = first->next;
    first->next = NULL;
    last->next = first;
    if (print)
        write(1, "rb\n", 3);
}

void rr(t_stack **stack_a, t_stack **stack_b, int print)
{
    if ((!stack_a || !*stack_a || !(*stack_a)->next) && 
        (!stack_b || !*stack_b || !(*stack_b)->next))
                return;
    ra(stack_a, 1);
    rb(stack_b, 1);
    if (print)
        write(1, "rr\n", 3);
}