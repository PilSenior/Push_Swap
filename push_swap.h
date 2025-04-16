# ifndef PUSH_SWAP_H
#define PUSH_SWAP_H

/* Gerekli kütüphaneler ve tanımlar */
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <stdio.h>
#include "../libft/libft.h" // ya da kütüphanenin konumuna göre düzenleyin

#define MIN_INT //EKLEMA YAPILCAK:
#define MAX_INT//EKLEMA YAPILCAK:

/* Stack yapısı - bağlı liste kullanarak */
typedef struct s_stack
{
    int             value;
    struct s_stack  *next;
} t_stack;

/* Fonksiyon prototipleri */
// Stack fonksiyonları
t_stack    *stack_new(int value);
void       stack_add_front(t_stack **stack, t_stack *new);
void       stack_add_back(t_stack **stack, t_stack *new);
int        stack_size(t_stack *stack);
t_stack    *stack_last(t_stack *stack);
void       stack_clear(t_stack **stack);
int        stack_min(t_stack *stack);
int        stack_max(t_stack *stack);
int        is_sorted(t_stack *stack);
int        get_position(t_stack *stack, int value);
int        get_min_position(t_stack *stack);

// Temel operasyonlar
void       sa(t_stack **stack_a, int print);
void       sb(t_stack **stack_b, int print);
void       ss(t_stack **stack_a, t_stack **stack_b, int print);
void       pa(t_stack **stack_a, t_stack **stack_b, int print);
void       pb(t_stack **stack_a, t_stack **stack_b, int print);
void       ra(t_stack **stack_a, int print);
void       rb(t_stack **stack_b, int print);
void       rr(t_stack **stack_a, t_stack **stack_b, int print);
void       rra(t_stack **stack_a, int print);
void       rrb(t_stack **stack_b, int print);
void       rrr(t_stack **stack_a, t_stack **stack_b, int print);

/* radix_sort.c */
void radix_sort(t_stack **stack_a, t_stack **stack_b);
void simple_radix_sort(t_stack **stack_a, t_stack **stack_b);

/* normalize_stack.c */
void normalize_stack(t_stack **stack, int size);
int is_normalized(t_stack *stack, int size);

// Yardımcı fonksiyonlar
void       error_exit(void);
int        *ft_atoi_check(const char *str, int *error);
int        check_duplicates(t_stack *stack);
t_stack    *parse_args(int argc, char **argv, int *size);
void       normalize_stack(t_stack **stack, int size);

/* small_sort.c */
void sort_two(t_stack **stack_a);
void sort_three(t_stack **stack_a);
void sort_five(t_stack **stack_a, t_stack **stack_b);
void sort_small(t_stack **stack_a, t_stack **stack_b, int size);
// In push_swap.h
// Add this declaration if it's missing

// Stack operation functions
void stack_swap(t_stack **stack);
void stack_push(t_stack **dest, t_stack **src);
void stack_rotate(t_stack **stack);
void stack_reverse_rotate(t_stack **stack);
int check_the_string(const char *str, int *error);

#endif