//FormAI DATASET v1.0 Category: System boot optimizer ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void optimize_boot() {
    printf("Optimizing system boot...\n");
    //simulate optimization process
    srand(time(NULL));
    int progress = 0;
    while (progress < 100) {
        progress += rand() % 10;
        printf("Progress: %d\n", progress);
        //sleep for random period of time to simulate asynchronous process
        int sleep_time = rand() % 3 + 1;
        sleep(sleep_time);
    }
    printf("System boot optimized!\n");
}

int main() {
    printf("System boot has started...\n");
    optimize_boot();
    printf("Welcome to the system!\n");
    return 0;
}