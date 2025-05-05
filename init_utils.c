/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 14:09:43 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/02 10:06:35 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	init_forks(t_table *table)
{
	int	count;

	table->forks = malloc(sizeof(t_fork) * table->amount_philo);
	if (!table->forks)
		return (1);
	count = 0;
	while (count < table->amount_philo)
	{
		if (pthread_mutex_init(&table->forks[count].mutex, NULL))
			return (1);
		count++;
	}
	return (0);
}

static int	init_philosophers(t_table *table)
{
	t_philosopher	*philo;
	int				count;

	table->philosophers = malloc(sizeof(t_philosopher)
			* table->amount_philo);
	if (!table->philosophers)
		return (1);
	count = 0;
	while (count < table->amount_philo)
	{
		philo = &table->philosophers[count];
		philo->index = count + 1;
		philo->number_meats = 0;
		philo->last_meal = 0;
		philo->table = table;
		philo->left_fork = &table->forks[count];
		philo->right_fork = &table->forks[(count + 1)
			% table->amount_philo];
		count++;
	}
	return (0);
}

static int	init_table(t_table *table, int argc, char **argv)
{
	if (!table)
		return (1);
	table->amount_philo = ft_atoi(argv[1]);
	table->die_time = ft_atoi(argv[2]);
	table->eat_time = ft_atoi(argv[3]);
	table->sleep_time = ft_atoi(argv[4]);
	if (argc == 6)
		table->number_meats = ft_atoi(argv[5]);
	else
		table->number_meats = -1;
	table->someone_died = 0;
	table->start_time = 0;
	if (pthread_mutex_init(&table->print_mutex, NULL)
		|| pthread_mutex_init(&table->death_mutex, NULL))
		return (1);
	return (init_forks(table) || init_philosophers(table));
}

int	init_game(t_table *table, int argc, char **argv)
{
	if (init_table(table, argc, argv))
	{
		printf("Error: Init failed\n");
		return (1);
	}
	return (0);
}
