//FormAI DATASET v1.0 Category: CPU usage monitor ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

int main() {
    float cpu_usage;
    time_t start, end;

    while(1) {
        start = clock();
        int x = 0;
        for(int i = 0; i < 1000000000; i++) {
            x += i;
        }
        end = clock();
        cpu_usage = (float)(end - start) / CLOCKS_PER_SEC;
        printf("Current CPU usage: %f %%\n", cpu_usage * 100);
        sleep(1);
    }

    return 0;
}