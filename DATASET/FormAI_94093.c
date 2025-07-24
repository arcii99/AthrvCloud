//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <time.h>

#define CPU_USAGE_FILE "/proc/stat"
#define BUFFER_SIZE 1024

int main() {
    char buffer[BUFFER_SIZE];
    int fd, read_bytes, user_time1, nice_time1, system_time1, idle_time1, total_time1;
    int user_time2, nice_time2, system_time2, idle_time2, total_time2, cpu_usage;
    float time_difference;

    fd = open(CPU_USAGE_FILE, O_RDONLY);
    if (fd == -1) {
        perror("Error opening CPU usage file");
        exit(EXIT_FAILURE);
    }

    // Get initial CPU usage stats
    read_bytes = read(fd, buffer, BUFFER_SIZE);
    buffer[read_bytes] = '\0';
    sscanf(buffer, "cpu %d %d %d %d", &user_time1, &nice_time1, &system_time1, &idle_time1);
    total_time1 = user_time1 + nice_time1 + system_time1 + idle_time1;

    // Loop to continually monitor CPU usage
    while (1) {
        // Wait for 0.5 seconds to get another CPU usage reading
        sleep(0.5);

        // Get latest CPU usage stats
        lseek(fd, 0, SEEK_SET);
        read_bytes = read(fd, buffer, BUFFER_SIZE);
        buffer[read_bytes] = '\0';
        sscanf(buffer, "cpu %d %d %d %d", &user_time2, &nice_time2, &system_time2, &idle_time2);
        total_time2 = user_time2 + nice_time2 + system_time2 + idle_time2;

        // Calculate CPU usage percentage
        time_difference = ((float) (total_time2 - total_time1)) / CLOCKS_PER_SEC;
        cpu_usage = (int) ((float) ((total_time2 - idle_time2) - (total_time1 - idle_time1)) / (total_time2 - total_time1) * 100.0);

        // Print CPU usage percentage and time difference between readings
        printf("CPU usage: %d%%\tTime difference: %f seconds\n", cpu_usage, time_difference);

        // Update initial CPU usage stats for next loop iteration
        user_time1 = user_time2;
        nice_time1 = nice_time2;
        system_time1 = system_time2;
        idle_time1 = idle_time2;
        total_time1 = total_time2;
    }

    return 0;
}