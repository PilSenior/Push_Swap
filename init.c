#include "philo.h"

static int init_mutexes(t_data *data)
{
    int i;

    data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
    if (!data->forks)
        return (1);

    i = 0;
    while (i < data->nb_philo) {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0) {
            while (--i >= 0)
                pthread_mutex_destroy(&data->forks[i]);
            free(data->forks);
            return (1);
        }
        i++;
    }

    if (pthread_mutex_init(&data->print_mutex, NULL) != 0 ||
        pthread_mutex_init(&data->death_mutex, NULL) != 0 ||
        pthread_mutex_init(&data->meal_mutex, NULL) != 0) {
        i = data->nb_philo;
        while (--i >= 0)
            pthread_mutex_destroy(&data->forks[i]);
        free(data->forks);
        return (1);
    }

    return (0);
}

int init_philos(t_data *data)
{
    int i;

    data->philos = malloc(sizeof(t_philo) * data->nb_philo);
    if (!data->philos)
        return (1);

    i = 0;
    while (i < data->nb_philo) {
        data->philos[i].id = i + 1;
        data->philos[i].left_fork = i;
        data->philos[i].right_fork = (i + 1) % data->nb_philo;
        data->philos[i].meal_count = 0;
        data->philos[i].last_meal = 0;
        data->philos[i].data = data;
        i++;
    }
    return (0);
}

int init_data(t_data *data, int argc, char **argv)
{
    data->nb_philo = ft_atoi(argv[1]);
    data->time_die = ft_atoi(argv[2]);
    data->time_eat = ft_atoi(argv[3]);
    data->time_sleep = ft_atoi(argv[4]);
    data->must_eat = (argc == 6) ? ft_atoi(argv[5]) : -1;
    data->someone_died = 0;

    if (data->nb_philo <= 0 || data->time_die <= 0 || data->time_eat <= 0 ||
        data->time_sleep <= 0 || (argc == 6 && data->must_eat <= 0))
        return (1);

    if (init_mutexes(data) != 0)
        return (1);

    if (init_philos(data) != 0) {
        destroy_all(data);
        return (1);
    }
    return (0);
}

int start_threads(t_data *data)
{
    int i;
    pthread_t monitor_thread;

    data->start_time = get_time();

    i = 0;
    while (i < data->nb_philo) {
        pthread_mutex_lock(&data->meal_mutex);
        data->philos[i].last_meal = data->start_time;
        pthread_mutex_unlock(&data->meal_mutex);
        if (pthread_create(&data->philos[i].thread, NULL, &routine, &data->philos[i]) != 0)
            return (1);
        i++;
    }

    if (pthread_create(&monitor_thread, NULL, &monitor_routine, data) != 0)
        return (1);

    pthread_join(monitor_thread, NULL);

    i = 0;
    while (i < data->nb_philo)
        pthread_join(data->philos[i++].thread, NULL);

    return (0);
}
