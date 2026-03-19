/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abegou <abegou@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/14 16:00:02 by abegou            #+#    #+#             */
/*   Updated: 2026/03/19 15:50:30 by abegou           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#define PHILO_H

// libs
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

// structs
typedef struct s_philo	{
	int			    pid;
	long long		last_eat;
    int             n_eat;
	pthread_mutex_t	*lfork;
	pthread_mutex_t	*rfork;
	t_data			*data;
	pthread_t		thread;
}					t_philo;

typedef struct s_data  {
    int				nb_philos;
    int				time_to_die;
    int				time_to_eat;
    int				time_to_sleep;
	int				must_eat;
	long long		start;
	int				end;
	pthread_mutex_t	*forks;
	t_philo			*philo;
}					t_data;