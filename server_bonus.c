/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:01:06 by oakbulak          #+#    #+#             */
/*   Updated: 2023/09/06 18:01:07 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_handler(int sig, siginfo_t *info, void *context)
{
	static char	c = 0;
	static int	i = 128;

	(void)context;
	if (sig == SIGUSR1)
		c += i;
	i /= 2;
	while (i == 0)
	{
		ft_putchar_fd(c, 1);
		if (c == '\0')
			kill(info->si_pid, SIGUSR2);
		i = 128;
		c = 0;
	}
}

int	main(void)
{
	int					pid;
	struct sigaction	act;

	act.sa_flags = SA_SIGINFO;
	act.sa_sigaction = &ft_handler;
	pid = getpid();
	ft_putstr_fd("\n---------------\n", 1);
	ft_putstr_fd("PID ID: ", 1);
	ft_putnbr_fd(pid, 1);
	ft_putstr_fd("\n---------------\n", 1);
	sigaction(SIGUSR1, &act, NULL);
	sigaction(SIGUSR2, &act, NULL);
	while (1)
		pause();
	return (0);
}
