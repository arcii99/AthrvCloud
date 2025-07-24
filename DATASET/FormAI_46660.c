//FormAI DATASET v1.0 Category: System boot optimizer ; Style: careful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MIN_BOOT_TIME 30
#define MAX_BOOT_TIME 300
#define MIN_OPTIMIZE_TIME 5
#define MAX_OPTIMIZE_TIME 60
#define MAX_NUM_OF_OPTIMIZATIONS 10

void delay(int seconds) {
    clock_t start_time = clock();
    while (clock() < start_time + seconds * CLOCKS_PER_SEC);
}

int main() {
    int boot_time = (rand() % (MAX_BOOT_TIME - MIN_BOOT_TIME + 1)) + MIN_BOOT_TIME;
    printf("Starting system boot... (Estimated time: %d seconds)\n", boot_time);
    delay(boot_time);

    printf("Booting complete!\n");
    int num_of_optimizations = rand() % MAX_NUM_OF_OPTIMIZATIONS + 1;
    printf("Performing %d optimizations...\n", num_of_optimizations);
    for (int i = 1; i <= num_of_optimizations; i++) {
        int optimize_time = (rand() % (MAX_OPTIMIZE_TIME - MIN_OPTIMIZE_TIME + 1)) + MIN_OPTIMIZE_TIME;
        printf("Optimization %d in progress... (Estimated time: %d seconds)\n", i, optimize_time);
        delay(optimize_time);
        printf("Optimization %d complete!\n", i);
    }

    printf("System optimization complete!\n");
    return 0;
}