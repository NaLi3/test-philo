/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_threads.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:53:51 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 17:11:08 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

void	ft_thread_create(t_program *program, pthread_mutex_t *forks);
void	*ft_dinner(void	*philo_x);
int		ft_is_dead(t_philo *philo);

void	ft_thread_create(t_program *program, pthread_mutex_t *forks)
{
	pthread_t	supervisor;
	int			i;

	if (pthread_create(&supervisor, NULL, &ft_verify, program->philos) != 0)
		ft_clean_all("Couldn't create supervisor thread", program, forks);
	i = 0;
	while (i < program->philos[i].amount_of_philos)
	{
		if (pthread_create(&program->philos[i].thread_id, NULL, &ft_dinner,
				&program->philos[i]) != 0)
			ft_clean_all("Thread creation error", program, forks);
		i++;
	}
	i = 0;
	if (pthread_join(supervisor, NULL) != 0)
		ft_clean_all("Couldn't join supervisor thread", program, forks);
	while (i < program->philos[i].amount_of_philos)
	{
		if (pthread_join(program->philos[i].thread_id, NULL) != 0)
			ft_clean_all("Thread join error", program, forks);
		i++;
	}
}

void	*ft_dinner(void	*philo_x)
{
	t_philo	*philo;

	philo = (t_philo *)philo_x;
	if (philo->number % 2 == 0)
		ft_delay(1);
	while (!ft_is_dead(philo))
	{
		ft_eat(philo);
		ft_sleep(philo);
		ft_think(philo);
	}
	return (philo_x);
}

int	ft_is_dead(t_philo *philo)
{
	pthread_mutex_lock(philo->deadlock);
	if (*philo->is_philo_dead == 1)
	{
		pthread_mutex_unlock(philo->deadlock);
		return (1);
	}
	pthread_mutex_unlock(philo->deadlock);
	return (0);
}
