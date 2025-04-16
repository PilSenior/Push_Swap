/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/16 08:12:09 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/16 08:12:09 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_atoi_check(const char *str, int *error)
{
	int		*num;
	long	result;

	if (!*str)
	{
		*error = 1;
		return (NULL);
	}
	result = ft_atoi(str);
	if (!check_the_string(str, error))
		return (NULL);
	if (!is_within_int_limits(result))
	{
		*error = 1;
		return (NULL);
	}
	num = (int *)malloc(sizeof(int));
	if (!num)
	{
		*error = 1;
		return (NULL);
	}
	*num = (int)result;
	return (num);
}

int	check_duplicates(t_stack *stack)
{
	t_stack	*current;
	t_stack	*check;

	current = stack;
	while (current)
	{
		check = current->next;
		while (check)
		{
			if (current->value == check->value)
				return (1);
			check = check->next;
		}
		current = current->next;
	}
	return (0);
}

static char	**split_args(int argc, char **argv)
{
	char	**args;
	int		i;

	if (argc == 2)
		return (ft_split(argv[1], ' '));
	args = (char **)malloc(sizeof(char *) * argc);
	if (!args)
		error_exit();
	i = 0;
	while (i < argc - 1)
	{
		args[i] = ft_strdup(argv[i + 1]);
		if (!args[i])
		{
			while (i > 0)
				free(args[--i]);
			free(args);
			error_exit();
		}
		i++;
	}
	args[i] = NULL;
	return (args);
}

static t_stack	*process_args(char **args, int *size, int *error)
{
	t_stack	*stack;
	t_stack	*new;
	int		*num;
	int		i;

	stack = NULL;
	i = 0;
	*size = 0;
	while (args[i])
	{
		num = ft_atoi_check(args[i], error);
		if (*error)
		{
			stack_clear(&stack);
			return (free(num), NULL);
		}
		new = stack_new(*num);
		free(num);
		if (!new)
			return (stack_clear(&stack), NULL);
		stack_add_back(&stack, new);
		(*size)++;
		i++;
	}
	return (stack);
}

t_stack	*parse_args(int argc, char **argv, int *size)
{
	char	**args;
	t_stack	*stack;
	int		error;
	int		i;

	if (argc < 2)
		exit(0);
	args = split_args(argc, argv);
	if (!args)
		error_exit();
	error = 0;
	stack = process_args(args, size, &error);
	i = 0;
	while (args[i])
		free(args[i++]);
	free(args);
	if (error || !stack)
		error_exit();
	if (check_duplicates(stack))
	{
		stack_clear(&stack);
		error_exit();
	}
	return (stack);
}
