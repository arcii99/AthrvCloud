//FormAI DATASET v1.0 Category: File handling ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>
#include <stdbool.h>

#define BUFSIZE 1024

// Global Variables
bool is_running = true;

// Signal Handler
void sigint_handler(int sig)
{
    printf("\nCaught signal %d, exiting...\n", sig);
    is_running = false;
}

// Main Function
int main(int argc, char *argv[])
{
    // Register Signal Handler
    if (signal(SIGINT, sigint_handler) == SIG_ERR)
        perror("signal");

    int fd, n;
    char buf[BUFSIZE];

    if (argc < 2)
    {
        printf("Usage: %s filename\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    // Open File
    if ((fd = open(argv[1], O_RDONLY)) == -1)
    {
        perror("open");
        exit(EXIT_FAILURE);
    }

    // Set Non-Blocking Mode
    if (fcntl(fd, F_SETFL, O_NONBLOCK) == -1)
    {
        perror("fcntl");
        exit(EXIT_FAILURE);
    }

    // Asynchronous Read Loop
    while (is_running)
    {
        // Read Data
        n = read(fd, buf, BUFSIZE);

        // Check for EOF or Error
        if (n == 0)
        {
            printf("\nEnd of file reached.\n");
            break;
        }
        else if (n == -1 && errno != EAGAIN)
        {
            perror("read");
            break;
        }

        // Print Data
        if (n > 0)
        {
            printf("%.*s", n, buf);
            memset(buf, 0, BUFSIZE);
        }

        // Sleep for 1 Second
        sleep(1);
    }

    // Close File
    if (close(fd) == -1)
    {
        perror("close");
        exit(EXIT_FAILURE);
    }

    return 0;
}