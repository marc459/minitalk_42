/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:19 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/01 21:50:53 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

void mysignalhandler(int sig)
{
	ft_printf("Signal number is %d \n",sig);
}

int		main(void)
{
	
	ft_printf("SERVER PID: %d\n",getpid());
	while(1)
	{
		signal(SIGIO, &mysignalhandler);
		sleep(1);
	}
	return (0);
}