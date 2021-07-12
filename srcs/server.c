/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:19 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/13 01:01:53 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

int ft_bintodec(long long n) {
    int dec = 0, i = 0, rem;
	int poww;
	poww = 1;
    while (n != 0) {
        rem = n % 10;
        n /= 10;
        dec += rem * poww;
		poww = 2 * poww;
        ++i;
    }
    return dec;
}
void mysignalhandler(int sig)
{
	ft_printf("CLIENTE: (Numero Señal) -> %d \n",sig);
}

int		main(void)
{
	printf("%d\n",ft_bintodec(1001001));
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
