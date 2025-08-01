/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fmarkul <fmarkul@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 19:00:07 by fmarkul           #+#    #+#             */
/*   Updated: 2025/06/26 14:04:45 by fmarkul          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <unistd.h>

void	receive_signal(int sig)
{
	static int				bit;
	static unsigned char	letter;

	if (sig == SIGUSR2)
		letter |= (1 << (7 - bit));
	bit++;
	if (bit == 8)
	{
		if (letter == '\0')
			write(1, "\n", 1);
		else
			write(1, &letter, 1);
		letter = 0;
		bit = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("The process ID is %d\n", pid);
	signal(SIGUSR1, receive_signal);
	signal(SIGUSR2, receive_signal);
	while (1)
			;
}
