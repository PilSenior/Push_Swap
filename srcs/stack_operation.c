#include "../includes/push_swap.h"

/*
** Stack'in üstündeki iki elemanı yer değiştirir (swap)
*/
void stack_swap(t_stack **stack)
{
    t_stack *first;
    t_stack *second;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    second = first->next;
    first->next = second->next;
    second->next = first;
    *stack = second;
}

/*
** Stack'in üstündeki elemanı diğer stack'e taşır (push)
*/
void stack_push(t_stack **dest, t_stack **src)
{
    t_stack *temp;

    if (!src || !*src || !dest)
        return;
    temp = *src;
    *src = (*src)->next;
    temp->next = *dest;
    *dest = temp;
}

/*
** Stack'i yukarı doğru döndürür (rotate)
** İlk eleman son eleman olur
*/
void stack_rotate(t_stack **stack)
{
    t_stack *first;
    t_stack *last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    first = *stack;
    last = stack_last(*stack);
    *stack = first->next;
    first->next = NULL;
    last->next = first;
}

/*
** Stack'i aşağı doğru döndürür (reverse rotate)
** Son eleman ilk eleman olur
*/
void stack_reverse_rotate(t_stack **stack)
{
    t_stack *last;
    t_stack *prev_last;

    if (!stack || !*stack || !(*stack)->next)
        return;
    last = *stack;
    prev_last = NULL;
    while (last->next)
    {
        prev_last = last;
        last = last->next;
    }
    prev_last->next = NULL;
    last->next = *stack;
    *stack = last;
}