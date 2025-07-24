//FormAI DATASET v1.0 Category: System administration ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <signal.h>

/* Define a signal handler to catch SIGINT */
void sigint_handler(int sig)
{
    printf("SIGINT received. Exiting...\n");
    exit(0);
}

int main()
{
    /* Install the signal handler for SIGINT */
    signal(SIGINT, sigint_handler);

    while (1) {
        printf("System administration example program running...\n");
        sleep(1);
    }

    return 0;
}