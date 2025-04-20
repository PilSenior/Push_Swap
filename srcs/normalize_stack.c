/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/20 20:11:22 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/20 20:11:22 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	swap_int(int *a, int *b)
{
	int	temp;

	temp = *a;
	*a = *b;
	*b = temp;
}

static void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
				swap_int(&arr[j], &arr[j + 1]);
			j++;
		}
		i++;
	}
}

static int	find_index(int *sorted_arr, int size, int value)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (sorted_arr[i] == value)
			return (i);
		i++;
	}
	return (-1);
}

void	normalize_stack(t_stack **stack, int size)
{
	t_stack	*current;
	int		*values;
	int		i;
	int		index;

	if (!stack || !*stack)
		return ;
	values = (int *)malloc(sizeof(int) * size);
	if (!values)
		error_exit();
	current = *stack;
	i = 0;
	while (current)
	{
		values[i++] = current->value;
		current = current->next;
	}
	bubble_sort_array(values, size);
	current = *stack;
	while (current)
	{
		index = find_index(values, size, current->value);
		current->value = index;
		current = current->next;
	}
	free(values);
}

int	is_normalized(t_stack *stack, int size)
{
	int			i;
	t_stack		*current;
	static int	found[10000];

	i = 0;
	while (i < size)
		found[i++] = 0;
	if (!stack)
		return (1);
	current = stack;
	while (current)
	{
		if (current->value < 0 || current->value >= size)
			return (0);
		found[current->value]++;
		if (found[current->value] > 1)
			return (0);
		current = current->next;
	}
	i = 0;
	while (i < size)
	{
		if (found[i] != 1)
			return (0);
		i++;
	}
	return (1);
}
