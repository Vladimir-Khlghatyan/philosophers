/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vkhlghat <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 17:23:04 by vkhlghat          #+#    #+#             */
/*   Updated: 2022/07/11 17:23:14 by vkhlghat         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdio.h>
# include <sys/time.h>

# define RED	"\33[1;31m"
# define GREEN	"\33[1;32m"
# define YELLOW	"\33[1;33m"
# define BLUE	"\33[1;34m"
# define PINK	"\33[1;35m"
# define CYAN	"\33[1;36m"
# define WHITE	"\33[1;37m"
# define RESET	"\33[0;m"

typedef struct s_philo	t_philo;

typedef struct s_mutual
{	
	int				philo_count;
	unsigned long	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				eat_max;
	t_philo			*to_philos;
	pthread_mutex_t	*forks;
	pthread_t		*threads;
	pthread_mutex_t	*lock_all;
}					t_mutual;

struct s_philo
{	
	int				index;
	int				eat_count;
	unsigned long	time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	unsigned long	sit_time;
	unsigned long	timer;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*lock_all;
};

/* checking.c */
int				all_the_philos_have_already_eaten(t_mutual *mut);
int				someone_died(t_philo *p);
int				check_if_the_party_is_over(t_mutual *mut);

/* main.c */
int				main(int ac, char **av);
t_mutual		*philosophers_party(int ac, char **av);
int				fill_mutual(int ac, char **av, t_mutual *mut);
void			free_all(t_mutual *mut);

/* party.c */
void			*start_party(void *arg);
void			eating(t_philo *p);
void			take_forks(t_philo *p);
void			put_down_forks(t_philo *p);
void			sleeping_and_thinking(t_philo *p);

/* philos_mutexes_threads */
void			create_mutexes(t_mutual *mut);
void			create_philos(t_mutual *mut);
void			forks_definition(t_mutual *mut, int index);
void			create_threads(t_mutual *mut);

/* utils.c */
unsigned long	now(void);
void			ft_usleep(unsigned long time);
void			ft_put_message(t_philo *p, char *color, char *str);
void			end_party(t_mutual *mut);
int				ft_atoi(char *str);

#endif
