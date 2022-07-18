/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkings.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:24:09 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/18 00:24:16 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	someone_died(t_philo *p)
{
	struct timeval	timer;

	gettimeofday(&timer, NULL);
	if (time_diffinmls(p->timer, timer) > p->time_to_die)
	{
		ft_put_message(p, RED, "died\n");
		return (1);
	}
	return (0);
}

void	*if_party_is_over(void *arg)
{
	t_philo		*p;

	p = (t_philo *)arg;
	while (1)
	{
		if (p->eat_max > 0 && !p->is_done && (p->eat_count >= p->eat_max))
		{
			sem_post(p->already_ate);
			p->is_done = 1;
		}
		if (someone_died(p))
			sem_post(p->is_dead);
	}
	return (0);
}
