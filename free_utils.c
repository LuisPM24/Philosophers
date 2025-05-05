/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:16:57 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/02 12:41:13 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_clean(t_table *table)
{
	int	count;

	if (table->forks)
	{
		count = 0;
		while (count < table->amount_philo)
		{
			pthread_mutex_destroy(&table->forks[count].mutex);
			count++;
		}
		free(table->forks);
		table->forks = NULL;
		free(table->philosophers);
		table->philosophers = NULL;
	}
	pthread_mutex_destroy(&table->print_mutex);
	pthread_mutex_destroy(&table->death_mutex);
	if (table->philosophers)
		free(table->philosophers);
}
