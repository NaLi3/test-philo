/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ilevy <ilevy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/28 15:38:44 by ilevy             #+#    #+#             */
/*   Updated: 2024/12/31 16:50:50 by ilevy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../h_files/ft_philo.h"

int		ft_atoi(char *str);
int		ft_is_digit(char c);
size_t	ft_current_time(void);
int		ft_usleep(size_t ms);

int	ft_atoi(char *str)
{
	int	i;
	int	sum;

	i = 0;
	sum = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t'))
		i++;
	while (str[i])
	{
		if (ft_is_digit(str[i]))
			sum = sum * 10 + str[i] - '0';
		else
			return (-1);
		i++;
	}
	return (sum);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

size_t	ft_current_time(void)
{
	struct timeval	time;
	size_t			final_time;

	if (gettimeofday(&time, NULL) == -1)
	{
		write(2, "gettimeofday error\n", 20);
		return (-1);
	}
	final_time = (size_t)time.tv_sec * 1000000 + (size_t)time.tv_usec;
	return (final_time);
}

int	ft_usleep(size_t	ms)
{
	size_t	start;

	start = ft_current_time();
	while ((ft_current_time - start) < ms)
		usleep(500);
	return (0);
}
