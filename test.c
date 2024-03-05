// #include <stdio.h>
// #include <signal.h>
// #include <stdlib.h>

// // Signal handler function
// void sigint_handler(int sig) {
//     printf("Received SIGINT. Exiting...\n");
//     exit(EXIT_SUCCESS);
// }

// int main() {

//     signal(SIGINT, sigint_handler);
//     printf("Running. Press Ctrl+C to exit.\n");
//     while (1) {
//         // Do some work
//     }

//     return 0;
// }

// #######################################################

// #include <stdio.h>
// #include <stdlib.h>
// #include <signal.h>
// #include <unistd.h>

// // Signal handler function for SIGUSR1
// void sigusr1_handler(int sig) {
//     printf("Received SIGUSR1. Performing custom action...\n");
//     // Perform custom action here
// }

// int main() {
//     // Registering the signal handler for SIGUSR1
//     signal(SIGUSR1, sigusr1_handler);

//     printf("Running. PID: %d\n", getpid());
//     printf("Send SIGUSR1 signal to this process to trigger custom action.\n");

//     // A long-running loop to keep the program running
//     while (1) {
//         usleep(100); // Sleep for 1 second
//     }

//     return 0;
// }

// #######################################################

#include <signal.h>
#include <stdio.h>
#include <strings.h>

// Signal handler for SIGINT
void	sigint_handler(int signal)
{
	if (signal == SIGINT)
		printf("\nIntercepted SIGINT!\n");
}

void set_signal_action(void)
{
	// Declare the sigaction structure
	struct sigaction	act;

	// Set all of the structure's bits to 0 to avoid errors
	// relating to uninitialized variables...
	bzero(&act, sizeof(act));
	// Set the signal handler as the default action
	act.sa_handler = &sigint_handler;
	// Apply the action in the structure to the
	// SIGINT signal (ctrl-c)
	sigaction(SIGINT, &act, NULL);
}

int	main(void)
{
	// Change SIGINT's associated action
	set_signal_action();
	// Infinite loop to give us time to do ctrl-c
	// as much as we want!
	while(1)
		continue ;
	return (0);
}
