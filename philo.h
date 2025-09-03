/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: htekdemi <htekdemi@student.42kocaeli.co    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/02 21:44:45 by htekdemi          #+#    #+#             */
/*   Updated: 2025/09/02 23:01:38 by htekdemi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_data	t_data;

typedef struct s_philo
{
	int				id;
	int				left_fork;
	int				right_fork;
	int				meal_count;
	long long		last_meal;
	pthread_t		thread;
	t_data			*data;
}	t_philo;

typedef struct s_data
{
	int				nb_philo;
	int				time_die;
	int				time_eat;
	int				time_sleep;
	int				must_eat;
	int				someone_died;
	long long		start_time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	pthread_mutex_t	meal_mutex;
	t_philo			*philos;
}	t_data;

/* Initialization */
int			init_data(t_data *data, int argc, char **argv);
int			start_threads(t_data *data);
int			init_philos(t_data *data);
void		destroy_all(t_data *data);

/* Philosopher routine */
void		*routine(void *arg);
void		*monitor_routine(void *arg);
void		eat(t_philo *philo);
void		print_status(t_philo *philo, char *msg);

/* Utils */
int			ft_atoi(const char *str);
long long	get_time(void);
void		ft_usleep(long long time_ms);

/* Monitor helpers */
int			check_death(t_data *data);
int			all_ate_enough(t_data *data);

#endif
