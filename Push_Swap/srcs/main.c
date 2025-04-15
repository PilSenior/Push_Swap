#include "../includes/push_swap.h"

/**
 * push_swap - Sorts the stack A using optimal algorithm based on stack size
 * @stack_a: Reference to stack A
 * @stack_b: Reference to stack B
 * @size: Number of elements in stack A
 */
static void push_swap(t_stack **stack_a, t_stack **stack_b, int size)
{
    // Skip if already sorted
    if (is_sorted(*stack_a))
        return;

    // Normalize stack values to indices (0 to size-1)
    normalize_stack(stack_a, size);

    // Choose sorting algorithm based on stack size
    if (size == 2)
        sort_two(stack_a);
    else if (size == 3)
        sort_three(stack_a);
    else if (size <= 5)
        sort_five(stack_a, stack_b);
    else
        radix_sort(stack_a, stack_b);
}

/**
 * main - Entry point for push_swap program
 * @argc: Argument count
 * @argv: Argument vector
 * Return: 0 on success
 */
int main(int argc, char **argv)
{
    t_stack *stack_a;
    t_stack *stack_b;
    int     size;

    // Exit if no arguments provided
    if (argc < 2)
        return (0);
    
    // Parse arguments and initialize stack A
    stack_a = parse_args(argc, argv, &size);
    // Initialize stack B as empty
    stack_b = NULL;
    
    // Sort the stack if needed
    push_swap(&stack_a, &stack_b, size);
    
    // Free allocated memory
    stack_clear(&stack_a);
    stack_clear(&stack_b);
    
    return (0);
}