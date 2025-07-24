//FormAI DATASET v1.0 Category: Benchmarking ; Style: calm
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARR_SIZE 1000000

void vanilla_search(int arr[], int target);
void binary_search(int arr[], int target);

int main() {
    // Declare variables
    int arr[ARR_SIZE], target;
    clock_t start, end;
    double vanilla_time, binary_time;

    // Populate array with random numbers between 1 and 100
    srand(time(NULL));
    for (int i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand() % 100 + 1;
    }

    // Prompt user for target number
    printf("Enter a target number between 1 and 100: ");
    scanf("%d", &target);

    // Vanilla Search
    printf("\nVanilla Search...\n");
    start = clock();
    vanilla_search(arr, target);
    end = clock();
    vanilla_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Binary Search
    printf("\nBinary Search...\n");
    start = clock();
    binary_search(arr, target);
    end = clock();
    binary_time = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print results
    printf("\nVanilla Search Time: %lf seconds\n", vanilla_time);
    printf("Binary Search Time: %lf seconds\n", binary_time);
    return 0;
}

// Vanilla Search Algorithm
void vanilla_search(int arr[], int target) {
    int i;
    for (i = 0; i < ARR_SIZE; i++) {
        if (arr[i] == target) {
            printf("Found %d at index %d\n", target, i);
            return;
        }
    }
    printf("%d not found in array\n", target);
    return;
}

// Binary Search Algorithm
void binary_search(int arr[], int target) {
    int low = 0, high = ARR_SIZE - 1, mid;
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == target) {
            printf("Found %d at index %d\n", target, mid);
            return;
        }
        else if (arr[mid] < target) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    printf("%d not found in array\n", target);
    return;
}