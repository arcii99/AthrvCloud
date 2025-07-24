//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() {
    int fd;
    char buf[1024];
    double total_time, idle_time, usage;
    int user, nice, system, idle, iowait, irq, softirq;

    fd = open("/proc/stat", O_RDONLY);
    if (fd < 0) {
        printf("Error: Cannot open /proc/stat\n");
        return 1;
    }

    // Read the first line of /proc/stat, which contains CPU usage information
    if (read(fd, buf, sizeof(buf)) < 0) {
        printf("Error: Cannot read /proc/stat\n");
        close(fd);
        return 1;
    }

    sscanf(buf, "cpu %d %d %d %d %d %d %d", &user, &nice, &system, &idle, &iowait, &irq, &softirq);

    // Calculate total CPU time and idle CPU time
    total_time = user + nice + system + idle + iowait + irq + softirq;
    idle_time = idle + iowait;

    // Calculate CPU usage percentage
    usage = 100.0 * (1 - (idle_time / total_time));

    printf("CPU Usage: %.2f%%\n", usage);

    close(fd);
    return 0;
}