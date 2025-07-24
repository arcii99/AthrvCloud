//FormAI DATASET v1.0 Category: Math exercise ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

void printArray(int *arr, int size) {
    printf("Array :: ");
    for(int i=0; i<size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int compare(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

int main() {
    // Generate Random Numbers for the Array
    srand(time(NULL));
    int size = 10;
    int arr[size];
    for(int i=0; i<size; i++)
        arr[i] = rand() % 1000;

    // Perform Mathematical Operations on the Array
    printArray(arr, size);
    qsort(arr, size, sizeof(int), compare);
    printArray(arr, size);

    int sum = 0;
    for(int i=0; i<size; i++)
        sum += arr[i];
    printf("Sum :: %d\n", sum);

    double avg = (double)sum/size;
    printf("Average :: %f\n", avg);

    double variance = 0;
    for(int i=0; i<size; i++)
        variance += pow(arr[i]-avg, 2);
    variance /= size;
    printf("Variance :: %f\n", variance);

    double std_deviation = sqrt(variance);
    printf("Standard Deviation :: %f\n", std_deviation);

    return 0;
}