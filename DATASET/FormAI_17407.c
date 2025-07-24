//FormAI DATASET v1.0 Category: System administration ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>

#define MAX_SIZE 1024

// Function to read CPU temperature
void readCPUTemp() {
    char buffer[MAX_SIZE];
    int fd = open("/sys/class/thermal/thermal_zone0/temp", O_RDONLY);
    if (fd == -1) {
        printf("Error: Unable to read CPU temperature\n");
        return;
    }
    read(fd, buffer, MAX_SIZE);
    float temp = atoi(buffer) / 1000.0;
    printf("CPU Temperature: %.2f°C\n", temp);
    close(fd);
}

// Function to read system uptime
void readUptime() {
    char buffer[MAX_SIZE];
    int fd = open("/proc/uptime", O_RDONLY);
    if (fd == -1) {
        printf("Error: Unable to read system uptime\n");
        return;
    }
    read(fd, buffer, MAX_SIZE);
    float uptime = atof(strtok(buffer, " "));
    printf("System Uptime: %.2f minutes\n", uptime/60);
    close(fd);
}

// Function to read disk usage
void readDiskUsage() {
    char buffer[MAX_SIZE];
    int fd = open("/proc/mounts", O_RDONLY);
    if (fd == -1) {
        printf("Error: Unable to read disk usage\n");
        return;
    }
    read(fd, buffer, MAX_SIZE);
    int count = 0;
    char *token = strtok(buffer, "\n");
    while (token != NULL) {
        if (strstr(token, "/dev/") != NULL && strstr(token, "/sys") == NULL) {
            char path[MAX_SIZE];
            char *device = strtok(token, " ");
            char *mount = strtok(NULL, " ");
            sprintf(path, "%s/usage.txt", mount);
            int usage_fd = open(path, O_CREAT | O_WRONLY, 0666);
            if (usage_fd == -1) {
                printf("Error: Unable to create usage file for %s\n", mount);
                continue;
            }
            char usage_buffer[MAX_SIZE];
            sprintf(usage_buffer, "Device: %s\n", device);
            write(usage_fd, usage_buffer, strlen(usage_buffer));
            sprintf(usage_buffer, "Mount: %s\n", mount);
            write(usage_fd, usage_buffer, strlen(usage_buffer));
            sprintf(usage_buffer, "Usage: ");
            write(usage_fd, usage_buffer, strlen(usage_buffer));
            FILE *pipe = popen("df -h | grep \"$mount\" | awk '{print $5}'", "r");
            if (pipe == NULL) {
                printf("Error: Unable to read usage for %s\n", mount);
                close(usage_fd);
                continue;
            }
            char usage[MAX_SIZE];
            fgets(usage, MAX_SIZE, pipe);
            pclose(pipe);
            sprintf(usage_buffer, "%s", usage);
            strcat(usage_buffer, "\n\n");
            write(usage_fd, usage_buffer, strlen(usage_buffer));
            close(usage_fd);
            count++;
        }
        token = strtok(NULL, "\n");
    }
    printf("%d mount(s) analyzed for disk usage\n", count);
    close(fd);
}

// Main function
int main() {

    readCPUTemp();
    readUptime();
    readDiskUsage();

    return 0;
}