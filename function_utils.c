/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:39:53 by lpalomin          #+#    #+#             */
/*   Updated: 2025/06/23 14:19:58 by lpalomin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_atoi(const char *nptr)
{
	int	sign;
	int	mem;
	int	cont;

	sign = 1;
	mem = 0;
	cont = 0;
	while (nptr[cont] == ' ' || (nptr[cont] >= 9 && nptr[cont] <= 13))
		cont++;
	if (nptr[cont] == '+' || nptr[cont] == '-')
	{
		if (nptr[cont] == '-')
			sign *= -1;
		cont++;
	}
	if (nptr[cont] == '+' || nptr[cont] == '-')
		return (0);
	while (nptr[cont] >= 48 && nptr[cont] <= 57)
	{
		mem = (mem * 10) + ((int)nptr[cont] - '0');
		cont++;
	}
	return (mem * sign);
}

long long	philo_timestamp(void)
{
	struct timeval	tv;
	long long		ms;

	gettimeofday(&tv, NULL);
	ms = (tv.tv_sec * 1000LL) + (tv.tv_usec / 1000);
	return (ms);
}

void	print_action(t_philosopher *philo, int action)
{
	long long	timestamp;

	timestamp = philo_timestamp();
	pthread_mutex_lock(&philo->table->print_mutex);
	if (!check_deaths(philo->table))
	{
		if (action == 1)
			printf("\033[0;32m%lld %d has taken a fork\033[0m\n",
				timestamp, philo->index);
		else if (action == 2)
			printf("%lld %d is eating\n", timestamp, philo->index);
		else if (action == 3)
			printf("\033[0;36m%lld %d is sleeping\033[0m\n",
				timestamp, philo->index);
		else if (action == 4)
			printf("\033[0;33m%lld %d is thinking\033[0m\n",
				timestamp, philo->index);
		else if (action == 5)
			printf("\033[0;31m%lld %d died\033[0m\n",
				timestamp, philo->index);
	}
	pthread_mutex_unlock(&philo->table->print_mutex);
}

void	ft_usleep(long long ms)
{
	long long	start;

	start = philo_timestamp();
	while ((philo_timestamp() - start) < ms)
		usleep(500);
}

int	check_deaths(t_table *table)
{
	int	result;

	pthread_mutex_lock(&table->death_mutex);
	result = table->someone_died;
	pthread_mutex_unlock(&table->death_mutex);
	return (result);
}
