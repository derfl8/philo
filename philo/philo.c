/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:58:59 by abegou            #+#    #+#             */
/*   Updated: 2026/10/16 22:10:26 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	argcheck(char *arg)
{
	long long	ret;
	int			i;

	i = ft_strlen(arg);
	if (i > 12)
		return (-1);
	i = 0;
	while (arg[i])
	{
		if (arg[i] < '0' || arg[i] > '9')
			return (-1);
		i++;
	}
	ret = ft_atol(arg);
	if (ret < 1 || ret > INT_MAX)
		return (-1);
	return (ret);
}

static int	parsing(int ac, char **av, t_data *data)
{
	if (ac != 5 && ac != 6)
		return (1);
	data->nb_philos = argcheck(av[1]);
	data->time_to_die = argcheck(av[2]);
	data->time_to_eat = argcheck(av[3]);
	data->time_to_sleep = argcheck(av[4]);
	if (ac == 6)
		data->must_eat = argcheck(av[5]);
	else
		data->must_eat = 0;
	if (ac == 6 && data->must_eat < 1)
		return (1);
	if (data->nb_philos < 1 || data->time_to_die < 1 || data->time_to_eat < 1
		|| data->time_to_sleep < 1)
		return (1);
	return (0);
}

static void	threads_engine(t_data *data)
{
	int	i;

	i = 0;
	while (i < data->nb_philos)
	{
		pthread_create(&data->philo[i].thread, NULL, routine, &data->philo[i]);
		i++;
	}
	i = 0;
	while (i < data->nb_philos)
	{
		pthread_join(data->philo[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av, &data))
		return (1);
	if (data_init(&data))
		return (1);
	threads_engine(&data);
	extermination(&data);
	return (0);
}
