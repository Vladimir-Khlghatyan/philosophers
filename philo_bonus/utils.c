/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:25:39 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/18 00:25:49 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	time_diffinmls(struct timeval start, struct timeval end)
{
	int	start_time;
	int	end_time;

	start_time = (start.tv_sec * 1000 + start.tv_usec / 1000);
	end_time = (end.tv_sec * 1000 + end.tv_usec / 1000);
	if (start_time > end_time)
		return (0);
	return (end_time - start_time);
}

int	gettime(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return (current_time.tv_sec * 1000 + current_time.tv_usec / 1000);
}

void	ft_usleep(int time)
{
	struct timeval	t;
	int				start;

	gettimeofday(&t, NULL);
	start = t.tv_sec * 1000 + t.tv_usec / 1000;
	while (gettime() - start < time)
		usleep(100);
}

void	ft_put_message(t_philo *p, char *color, char *str)
{
	struct timeval	current_time;
	int				interval;

	sem_wait(p->lock_all);
	gettimeofday(&current_time, NULL);
	interval = time_diffinmls(p->sit_time, current_time);
	printf("%s%d %d %s", color, interval, p->index + 1, str);
	if (str[0] != 'd')
		sem_post(p->lock_all);
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
