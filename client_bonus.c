/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: oakbulak <oakbulak@student.42kocaeli.com.  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/06 18:00:53 by oakbulak          #+#    #+#             */
/*   Updated: 2023/09/06 18:00:55 by oakbulak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	size_t	j;
	size_t	k;
	char	*str;

	i = ft_strlen(s1) + ft_strlen(s2);
	str = (char *)malloc((sizeof(char) * i) + 1);
	if (!str)
		return (NULL);
	j = 0;
	while (s1[j] != '\0')
	{
		str[j] = s1[j];
		j++;
	}
	k = 0;
	while (j < i + 1 && s2[k] != '\0')
	{
		str[j] = s2[k];
		j++;
		k++;
	}
	str[j] = '\0';
	return (str);
}

void	signal_direction(int sig)
{
	if (sig == SIGUSR2)
		ft_putstr_fd("Signal Received\n", 1);
}

void	signal_push(int pid, char *str)
{
	int	i;
	int	j;

	j = 0;
	while (j <= (int)ft_strlen(str))
	{
		i = 7;
		while (i >= 0)
		{
			if (str[j] >> i & 1)
				kill(pid, SIGUSR1);
			else
				kill(pid, SIGUSR2);
			usleep(100);
			i--;
		}
		j++;
	}
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;

	if (argc == 3)
	{
		pid = ft_atoi(argv[1]);
		signal(SIGUSR2, signal_direction);
		message = ft_strjoin(argv[2], "\n");
		signal_push(pid, message);
		free(message);
	}
	return (0);
}
