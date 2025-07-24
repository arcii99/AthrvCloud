//FormAI DATASET v1.0 Category: System administration ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

// Function to handle signals
void handleSignal(int sig_number)
{
    printf("Signal %d received \n", sig_number);
}

int main()
{
    // Register signal handler
    signal(SIGINT, handleSignal);

    // Create child process
    pid_t pid = fork();

    // Error handling
    if (pid < 0)
    {
        printf("Fork failed \n");
        exit(1);
    }

    // Child process code
    else if (pid == 0)
    {
        printf("Child process running \n");

        // Wait for 10 seconds
        sleep(10);

        printf("Child process completed \n");
        exit(0);
    }

    // Parent process code
    else
    {
        printf("Parent process running \n");

        // Wait for signal to terminate child process
        while (1)
        {
            sleep(1);
        }
    }

    return 0;
}