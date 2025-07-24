//FormAI DATASET v1.0 Category: Dice Roller ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#include <unistd.h>
#include <fcntl.h>

#define BUFFER_SIZE 1024

// Define minimum and maximum die values
#define MIN_DIE_VALUE 1
#define MAX_DIE_VALUE 6

// Define variables for asynchronous input reading
static char buffer[BUFFER_SIZE];
static char *buffer_end = buffer;
static bool reading_input = false;

// Define file descriptor for asynchronous input reading
static int input_fd;

// Asynchronous input reading function
void read_input() {
    ssize_t bytes_read = read(input_fd, buffer_end, BUFFER_SIZE - (buffer_end - buffer));
    buffer_end += bytes_read;
    if (bytes_read == 0 || buffer_end - buffer == BUFFER_SIZE) {
        *buffer_end = '\0';
        reading_input = false;
    }
}

// Random number generator function
int roll_dice() {
    return (rand() % (MAX_DIE_VALUE - MIN_DIE_VALUE + 1)) + MIN_DIE_VALUE;
}

int main() {
    // Seed the random number generator
    srand(time(NULL));

    // Open stdin non-blocking for asynchronous input reading
    input_fd = fcntl(STDIN_FILENO, F_SETFL, O_NONBLOCK);

    // Print welcome message
    printf("Welcome to Dice Roller! Type 'roll' to roll the dice or 'exit' to quit.\n");

    // Main loop
    while (true) {
        // Check if there is input available
        if (!reading_input) {
            fd_set fds;
            FD_ZERO(&fds);
            FD_SET(input_fd, &fds);
            struct timeval timeout = {0, 0};
            int result = select(input_fd + 1, &fds, NULL, NULL, &timeout);

            if (result == -1) {
                perror("select");
                return 1;
            }
            if (result == 1) {
                reading_input = true;
                read_input();
            }
        }

        // Parse input and roll the dice if 'roll' is typed
        char *command_end = strstr(buffer, "\n");
        if (command_end != NULL) {
            *command_end = '\0';
            if (strcmp(buffer, "roll") == 0) {
                int roll = roll_dice();
                printf("You have rolled a %d!\n", roll);
            } else if (strcmp(buffer, "exit") == 0) {
                printf("Goodbye!\n");
                return 0;
            } else {
                printf("Unknown command: %s\n", buffer);
            }
            buffer_end = buffer;
            reading_input = false;
        }

        // Wait for a short time to avoid high CPU usage in the loop
        usleep(100);
    }
}