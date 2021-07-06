/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:15 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/06 20:44:32 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

/*void	send_char(int pid, unsigned char byte)
{
	uint8_t		counter;

	counter = 1 << 6; //1 * Math.pow(2,6)
	
	while (counter)
	{
		printf("char -> %d, %d\n",counter, byte);
		if (byte & counter)
		{
			printf(" SIGUSR1 ");
			if (kill(pid, SIGUSR1) == -1)
				printerr("bad pid\n");
		}
		else
		{
			printf(" SIGUSR-2 ");
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

	//sig_send_msg (atoi(argv[1]), SIGUSR1, "mensaje");
	//kill(atoi(argv[1]), SIGUSR1);
	if(argv[2][i])
	{
		send_char(ft_atoi(argv[1]),argv[2][i]);
		i++;
	}
		

	return (0);
}*/


void	usage(void)
{
	write(1, "usage: ./client [server-pid] [message]\n", 39);
	exit(0);
}

void	send_char(int pid, unsigned char byte)
{
	uint8_t		counter;

	counter = 1 << 6;
	while (counter)
	{
		printf("char -> %d, %d ",counter, byte);
		if (byte & counter)
		{
			printf(" SIGUSR1 ");
			if (kill(pid, SIGUSR1) == -1)
				printerr("bad pid\n");
		}
		else
		{
			printf(" SIGUSR-2 ");
			if (kill(pid, SIGUSR2) == -1)
				printerr("bad pid\n");
		}
		counter >>= 1;
		usleep(600);
	}
	printf("\n");
}

void	main_handler(char *str_pid, char *message)
{
	int			pid;

	pid = ft_atoi(str_pid);
	while (*message)
	{
		send_char(pid, *message);
		++message;
	}
	send_char(pid, *message);
}

void	success(int sig)
{
	(void)sig;
	write(1, "Data has been received.\n", 25);
}

int		main(int argc, char **argv)
{
	if (argc != 3)
		usage();
	signal(SIGUSR1, success);
	main_handler(argv[1], argv[2]);
	return (0);
}

