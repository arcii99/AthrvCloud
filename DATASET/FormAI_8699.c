//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// Define the structure of the linked list to be used in the buckets
struct Node {
    int value;
    struct Node *next;
};

// Function to insert an element into the linked list of a bucket
void insert(struct Node** bucket, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*bucket == NULL) {
        *bucket = newNode;
        return;
    }

    struct Node* current = *bucket;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to get the maximum value in an array
int getMaxValue(int arr[], int n) {
    int maxVal = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > maxVal) {
            maxVal = arr[i];
        }
    }
    return maxVal;
}

// Function to perform the Bucket Sort algorithm
void sort(int arr[], int n) {
    // Determine the range of values in the array
    int maxVal = getMaxValue(arr, n);
    int range = maxVal / n + 1;

    // Create an array of buckets
    struct Node** buckets = (struct Node**)malloc(range * sizeof(struct Node*));
    for (int i = 0; i < range; i++) {
        buckets[i] = NULL;
    }

    // Insert the elements of the array into the appropriate bucket
    for (int i = 0; i < n; i++) {
        int index = arr[i] / range;
        insert(&buckets[index], arr[i]);
    }

    // Traverse each bucket and insert the elements back into the original array
    int index = 0;
    for (int i = 0; i < range; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index++] = current->value;
            current = current->next;
        }
    }
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Driver program to test the Bucket Sort algorithm
int main() {
    int arr[] = { 22, 45, 12, 8, 10, 6, 72, 81, 33, 18 };
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    printArray(arr, n);

    sort(arr, n);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}