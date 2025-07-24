//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/resource.h>
#include <sys/time.h>

int main() {
    int usage;
    struct rusage cpu_usage;
    struct timeval start, end;
    double elapsed_time;

    printf("Starting CPU usage monitor...\n");

    while(1) {
        if(getrusage(RUSAGE_SELF, &cpu_usage) == -1) {
            printf("Error getting system CPU usage!\n");
            exit(1);
        }

        usage = cpu_usage.ru_utime.tv_sec + cpu_usage.ru_stime.tv_sec;

        printf("CPU usage: %d seconds\n", usage);

        gettimeofday(&start, NULL);

        // Perform some heavy computation
        for(int i=1; i<=1000000; i++) {
            for(int j=1; j<=1000; j++) {
                for(int k=1; k<=10; k++) {
                    int x = i*j*k;
                }
            }
        }

        gettimeofday(&end, NULL);

        elapsed_time = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec)/1000000.0;

        printf("Elapsed time: %f seconds\n", elapsed_time);

        sleep(1); // Sleep for one second before checking CPU usage again
    }

    return 0;
}