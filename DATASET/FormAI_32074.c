//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    clock_t start, end;
    double cpu_time_used;

    int i;
    start = clock();

    for (i = 0; i < 1000000; i++) {
        printf("You are amazing! Keep up the good work!\n");
    }

    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("The loop ran for %f seconds\n", cpu_time_used);

    return 0;
}