/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   wait.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:25:53 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/18 00:25:58 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	wait_for_end(t_mutual *mut)
{
	pthread_t	ifdead;
	pthread_t	ifeatmax;

	pthread_create(&ifdead, NULL, wait_for_dead, mut);
	pthread_create(&ifeatmax, NULL, wait_for_eatmax, mut);
	pthread_detach(ifeatmax);
	pthread_join(ifdead, NULL);
}

void	*wait_for_dead(void *arg)
{
	t_mutual	*mut;

	mut = (t_mutual *)arg;
	sem_wait(mut->dead_philo);
	return (NULL);
}

void	*wait_for_eatmax(void *arg)
{
	t_mutual	*mut;
	int			i;

	mut = (t_mutual *)arg;
	i = -1;
	while (++i < mut->philo_count)
		sem_wait(mut->everyone_ate);
	sem_wait(mut->lock_all);
	printf("%sThe simulation has successfully completed\n", GREEN);
	sem_post(mut->dead_philo);
	return (NULL);
}
