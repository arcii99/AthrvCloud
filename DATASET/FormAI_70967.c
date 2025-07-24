//FormAI DATASET v1.0 Category: Benchmarking ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

int main()
{
    int array1[SIZE];
    int array2[SIZE];
    int array3[SIZE];
    int array4[SIZE];
    int i, j;
    clock_t start, end;

    // Initialize the arrays with random numbers between 0 and 99
    srand(time(NULL));
    for (i = 0; i < SIZE; i++) {
        array1[i] = rand() % 100;
        array2[i] = rand() % 100;
    }

    // Copy arrays 1 and 2 into arrays 3 and 4
    start = clock();
    for (i = 0; i < SIZE; i++) {
        array3[i] = array1[i];
        array4[i] = array2[i];
    }
    end = clock();
    printf("Time taken to copy arrays using for loop: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Use memcpy function to copy arrays 1 and 2 into arrays 3 and 4
    start = clock();
    memcpy(array3, array1, sizeof(array1));
    memcpy(array4, array2, sizeof(array2));
    end = clock();
    printf("Time taken to copy arrays using memcpy function: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Reverse array 1 using a for loop
    start = clock();
    for (i = 0, j = SIZE - 1; i < j; i++, j--) {
        int temp = array1[i];
        array1[i] = array1[j];
        array1[j] = temp;
    }
    end = clock();
    printf("Time taken to reverse array using for loop: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    // Use memcpy and memcpy_reverse functions to reverse array 2
    start = clock();
    memcpy_reverse(array2, sizeof(array2));
    end = clock();
    printf("Time taken to reverse array using memcpy_reverse function: %lf seconds\n", (double)(end - start) / CLOCKS_PER_SEC);

    return 0;
}

void memcpy_reverse(void* dest, size_t n)
{
    char* src = dest;
    char* end = src + n - 1;

    while (src < end) {
        char tmp = *src;
        *src = *end;
        *end = tmp;

        ++src;
        --end;
    }
}