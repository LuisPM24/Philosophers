/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_killer.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/19 14:16:11 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/26 13:05:42 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	mark_death(t_table *table)
{
	pthread_mutex_lock(&table->death_mutex);
	table->someone_died = 1;
	pthread_mutex_unlock(&table->death_mutex);
}

static int	enough_meal(t_table *table)
{
	int	count;

	count = 0;
	if (table->number_meats == -1)
		return (1);
	while (count < table->amount_philo)
	{
		if (table->philosophers[count].number_meats < table->number_meats)
			return (1);
		count++;
	}
	return (0);
}

static void	*meal_cycle(t_table *table)
{
	t_philosopher	*philo;
	long long		time_last_meal;
	int				count;

	count = 0;
	while (count < table->amount_philo)
	{
		philo = &table->philosophers[count];
		time_last_meal = philo_timestamp() - philo->last_meal;
		if (time_last_meal >= table->die_time)
		{
			print_action(philo, 5);
			mark_death(table);
			return (NULL);
		}
		count++;
	}
	if (!enough_meal(table))
	{
		mark_death(table);
		return (NULL);
	}
	usleep(1000);
	return (NULL);
}

void	*death_checker(void *arg)
{
	t_table			*table;

	table = (t_table *)arg;
	while (!check_deaths(table))
		meal_cycle(table);
	return (NULL);
}
