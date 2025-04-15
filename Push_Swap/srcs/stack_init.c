#include "../includes/push_swap.h"

/*
** Yeni bir stack node'u oluşturur ve değerini atar
*/
t_stack *stack_new(int value)
{
    t_stack *new;

    new = (t_stack *)malloc(sizeof(t_stack));
    if (!new)
        return (NULL);
    new->value = value;
    new->next = NULL;
    return (new);
}

/*
** Stack'in başına yeni bir node ekler
*/
void stack_add_front(t_stack **stack, t_stack *new)
{
    if (!stack || !new)
        return;
    new->next = *stack;
    *stack = new;
}

/*
** Stack'in sonuna yeni bir node ekler
*/
void stack_add_back(t_stack **stack, t_stack *new)
{
    t_stack *last;

    if (!stack || !new)
        return;
    if (!*stack)
    {
        *stack = new;
        return;
    }
    last = stack_last(*stack);
    last->next = new;
}

/*
** Stack'i tamamen temizler ve belleği serbest bırakır
*/
void stack_clear(t_stack **stack)
{
    t_stack *temp;

    if (!stack || !*stack)
        return;
    while (*stack)
    {
        temp = (*stack)->next;
        free(*stack);
        *stack = temp;
    }
    *stack = NULL;
}