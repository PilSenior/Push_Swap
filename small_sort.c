/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   small_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 07:04:29 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/16 07:04:29 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_two(t_stack **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if ((*stack_a)->value > (*stack_a)->next->value)
		sa(stack_a, 1);
}

void	sort_three(t_stack **stack_a)
{
	int	first;
	int	second;
	int	third;

	if (!stack_a || !*stack_a || !(*stack_a)->next
		|| !(*stack_a)->next->next)
		return ;//NULL ÇEK İÇİN AYRI FONKSİYON OLUŞTUR.
	first = (*stack_a)->value;
	second = (*stack_a)->next->value;
	third = (*stack_a)->next->next->value;
	if (first > second && first < third && second < third)
		sa(stack_a, 1);
	else if (first > second && first > third && second < third)
		ra(stack_a, 1);
	else if (first > second && first > third && second > third)
	{
		sa(stack_a, 1);
		rra(stack_a, 1);
	}
	else if (first < second && first < third && second > third)
	{
		sa(stack_a, 1);
		ra(stack_a, 1);
	}
	else if (first < second && first > third && second > third)
		rra(stack_a, 1);
}

static void	push_min_to_b(t_stack **stack_a, t_stack **stack_b)
{
	int	min_pos;
	int	size;

	min_pos = get_min_position(*stack_a);
	size = stack_size(*stack_a);
	if (min_pos <= size / 2)
	{
		while (min_pos-- > 0)
			ra(stack_a, 1);
	}
	else
	{
		while (min_pos++ < size)
			rra(stack_a, 1);
	}
	pb(stack_a, stack_b, 1);
}

void	sort_five(t_stack **stack_a, t_stack **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	size = stack_size(*stack_a);
	if (size <= 1)
		return ;
	if (size == 2)
	{
		sort_two(stack_a);
		return ;
	}
	if (size > 3)
		push_min_to_b(stack_a, stack_b);
	if (size > 4)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_size(*stack_b) > 0)
		pa(stack_a, stack_b, 1);
}

void	sort_small(t_stack **stack_a, t_stack **stack_b, int size)
{
	if (size <= 5)
	{
		sort_five(stack_a, stack_b);
		return ;
	}
	while (stack_size(*stack_a) > 3)
		push_min_to_b(stack_a, stack_b);
	sort_three(stack_a);
	while (stack_size(*stack_b) > 0)
		pa(stack_a, stack_b, 1);
}
