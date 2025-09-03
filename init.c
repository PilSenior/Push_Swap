/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:21:36 by htekdemi          #+#    #+#             */
/*   Updated: 2025/09/03 00:07:40 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void cleanup_partial_init(t_data *data, int forks_initialized)
{
    int i = 0;
    
    // Initialize edilmiş fork'ları temizle
    while (i < forks_initialized)
        pthread_mutex_destroy(&data->forks[i++]);
    
    if (data->forks)
        free(data->forks);
    data->forks = NULL;
}

void	init_mutex_two(t_data *data, int ct)
{
	while (--ct >= 0)
		pthread_mutex_destroy(&data->forks[ct]);
}

static int init_mutexes(t_data *data)
{
    int i = 0;
    
    data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philo);
    if (!data->forks)
        return (1);
    
    // Fork mutex'lerini initialize et
    while (i < data->nb_philo)
    {
        if (pthread_mutex_init(&data->forks[i], NULL) != 0)
        {
            cleanup_partial_init(data, i);  // ✅ YENİ
            return (1);
        }
        i++;
    }
    if (pthread_mutex_init(&data->print_mutex, NULL) != 0 ||
        pthread_mutex_init(&data->death_mutex, NULL) != 0 ||
        pthread_mutex_init(&data->meal_mutex, NULL) != 0)
    {
        cleanup_partial_init(data, data->nb_philo);  // ✅ YENİ
        return (1);
    }
    return (0);
}


int	init_philos(t_data *data)
{
	int	i;

	data->philos = malloc(sizeof(t_philo) * data->nb_philo);
	if (!data->philos)
		return (1);
	i = 0;
	while (i < data->nb_philo)
	{
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

int	init_data(t_data *data, int argc, char **argv)
{
	data->nb_philo = ft_atoi(argv[1]);
	data->time_die = ft_atoi(argv[2]);
	data->time_eat = ft_atoi(argv[3]);
	data->time_sleep = ft_atoi(argv[4]);
	data->must_eat = -1;
	if (argc == 6)
		data->must_eat = ft_atoi(argv[5]);
	data->someone_died = 0;
if (data->nb_philo <= 0 || data->nb_philo > 200)
    return (1); // Maksimum filozof sayısı

if (data->time_die < 60 || data->time_eat < 60 || data->time_sleep < 60)
    return (1); // Minimum time değerleri

if (data->time_die > 1000000 || data->time_eat > 1000000 || 
    data->time_sleep > 1000000)
    return (1); // Maksimum time değerleri

// ✅ YENİ: Race condition için özel kontrol
if (data->nb_philo > 100 && data->time_die < (data->time_eat + data->time_sleep + 50))
    return (1);

if (argc == 6 && data->must_eat <= 0)
    return (1);
	if (init_mutexes(data) != 0)
		return (1);
	if (init_philos(data) != 0)
	{
		destroy_all(data);
		return (1);
	}
	return (0);
}

int	start_threads(t_data *data)
{
	int			i;
	pthread_t	monitor_thread;

	data->start_time = get_time();
	i = 0;
	while (i < data->nb_philo)
	{
		pthread_mutex_lock(&data->meal_mutex);
		data->philos[i].last_meal = data->start_time;
		pthread_mutex_unlock(&data->meal_mutex);
		if (pthread_create(&data->philos[i].thread, NULL,
				&routine, &data->philos[i]) != 0)
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
