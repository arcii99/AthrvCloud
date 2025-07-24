//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: accurate
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/time.h>

#define DATA_SIZE 10000000

int main() {
    int i, j, k;
    char* data = (char*) malloc(DATA_SIZE);
    double total_time = 0.0;

    struct timeval start_time, end_time;

    // Initialize data with random values
    srand(time(NULL));
    for (i = 0; i < DATA_SIZE; i++) {
        data[i] = rand() % 256;
    }

    // Perform speed test
    for (k = 0; k < 10; k++) {
        printf("Speed Test #%d\n", k + 1);

        gettimeofday(&start_time, NULL);
        for (i = 0; i < DATA_SIZE; i++) {
            j = i + (rand() % 100 - 50);
            if (j < 0 || j >= DATA_SIZE) {
                j = rand() % DATA_SIZE;
            }
            data[i] ^= data[j];
        }
        gettimeofday(&end_time, NULL);

        total_time += (end_time.tv_sec - start_time.tv_sec) * 1000.0;
        total_time += (end_time.tv_usec - start_time.tv_usec) / 1000.0;

        printf("Elapsed time: %.2f ms\n", total_time);
    }

    free(data);
    return 0;
}