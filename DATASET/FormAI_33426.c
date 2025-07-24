//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Ken Thompson
#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <stdlib.h>
#include <time.h>

int main() {

    unsigned long last_total_time = 0, last_idle_time = 0;
    int fd, i;
    char buf[1024];
    unsigned long total_time, user_time, system_time, idle_time, total_delta, idle_delta;
    time_t rawtime;
    struct tm * timeinfo;

    while (1) {

        fd = open("/proc/stat", O_RDONLY);
        read(fd, buf, sizeof(buf));
        close(fd);

        sscanf(buf, "cpu %lu %lu %lu %lu", &user_time, &system_time, &idle_time, &total_time);

        total_delta = total_time - last_total_time;
        idle_delta = idle_time - last_idle_time;

        if (last_total_time != 0) {

            float usage = (((float)total_delta - (float)idle_delta) / (float)total_delta) * 100;
            printf("\033[2J\033[1;1H"); // Clear terminal and move cursor to top left corner
            time(&rawtime);
            timeinfo = localtime(&rawtime);
            printf("CPU Usage Monitor - %s", asctime(timeinfo));
            printf("===================================\n");
            printf("Total CPU time: %lu\n", total_delta);
            printf("Idle CPU time: %lu\n", idle_delta);
            printf("CPU Usage: %.2f%%\n", usage);

        }

        last_total_time = total_time;
        last_idle_time = idle_time;

        sleep(1);
    }

    return 0;
}