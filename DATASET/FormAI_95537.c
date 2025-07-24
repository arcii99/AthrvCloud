//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

void print_cpu_usage() {
    static int count = 0;
    struct rusage usage;

    if(getrusage(RUSAGE_SELF, &usage) != 0) {
        perror("Error: ");
        return;
    }

    long utime = usage.ru_utime.tv_sec * 1000 + usage.ru_utime.tv_usec / 1000;
    long stime = usage.ru_stime.tv_sec * 1000 + usage.ru_stime.tv_usec / 1000;
    long total_time = utime + stime;

    if(count == 0) {
        printf("CPU usage:\n");
        printf("-----------\n");
        printf("%-10s %-10s %-10s\n", "User", "System", "Total");
    }

    printf("%-10ld %-10ld %-10ld\n", utime, stime, total_time);

    count++;
}

int main() {
    printf("Welcome to Retro CPU Usage Monitor\n");
    printf("---------------------------------\n");

    while(1) {
        print_cpu_usage();
        usleep(500000); // Wait for 0.5 seconds
    }

    return 0;
}