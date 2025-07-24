//FormAI DATASET v1.0 Category: Benchmarking ; Style: brave
#include <stdio.h>
#include <time.h>

int sum(int arr[], int n)
{
    int s = 0;
    for (int i = 0; i < n; i++)
        s += arr[i];
    return s;
}

int main()
{
    int n = 1000000;
    int arr[n];
    time_t start, end;

    for (int i = 0; i < n; i++)
        arr[i] = i;

    start = clock();
    int s = sum(arr, n);
    end = clock();

    double time_taken = ((double)(end - start))/CLOCKS_PER_SEC;

    printf("Sum of first %d numbers is %d\n", n, s);
    printf("Time taken by function: %f seconds\n", time_taken);

    return 0;
}