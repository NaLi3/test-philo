/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:37:04 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 16:28:47 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

int	main(int argc, char **argv)
{
	t_philo			philo[200];
	t_program		program;
	pthread_mutex_t	forks[200];

	if (ft_check_arg == -1)
		return (-1);
	ft_init_forks(&forks, ft_atoi(argv[1]));
	ft_init_program(&program, &philo);
	ft_init_philo(&philo, argv, &program, &forks);
	ft_threads(&program, &forks);
	ft_clean_all('\0', &program, forks);
	return (0);
}
