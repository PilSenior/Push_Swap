#include "philo.h"

int ft_atoi(const char *str)
{
    int i = 0, sign = 1;
    long result = 0;

    while ((str[i] >= 9 && str[i] <= 13) || str[i] == 32)
        i++;
    if (str[i] == '-' || str[i] == '+')
        if (str[i++] == '-')
            sign = -1;
    if (str[i] < '0' || str[i] > '9')
        return (-1);
    while (str[i] >= '0' && str[i] <= '9') {
        result = result * 10 + (str[i] - '0');
        if (result > 2147483647)
            return (-1);
        i++;
    }
    return ((int)(result * sign));
}

long long get_time(void)
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return ((tv.tv_sec * 1000LL) + (tv.tv_usec / 1000));
}

void ft_usleep(long long time_ms)
{
    long long start = get_time();
    while (get_time() - start < time_ms)
        usleep(100);
}

void print_status(t_philo *philo, char *msg)
{
    long long time;
    pthread_mutex_lock(&philo->data->print_mutex);
    if (!philo->data->someone_died) {
        time = get_time() - philo->data->start_time;
        printf("%lld %d %s\n", time, philo->id, msg);
    }
    pthread_mutex_unlock(&philo->data->print_mutex);
}
