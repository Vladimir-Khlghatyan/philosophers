/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:24:26 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/18 00:24:36 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	main(int argc, char **argv)
{
	if (argc < 5 || argc > 6)
		printf("%sInvalid number of arguments\n", RED);
	else
		philosophers_party(argc, argv);
	return (0);
}

void	philosophers_party(int ac, char **av)
{
	t_mutual	*mut;

	mut = malloc(sizeof(t_mutual));
	if (fill_mutual(ac, av, mut) == 0)
	{
		printf("%sBad inputs!\n", RED);
		free(mut);
		exit (1);
	}
	create_semos(mut);
	create_philos(mut);
	create_processes(mut);
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

void	free_all_and_exit(t_mutual *mut)
{
	if (mut->processes != NULL)
		free(mut->processes);
	if (mut->to_philos != NULL)
		free(mut->to_philos);
	free(mut);
	exit(1);
}

void	kill_processes(t_mutual *mut)
{
	int	i;

	i = -1;
	while (++i < mut->philo_count)
		kill(mut->processes[i], SIGKILL);
}
