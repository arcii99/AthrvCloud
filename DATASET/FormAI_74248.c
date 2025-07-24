//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define MAX_BUFFER 256
#define PROC_CPU_INFO "/proc/stat"

int main(int argc, char *argv[]) {

    unsigned long long total_time_elapsed;
    unsigned long long prev_total_time_elapsed = 0;
    unsigned long long idle_time_elapsed;
    unsigned long long prev_idle_time_elapsed = 0;
    int cpu_usage = 0;
    int prev_cpu_usage = 0;
    int cpu_number = 0;

    char buffer[MAX_BUFFER];
    int fd = open(PROC_CPU_INFO, O_RDONLY);
    if (fd == -1) {
        perror("Open failed");
        exit(EXIT_FAILURE);
    }

    // Read CPU usage values from /proc/stat
    ssize_t num_bytes_read = read(fd, buffer, MAX_BUFFER-1);
    if (num_bytes_read == -1) {
        perror("Read failed");
        exit(EXIT_FAILURE);
    }
    buffer[num_bytes_read] = '\0';

    // Parse total and idle time elapsed from first line
    char *line = strtok(buffer, "\n");
    sscanf(line, "cpu %llu %*llu %llu %*llu %*llu %*llu %*llu %*llu %*llu %*llu",
           &prev_total_time_elapsed, &prev_idle_time_elapsed);

    // Get number of CPUs
    line = strtok(NULL, "\n");
    while (line != NULL && strncmp(line, "cpu", 3) == 0) {
        cpu_number++;
        line = strtok(NULL, "\n");
    }

    close(fd);
    
    while (1) {
        sleep(1);
        fd = open(PROC_CPU_INFO, O_RDONLY);
        if (fd == -1) {
            perror("Open failed");
            exit(EXIT_FAILURE);
        }

        // Read CPU usage values from /proc/stat
        num_bytes_read = read(fd, buffer, MAX_BUFFER-1);
        if (num_bytes_read == -1) {
            perror("Read failed");
            exit(EXIT_FAILURE);
        }
        buffer[num_bytes_read] = '\0';

        // Parse total and idle time elapsed from first line
        line = strtok(buffer, "\n");
        sscanf(line, "cpu %llu %*llu %llu %*llu %*llu %*llu %*llu %*llu %*llu %*llu",
               &total_time_elapsed, &idle_time_elapsed);

        close(fd);

        // Calculate CPU usage percentage
        cpu_usage = (int)(((total_time_elapsed - prev_total_time_elapsed) -
                            (idle_time_elapsed - prev_idle_time_elapsed)) * 100 /
                          (total_time_elapsed - prev_total_time_elapsed) /
                          cpu_number);
        if (prev_cpu_usage != cpu_usage) {
            printf("CPU usage: %d%%\n", cpu_usage);
            prev_cpu_usage = cpu_usage;
        }
        prev_total_time_elapsed = total_time_elapsed;
        prev_idle_time_elapsed = idle_time_elapsed;
    }
    
    return 0;
}