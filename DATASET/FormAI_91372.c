//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    clock_t start, end;
    time_t start_time, end_time;

    start = clock();
    time(&start_time);

    // Your program logic here

    end = clock();
    time(&end_time);

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    double wall_time_used = difftime(end_time, start_time);

    printf("CPU utilization: %.2f%%\n", (cpu_time_used / wall_time_used) * 100);

    return 0;
}