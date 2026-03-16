/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 15:58:59 by abegou            #+#    #+#             */
/*   Updated: 2026/03/16 15:12:32 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	int_check(char *arg)
{
	int		i;
	char	**char_to_long;

	char_to_long = ft_split(arg, ' ');
	i = 0;
	while (char_to_long[i])
	{
		if (ft_strlenin(char_to_long[i]) > 11
			|| (ft_atol(char_to_long[i]) > INT_MAX
				|| ft_atol(char_to_long[i]) < INT_MIN))
		{
			ft_free(char_to_long);
			return (false);
		}
		i++;
	}
	ft_free(char_to_long);
	return (true);
}

bool	argcheck(char *arg)
{
	int	i;

	i = 0;
	while (arg[i])
	{
		if (arg[i] != ' ' && arg[i] != '-' && arg[i] != '+' && (arg[i] < '0'
				|| arg[i] > '9'))
			return (false);
		else if ((arg[i] == '-' || arg[i] == '+') && (arg[i + 1] == ' ' || arg[i
					+ 1] == '-' || arg[i + 1] == '+' || arg[i + 1] == '\0'))
			return (false);
		else if (i > 0 && ((arg[i] == '-' || arg[i] == '-') && (arg[i
						- 1] >= '0' && arg[i - 1] <= '9')))
			return (false);
		i++;
	}
	return (true);
}

int	main(int ac, char **av)
{
	int		i;

	i = 1;
	if (ac != 4 && ac != 5)
		return (0);
	while (av[i])
	{
		if (argcheck(av[i]) == false)
			return (0);
		if (ft_atoi(av[i]) < 1 || int_check(av[i++]) == false)
			return (0);
	}
	return (0);
}
