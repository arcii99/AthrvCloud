//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define BUFFER_SIZE 1024

int main()
{
    int fd, nbytes, total_bytes = 0, idle, prev_idle, total, prev_total, cpu_usage;
    double usage_percentage;
    char buffer[BUFFER_SIZE], cpu[BUFFER_SIZE];

    // Open the CPU stat file in the proc filesystem
    fd = open("/proc/stat", O_RDONLY);
    if(fd == -1)
    {
        perror("Failed to open /proc/stat");
        exit(1);
    }

    // Read the initial CPU usage data
    nbytes = read(fd, buffer, BUFFER_SIZE);
    buffer[nbytes - 1] = '\0';
    sscanf(buffer, "%s %d %d %d %d %d %d %d", cpu, &prev_total, &prev_idle, &total, &total, &total, &total, &total);

    // Close the file descriptor
    close(fd);

    // Loop to continuously monitor the CPU usage
    while(1)
    {
        // Sleep for 1 second before re-reading the CPU usage data
        sleep(1);

        // Open the CPU stat file in the proc filesystem
        fd = open("/proc/stat", O_RDONLY);
        if(fd == -1)
        {
            perror("Failed to open /proc/stat");
            exit(1);
        }

        // Read the CPU usage data
        nbytes = read(fd, buffer, BUFFER_SIZE);
        buffer[nbytes - 1] = '\0';
        sscanf(buffer, "%s %d %d %d %d %d %d %d", cpu, &total, &idle, &total, &total, &total, &total, &total);

        // Calculate the CPU usage percentage
        cpu_usage = total - prev_total;
        usage_percentage = ((double)(cpu_usage - (idle - prev_idle)) / cpu_usage) * 100;

        // Print the CPU usage percentage
        printf("CPU Usage: %0.2lf%%\n", usage_percentage);

        // Save the current CPU usage data as previous data for the next iteration of the loop
        prev_total = total;
        prev_idle = idle;

        // Close the file descriptor
        close(fd);
    }

    return 0;
}