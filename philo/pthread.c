/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pthread.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 14:46:02 by abegou            #+#    #+#             */
/*   Updated: 2026/10/15 22:47:36 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void *arg)
{
	t_philo *philo;

	philo = arg;
	print_status(philo, "is thinking");
	return (NULL);
}

void	print_status(t_philo *philo, char *msg)
{
	pthread_mutex_lock(&philo->data->print_lock);
	printf("%lld %d %s\n", ft_time() - philo->data->start, philo->pid, msg);
	pthread_mutex_unlock(&philo->data->print_lock);
}
