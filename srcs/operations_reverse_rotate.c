/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 06:11:14 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/21 06:11:14 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	last = *stack_a;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack_a;
	*stack_a = last;
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int print)
{
	t_stack	*last;
	t_stack	*prev_last;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	last = *stack_b;
	prev_last = NULL;
	while (last->next)
	{
		prev_last = last;
		last = last->next;
	}
	prev_last->next = NULL;
	last->next = *stack_b;
	*stack_b = last;
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next)
		&& (!stack_b || !*stack_b || !(*stack_b)->next))
		return ;
	rra(stack_a, 1);
	rrb(stack_b, 1);
	if (print)
		write(1, "rrr\n", 4);
}
