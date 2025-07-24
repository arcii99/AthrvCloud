//FormAI DATASET v1.0 Category: Benchmarking ; Style: retro
#include <stdio.h>
#include <time.h>

#define MAX_NUMBERS 1000000

void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++)     
        for (j = 0; j < n-i-1; j++)
            if (arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
}

int main() {
    int numbers[MAX_NUMBERS];
    int i;

    printf("Initializing array with random numbers..\n");
    srand(time(NULL));

    for (i = 0; i < MAX_NUMBERS; i++)
        numbers[i] = rand();

    printf("Sorting array using Bubble sort..\n");
    clock_t start = clock();
    bubbleSort(numbers, MAX_NUMBERS);
    clock_t end = clock();

    double time_taken = (double)(end-start)/CLOCKS_PER_SEC;

    printf("Sorting complete! Array has been sorted in %lf seconds\n", time_taken);

    return 0;
}