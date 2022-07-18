/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:46 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/11 17:22:53 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*start_party(void *arg)
{
	t_philo	*p;

	p = (t_philo *)arg;
	p->timer = now();
	if (p->index % 2 == 1)
		ft_usleep(p->time_to_eat);
	eating(p);
	return (NULL);
}

void	eating(t_philo *p)
{
	take_forks(p);
	ft_put_message(p, BLUE, "is eating\n");
	ft_usleep(p->time_to_eat);
	p->timer = now();
	p->eat_count++;
	put_down_forks(p);
	sleeping_and_thinking(p);
}

void	take_forks(t_philo *p)
{
	pthread_mutex_lock(p->right_fork);
	ft_put_message(p, PINK, "has taken a fork\n");
	pthread_mutex_lock(p->left_fork);
	ft_put_message(p, PINK, "has taken a fork\n");
}

void	put_down_forks(t_philo *p)
{
	pthread_mutex_unlock(p->right_fork);
	pthread_mutex_unlock(p->left_fork);
}

void	sleeping_and_thinking(t_philo *p)
{
	ft_put_message(p, CYAN, "is sleeping\n");
	ft_usleep(p->time_to_sleep);
	ft_put_message(p, YELLOW, "is thinking\n");
	eating(p);
}
