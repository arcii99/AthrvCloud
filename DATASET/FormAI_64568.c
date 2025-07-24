//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include <stdio.h>
#include <stdlib.h>

// Define a struct to represent each element in our "bucket"
typedef struct BucketElement {
    int value;
    struct BucketElement *next;
} BucketElement;

// Function to insert an element into the bucket list
void insert(BucketElement **head, int value) {
    BucketElement *newEl = (BucketElement*)malloc(sizeof(BucketElement));
    newEl->value = value;
    newEl->next = NULL;

    // If the list is empty, add the new element as the head
    if (*head == NULL) {
        *head = newEl;
        return;
    }

    // Find the correct position to insert the element
    BucketElement *node = *head;
    while (node->next != NULL && node->next->value <= value) {
        node = node->next;
    }

    // Insert the element
    newEl->next = node->next;
    node->next = newEl;
}

// Function to sort the bucket
void bucketSort(int arr[], int n, int max) {

    // Create an array of empty buckets, each represented by a linked list
    BucketElement **buckets = (BucketElement**)calloc(max+1, sizeof(BucketElement*));

    // Insert each element of the array into the appropriate bucket
    for (int i = 0; i < n; i++) {
        int index = arr[i];
        insert(&buckets[index], arr[i]);
    }

    // Iterate over each bucket and copy its elements to the output array
    int outputIdx = 0;
    for (int i = 0; i <= max; i++) {
        BucketElement *node = buckets[i];
        while (node != NULL) {
            arr[outputIdx++] = node->value;
            node = node->next;
        }
    }

    // Free the memory used by the bucket lists
    for (int i = 0; i <= max; i++) {
        BucketElement *node = buckets[i];
        while (node != NULL) {
            BucketElement *tmp = node;
            node = node->next;
            free(tmp);
        }
    }

    // Free the memory used by the bucket array
    free(buckets);
}

int main() {
    int arr[] = {5, 2, 8, 3, 1, 4, 9, 6, 7, 0};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, n, 9);

    printf("Sorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}