/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   party.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:24:46 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/18 00:24:54 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	start_party(t_philo *p)
{
	pthread_t	check_dead;

	pthread_create(&check_dead, NULL, if_party_is_over, p);
	pthread_detach(check_dead);
	gettimeofday(&(p->timer), NULL);
	eating(p);
}

void	eating(t_philo *p)
{
	take_forks(p);
	ft_put_message(p, BLUE, "is eating\n");
	ft_usleep(p->time_to_eat);
	gettimeofday(&(p->timer), NULL);
	p->eat_count++;
	put_down_forks(p);
	sleeping_and_thinking(p);
}

void	take_forks(t_philo *p)
{
	sem_wait(p->forks);
	ft_put_message(p, PINK, "has taken a fork\n");
	sem_wait(p->forks);
	ft_put_message(p, PINK, "has taken a fork\n");
}

void	put_down_forks(t_philo *p)
{
	sem_post(p->forks);
	sem_post(p->forks);
}

void	sleeping_and_thinking(t_philo *p)
{
	ft_put_message(p, CYAN, "is sleeping\n");
	ft_usleep(p->time_to_sleep);
	ft_put_message(p, YELLOW, "is thinking\n");
	eating(p);
}
