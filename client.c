/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarkul <fmarkul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:00:13 by fmarkul           #+#    #+#             */
/*   Updated: 2025/06/26 14:02:59 by fmarkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <unistd.h>

void	send_signal(int pid, unsigned char character)
{
	int				i;
	unsigned char	temp;

	temp = character;
	i = 7;
	while (i >= 0)
	{
		temp = (character >> i) & 1;
		if (temp == 0)
			kill(pid, SIGUSR1);
		else
			kill(pid, SIGUSR2);
		usleep(200);
		i--;
	}
}

int	main(int ac, char *av[])
{
	int	i;
	int	pid;

	if (ac == 3)
	{
		pid = ft_atoi(av[1]);
		i = 0;
		while (av[2][i])
		{
			send_signal(ft_atoi(av[1]), av[2][i]);
			i++;
		}
		send_signal(pid, '\0');
	}
	return (0);
}
