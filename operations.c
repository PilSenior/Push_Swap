/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:07:05 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/16 07:07:05 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sa(t_stack **stack_a, int print)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	stack_swap(stack_a);
	if (print)
		write(1, "sa\n", 3);
}

void	sb(t_stack **stack_b, int print)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	stack_swap(stack_b);
	if (print)
		write(1, "sb\n", 3);
}

void	ss(t_stack **stack_a, t_stack **stack_b, int print)
{
	if ((!stack_a || !*stack_a || !(*stack_a)->next)
		&& (!stack_b || !*stack_b || !(*stack_b)->next))
		return ;
	stack_swap(stack_a);
	stack_swap(stack_b);
	if (print)
		write(1, "ss\n", 3);
}
