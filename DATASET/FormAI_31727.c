//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>

int main() {
    struct timeval start, end;
    double cpu_time_used;

    printf("Starting CPU usage monitor...\n");

    while(1) {
        gettimeofday(&start, NULL);

        for(int i=0; i<50000000; i++) {
            srand(time(NULL));
            int a = rand() % 10;
            int b = rand() % 10;
            int c = a + b;
        }

        gettimeofday(&end, NULL);
        cpu_time_used = ((double) (end.tv_usec - start.tv_usec) / 1000000 +
                         (double) (end.tv_sec - start.tv_sec));
        printf("CPU usage: %f%%\n", cpu_time_used*100);
    }

    return 0;
}