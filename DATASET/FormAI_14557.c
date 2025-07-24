//FormAI DATASET v1.0 Category: Benchmarking ; Style: creative
#include <stdio.h>
#include <time.h>

int main() {
    int n = 50000;
    int arr[n];
    
    // Initialize array with random values between 0 and 9999
    srand(time(NULL));
    for (int i = 0; i < n; i++) {
        arr[i] = rand() % 10000;
    }
    
    // Bubble sort
    clock_t start = clock();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t end = clock();
    float bubbleSortTime = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Bubble sort time: %f\n", bubbleSortTime);
    
    // Binary Search
    int key = rand() % 10000;
    int low = 0, high = n-1, mid;
    start = clock();
    while (low <= high) {
        mid = (low + high) / 2;
        if (arr[mid] == key) {
            printf("Key found at index %d\n", mid);
            break;
        } else if (arr[mid] < key) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    end = clock();
    float binarySearchTime = (float)(end - start) / CLOCKS_PER_SEC;
    printf("Binary search time: %f\n", binarySearchTime);
    
    return 0;
}