//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <fcntl.h>

// Function to get the current CPU usage
float getCpuUsage() {
    int fd;
    char buf[1024];
    fd = open("/proc/stat", O_RDONLY);
    if (fd < 0) {
        printf("Cannot open file\n");
        return -1.0;
    }
    read(fd, buf, sizeof(buf));
    close(fd);
    char *line = strtok(buf, "\n");
    while (line != NULL && strncmp(line, "cpu ", 4) != 0) {
        line = strtok(NULL, "\n");
    }
    if (line == NULL) {
        printf("Cannot read CPU usage\n");
        return -1.0;
    }
    line += 4;
    char *tok = strtok(line, " ");
    int user = atoi(tok);
    tok = strtok(NULL, " ");
    int nice = atoi(tok);
    tok = strtok(NULL, " ");
    int sys = atoi(tok);
    tok = strtok(NULL, " ");
    int idle = atoi(tok);
    tok = strtok(NULL, " ");
    int iowait = atoi(tok);
    int total = user + nice + sys + idle + iowait;
    return (total > 0) ? (float)(user + nice + sys) / total : 0.0;
}

int main() {
    float cpuUsage;
    while (1) {
        cpuUsage = getCpuUsage();
        printf("Current CPU usage: ");
        if (cpuUsage > 0.9)
            printf("99%%\n");
        else if (cpuUsage > 0.8)
            printf("90%%\n");
        else if (cpuUsage > 0.7)
            printf("80%%\n");
        else if (cpuUsage > 0.6)
            printf("70%%\n");
        else if (cpuUsage > 0.5)
            printf("60%%\n");
        else if (cpuUsage > 0.4)
            printf("50%%\n");
        else if (cpuUsage > 0.3)
            printf("40%%\n");
        else if (cpuUsage > 0.2)
            printf("30%%\n");
        else if (cpuUsage > 0.1)
            printf("20%%\n");
        else if (cpuUsage > 0.05)
            printf("10%%\n");
        else
            printf("1%%\n");
        usleep(500000); // Sleep for 500ms
    }
    return 0;
}