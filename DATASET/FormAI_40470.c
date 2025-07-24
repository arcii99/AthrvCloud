//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main() {
    int fd;
    char buf[1024];
    int cpu_usage;
    int cpu_usage_prev;
    fd = open("/proc/stat", O_RDONLY);
    if (fd == -1) {
        perror("open");
        exit(EXIT_FAILURE);
    }
    while (1) {
        if (read(fd, buf, sizeof(buf)) == -1) {
            perror("read");
            exit(EXIT_FAILURE);
        }
        cpu_usage_prev = cpu_usage;
        sscanf(buf, "cpu %d", &cpu_usage);
        printf("CPU usage: %d %%\n", cpu_usage - cpu_usage_prev);
        lseek(fd, 0, SEEK_SET);
        usleep(1000000);
    }
    return 0;
}