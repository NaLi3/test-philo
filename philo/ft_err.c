/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_err.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:39:18 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 15:03:17 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

int	ft_check_arg(int argc, char **argv);
int	ft_check_each_arg(int argc, char **argv);

int	ft_check_arg(int argc, char **argv)
{
	char	c;

	if (argc != 6 && argc != 5)
	{
		write(2, "Usage: ./philo [number_of_philosophers] [time_to_die]", 53);
		write(2, " [time_to_eat] [time_to_sleep] {number_of_times_", 47);
		write(2, "_philosophers_must_eat}\n", 24);
		return (-1);
	}
	if (ft_atoi(argv[1]) > 200)
	{
		write(2, "Max amount of philosophers is 200\n", 35);
		return (-1);
	}
	if (ft_check_each_arg(argc, argv) == -1)
		return (-1);
	return (0);
}

int	ft_check_each_arg(int argc, char **argv)
{
	int		i;
	char	c;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == -1)
		{
			write(2, "Invalid argument for argument number: ", 38);
			c = i + '0';
			write(2, &c, 1);
			write(2, "\n", 1);
			return (-1);
		}
		i++;
	}
	return (0);
}
