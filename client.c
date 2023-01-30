/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:16:36 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/16 01:00:45 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int	ft_atoi(char *s)
{
	int	i;

	i = 0;
	while (*s)
	{
		i = (i * 10) + (*s - 48);
		s++;
	}
	return (i);
}

void	sendsignal(int pid, char *av)
{
	int	c;
	int	i;

	i = 0;
	while (av[i])
	{
		c = 8;
		while (c--)
		{
			if (((av[i] >> c) & 1) == 1)
			{
				kill(pid, SIGUSR1);
			}
			else
				kill(pid, SIGUSR2);
			usleep(100);
		}
		i++;
	}
	i = 8;
	while (i--)
	{
		kill(pid, SIGUSR2);
		usleep(100);
	}
}

int	main(int ac, char **av)
{
	if (ac != 3)
		printf("invalid arguments!");
	else
	{
		sendsignal(ft_atoi(av[1]), av[2]);
	}
	return (0);
}
