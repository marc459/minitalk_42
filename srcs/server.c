/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: msantos- <msantos-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:49:19 by msantos-          #+#    #+#             */
/*   Updated: 2021/07/06 20:13:28 by msantos-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <minitalk.h>

/*void mysignalhandler(int sig)
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
}*/

# define BUFFSIZE 1024

# ifndef TRUE
#  define TRUE 1
# endif

# ifndef FALSE
#  define FALSE 0
# endif
typedef struct	s_stack
{
	char		message[BUFFSIZE];
	int			top_bit;
	int			top_byte;
	_Bool		all_receive;
	_Bool		buff_overflow;
}				t_stack;

t_stack			g_to_print = {{0}, 1 << 6, 0, FALSE, FALSE};

void		print_pid(void)
{
	char	*tmp_pid;

	tmp_pid = ft_itoa(getpid());
	write(1, "pid: ", 5);
	write(1, tmp_pid, ft_strlen(tmp_pid));
	write(1, "\n", 1);
	free(tmp_pid);
}

void		activebit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	(void)info;
	if (!g_to_print.top_bit)
	{
		g_to_print.top_bit = 1 << 6;
		++(g_to_print.top_byte);
	}
	g_to_print.message[g_to_print.top_byte] += g_to_print.top_bit;
	g_to_print.top_bit >>= 1;
	if (g_to_print.top_byte == BUFFSIZE - 2 && !g_to_print.top_bit)
		g_to_print.buff_overflow = TRUE;
}

void		nullbit(int sig, siginfo_t *info, void *context)
{
	(void)sig;
	(void)context;
	if (!g_to_print.top_bit)
	{
		g_to_print.top_bit = 1 << 6;
		++(g_to_print.top_byte);
	}
	g_to_print.top_bit >>= 1;
	if (g_to_print.top_byte == BUFFSIZE - 2 && !g_to_print.top_bit)
		g_to_print.buff_overflow = TRUE;
	else if (!g_to_print.message[g_to_print.top_byte]
		&& !g_to_print.top_bit)
	{
		g_to_print.all_receive = TRUE;
		kill(info->si_pid, SIGUSR1);
	}
}

_Bool		main_handler(void)
{
	while (1)
	{
		pause();
		if (g_to_print.all_receive || g_to_print.buff_overflow)
		{
			write(1, g_to_print.message, ft_strlen(g_to_print.message));
			ft_bzero(g_to_print.message, BUFFSIZE);
			g_to_print.top_byte = 0;
			g_to_print.top_bit = 1 << 6;
			if (g_to_print.all_receive)
				write(1, "\n", 1);
			g_to_print.all_receive = FALSE;
			g_to_print.buff_overflow = FALSE;
		}
	}
	return (TRUE);
}

int			main(void)
{
	struct sigaction active_act;
	struct sigaction null_act;

	active_act.sa_sigaction = activebit;
	null_act.sa_sigaction = nullbit;
	active_act.sa_flags = SA_SIGINFO;
	null_act.sa_flags = SA_SIGINFO;
	if (sigaction(SIGUSR1, &active_act, NULL) != 0)
		printerr("signal error\n");
	if (sigaction(SIGUSR2, &null_act, NULL) != 0)
		printerr("signal error\n");
	print_pid();
	ft_bzero(g_to_print.message, BUFFSIZE);
	main_handler();
}