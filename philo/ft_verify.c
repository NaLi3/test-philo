/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_verify.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:36:55 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 17:30:23 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

void	*ft_verify(void *philo_x)
{
	t_philo *philo;
	int		i;

	philo = (t_philo *)philo_x;
	while (1)
	{
		if (ft_is_dead(philo) == 1 || ft_done_eating(philo) == 1)
			break;
	}
	return (philo_x);
}
