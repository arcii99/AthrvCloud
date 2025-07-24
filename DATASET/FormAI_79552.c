//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {

    printf("Happy CPU usage monitoring!\n");

    while (1) {
        
        struct rusage usage;
        getrusage(RUSAGE_SELF, &usage);
        
        double seconds = usage.ru_utime.tv_sec + usage.ru_stime.tv_sec;
        double micros = usage.ru_utime.tv_usec + usage.ru_stime.tv_usec;
        double millis = micros / 1000;
        double total = seconds + (millis / 1000);

        printf("CPU usage: %f seconds\n", total);
        
        sleep(1);
    }

    return 0;
}