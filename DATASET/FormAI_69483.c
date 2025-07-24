//FormAI DATASET v1.0 Category: Benchmarking ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));

    printf("My love, let me benchmark our love today.\n");
    printf("How many times should we run our love benchmark?\n");
    int benchmark_times;
    scanf("%d", &benchmark_times);

    printf("Ok, I will benchmark our love %d times.\n", benchmark_times);
    printf("Are you ready to start the benchmarking process?\n");
    printf("Press any key to continue...\n");

    getchar(); // This waits for the user to press any key

    clock_t start_time = clock();

    for (int i = 0; i < benchmark_times; i++) {
        int a = rand() % 50 + 1;
        int b = rand() % 50 + 1;
        int result = a * b;

        printf("Our love is %d%% strong!\n", result);
    }

    clock_t end_time = clock();
    double total_time = (double)(end_time - start_time) / CLOCKS_PER_SEC;

    printf("Done! Our love benchmark took %f seconds.\n", total_time);
    printf("Our love is eternal, but this benchmark just measured a moment in time.\n");

    return 0;
}