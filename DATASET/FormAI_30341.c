//FormAI DATASET v1.0 Category: Benchmarking ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Let's declare some funny variables to keep it cheerful!
int party = 0;
int balloons = 0;
int music = 1;

// The following function is the Quick Sort algorithm
void quickSort(int arr[], int left, int right) {
    int i = left, j = right;
    int tmp;
    int pivot = arr[(left + right) / 2];

    /* partition */
    while (i <= j) {
        while (arr[i] < pivot)
            i++;
        while (arr[j] > pivot)
            j--;
        if (i <= j) {
            tmp = arr[i];
            arr[i] = arr[j];
            arr[j] = tmp;
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

// Now let's create the main function

int main() {
    srand(time(NULL));  // Initialize random number generator
    int n = 100000;  // We'll create an array with 100,000 integers!
    int arr[n];

    // Let's add some balloons to the party!
    for (int i = 0; i < n; i++) {
        arr[i] = rand();
        balloons++;
    }

    // Now, let's sort the array using Quick Sort and measure the time it takes
    clock_t start = clock();
    quickSort(arr, 0, n-1);
    clock_t end = clock();
    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Sorting %d integers took %f seconds with %d balloons and %d songs!\n", n, cpu_time_used, balloons, music);

    // Let's turn up the music!
    music += 5;

    return 0;
}