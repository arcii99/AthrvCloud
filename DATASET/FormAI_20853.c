//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/* Function to get CPU usage */
float get_cpu_usage() {
    /* Open the system's CPU usage file in read-only mode */
    int fd = open("/proc/stat", O_RDONLY);
    if (fd == -1) {
        printf("Error: could not open CPU usage file\n");
        exit(1);
    }

    /* Read the CPU usage data from the file */
    char buff[1024];
    read(fd, buff, sizeof(buff));
    close(fd);

    /* Parse the data to get the CPU usage percent */
    char* line = strtok(buff, "\n");
    int user, nice, sys, idle, iowait, irq, softirq, steal, guest, guest_nice;
    sscanf(line, "cpu %d %d %d %d %d %d %d %d %d %d", &user, &nice, &sys, &idle, &iowait, &irq, &softirq, &steal, &guest, &guest_nice);
    int total_cpu_time = user + nice + sys + idle + iowait + irq + softirq + steal;
    int idle_cpu_time = idle + iowait;
    float cpu_usage_percent = 100.0 - ((float)(idle_cpu_time * 100) / total_cpu_time);

    return cpu_usage_percent;
}

/* Main function */
int main() {
    while (1) {
        float cpu_usage_percent = get_cpu_usage();
        printf("Current CPU usage: %.2f%%\n", cpu_usage_percent); /* Display the CPU usage percent */
        sleep(1); /* Wait for 1 second */
    }

    return 0;
}