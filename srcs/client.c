/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:15 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/02 22:46:40 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void sig_send_msg ( pid_t id, int signo, char *msg )
{
	union sigval *sigdata;

	sigdata = malloc ( sizeof ( union sigval ) );
	sigdata->sival_ptr = msg;

	//sigqueue(id, signo, *sigdata);
	//kill(id, SIGUSR1);
	free ( sigdata );
}

int		main(int argc, char **argv)
{
	if(argc != 3)
		printerr("Usage: ./client [server-pid] [message]");
	
	//sig_send_msg (atoi(argv[1]), SIGUSR1, "mensaje");
	kill(atoi(argv[1]), SIGUSR1);

	return (0);
}


