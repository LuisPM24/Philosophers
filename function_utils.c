/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   function_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lpalomin <lpalomin@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/30 15:39:53 by lpalomin          #+#    #+#             */
/*   Updated: 2025/04/30 15:40:44 by lpalomin         ###   ########.fr       */
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
