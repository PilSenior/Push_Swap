/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/21 08:33:02 by htekdemi          #+#    #+#             */
/*   Updated: 2025/04/21 08:33:02 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>
# include <stdio.h>
# include "../libft/libft.h"

typedef struct s_stack
{
	int				value;
	struct s_stack	*next;
}	t_stack;

typedef struct s_radix
{
	int	max_bits;
	int	size;
	int	num;
}	t_radix;

t_stack	*stack_new(int value);
void	stack_add_front(t_stack **stack, t_stack *new);
void	stack_add_back(t_stack **stack, t_stack *new);
int		stack_size(t_stack *stack);
t_stack	*stack_last(t_stack *stack);
void	stack_clear(t_stack **stack);
int		stack_min(t_stack *stack);
int		stack_max(t_stack *stack);
int		is_sorted(t_stack *stack);
int		get_position(t_stack *stack, int value);
int		get_min_position(t_stack *stack);

void	sa(t_stack **stack_a, int print);
void	sb(t_stack **stack_b, int print);
void	ss(t_stack **stack_a, t_stack **stack_b, int print);
void	pa(t_stack **stack_a, t_stack **stack_b, int print);
void	pb(t_stack **stack_a, t_stack **stack_b, int print);
void	ra(t_stack **stack_a, int print);
void	rb(t_stack **stack_b, int print);
void	rr(t_stack **stack_a, t_stack **stack_b, int print);
void	rra(t_stack **stack_a, int print);
void	rrb(t_stack **stack_b, int print);
void	rrr(t_stack **stack_a, t_stack **stack_b, int print);

void	radix_sort(t_stack **stack_a, t_stack **stack_b);
void	simple_radix_sort(t_stack **stack_a, t_stack **stack_b);

void	error_exit(void);
int		*ft_atoi_check(const char *str, int *error);
int		check_duplicates(t_stack *stack);
t_stack	*parse_args(int argc, char **argv, int *size);
void	normalize_stack(t_stack **stack, int size);

void	sort_two(t_stack **stack_a);
void	sort_three(t_stack **stack_a);
void	sort_five(t_stack **stack_a, t_stack **stack_b);
void	sort_small(t_stack **stack_a, t_stack **stack_b, int size);

int		check_the_string(const char *str, int *error);

#endif
