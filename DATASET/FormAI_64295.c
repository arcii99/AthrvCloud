//FormAI DATASET v1.0 Category: Temperature monitor ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

#define TEMP_MONITOR_PATH "/sys/class/thermal/thermal_zone0/temp"
#define MAX_BUFFER_SIZE 64
#define POLL_INTERVAL 5

static volatile sig_atomic_t terminate = 0;

static void signal_handler(int signum)
{
    if (signum == SIGINT || signum == SIGTERM)
        terminate = 1;
}

int main()
{
    int fd, len;
    char buffer[MAX_BUFFER_SIZE], *temperatures[2], *delim = "\n";
    double current_temp;

    // Register signal handler
    signal(SIGINT, signal_handler);
    signal(SIGTERM, signal_handler);

    // Open temperature file
    if ((fd = open(TEMP_MONITOR_PATH, O_RDONLY)) < 0)
    {
        perror("Failed to open temperature file: ");
        exit(EXIT_FAILURE);
    }

    // Keep polling temperature until program is terminated
    while (!terminate)
    {
        // Read temperature data into buffer
        len = read(fd, buffer, MAX_BUFFER_SIZE - 1);

        if (len == -1 && errno != EINTR)
        {
            perror("Failed to read temperature data: ");
            exit(EXIT_FAILURE);
        }

        if (len > 0)
        {
            // Null terminate the buffer
            buffer[len] = '\0';

            // Split data into separate temperatures
            temperatures[0] = strtok(buffer, delim);
            temperatures[1] = strtok(NULL, delim);

            // Extract the current temperature
            current_temp = strtod(temperatures[0], NULL) / 1000;

            // Print the current temperature
            printf("Current temperature: %.2f°C\n", current_temp);
        }

        // Wait for specified time interval before polling again
        sleep(POLL_INTERVAL);
    }

    // Clean up and exit
    close(fd);
    printf("Temperature monitor program terminated.\n");
    exit(EXIT_SUCCESS);
}