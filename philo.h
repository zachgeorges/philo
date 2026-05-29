/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: zgeorges <zgeorges@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/05/27 14:33:34 by zgeorges          #+#    #+#             */
/*   Updated: 2026/05/27 17:42:37 by zgeorges         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef PHILO_H
# define PHILO_H

#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>
#include <sys/time.h>
#include <limits.h>
#include <stdbool.h>
#include <errno.h>

/*operation codes for threads and mutexes*/
typedef enum	e_code
{
	LOCK,
	UNLOCK,
	INIT,
	DESTROY,
	CREATE,
	JOIN,
	DETACH,
}	t_code;

/*structures*/
typedef struct s_info	t_info;

typedef pthread_mutex_t	t_mutex;

typedef struct	s_fork
{
	t_mutex	fork;
	int	fork_num;
}	t_fork;

typedef struct	s_philo
{
	int	num;
	long	times_eaten;
	bool	full;
	long	last_eaten;
	t_fork	*left_fork;
	t_fork	*right_fork;
	pthread_t	thread_id;
	t_info	*info;
}	t_philo;

typedef struct	s_info
{
	long	number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	long	plh;//smth with meals
	long	start_time;
	long	number_of_times_each_philosopher_must_eat;
	bool	end_sim;
	t_fork	*forks;
	t_philo	*philos;
}	t_info;

/*parsing functions*/
void	parse_input(t_info *info, char **av);
/*init functions*/
void	data_init(t_info *info);
/*safety functions*/
void	*malloc_controlled(size_t bytes);
void	mutex_controlled(t_mutex *mutex, t_code code);
void	thread_controlled(pthread_t *thread, void *(*f)(void *), void *data, t_code code);
/*utils functions*/
void	error_exit(const char *error);

#endif