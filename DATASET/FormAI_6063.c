//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>

void bucketSort(int array[], int n)
{
    int i, j;
    int count[n];
    for (i = 0; i < n; i++) {
        count[i] = 0;
    }

    for (i = 0; i < n; i++) {
        (count[array[i]])++;
    }

    for (i = 0, j = 0; i < n; i++) {
        for (; count[i] > 0; (count[i])--) {
            array[j++] = i;
        }
    }
}

void printArray(int array[], int size)
{
    int i;
    for (i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main()
{
    int array[] = {9, 3, 7, 1, 8, 5, 2, 6, 4, 0};
    int n = sizeof(array) / sizeof(array[0]);

    printf("Array before sorting: \n");
    printArray(array, n);

    bucketSort(array, n);

    printf("Array after sorting: \n");
    printArray(array, n);

    return 0;
}