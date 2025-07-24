//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUF_SIZE 128

int main() {
    int cpu_fd, buf_fd;
    float user, nice, sys, idle;
    char buf[BUF_SIZE];
    
    while(1) {
        cpu_fd = open("/proc/stat", O_RDONLY);
        if(cpu_fd == -1) {
            perror("Error opening /proc/stat file\n");
            exit(EXIT_FAILURE);
        }

        if(read(cpu_fd, buf, BUF_SIZE) == -1) {
            perror("Error reading /proc/stat file\n");
            exit(EXIT_FAILURE);
        }

        close(cpu_fd);

        // Parse the user, nice, system, and idle times
        char line[BUF_SIZE];
        char* token;
        float total_time = 0;
        float idle_time = 0;

        sscanf(buf, "%s %f %f %f %f", line, &user, &nice, &sys, &idle);
        total_time = user + nice + sys + idle;
        idle_time = idle;
        
        // Wait for one second
        sleep(1);

        // Read the buffer and get CPU usage
        buf_fd = open("/proc/stat", O_RDONLY);
        if(buf_fd == -1) {
            perror("Error opening /proc/stat file\n");
            exit(EXIT_FAILURE);
        }

        if(read(buf_fd, buf, BUF_SIZE) == -1) {
            perror("Error reading /proc/stat file\n");
            exit(EXIT_FAILURE);
        }

        close(buf_fd);

        // Parse the user, nice, system, and idle times again
        float new_user = 0, new_nice = 0, new_sys = 0, new_idle = 0;
        sscanf(buf, "%s %f %f %f %f", line, &new_user, &new_nice, &new_sys, &new_idle);

        // Calculate CPU usage percentage
        float usage = ((new_user + new_nice + new_sys) - (user + nice + sys)) / ((new_user + new_nice + new_sys + new_idle) - (user + nice + sys + idle)) * 100;

        // Print CPU usage
        printf("CPU Usage: %.2f%%\n", usage);
    }

    return 0;
}