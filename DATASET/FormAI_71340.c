//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: visionary
#include <stdio.h>
#include <stdlib.h>

// Function Declarations
void bucketSort(float [], int);
void printArray(float [], int);
int getMaxPower(float [], int);

// Function Definitions
void bucketSort(float arr[], int n) {

    // Create maximum-sized bucket
    int i, j, count = 0;
    int power = getMaxPower(arr, n);
    int maxVal = 1;
    for (i = 0; i < power; i++)
        maxVal *= 10;
    float bucket[maxVal];

    // Initialize bucket with zeros
    for (i = 0; i < maxVal; i++)
        bucket[i] = 0;

    // Add values to bucket
    for (i = 0; i < n; i++) {
        int key = arr[i] * maxVal;
        bucket[key] = arr[i];
        count++;
    }

    // Sort values in each bucket
    for (i = 0; i < maxVal; i++) {
        float temp[count];
        count = 0;
        for (j = 0; j < maxVal; j++) {
            if (bucket[j] != 0)
                temp[count++] = bucket[j];
        }
        for (j = 0; j < count - 1; j++) {
            if (temp[j] > temp[j + 1]) {
                float tempVal = temp[j];
                temp[j] = temp[j + 1];
                temp[j + 1] = tempVal;
            }
        }
        for (j = 0; j < count; j++) {
            bucket[j] = temp[j];
        }
    }

    // Copy values back to original array
    int index = 0;
    for (i = 0; i < maxVal; i++) {
        if (bucket[i] != 0)
            arr[index++] = bucket[i];
    }
}

void printArray(float arr[], int size) {
    int i;
    for (i = 0; i < size; i++)
        printf("%.2f ", arr[i]);
    printf("\n");
}

int getMaxPower(float arr[], int n) {
    int i, power = 0;
    for (i = 0; i < n; i++) {
        int temp = arr[i] * 10;
        while (temp > 1) {
            power++;
            temp /= 10;
        }
    }
    return power;
}

// Driver Code
int main() {
    float arr[] = {0.1, 0.9, 0.5, 0.3, 0.7, 0.2, 0.6, 0.4, 0.8};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Unsorted array:\n");
    printArray(arr, n);

    // Sort array using bucket sort
    bucketSort(arr, n);

    printf("Sorted array:\n");
    printArray(arr, n);

    return 0;
}