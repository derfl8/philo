/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:00:02 by abegou            #+#    #+#             */
/*   Updated: 2026/03/16 15:06:45 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PHILO_H
#include <limits.h>
#include <pthread.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

// utils
int			ft_atoi(const char *nptr);
long long	ft_atol(const char *nptr);
void		*ft_calloc(size_t nmemb, size_t size);
size_t		ft_strlen(const char *s);
size_t		ft_strlenin(const char *s);
void		*ft_free(char **array);
char		**ft_split(char const *s, char c);
char		*ft_substr(char const *s, unsigned int start, size_t len);
