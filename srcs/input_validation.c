#include "../includes/push_swap.h"

/*
** Hata mesajı yazdırıp programı sonlandırır
*/
void error_exit(void)
{
    write(2, "Error\n", 6);
    exit(1);
}

/*
** Sayının integer sınırları içinde olup olmadığını kontrol eder
*/
static int is_within_int_limits(long num)
{
    return (num >= INT_MIN && num <= INT_MAX);
}

/*
** String'i integer'a çevirir, hata durumunda error parametresini 1 yapar
*/
int *ft_atoi_check(const char *str, int *error)
{
    long result;
    int sign;
    int *num;

    result = 0;
    sign = 1;
    while (*str == ' ' || (*str >= 9 && *str <= 13))
        str++;
    if (*str == '-' || *str == '+')
    {
        if (*str == '-')
            sign = -1;
        str++;
    }
    if (!*str)
        *error = 1;
    while (*str)
    {
        if (*str < '0' || *str > '9')
        {
            *error = 1;
            return (NULL);
        }
        result = result * 10 + (*str - '0');
        if (!is_within_int_limits(result * sign))
        {
            *error = 1;
            return (NULL);
        }
        str++;
    }
    num = (int *)malloc(sizeof(int));
    if (!num)
        *error = 1;
    else
        *num = (int)(result * sign);
    return (num);
}

/*
** Stack'te aynı değere sahip eleman olup olmadığını kontrol eder
*/
int check_duplicates(t_stack *stack)
{
    t_stack *current;
    t_stack *check;

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

/*
** Argümanları parçalara ayırır (boşluklara göre)
** ft_split libft'den gelir
*/
static char **split_args(int argc, char **argv)
{
    char **args;
    
    if (argc == 2)
        args = ft_split(argv[1], ' ');
    else
    {
        int i = 0;
        args = (char **)malloc(sizeof(char *) * argc);
        if (!args)
            error_exit();
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
    }
    return (args);
}

/*
** Argümanları parse eder ve stack'i oluşturur
*/
t_stack *parse_args(int argc, char **argv, int *size)
{
    char **args;
    t_stack *stack;
    t_stack *new;
    int i;
    int error;
    int *num;

    if (argc < 2)
        exit(0);
    args = split_args(argc, argv);
    if (!args)
        error_exit();
    stack = NULL;
    i = 0;
    *size = 0;
    while (args[i])
    {
        error = 0;
        num = ft_atoi_check(args[i], &error);
        if (error)
        {
            stack_clear(&stack);
            free(num);
            i = 0;
            while (args[i])
                free(args[i++]);
            free(args);
            error_exit();
        }
        new = stack_new(*num);
        free(num);
        if (!new)
        {
            stack_clear(&stack);
            i = 0;
            while (args[i])
                free(args[i++]);
            free(args);
            error_exit();
        }
        stack_add_back(&stack, new);
        (*size)++;
        i++;
    }
    i = 0;
    while (args[i])
        free(args[i++]);
    free(args);
    if (check_duplicates(stack))
    {
        stack_clear(&stack);
        error_exit();
    }
    return (stack);
}