/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:22:31 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/11 17:22:39 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int ac, char **av)
{
	t_mutual	*mut;

	mut = NULL;
	if (ac < 5 || ac > 6)
	{
		printf("%sInvalid number of arguments\n", RED);
		return (0);
	}
	else
		mut = philosophers_party(ac, av);
	if (mut != NULL)
		free_all(mut);
	return (0);
}

t_mutual	*philosophers_party(int ac, char **av)
{
	t_mutual	*mut;

	mut = malloc(sizeof(t_mutual));
	if (fill_mutual(ac, av, mut) == 0)
	{
		printf("%sBad inputs!\n", RED);
		free(mut);
		return (NULL);
	}
	create_mutexes(mut);
	create_philos(mut);
	create_threads(mut);
	return (mut);
}

int	fill_mutual(int ac, char **av, t_mutual *mut)
{
	if (ft_atoi(av[1]) <= 0 || ft_atoi(av[2]) <= 0
		|| ft_atoi(av[3]) <= 0 || ft_atoi(av[4]) <= 0)
		return (0);
	if (ac == 6 && ft_atoi(av[5]) <= 0)
		return (0);
	mut->philo_count = ft_atoi(av[1]);
	mut->time_to_die = ft_atoi(av[2]);
	mut->time_to_eat = ft_atoi(av[3]);
	mut->time_to_sleep = ft_atoi(av[4]);
	mut->eat_max = 0;
	if (ac == 6)
		mut->eat_max = ft_atoi(av[5]);
	return (1);
}

void	free_all(t_mutual *mut)
{
	free(mut->threads);
	free(mut->forks);
	free(mut->to_philos);
	free(mut->lock_all);
	free(mut);
}
