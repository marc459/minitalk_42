/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcos <marcos@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:19 by msantos-          #+#    #+#             */
/*   Updated: 2021/06/18 14:23:57 by marcos           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/minitalk.h"

void mysignalhandler(int sig)
{
	ft_printf("Signal number is %d \n",sig);
}

int		main(void)
{
	//printf("SERVER\n");
	signal(SIGIO, &mysignalhandler);
	while(1)
	{
		ft_printf("Server is running\n");
		sleep(2);
	}
	//printf("pid %d\n",pid);
	return (0);
}