//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: Cryptic
#include <stdio.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/resource.h>

int main() {
    printf("Initializing CPU monitor program...\n");
    struct rusage usage;
    struct timeval start_cpu, end_cpu;
    getrusage(RUSAGE_SELF, &usage);
    start_cpu = usage.ru_stime;

    // some cryptic code here...
    int x = 1;
    while (x) {
        // CPU intensive task
        int i, j, k;
        for (i = 0; i < 100; i++) {
            for (j = 0; j < 100; j++) {
                for (k = 0; k < 10000; k++) {
                    int temp = i * j;
                }
            }
        }

        // check CPU usage every second
        sleep(1);
        getrusage(RUSAGE_SELF, &usage);
        end_cpu = usage.ru_stime;
        long int diff = (end_cpu.tv_sec - start_cpu.tv_sec) * 1000000 + (end_cpu.tv_usec - start_cpu.tv_usec);
        printf("CPU usage: %ld microseconds\n", diff);
        if (diff > 5000000) { // 5 seconds
            printf("CPU usage exceeded 5 seconds. Terminating program...\n");
            x = 0;
        }
    }
    return 0;
}