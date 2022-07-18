/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checking.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:13 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/11 17:22:25 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	all_the_philos_have_already_eaten(t_mutual *mut)
{
	int	i;

	i = -1;
	while (++i < mut->philo_count)
		if (mut->eat_max == 0 || \
			mut->to_philos[i].eat_count < mut->eat_max)
			return (0);
	return (1);
}

int	someone_died(t_philo *p)
{
	if (now() - p->timer > p->time_to_die)
		return (1);
	return (0);
}

int	check_if_the_party_is_over(t_mutual *mut)
{
	int	i;

	while (1)
	{
		if (all_the_philos_have_already_eaten(mut))
		{
			ft_usleep(10);
			printf("%sThe simulation has successfully completed\n", GREEN);
			return (1);
		}
		i = -1;
		while (++i < mut->philo_count)
		{
			if (someone_died(&(mut->to_philos[i])))
			{
				ft_put_message(&(mut->to_philos[i]), RED, "died\n");
				return (2);
			}
		}
	}
	return (0);
}
