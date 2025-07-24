//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
    int fd, ret, idle_time, non_idle_time, total_time;
    char buf[1024], *str, *sub, *ptr;

    fd = open("/proc/stat", O_RDONLY);

    if (fd < 0) {
        perror("Unable to open /proc/stat");
        exit(1);
    }

    ret = read(fd, buf, sizeof(buf));

    if (ret < 0) {
        perror("Unable to read /proc/stat");
        exit(1);
    }

    str = buf;

    while (*str != '\n')
        str++;

    str++;

    sub = str;

    while (*sub != ' ')
        sub++;

    *sub = '\0';

    total_time = 0;

    for (ptr = str; *ptr != '\0'; ptr++) {
        if (*ptr >= '0' && *ptr <= '9')
            total_time = (total_time * 10) + (*ptr - '0');
    }

    sub++;

    idle_time = 0;

    for (ptr = sub; *ptr != ' '; ptr++) {
        if (*ptr >= '0' && *ptr <= '9')
            idle_time = (idle_time * 10) + (*ptr - '0');
    }

    non_idle_time = total_time - idle_time;

    printf("Total CPU time: %d\n", total_time);
    printf("Idle CPU time: %d\n", idle_time);
    printf("Non-idle CPU time: %d\n", non_idle_time);

    float cpu_usage = (float)(non_idle_time*100)/(float)total_time;

    printf("CPU usage: %f\n", cpu_usage);

    close(fd);

    return 0;
}