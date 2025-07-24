//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list implementation of buckets
struct Node {
    int data;
    struct Node *next;
};

// Function to insert a node into a linked list bucket
void insertNode(struct Node **head, int data) {
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL) {  // If bucket is empty
        *head = newNode;
    } else {  // If bucket is not empty
        struct Node *currNode = *head;

        // Traverse to end of list
        while (currNode->next != NULL) {
            currNode = currNode->next;
        }

        // Insert new node at end of list
        currNode->next = newNode;
    }
}

// Function to sort an array using bucket sort
void bucketSort(int arr[], int n, int numBuckets) {
    // Create array of linked list buckets
    struct Node **buckets = (struct Node**)malloc(numBuckets * sizeof(struct Node*));

    // Initialize each bucket as empty
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }

    // Insert each element into corresponding bucket based on value range
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / numBuckets;
        insertNode(&buckets[bucketIndex], arr[i]);
    }

    // Traverse each bucket and overwrite original array with sorted values
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        struct Node *currNode = buckets[i];

        while (currNode != NULL) {
            arr[index++] = currNode->data;
            currNode = currNode->next;
        }
    }

    // Free memory allocated for buckets
    for (int i = 0; i < numBuckets; i++) {
        struct Node *currNode = buckets[i];

        while (currNode != NULL) {
            struct Node *temp = currNode;
            currNode = currNode->next;
            free(temp);
        }
    }
    free(buckets);
}

// Function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    // Test bucket sort implementation
    int arr[] = {29, 25, 22, 10, 16, 18, 9, 42, 61, 53};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numBuckets = 5;

    printf("Original array: ");
    printArray(arr, n);

    bucketSort(arr, n, numBuckets);

    printf("Sorted array: ");
    printArray(arr, n);

    return 0;
}