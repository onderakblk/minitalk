/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/12 11:31:41 by oakbulak          #+#    #+#             */
/*   Updated: 2023/08/12 11:39:09 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int s)
{
	static char	c = 0;
	static int	i = 128;

	if (s == SIGUSR1)
		c += i;
	i /= 2;
	while (i == 0)
	{
		ft_putchar_fd(c, 1);
		i = 128;
		c = 0;
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_putstr_fd("\n---------------\n", 1);
	ft_putstr_fd("PID ID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n---------------\n", 1);
	signal(SIGUSR1, ft_handler);
	signal(SIGUSR2, ft_handler);
	while (1)
		pause();
	return (0);
}
