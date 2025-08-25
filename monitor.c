#include "philo.h"

int check_death(t_data *data)
{
    int result;
    pthread_mutex_lock(&data->death_mutex);
    result = data->someone_died;
    pthread_mutex_unlock(&data->death_mutex);
    return (result);
}

int all_ate_enough(t_data *data)
{
    int i, finished_count;
    if (data->must_eat == -1)
        return (0);
    finished_count = 0;
    i = 0;
    while (i < data->nb_philo) {
        pthread_mutex_lock(&data->meal_mutex);
        if (data->philos[i].meal_count >= data->must_eat)
            finished_count++;
        pthread_mutex_unlock(&data->meal_mutex);
        i++;
    }
    return (finished_count == data->nb_philo);
}

static int check_philosopher_death(t_data *data, int i)
{
    long long current_time, last_meal;
    pthread_mutex_lock(&data->meal_mutex);
    last_meal = data->philos[i].last_meal;
    pthread_mutex_unlock(&data->meal_mutex);
    current_time = get_time();
    if ((current_time - last_meal) > data->time_die) {
        pthread_mutex_lock(&data->death_mutex);
        data->someone_died = 1;
        pthread_mutex_unlock(&data->death_mutex);
        pthread_mutex_lock(&data->print_mutex);
        printf("%lld %d died\n", current_time - data->start_time, data->philos[i].id);
        pthread_mutex_unlock(&data->print_mutex);
        return (1);
    }
    return (0);
}

void *monitor_routine(void *arg)
{
    t_data *data = (t_data *)arg;
    int i;
    while (!check_death(data)) {
        i = 0;
        while (i < data->nb_philo && !check_death(data)) {
            if (check_philosopher_death(data, i))
                return (NULL);
            i++;
        }
        if (all_ate_enough(data)) {
            pthread_mutex_lock(&data->death_mutex);
            data->someone_died = 1;
            pthread_mutex_unlock(&data->death_mutex);
            return (NULL);
        }
        usleep(1000);
    }
    return (NULL);
}
