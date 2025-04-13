#include "../includes/push_swap.h"

/*
** Stack'in boyutunu döndürür
*/
int stack_size(t_stack *stack)
{
    int size;

    size = 0;
    while (stack)
    {
        size++;
        stack = stack->next;
    }
    return (size);
}

/*
** Stack'in son elemanını döndürür
*/
t_stack *stack_last(t_stack *stack)
{
    if (!stack)
        return (NULL);
    while (stack->next)
        stack = stack->next;
    return (stack);
}

/*
** Stack'teki en küçük değeri bulur
*/
int stack_min(t_stack *stack)
{
    int min;

    if (!stack)
        return (0);
    min = stack->value;
    while (stack)
    {
        if (stack->value < min)
            min = stack->value;
        stack = stack->next;
    }
    return (min);
}

/*
** Stack'teki en büyük değeri bulur
*/
int stack_max(t_stack *stack)
{
    int max;

    if (!stack)
        return (0);
    max = stack->value;
    while (stack)
    {
        if (stack->value > max)
            max = stack->value;
        stack = stack->next;
    }
    return (max);
}

/*
** Stack'in sıralı olup olmadığını kontrol eder
*/
int is_sorted(t_stack *stack)
{
    if (!stack)
        return (1);
    while (stack->next)
    {
        if (stack->value > stack->next->value)
            return (0);
        stack = stack->next;
    }
    return (1);
}

/*
** Belirli bir değerin stack'teki pozisyonunu bulur
*/
int get_position(t_stack *stack, int value)
{
    int pos;

    pos = 0;
    while (stack)
    {
        if (stack->value == value)
            return (pos);
        pos++;
        stack = stack->next;
    }
    return (-1);
}

/*
** En küçük değerin stack'teki pozisyonunu bulur
*/
int get_min_position(t_stack *stack)
{
    int min;
    int min_pos;
    int current_pos;

    if (!stack)
        return (-1);
    min = stack->value;
    min_pos = 0;
    current_pos = 0;
    while (stack)
    {
        if (stack->value < min)
        {
            min = stack->value;
            min_pos = current_pos;
        }
        current_pos++;
        stack = stack->next;
    }
    return (min_pos);
}