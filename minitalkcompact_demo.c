
#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <stdlib.h>

void signal_handler ( int sig, siginfo_t *siginfo, void *context );
void signal_gen ( void );
void sig_set_handler ( int signo, void *handler );
void sig_send_msg ( pid_t id, int signo, char *msg );
void sig_send_val ( pid_t id, int signo, int val );

int main ( void )
{
	sig_set_handler (SIGUSR1, &signal_handler);

	if ( !fork () )
	{
		signal_gen ();
		_exit ( 0 );
	}

	while (1)
		usleep ( 1000 );

	return 0;
}

//SERVER
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

//CLIENT
void signal_gen ( void )
{
	char *c = "hello_world";

	while ( 1 )
	{
		sig_send_msg (getppid (), SIGUSR1, c);
		sleep ( 2 );
	}
}

void sig_send_msg ( pid_t id, int signo, char *msg )
{
	union sigval *sigdata;

	sigdata = malloc ( sizeof ( union sigval ) );
	sigdata->sival_ptr = msg;

	sigqueue(id, signo, *sigdata);
	free ( sigdata );
}






void sig_send_val ( pid_t id, int signo, int val )
{
	union sigval *sigdata;

	sigdata = malloc ( sizeof ( union sigval ) );
	sigdata -> sival_int = val;

	sigqueue ( id, signo, *sigdata );
	free ( sigdata );
}