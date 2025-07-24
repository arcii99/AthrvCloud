//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    struct rusage usage;
    double user_time, sys_time;
    int pid = getpid();
    while(1) {
        getrusage(RUSAGE_SELF, &usage);
        user_time = (double) (usage.ru_utime.tv_sec) + ((double) (usage.ru_utime.tv_usec) / 1000000);
        sys_time = (double) (usage.ru_stime.tv_sec) + ((double) (usage.ru_stime.tv_usec) / 1000000);
        printf("Process ID: %d\n", pid);
        printf("CPU Usage\n");
        printf("User Time: %f seconds\n", user_time);
        printf("System Time: %f seconds\n", sys_time);
        sleep(1);
    }
    return 0;
}