/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: olyetisk <olyetisk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 15:25:55 by olyetisk          #+#    #+#             */
/*   Updated: 2024/02/28 17:27:26 by olyetisk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *str)
{
	int		i;
	int		sign;
	long	result;

	i = 0;
	sign = 1;
	result = 0;
	while (str[i] == 32 || (str[i] >= 9 && str[i] <= 13))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - 48);
		i++;
	}
	return (result * sign);
}

void	ft_function(unsigned char a, int pid)
{
	int		j;

	j = 7;
	while (j >= 0)
	{
		if ((a >> j) & 1)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		j--;
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	int		i;
	int		pid;

	i = 0;
	pid = ft_atoi(av[1]);
	if (ac != 3)
		return (0);
	while (av[2][i])
	{
		ft_function(av[2][i], pid);
		i++;
	}
}
