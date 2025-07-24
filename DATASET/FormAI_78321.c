//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main(int argc, char *argv[]) {

    if (argc < 2) {
        printf("Usage: %s PID\n", argv[0]);
        return 1;
    }

    int pid = atoi(argv[1]);

    while (1) {
        struct rusage usage;
        if (getrusage(pid, &usage) == -1) {
            printf("PID %d does not exist\n", pid);
            return 1;
        }

        double utime = usage.ru_utime.tv_sec + usage.ru_utime.tv_usec / 1000000.0;
        double stime = usage.ru_stime.tv_sec + usage.ru_stime.tv_usec / 1000000.0;
        double total_time = utime + stime;

        double cpu_usage = total_time / (double)sysconf(_SC_CLK_TCK);

        printf("PID %d CPU usage: %lf%%\n", pid, cpu_usage);

        sleep(1);
    }

    return 0;
}