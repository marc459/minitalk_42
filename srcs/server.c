/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:19 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/12 18:41:06 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void mysignalhandler(int sig)
{
	ft_printf("CLIENTE: (Numero Señal) -> %d \n",sig);
}

int		main(void)
{
	signal(SIGUSR1, &mysignalhandler);
	signal(SIGUSR2, &mysignalhandler);
	//sig_set_handler (SIGUSR1, &signal_handler);
	ft_printf("SERVER PID: %d\n",getpid());
	while(1)
	{
		usleep(2000000);
	}
	return (0);
}
