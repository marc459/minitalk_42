/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:19 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/02 22:33:37 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void sig_set_handler ( int signo, void *handler )
{
	struct sigaction *act;
	act = malloc ( sizeof ( struct sigaction ) );
	act -> sa_sigaction = handler;
	act -> sa_flags = SA_SIGINFO;

	sigaction ( signo, act, NULL );
}

void signal_handler ( int sig, siginfo_t *siginfo, void *context )
{
	printf ( "nrec signal with infon" );
	printf ( "nmessage = %sn", siginfo -> si_value );
}

void mysignalhandler(int sig, void *handler)
{
	ft_printf("CLIENTE: (señal) %d \n",sig);
}

int		main(void)
{
	//signal(SIGUSR1, &mysignalhandler);
	sig_set_handler (SIGUSR1, &signal_handler);
	ft_printf("SERVER PID: %d\n",getpid());
	while(1)
	{
		sleep(1);
	}
	return (0);
}