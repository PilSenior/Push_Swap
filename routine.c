#include "philo.h"

static void take_forks(t_philo *philo)
{
    if (philo->id % 2 == 0) {
        pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
        print_status(philo, "has taken a fork");
    } else {
        pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
        print_status(philo, "has taken a fork");
        pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
        print_status(philo, "has taken a fork");
    }
}

static void drop_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
    pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void eat(t_philo *philo)
{
    take_forks(philo);
    pthread_mutex_lock(&philo->data->meal_mutex);
    philo->last_meal = get_time();
    pthread_mutex_unlock(&philo->data->meal_mutex);
    print_status(philo, "is eating");
    ft_usleep(philo->data->time_eat);
    pthread_mutex_lock(&philo->data->meal_mutex);
    philo->meal_count++;
    pthread_mutex_unlock(&philo->data->meal_mutex);
    drop_forks(philo);
}

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;

    if (philo->id % 2 == 0)
        ft_usleep(1);

    while (!check_death(philo->data)) {
        eat(philo);
        if (check_death(philo->data))
            break;
        print_status(philo, "is sleeping");
        ft_usleep(philo->data->time_sleep);
        if (check_death(philo->data))
            break;
        print_status(philo, "is thinking");
    }
    return (NULL);
}
