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

#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler function for SIGUSR1
void sigusr1_handler(int sig) {
    printf("Received SIGUSR1. Performing custom action...\n");
    // Perform custom action here
}

int main() {
    // Registering the signal handler for SIGUSR1
    signal(SIGUSR1, sigusr1_handler);

    printf("Running. PID: %d\n", getpid());
    printf("Running. PID: %d\n", SIGUSR1);
    printf("Running. PID: %d\n", SIGUSR2);
    printf("Send SIGUSR1 signal to this process to trigger custom action.\n");

    // A long-running loop to keep the program running
    while (1) {
        usleep(100); // Sleep for 1 second
    }

    return 0;
}

