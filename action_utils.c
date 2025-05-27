/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/12 09:04:49 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/26 11:34:35 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->left_fork->mutex);
	print_action(philo, 1);
	pthread_mutex_lock(&philo->right_fork->mutex);
	print_action(philo, 1);
}

static void	drop_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->left_fork->mutex);
	pthread_mutex_unlock(&philo->right_fork->mutex);
}

static void	*philo_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	if (philo->index % 2 == 0)
		usleep(100);
	while (!check_deaths(philo->table))
	{
		print_action(philo, 4);
		take_forks(philo);
		print_action(philo, 2);
		philo->last_meal = philo_timestamp();
		ft_usleep(philo->table->eat_time);
		philo->number_meats++;
		drop_forks(philo);
		print_action(philo, 3);
		ft_usleep(philo->table->sleep_time);
	}
	return (NULL);
}

int	start_game(t_table *table)
{
	pthread_t	death_thread;
	int			count;

	table->start_time = philo_timestamp();
	count = 0;
	while (count < table->amount_philo)
	{
		table->philosophers[count].last_meal = table->start_time;
		if (pthread_create(&table->philosophers[count].thread, NULL,
				philo_routine, &table->philosophers[count]) != 0)
			return (1);
		usleep(100);
		count++;
	}
	if (pthread_create(&death_thread, NULL, death_checker, table) != 0)
		return (1);
	pthread_join(death_thread, NULL);
	count = 0;
	while (count < table->amount_philo)
	{
		pthread_join(table->philosophers[count].thread, NULL);
		count++;
	}
	return (0);
}
