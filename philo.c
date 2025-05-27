/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 12:50:52 by lpalomin          #+#    #+#             */
/*   Updated: 2025/05/26 13:38:18 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	philosophers(int argc, char **argv)
{
	t_table	table;

	if (init_game(&table, argc, argv) != 0)
	{
		free_and_clean(&table);
		return (1);
	}
	if (start_game(&table) != 0)
	{
		free_and_clean(&table);
		return (1);
	}
	free_and_clean(&table);
	return (0);
}

int	main(int argc, char **argv)
{
	if (argc == 5 || argc == 6)
	{
		if (!philosophers(argc, argv))
			return (1);
	}
	else
		write(2, "Error: Bad arguments\n", 21);
	return (0);
}
