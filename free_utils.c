/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/02 12:16:57 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/26 14:56:38 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_and_clean(t_table *table)
{
	int	count;

	if (table->forks && table->forks_init > 0)
	{
		count = 0;
		while (count < table->forks_init)
			pthread_mutex_destroy(&table->forks[count++].mutex);
		free(table->forks);
		table->forks = NULL;
	}
	if (table->mutex_print_init)
		pthread_mutex_destroy(&table->print_mutex);
	if (table->mutex_death_init)
		pthread_mutex_destroy(&table->death_mutex);
	if (table->philosophers)
	{
		free(table->philosophers);
		table->philosophers = NULL;
	}
}
