//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Node structure for creating linked lists
struct Node {
    int data;
    struct Node* next;
};

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n) {
    // Define the number of buckets
    const int numBuckets = 10;
    // Create an array of linked list pointers
    struct Node* buckets[numBuckets];
    // Initialize each element of the array to NULL
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }
    // Insert each element of the array into the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucketIdx = arr[i] / numBuckets;
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->data = arr[i];
        newNode->next = buckets[bucketIdx];
        buckets[bucketIdx] = newNode;
    }
    // Traverse each bucket and sort its elements using insertion sort
    for (int i = 0; i < numBuckets; i++) {
        struct Node* head = buckets[i];
        if (head == NULL) {
            continue;
        }
        struct Node* current = head->next;
        while (current != NULL) {
            struct Node* prev = head;
            while (prev != current) {
                if (prev->data > current->data) {
                    int temp = prev->data;
                    prev->data = current->data;
                    current->data = temp;
                }
                prev = prev->next;
            }
            current = current->next;
        }
        // Copy the sorted elements back into the original array
        int idx = 0;
        current = head;
        while (current != NULL) {
            arr[idx++] = current->data;
            current = current->next;
        }
    }
}

int main() {
    // Test the bucket sort function
    int arr[] = {37, 63, 14, 98, 77, 79, 30, 68, 8, 89};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, n);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}