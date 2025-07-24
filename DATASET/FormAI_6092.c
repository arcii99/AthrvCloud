//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: genious
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

#define MILLION 1000000

// function to generate random numbers
int get_random_number(int min_num, int max_num) {
    int result = 0, low_num = 0, hi_num = 0;

    if (min_num < max_num) {
        low_num = min_num;
        hi_num = max_num + 1;
    } else {
        low_num = max_num + 1;
        hi_num = min_num;
    }

    srand(time(NULL));
    result = (rand() % (hi_num - low_num)) + low_num;

    return result;
}

int main() {
    int cpu_usage = 0;

    while(1) {
        // simulate CPU usage by generating random numbers
        cpu_usage = get_random_number(0, 100);

        // get time in seconds and microseconds
        struct timeval tv;
        gettimeofday(&tv, NULL);

        long int sec = tv.tv_sec;
        long int usec = tv.tv_usec;

        // print CPU usage and time in seconds and microseconds
        printf("CPU Usage: %d%% | Time: %ld seconds %ld microseconds\n", 
                cpu_usage, sec, usec);

        // wait for 1 second before repeating
        sleep(1);
    }

    return 0;
}