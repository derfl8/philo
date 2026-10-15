/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/15 16:44:25 by abegou            #+#    #+#             */
/*   Updated: 2026/10/15 21:39:30 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    extermination(t_data *data)
{
    int i;

    i = 0;
    while (i < data->nb_philos)
    {
        pthread_mutex_destroy(&data->forks[i]);
        pthread_mutex_destroy(&data->philo[i].meal_lock);
        i++;
    }
    pthread_mutex_destroy(&data->print_lock);
    free(data->forks);
    free(data->philo);
}

static int	alloc_and_mutex(t_data *data)
{
	int	i;

	i = 0;
	data->forks = malloc(sizeof(pthread_mutex_t) * data->nb_philos);
	if (!data->forks)
		return (1);
	data->philo = malloc(sizeof(t_philo) * data->nb_philos);
	if (!data->philo)
	{
		free(data->forks);
		return (1);
	}
	pthread_mutex_init(&data->print_lock, NULL);
	while (i < data->nb_philos)
    {
		pthread_mutex_init(&data->forks[i], NULL);
        pthread_mutex_init(&data->philo[i].meal_lock, NULL);
        i++;
    }
	return (0);
}

static void	philo_init(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		data->philo[i].data = data;
		data->philo[i].pid = i + 1;
		data->philo[i].n_eat = 0;
		data->philo[i].lfork = &data->forks[i];
		data->philo[i].rfork = &data->forks[(i + 1) % data->nb_philos];
        data->philo[i].last_eat = data->start;
		i++;
	}
}

int	data_init(t_data *data)
{
    data->end = 0;
    data->start = ft_time();
	if (alloc_and_mutex(data))
		return (1);
	philo_init(data);
	return (0);
}
