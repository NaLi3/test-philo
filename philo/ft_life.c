/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_life.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 16:34:06 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 17:04:01 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

void	ft_eat(t_philo *philo)
{
	pthread_mutex_lock(philo->right_f);
	ft_write("has taken their right fork", philo, philo->number);
	if (philo->amount_of_philos == 1)
	{
		ft_usleep(philo->time_to_die);
		pthread_mutex_unlock(philo->right_f);
		return ;
	}
	pthread_mutex_lock(philo->left_f);
	ft_write("has taken their left fork", philo, philo->number);
	philo->eating = 1;
	ft_write("is eating spaghet", philo, philo->number);
	pthread_mutex_lock(philo->meal_lock);
	philo->last_meal = ft_current_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(philo->meal_lock);
	ft_usleep(philo->time_to_eat);
	philo->eating = 0;
	pthread_mutex_unlock(philo->right_f);
	pthread_mutex_unlock(philo->left_f);
}

void	ft_sleep(t_philo *philo)
{
	ft_write("is sleeping the sleepless dream", philo, philo->number);
	ft_usleep(philo->time_to_sleep);
}

void	ft_think(t_philo *philo)
{
	ft_write("is thinking big thoughts", philo, philo->number);
}
