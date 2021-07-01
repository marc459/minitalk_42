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
