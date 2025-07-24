//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int get_cpu_usage() {
    int fd = open("/proc/stat", O_RDONLY);
    char buf[1024];
    read(fd, buf, 1024);
    close(fd);

    int user_time, nice_time, sys_time, idle_time;
    sscanf(buf, "cpu %d %d %d %d", &user_time, &nice_time, &sys_time, &idle_time);

    int total_time = user_time + nice_time + sys_time + idle_time;
    int cpu_usage = ((float)(total_time - idle_time) / total_time) * 100;

    return cpu_usage;
}

int main() {
    int cpu_usage = get_cpu_usage();

    printf("CPU Usage: %d%%\n", cpu_usage);

    return 0;
}