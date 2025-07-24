//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/times.h>
#include <time.h>

int main() {

    float total_time, sys_time, user_time;
    struct tms buf;
    clock_t start, end;

    // Get the starting CPU time
    start = times(&buf);

    // Do some CPU intensive task
    int max = 100000000;
    long long sum = 0;
    for (int i = 0; i < max; i++) {
        sum += i;
    }

    // Get the ending CPU time
    end = times(&buf);

    // Calculate the total CPU time, system time and user time
    total_time = (end - start) / (float)CLOCKS_PER_SEC;
    sys_time = buf.tms_stime / (float)CLOCKS_PER_SEC;
    user_time = buf.tms_utime / (float)CLOCKS_PER_SEC;

    // Print the CPU usage
    printf("Total CPU time: %f seconds\n", total_time);
    printf("System CPU time: %f seconds\n", sys_time);
    printf("User CPU time: %f seconds\n", user_time);

    return 0;
}