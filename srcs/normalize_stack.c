/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normalize_stack.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 06:02:53 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/21 06:02:53 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

static void	bubble_sort_array(int *arr, int size)
{
	int	i;
	int	j;
	int	temp;

	i = 0;
	while (i < size - 1)
	{
		j = 0;
		while (j < size - i - 1)
		{
			if (arr[j] > arr[j + 1])
			{
				temp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = temp;
			}
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

void	normalize_stack(t_stack **stack, int size, int *values)
{
	t_stack	*current;
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
