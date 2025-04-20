/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:20:18 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/20 20:20:18 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	int	max_bits;
	int	size;
	int	i;
	int	j;
	int	num;

	if (!stack_a || !*stack_a)
		return ;
	size = stack_size(*stack_a);
	max_bits = 0;
	while ((size - 1) >> max_bits != 0)
		max_bits++;
	i = 0;
	while (i < max_bits)
	{
		j = 0;
		while (j < size)
		{
			num = (*stack_a)->value;
			if ((num >> i) & 1)
				ra(stack_a, 1);
			else
				pb(stack_a, stack_b, 1);
			j++;
		}
		while (stack_size(*stack_b) != 0)
			pa(stack_a, stack_b, 1);
		i++;
	}
}

