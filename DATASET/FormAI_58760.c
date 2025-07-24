//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <fcntl.h>
#include <errno.h>

#define BUFFER_SIZE 1024

int main(int argc, char *argv[]) {

    char buffer[BUFFER_SIZE];
    char cpu[BUFFER_SIZE];
    int cpu_usage;
    long long int idle, prev_idle;
    long long int user, prev_user;
    long long int nice, prev_nice;
    long long int system, prev_system;
    long long int total, prev_total;

    prev_idle = prev_user = prev_nice = prev_system = prev_total = 0;

    while (1) {

        // Open the /proc/stat file to get the CPU usage
        int fd = open("/proc/stat", O_RDONLY);
        if (fd < 0) {
            perror("Failed to open /proc/stat");
            exit(1);
        }

        // Read the contents of /proc/stat into the buffer
        int bytes_read = read(fd, buffer, BUFFER_SIZE);
        if (bytes_read < 0) {
            perror("Failed to read /proc/stat");
            exit(1);
        }

        // Close the /proc/stat file
        close(fd);

        // Parse the CPU stats from the buffer
        sscanf(buffer, "%s %lld %lld %lld %lld %lld",
                cpu, &user, &nice, &system, &idle, &total);

        // Calculate the CPU usage as a percentage
        if (prev_total != 0) {
            cpu_usage = (int)((float)(total - prev_total - (idle - prev_idle)) / (total - prev_total) * 100.0);
        }

        // Print the CPU usage to the console
        printf("CPU usage: %d%%\n", cpu_usage);

        // Update the previous stats
        prev_idle = idle;
        prev_user = user;
        prev_nice = nice;
        prev_system = system;
        prev_total = total;

        // Wait for a second before checking the CPU usage again
        sleep(1);
    }

    return 0;
}