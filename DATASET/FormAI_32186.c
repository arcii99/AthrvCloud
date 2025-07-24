//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: sophisticated
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

#define BUFF_SIZE 512
#define CPU_USAGE_FILE "/proc/stat"

int main(int argc, char *argv[]) {
    int fd;
    char buff[BUFF_SIZE];
    long total_idle_time_1, total_idle_time_2, total_time_1, total_time_2;
    float cpu_usage;
    char cpu[4];

    if ((fd = open(CPU_USAGE_FILE, O_RDONLY)) == -1) {
        fprintf(stderr, "Error: Failed to open %s\n", CPU_USAGE_FILE);
        exit(1);
    }

    if (read(fd, buff, BUFF_SIZE) == -1) {
        fprintf(stderr, "Error: Failed to read %s\n", CPU_USAGE_FILE);
        close(fd);
        exit(1);
    }

    sscanf(buff, "%3s %ld %*d %*d %*d %*d %*d %*d %*d %*d", cpu, &total_idle_time_1);
    total_time_1 = strtol(buff+5, NULL, 10) + strtol(buff+8, NULL, 10) + strtol(buff+11, NULL, 10);

    while (1) {
        close(fd);

        if ((fd = open(CPU_USAGE_FILE, O_RDONLY)) == -1) {
            fprintf(stderr, "Error: Failed to open %s\n", CPU_USAGE_FILE);
            exit(1);
        }

        if (read(fd, buff, BUFF_SIZE) == -1) {
            fprintf(stderr, "Error: Failed to read %s\n", CPU_USAGE_FILE);
            close(fd);
            exit(1);
        }

        sscanf(buff, "%3s %ld %*d %*d %*d %*d %*d %*d %*d %*d", cpu, &total_idle_time_2);
        total_time_2 = strtol(buff+5, NULL, 10) + strtol(buff+8, NULL, 10) + strtol(buff+11, NULL, 10);

        cpu_usage = 1.0 - ((total_idle_time_2 - total_idle_time_1) * 1.0) / (total_time_2 - total_time_1);

        printf("CPU Usage: %.2f%%\n", cpu_usage*100);

        total_time_1 = total_time_2;
        total_idle_time_1 = total_idle_time_2;

        sleep(1);
    }

    close(fd);

    return 0;
}