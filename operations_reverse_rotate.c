/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_reverse_rotate.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:08:13 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/16 07:08:13 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rra(t_stack **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	stack_reverse_rotate(stack_a);
	if (print)
		write(1, "rra\n", 4);
}

void	rrb(t_stack **stack_b, int print)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	stack_reverse_rotate(stack_b);
	if (print)
		write(1, "rrb\n", 4);
}

void	rrr(t_stack **stack_a, t_stack **stack_b, int print)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next)
		&& (!stack_b || !*stack_b || !(*stack_b)->next))
		return ;
	stack_reverse_rotate(stack_a);
	stack_reverse_rotate(stack_b);
	if (print)
		write(1, "rrr\n", 4);
}
