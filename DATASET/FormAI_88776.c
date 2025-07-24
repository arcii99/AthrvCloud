//FormAI DATASET v1.0 Category: System boot optimizer ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C System Boot Optimizer!\n");
    printf("We are going to help you boot your system faster than ever before!\n");
    printf("Press ENTER to begin optimizing your system...\n");
    getchar();

    printf("\nInitializing Boot Optimizer...\n");

    // Start the timer
    clock_t start = clock();

    // Simulate boot optimizing process
    for (int i = 0; i < 10000000; ++i) {
        int j = rand() % 10000000;
    }

    // End the timer and get the elapsed time
    clock_t end = clock();
    double elapsed_time = (double)(end - start) / CLOCKS_PER_SEC;

    printf("Boot Optimization complete in %.2f seconds!\n", elapsed_time);
    printf("Your boot time has been reduced by %.2f seconds!\n", elapsed_time / 2);

    return 0;
}