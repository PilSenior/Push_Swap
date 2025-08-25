#include "philo.h"

void destroy_all(t_data *data)
{
    int i;

    if (data->forks) {
        i = 0;
        while (i < data->nb_philo)
            pthread_mutex_destroy(&data->forks[i++]);
        free(data->forks);
    }

    pthread_mutex_destroy(&data->print_mutex);
    pthread_mutex_destroy(&data->death_mutex);
    pthread_mutex_destroy(&data->meal_mutex);

    if (data->philos)
        free(data->philos);
}
