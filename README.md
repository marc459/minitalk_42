# minitalk_42
### COMPILE && EXECUTING MINITALK GUIDE ###

make

./server	//It will create a running proccess that lisents for client messages

./client [serverpid] [message]	//Open a new terminal to run this program, it will send a personalized message to the running server

### COMMAND CHEAT SHEET ###

ps -a		// Show active process and their pid
kill -l		// List signal names
killall [program] // Stop all proccess that are called [program]
kill -s STOP [programpid] // Sends STOP signal to the program with [programpid]

## MINITALK EXPLANATION ##
How to sent data througth signals. Easy. We need to send character by character and a character would be defined
by a set of signals USR1 (1) or USR2 (0) that will create a number in binary. for example: 1100001 -> 97 -> a.

This data will be received by a server throught a client.

h

1101000 1
1000000

1101000 1
 100000

1101000 0
  10000

1101000 1
   1000

1101000 0
    100

1101000 0
     10

1101000 0
      1