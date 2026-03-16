/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/14 16:55:30 by abegou            #+#    #+#             */
/*   Updated: 2026/03/15 18:31:50 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

size_t	ft_strlen(const char *s)
{
	const char	*tmp = s;

	while (*tmp)
		tmp++;
	return (tmp - s);
}

size_t	ft_strlenin(const char *s)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	if (s[i] == '-')
		i++;
	while (s[i] == '0')
		i++;
	while (s[i])
	{
		i++;
		j++;
	}
	return (j);
}
