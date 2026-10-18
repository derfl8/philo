/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:00:02 by abegou            #+#    #+#             */
/*   Updated: 2026/10/18 20:37:01 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

// libs
# include <limits.h>
# include <pthread.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct s_data	t_data;
typedef struct s_philo	t_philo;

typedef struct s_philo
{
	int					pid;
	long long			last_eat;
	int					n_eat;
	pthread_mutex_t		*lfork;
	pthread_mutex_t		*rfork;
	pthread_mutex_t		meal_lock;
	t_data				*data;
	pthread_t			thread;
}						t_philo;

typedef struct s_data
{
	int					nb_philos;
	int					time_to_die;
	int					time_to_eat;
	int					time_to_sleep;
	int					must_eat;
	long long			start;
	int					end;
	pthread_mutex_t		print_lock;
	pthread_mutex_t		*forks;
	t_philo				*philo;
}						t_data;

// utils
int						ft_strlen(char *s);
long long				ft_atol(const char *nptr);
long long				ft_time(void);
void					enhanced_usleep(long long ms);

// init.c
int						data_init(t_data *data);
void					extermination(t_data *data);

// pthread.c
void					print_status(t_philo *philo, char *msg);
void					*routine(void *arg);

// monitor.c
void					monitor(t_data *data);

#endif