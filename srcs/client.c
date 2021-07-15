/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:15 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/15 16:30:11 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void	send_char(int pid, unsigned char byte)
{
	uint8_t		counter;

	counter = 1 << 6; //1 * Math.pow(2,6)
	while (counter)
	{
		if (byte & counter)
		{
			printf("1 ");
			if (kill(pid, SIGUSR1) == -1)
				printerr("bad pid\n");
		}
		else
		{
			printf("0 ");
			if (kill(pid, SIGUSR2) == -1)
				printerr("bad pid\n");
		}
		counter >>= 1; // counter / Math.pow(2,1)
		usleep(600);
	}
	printf("\n");
}

int		main(int argc, char **argv)
{
	int i;

	i = 0;
	if(argc != 3)
		printerr("Usage: ./client [server-pid] [message]");

	if(argv[2][i])
	{
		send_char(ft_atoi(argv[1]),argv[2][i]);
		i++;
	}
		

	return (0);
}
