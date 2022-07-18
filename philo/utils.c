/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:23:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/11 17:23:45 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

unsigned long	now(void)
{
	struct timeval	t;

	gettimeofday(&t, NULL);
	return (t.tv_sec * 1000 + t.tv_usec / 1000);
}

void	ft_usleep(unsigned long time)
{
	unsigned long	start;

	start = now();
	while (now() - start < time)
		;
}

void	ft_put_message(t_philo *p, char *color, char *str)
{
	pthread_mutex_lock(p->lock_all);
	printf("%s%ld %d %s", color, (now() - p->sit_time), p->index + 1, str);
	if (str[0] != 'd')
		pthread_mutex_unlock(p->lock_all);
}

void	end_party(t_mutual *mut)
{
	int	i;

	i = -1;
	while (++i < mut->philo_count)
		pthread_detach(mut->threads[i]);
	i = -1;
	while (++i < mut->philo_count)
		pthread_mutex_destroy(&(mut->forks[i]));
}

int	ft_atoi(char *str)
{
	int	num;
	int	sign;
	int	i;

	num = 0;
	sign = 1;
	i = 0;
	while (str[i] == '\t' || str[i] == '\n' || str[i] == '\v' || \
				str[i] == '\f' || str[i] == '\r' || str[i] == ' ')
			i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + str[i] - '0';
		i++;
	}
	return (num * sign);
}
