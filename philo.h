/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:20:39 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/26 09:28:49 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <sys/time.h>

typedef struct s_fork
{
	pthread_mutex_t	mutex;
}	t_fork;

typedef struct s_philosopher
{
	int				index;
	int				number_meats;
	long long		last_meal;
	pthread_t		thread;
	struct s_fork	*left_fork;
	struct s_fork	*right_fork;
	struct s_table	*table;
}	t_philosopher;

typedef struct s_table
{
	int						amount_philo;
	int						die_time;
	int						eat_time;
	int						sleep_time;
	int						number_meats;
	int						someone_died;
	long long				start_time;
	struct s_philosopher	*philosophers;
	struct s_fork			*forks;
	pthread_mutex_t			print_mutex;
	pthread_mutex_t			death_mutex;
}	t_table;

// init_game.c
int			init_game(t_table *table, int argc, char **argv);
// free_utils.c
void		free_and_clean(t_table *table);
// action_utils.c
int			start_game(t_table *table);
// function_utils.c
int			ft_atoi(const char *nptr);
long long	philo_timestamp(void);
void		print_action(t_philosopher *philo, int action);
void		ft_usleep(long long ms);
int			check_deaths(t_table *table);
// philosopher_killer.c
void		*death_checker(void *arg);
#endif
