/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 06:00:15 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/21 06:00:15 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	radix_utils(t_stack **stack_a, t_stack **stack_b, t_radix data, int i)
{
	int	j;

	j = 0;
	while (j < data.size)
	{
		data.num = (*stack_a)->value;
		if ((data.num >> i) & 1)
			ra(stack_a, 1);
		else
			pb(stack_a, stack_b, 1);
		j++;
	}
}

void	radix_sort(t_stack **stack_a, t_stack **stack_b)
{
	t_radix	data;
	int		i;

	if (!stack_a || !*stack_a)
		return ;
	data.size = stack_size(*stack_a);
	data.max_bits = 0;
	while ((data.size - 1) >> data.max_bits != 0)
		data.max_bits++;
	i = 0;
	while (i < data.max_bits)
	{
		radix_utils(stack_a, stack_b, data, i);
		while (stack_size(*stack_b) != 0)
			pa(stack_a, stack_b, 1);
		i++;
	}
}
