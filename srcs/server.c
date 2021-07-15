/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:19 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/15 20:37:41 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>
#include <zconf.h>

#	define BUFFSIZE 1024
int	g_o;

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif
typedef struct s_talk
{
	char		message[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	_Bool		all_receive;
	_Bool		buff_overflow;
}				t_talk;

t_talk			g_to_print = {{0}, 1 << 6, 0, FALSE, FALSE};

void mysignalhandler(int sig)
{
	int i;
	
	i = 0;
	ft_printf("CLIENTE: (Numero Señal) -> %d \n",sig);
	if(sig == 30)
	{
		i = i * 10 + 1;
	}
	else if(sig == 31)
	{
		i = i * 10;
	}
	pow();
	printf("char = %d\n",i);
}

void handle_activebit(int sig, siginfo_t *info, void *context)
{
	int i;

	i = 0;
	ft_printf("CLIENTE: (Numero Señal) -> %d \n",sig);
	if(sig == 30)
	{
		i = i * 10 + 1;
	}
	else if(sig == 31)
	{
		i = i * 10;
	}
	printf("char = %d\n",i);
}

int		main(void)
{
	struct sigaction active_act;
	struct sigaction null_act;

	active_act.sa_sigaction = &handle_activebit;
	///null_act.sa_sigaction = &handle_activebit;
	active_act.sa_flags = SA_SIGINFO;
	//null_act.sa_flags = SA_SIGINFO;
	
	printf("%d\n",ft_bintodec(1001001));
	sigaction(SIGUSR1, &active_act, NULL);
	//sigaction(SIGUSR2, &null_act, NULL);
	ft_printf("SERVER PID: %d\n",getpid());
	while(1)
	{
		usleep(2000000);
	}
	return (0);
}
