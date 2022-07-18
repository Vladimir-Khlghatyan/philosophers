/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_mutexes_threads.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:23:23 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/11 17:23:34 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	create_mutexes(t_mutual *mut)
{
	int	i;

	mut->forks = malloc(sizeof(pthread_mutex_t) * mut->philo_count);
	mut->lock_all = malloc(sizeof(pthread_mutex_t));
	pthread_mutex_init(mut->lock_all, NULL);
	i = -1;
	while (++i < mut->philo_count)
		pthread_mutex_init(mut->forks + i, NULL);
}

void	create_philos(t_mutual *mut)
{
	int				i;
	unsigned long	hima;

	hima = now();
	mut->to_philos = malloc(sizeof(t_philo) * mut->philo_count);
	i = -1;
	while (++i < mut->philo_count)
	{
		mut->to_philos[i].index = i;
		mut->to_philos[i].eat_count = 0;
		mut->to_philos[i].time_to_die = mut->time_to_die;
		mut->to_philos[i].time_to_eat = mut->time_to_eat;
		mut->to_philos[i].time_to_sleep = mut->time_to_sleep;
		mut->to_philos[i].sit_time = hima;
		mut->to_philos[i].lock_all = mut->lock_all;
		mut->to_philos[i].timer = now();
		forks_definition(mut, i);
	}
}

void	forks_definition(t_mutual *mut, int index)
{
	int	x;

	if (index == mut->philo_count - 1)
		x = 0;
	else
		x = index + 1;
	mut->to_philos[index].right_fork = mut->forks + index;
	mut->to_philos[index].left_fork = mut->forks + x;
}

void	create_threads(t_mutual *mut)
{
	int	i;

	mut->threads = malloc(sizeof(pthread_t) * mut->philo_count);
	if (!mut->threads || !mut->to_philos)
		return ;
	i = -1;
	while (++i < mut->philo_count)
	{
		pthread_create(mut->threads + i, NULL,
			start_party, (void *)(mut->to_philos + i));
	}
	check_if_the_party_is_over(mut);
	end_party(mut);
}
