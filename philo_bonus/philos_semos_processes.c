/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philos_semos_processes.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:25:27 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/18 00:25:33 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	create_semos(t_mutual *mut)
{
	sem_unlink("sem1");
	sem_unlink("sem2");
	sem_unlink("sem3");
	sem_unlink("sem4");
	mut->forks = sem_open("sem1", O_CREAT | O_EXCL, 0644, mut->philo_count);
	mut->lock_all = sem_open("sem2", O_CREAT | O_EXCL, 0644, 1);
	mut->dead_philo = sem_open("sem3", O_CREAT | O_EXCL, 0644, 0);
	mut->everyone_ate = sem_open("sem4", O_CREAT | O_EXCL, 0644, 0);
}

void	create_philos(t_mutual *mut)
{
	int				i;
	struct timeval	timer;

	i = -1;
	gettimeofday(&timer, NULL);
	mut->to_philos = malloc(sizeof(t_philo) * mut->philo_count);
	while (++i < mut->philo_count)
	{
		mut->to_philos[i].index = i;
		mut->to_philos[i].time_to_die = mut->time_to_die;
		mut->to_philos[i].time_to_eat = mut->time_to_eat;
		mut->to_philos[i].time_to_sleep = mut->time_to_sleep;
		mut->to_philos[i].eat_max = mut->eat_max;
		mut->to_philos[i].eat_count = 0;
		mut->to_philos[i].lock_all = mut->lock_all;
		mut->to_philos[i].sit_time = timer;
		mut->to_philos[i].forks = mut->forks;
		mut->to_philos[i].is_dead = mut->dead_philo;
		mut->to_philos[i].already_ate = mut->everyone_ate;
		mut->to_philos[i].is_done = 0;
		gettimeofday(&mut->to_philos[i].timer, NULL);
		mut->processes = NULL;
	}
}

void	create_processes(t_mutual *mut)
{
	int		i;
	pid_t	pid;

	mut->processes = malloc(sizeof(pthread_t) * mut->philo_count);
	if (!mut->processes || !mut->to_philos)
	{
		kill_processes(mut);
		free_all_and_exit(mut);
	}
	i = -1;
	while (++i < mut->philo_count)
	{
		ft_usleep(100);
		pid = fork();
		if (pid == 0)
			start_party(mut->to_philos + i);
		mut->processes[i] = pid;
		mut->to_philos[i].pid = pid;
	}
	wait_for_end(mut);
	kill_processes(mut);
	free_all_and_exit(mut);
}
