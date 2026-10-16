/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:46:02 by abegou            #+#    #+#             */
/*   Updated: 2026/10/16 22:29:34 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	foodie(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(philo->rfork);
	print_status(philo, "has taken a fork");
	pthread_mutex_lock(&philo->meal_lock);
	philo->n_eat++;
	philo->last_eat = ft_time();
	pthread_mutex_unlock(&philo->meal_lock);
	print_status(philo, "is eating");
	enhanced_usleep(philo->data->time_to_eat);
	pthread_mutex_unlock(philo->lfork);
	pthread_mutex_unlock(philo->rfork);
}

void	*schopenhauer(t_philo *philo)
{
	pthread_mutex_lock(philo->lfork);
	print_status(philo, "has taken a fork");
	enhanced_usleep(philo->data->time_to_die);
	pthread_mutex_unlock(philo->lfork);
	return (NULL);
}

void	*routine(void *arg)
{
	t_philo	*philo;

	philo = arg;
	if (philo->data->nb_philos == 1)
		return (schopenhauer(philo));
	if (philo->pid % 2 == 0)
		enhanced_usleep(philo->data->time_to_eat / 2);
	while (1)
	{
		foodie(philo);
		print_status(philo, "is sleeping");
		enhanced_usleep(philo->data->time_to_sleep);
		print_status(philo, "is thinking");
	}
	return (NULL);
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	printf("%lld %d %s\n", ft_time() - philo->data->start, philo->pid, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}
