/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:13:14 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/30 16:12:10 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

void	ft_init_philo(t_philo *philo, char **argv,
			t_program *program, pthread_mutex_t *forks);
void	ft_init_p(t_philo *philos, char **argv);
void	ft_init_forks(pthread_mutex_t *forks, int num_of_philos);
void	ft_init_program(t_program *program, t_philo *philos);

void	ft_init_philo(t_philo *philo, char **argv,
			t_program *program, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < ft_atoi(argv[1]))
	{
		philo[i].number = i + 1;
		ft_init_p(&philo[i], argv);
		if (ft_atoi(argv[5]))
			philo[i].amount_of_times_to_eat = ft_atoi(argv[5]);
		else
			philo[i].amount_of_times_to_eat = -1;
		philo[i].start_time = ft_current_time();
		philo[i].left_f = &forks[i];
		if (!i)
			philo[i].right_f = &forks[ft_atoi(argv[1]) - 1];
		else
			philo[i].right_f = &forks[i - 1];
		philo[i].write_lock = &program->write_lock;
		philo[i].meal_lock = &program->meal_lock;
		philo[i].deadlock = &program->deadlock;
		i++;
	}
}

void	ft_init_p(t_philo *philos, char **argv)
{
	philos->eating = 0;
	philos->meals_eaten = 0;
	philos->amount_of_philos = ft_atoi(argv[1]);
	philos->last_meal = ft_current_time();
	philos->time_to_die = ft_atoi(argv[2]);
	philos->time_to_eat = ft_atoi(argv[3]);
	philos->time_to_sleep = ft_atoi(argv[4]);
}

void	ft_init_forks(pthread_mutex_t *forks, int num_of_philos)
{
	int	i;

	i = 0;
	while (i < num_of_philos)
	{
		pthread_mutex_init(&forks[i], NULL);
		i++;
	}
}

void	ft_init_program(t_program *program, t_philo *philos)
{
	program->dead = 0;
	program->philos = philos;
	pthread_mutex_init(&program->deadlock, NULL);
	pthread_mutex_init(&program->meal_lock, NULL);
	pthread_mutex_init(&program->write_lock, NULL);
}
