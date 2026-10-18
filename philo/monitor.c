/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/18 19:07:27 by abegou            #+#    #+#             */
/*   Updated: 2026/10/18 20:37:31 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	dead_or_what(t_data *data, int i)
{
	long long	keat;

	pthread_mutex_lock(&data->philo[i].meal_lock);
	keat = data->philo[i].last_eat;
	pthread_mutex_unlock(&data->philo[i].meal_lock);
	if (ft_time() - keat >= data->time_to_die)
	{
		pthread_mutex_lock(&data->print_lock);
		printf("%lld %d %s\n", ft_time() - data->start, data->philo[i].pid,
			"died");
		data->end = 1;
		pthread_mutex_unlock(&data->print_lock);
		return (1);
	}
	return (0);
}

static int	is_everyone_satisfied(t_data *data)
{
	int	i;
	int	how_many_philo_is_full_of_food_in_their_stomach;

	if (data->must_eat == 0)
		return (0);
	i = 0;
	how_many_philo_is_full_of_food_in_their_stomach = 0;
	while (i < data->nb_philos)
	{
		pthread_mutex_lock(&data->philo[i].meal_lock);
		if (data->philo[i].n_eat >= data->must_eat)
			how_many_philo_is_full_of_food_in_their_stomach++;
		pthread_mutex_unlock(&data->philo[i].meal_lock);
		i++;
	}
	if (how_many_philo_is_full_of_food_in_their_stomach == data->nb_philos)
	{
		pthread_mutex_lock(&data->print_lock);
		data->end = 1;
		pthread_mutex_unlock(&data->print_lock);
		return (1);
	}
	return (0);
}

void	monitor(t_data *data)
{
	int	i;

	while (1)
	{
		i = 0;
		while (i < data->nb_philos)
		{
			if (dead_or_what(data, i))
				return ;
			i++;
		}
		if (is_everyone_satisfied(data))
			return ;
		enhanced_usleep(1);
	}
}
