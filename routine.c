/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:46:55 by htekdemi          #+#    #+#             */
/*   Updated: 2025/09/03 01:58:38 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philo *philo)
{
    if (philo->data->nb_philo == 1)
    {
        pthread_mutex_lock(&philo->data->forks[0]);
        print_status(philo, "has taken a fork");
        ft_usleep(philo->data->time_die + 1);
        pthread_mutex_unlock(&philo->data->forks[0]);
        return;
    }
    
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
        usleep(200);
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
	}
	else
	{
		pthread_mutex_lock(&philo->data->forks[philo->left_fork]);
		print_status(philo, "has taken a fork");
        usleep(200);
		pthread_mutex_lock(&philo->data->forks[philo->right_fork]);
		print_status(philo, "has taken a fork");
	}
}

static void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->data->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->data->forks[philo->right_fork]);
}

void	eat(t_philo *philo)
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

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->id % 2 == 0)
		ft_usleep(1);
	while (!check_death(philo->data))
	{
		eat(philo);
		if (check_death(philo->data))
			break ;
		print_status(philo, "is sleeping");
		ft_usleep(philo->data->time_sleep);
		if (check_death(philo->data))
			break ;
		print_status(philo, "is thinking");
	}
	return (NULL);
}
