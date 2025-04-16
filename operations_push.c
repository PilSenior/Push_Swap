/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations_push.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:08:32 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/16 07:08:32 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	pa(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (!stack_b || !*stack_b || !stack_a)
		return ;
	stack_push(stack_a, stack_b);
	if (print)
		write(1, "pa\n", 3);
}

void	pb(t_stack **stack_a, t_stack **stack_b, int print)
{
	if (!stack_a || !*stack_a || !stack_b)
		return ;
	stack_push(stack_b, stack_a);
	if (print)
		write(1, "pb\n", 3);
}
