/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 00:25:05 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/18 00:25:18 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <semaphore.h>
# include <stdio.h>
# include <sys/time.h>
# include <errno.h>
# include <signal.h>
# include <fcntl.h>
# include <sys/stat.h>

# define RED        "\33[1;31m"
# define GREEN      "\33[1;32m"
# define PINK	    "\33[1;35m"
# define YELLOW		"\33[1;33m"
# define BLUE     	"\33[1;36m"
# define CYAN       "\33[1;36m"

typedef struct s_philo	t_philo;

typedef struct s_mutual
{
	int				philo_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_max;
	t_philo			*to_philos;
	sem_t			*lock_all;
	sem_t			*forks;
	sem_t			*dead_philo;
	sem_t			*everyone_ate;
	pid_t			*processes;
}					t_mutual;

struct s_philo
{
	int				index;
	int				eat_count;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_max;
	struct timeval	sit_time;
	struct timeval	timer;
	sem_t			*forks;
	sem_t			*lock_all;
	sem_t			*is_dead;
	sem_t			*already_ate;
	int				is_done;
	pid_t			pid;
};

/* checking.c */
int		someone_died(t_philo *p);
void	*if_party_is_over(void *arg);

/* main.c */
int		main(int argc, char **argv);
void	philosophers_party(int ac, char **av);
int		fill_mutual(int ac, char **av, t_mutual *mut);
void	free_all_and_exit(t_mutual *mut);
void	kill_processes(t_mutual *mut);

/* party.c */
void	start_party(t_philo *p);
void	eating(t_philo *p);
void	take_forks(t_philo *p);
void	put_down_forks(t_philo *p);
void	sleeping_and_thinking(t_philo *p);

/* philos_semos_processes.c */
void	create_semos(t_mutual *mut);
void	create_philos(t_mutual *mut);
void	create_processes(t_mutual *mut);

/* utils.c */
int		time_diffinmls(struct timeval start, struct timeval end);
int		gettime(void);
void	ft_usleep(int time);
void	ft_put_message(t_philo *p, char *color, char *str);
int		ft_atoi(char *str);

/* wait.c */
void	wait_for_end(t_mutual *mut);
void	*wait_for_dead(void *arg);
void	*wait_for_eatmax(void *arg);

#endif
