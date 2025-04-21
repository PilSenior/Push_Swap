/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:11:56 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/20 20:11:56 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void sa(t_stack **stack_a, int print)
{
    t_stack	*second;
    t_stack	*first;
 
    if(!stack_a || !*stack_a || !(*stack_a)->next)
            return;

	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
    if(print)
        write(1, "sa\n", 3);
}

void sb(t_stack **stack_b, int print)
{
    t_stack	*first;
    t_stack	*second;

    if(!stack_b || !*stack_b || !(*stack_b)->next)
            return;
	
    first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
    if (print)
        write(1, "sb\n", 3);
}

void ss(t_stack **stack_a, t_stack **stack_b, int print)
{
    if ((!stack_a || !*stack_a || !(*stack_a)->next) && 
        (!stack_b || !*stack_b || !(*stack_b)->next))
            return;
    sa(stack_a, print);
    sb(stack_b, print);
    if (print)
        write(1, "ss\n", 3);
}