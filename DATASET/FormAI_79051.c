//FormAI DATASET v1.0 Category: Temperature monitor ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

// Define the maximum size of the temperature data buffer
#define BUFFER_SIZE 1024

// Define the maximum temperature threshold
#define MAX_TEMPERATURE 100

int main()
{
    // Initialize the temperature data buffer and other variables
    char temperature_data[BUFFER_SIZE];
    int temperature_value = 0;

    // Set up the IPC mechanism (using pipes in this case)
    int temperature_pipe[2];
    if (pipe(temperature_pipe) == -1) {
        perror("Error creating temperature pipe");
        exit(EXIT_FAILURE);
    }

    // Fork the process to create a distributed system
    pid_t pid = fork();

    if (pid == -1) { // Error occurred when forking process
        perror("Error creating child process");
        exit(EXIT_FAILURE);
    }
    else if (pid == 0) { // Child process (temperature sensor)
        close(temperature_pipe[0]); // Close the read-end of the pipe since we don't need it

        // Continuously generate random temperature values and write them to the pipe
        while (1) {
            temperature_value = rand() % (MAX_TEMPERATURE + 1);
            sprintf(temperature_data, "%d", temperature_value);
            write(temperature_pipe[1], temperature_data, strlen(temperature_data));
            sleep(1);
        }
    }
    else { // Parent process (temperature monitor)
        close(temperature_pipe[1]); // Close the write-end of the pipe since we don't need it

        // Continuously read the temperature values from the pipe and print them
        while (1) {
            read(temperature_pipe[0], temperature_data, BUFFER_SIZE);
            temperature_value = atoi(temperature_data);
            printf("Temperature value: %d\n", temperature_value);
            sleep(1);
        }
    }

    return 0;
}