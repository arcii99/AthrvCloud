//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Ken Thompson
#include <stdio.h>
#include <stdlib.h>

// Represents a node in the linked list
struct Node {
    float value;
    struct Node* next;
};

/**
 * Sorts an array of floats using Bucket Sort algorithm
 */
void bucketSort(float arr[], int size) {
    // Create an array of linked lists
    struct Node* buckets[size];

    // Initialize each linked list to NULL
    for (int i = 0; i < size; i++) {
        buckets[i] = NULL;
    }

    // Scatter elements of array into the correct bucket
    for (int i = 0; i < size; i++) {
        int index = arr[i] * size;
        struct Node* node = (struct Node*) malloc(sizeof(struct Node));
        node->value = arr[i];
        node->next = buckets[index];
        buckets[index] = node;
    }

    // Sort each bucket using insertion sort
    for (int i = 0; i < size; i++) {
        struct Node* head = buckets[i];
        struct Node* prev = NULL;
        struct Node* curr = head;

        // Perform insertion sort
        while (curr != NULL) {
            if (prev != NULL && curr->value < prev->value) {
                prev->next = curr->next;
                curr->next = prev;

                if (prev == head) {
                    head = curr;
                }
                curr = prev;
            }
            prev = curr;
            curr = curr->next;
        }
        // Update the linked list in the bucket with head node
        buckets[i] = head;
    }

    // Gather elements in the sorted order
    int index = 0;
    for (int i = 0; i < size; i++) {
        struct Node* node = buckets[i];
        while (node != NULL) {
            arr[index++] = node->value;
            node = node->next;
        }
    }
}

// Main function
int main() {
    float arr[] = {0.12, 0.23, 0.01, 0.35, 0.48, 0.67, 0.33, 0.52};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Input Array: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    // Sort the array
    bucketSort(arr, size);

    printf("Sorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%.2f ", arr[i]);
    }
    printf("\n");

    return 0;
}