//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define BUFFER_SIZE 256

int main() {
    int fd;
    char buffer[BUFFER_SIZE];
    char temp[BUFFER_SIZE];
    double idle_time, prev_idle_time, usage;

    fd = open("/proc/stat", O_RDONLY);

    if(fd < 0) {
        printf("Error opening file\n");
        return 1;
    }

    while(1) {
        lseek(fd, 0, SEEK_SET);
        read(fd, buffer, BUFFER_SIZE);
        sscanf(buffer, "%s %lf %*lf %*lf %lf", temp, &idle_time, &usage);

        if(!strncmp(temp, "cpu", 3)) {
            if(prev_idle_time != 0) {
                usage = (usage + idle_time - prev_idle_time) / (usage + idle_time) * 100;
                printf("CPU usage: %.2lf%%\n", usage);
            }
            prev_idle_time = idle_time;
        }
        sleep(1);
    }

    close(fd);

    return 0;
}