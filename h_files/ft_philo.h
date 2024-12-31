/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:30:29 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 17:04:14 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PHILO_H
# define FT_PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_philo
{
	pthread_t		thread_id;
	int				number;

	int				eating;
	int				meals_eaten;
	int				amount_of_philos;
	int				amount_of_times_to_eat;
	int				*is_philo_dead;

	size_t			last_meal;
	size_t			time_to_die;
	size_t			time_to_sleep;
	size_t			time_to_eat;
	size_t			start_time;

	pthread_mutex_t	*right_f;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*write_lock;
	pthread_mutex_t	*deadlock;
	pthread_mutex_t	*meal_lock;
}					t_philo;

typedef struct s_program
{
	int				dead;
	pthread_mutex_t	deadlock;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	meal_lock;
	t_philo			*philos;
}					t_program;

// ft_err.c
int		ft_check_arg(int argc, char **argv);
int		ft_check_each_arg(int argc, char **argv);

// ft_init.c
void	ft_init_forks(pthread_mutex_t *forks, int num_of_philos);
void	ft_init_program(t_program *program, t_philo *philos);
void	ft_init_philo(t_philo *philo, char **argv,
			t_program *program, pthread_mutex_t *forks);
void	ft_init_p(t_philo *philos, char **argv);

// ft_utils.c
int		ft_atoi(char *str);
int		ft_is_digit(char c);
size_t	ft_current_time(void);

// ft_dinner.c
void	ft_thread_create(t_program *program, pthread_mutex_t *forks);
void	*ft_dinner(void	*philo_x);
int		ft_is_dead(t_philo *philo);

// ft_message.c
void	ft_putendl_fd(char *str, int fd);
void	ft_putstr_fd(char *str, int fd);
void	ft_clean_all(char *str, t_program *program, pthread_mutex_t *forks);
void	ft_write(char *str, t_philo *philo, int id);

// ft_verify.c
void	*ft_verify(void *program_old);

// ft_life.c
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);

#endif
