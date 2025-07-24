//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: irregular
#include <stdio.h>
#include <stdlib.h>

// Defining the struct for the bucket
struct Node {
    int value;
    struct Node* next;
};

// Perform a bucket sort on a given array
void bucketSort(double array[], int n) {
    // Declare an array of pointers to nodes
    struct Node* buckets[n];

    // Initialize each bucket with a null pointer
    for (int i = 0; i < n; i++) {
        buckets[i] = NULL;
    }

    // Calculate the maximum value from the array
    double maxVal = array[0];
    for (int i = 1; i < n; i++) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }

    // Divide each value in the array by the maximum value to get a percentage value
    for (int i = 0; i < n; i++) {
        array[i] = array[i] / maxVal;
    }

    // Insert each value in the array into the correct bucket
    for (int i = 0; i < n; i++) {
        int index = (int)(array[i] * n);
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = array[i];
        newNode->next = buckets[index];
        buckets[index] = newNode;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < n; i++) {
        struct Node* bucket = buckets[i];
        while (bucket != NULL) {
            struct Node* current = bucket->next;
            while (current != NULL && current->value < bucket->value) {
                bucket->next = current->next;
                current->next = bucket;
                current = bucket->next;
            }
            bucket = current;
        }
    }

    // Copy the values from the sorted buckets back into the array
    int index = 0;
    for (int i = 0; i < n; i++) {
        struct Node* bucket = buckets[i];
        while (bucket != NULL) {
            array[index++] = bucket->value * maxVal;
            bucket = bucket->next;
        }
    }
}

// Main function to test the bucket sort
int main() {
    // Create an array of random values between 0 and 1
    double array[] = {0.89, 0.23, 0.53, 0.77, 0.12, 0.45, 0.98, 0.56, 0.32, 0.11};

    // Print the unsorted array
    printf("Unsorted array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(array, 10);

    // Print the sorted array
    printf("Sorted array:\n");
    for (int i = 0; i < 10; i++) {
        printf("%.2f ", array[i]);
    }
    printf("\n");

    return 0;
}