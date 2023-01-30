/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbolat <bbolat@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/11 17:16:39 by bbolat            #+#    #+#             */
/*   Updated: 2022/08/16 01:09:52 by bbolat           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_action(int signum)
{
	static char		c = 0;
	static int		i = 0;

	c |= (signum == SIGUSR1);
	if (++i == 8)
	{
		i = 0;
		if (!c)
			write(1, "\n", 1);
		write(1, &c, 1);
		c = 0;
	}
	else
		c <<= 1;
}

int	main(void)
{
	printf("PID: %d\n", getpid());
	signal(SIGUSR1, ft_action);
	signal(SIGUSR2, ft_action);
	while (1)
	{
		pause();
	}
}
