//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>

// Define a linked list structure
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Bucket sort function
void bucketSort(int arr[], int n) {
    Node** buckets = (Node**)calloc(n, sizeof(Node*)); // Allocate memory for n buckets

    // Divide the input values into buckets
    for (int i = 0; i < n; i++) {
        int bucketIndex = (n * arr[i]) / (100 + 1);
        Node* newNode = (Node*)malloc(sizeof(Node));
        newNode->value = arr[i];
        newNode->next = NULL;

        // Add new node to the begining of the appropriated linked list
        if (buckets[bucketIndex] == NULL) {
            buckets[bucketIndex] = newNode;
        } else {
            newNode->next = buckets[bucketIndex];
            buckets[bucketIndex] = newNode;
        }
    }

    // Sort each non-empty bucket and combine them into output array
    int index = 0;
    for (int i = 0; i < n; i++) {
        Node* currentNode = buckets[i];
        while (currentNode != NULL) {
            arr[index++] = currentNode->value;
            currentNode = currentNode->next;
        }
    }

    // Clean up allocated memory
    for (int i = 0; i < n; i++) {
        Node* currentNode = buckets[i];
        while (currentNode != NULL) {
            Node* tempNode = currentNode;
            currentNode = currentNode->next;
            free(tempNode);
        }
    }
    free(buckets);
}

// Main function for testing
int main() {
    int n = 10;
    int arr[] = {23, 10, 64, 32, 52, 78, 15, 6, 40, 59};

    // Before sorting
    printf("Before sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Sort the array using bucket sort
    bucketSort(arr, n);

    // After sorting
    printf("After sorting: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}