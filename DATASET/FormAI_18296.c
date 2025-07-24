//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
/* Welcome to the Benchmarking Program in C! */
/* In this program, we will be comparing the performance of the bubble sort algorithm to the quicksort algorithm */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to bubble sort an array
void bubbleSort(int arr[], int n) {
    int i, j, temp;
    for (i = 0; i < n-1; i++) {
        for (j = 0; j < n-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                // Swap arr[j] and arr[j+1]
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

// Function to perform quicksort on an array
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int pivot = arr[(left + right) / 2];
    int temp;

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    };

    /* recursion */
    if (left < j)
        quickSort(arr, left, j);
    if (i < right)
        quickSort(arr, i, right);
}

int main(int argc, char** argv) {
    srand(time(NULL)); // Seed the random number generator 
    int arr[100000], arrCopy[100000], i;

    // Fill both arrays with random integers 
    for (i = 0; i < 100000; i++) {
        int num = rand() % 1000;
        arr[i] = num;
        arrCopy[i] = num;
    }

    // Time Bubble Sort 
    printf("Timing Bubble Sort...\n");
    clock_t t0 = clock();
    bubbleSort(arr, 100000);
    clock_t t1 = clock();
    double bubbleTime = (double) (t1 - t0) / CLOCKS_PER_SEC;
    printf("Bubble Sort Time: %.4lf seconds\n", bubbleTime);

    // Time Quick Sort 
    printf("Timing Quick Sort...\n");
    t0 = clock();
    quickSort(arrCopy, 0, 99999);
    t1 = clock();
    double quickTime = (double) (t1 - t0) / CLOCKS_PER_SEC;
    printf("Quick Sort Time: %.4lf seconds\n", quickTime);

    // Print which sorting algorithm was faster 
    if (bubbleTime < quickTime) {
        printf("Bubble Sort was faster.\n");
    } else {
        printf("Quick Sort was faster.\n");
    }

    return 0;
}