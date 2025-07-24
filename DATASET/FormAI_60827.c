//FormAI DATASET v1.0 Category: Benchmarking ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 1000000

int main()
{
    int a[N], i, key;

    // Generate random array
    srand(time(NULL));
    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 1000;
    }

    // Linear search
    clock_t start1 = clock();
    for (i = 0; i < N; i++)
    {
        if (a[i] == 500)
            break;
    }
    clock_t end1 = clock();

    // Binary search
    int low = 0, high = N-1, mid;
    clock_t start2 = clock();
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (a[mid] == 500)
            break;
        else if (a[mid] > 500)
            high = mid - 1;
        else
            low = mid + 1;
    }
    clock_t end2 = clock();

    // Output benchmarking results
    printf("Linear search time: %f seconds\n", (double)(end1 - start1) / CLOCKS_PER_SEC);
    printf("Binary search time: %f seconds\n", (double)(end2 - start2) / CLOCKS_PER_SEC);

    return 0;
}