/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/31 15:21:08 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 17:11:39 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

void	ft_write(char *str, t_philo *philo, int id);
void	ft_putstr_fd(char *str, int fd);
void	ft_putendl_fd(char *str, int fd);
void	ft_clean_all(char *str, t_program *program, pthread_mutex_t *forks);

void	ft_putstr_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i -1);
}

void	ft_putendl_fd(char *str, int fd)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	write(fd, str, i - 1);
	write(fd, "\n", 1);
}

void	ft_clean_all(char *str, t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	if (str[i])
		ft_putendl_fd(str, 2);
	pthread_mutex_destroy(&program->deadlock);
	pthread_mutex_destroy(&program->meal_lock);
	pthread_mutex_destroy(&program->write_lock);
	while (i < program->philos[i].amount_of_philos)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
}

void	ft_write(char *str, t_philo *philo, int id)
{
	size_t	time;

	pthread_mutex_lock(philo->write_lock);
	time = ft_current_time() - philo->start_time;
	if (!ft_is_dead(philo))
		printf("%lu %d %s\n", time, id, str);
	pthread_mutex_unlock(philo->write_lock);
}
