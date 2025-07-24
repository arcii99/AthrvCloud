//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

// Define the bucket structure
struct Node {
    int data;
    struct Node* next;
};

// Helper function to insert a node into the linked list in ascending order
void insertNode(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = value;
    newNode->next = NULL;
    
    if (*head == NULL) {
        *head = newNode;
    } else if (value < (*head)->data) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && value > current->next->data) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Bucket Sort algorithm implementation
void bucketSort(int arr[], int size, int numBuckets) {
    // Create the buckets
    struct Node** buckets = (struct Node**) malloc(numBuckets * sizeof(struct Node*));
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }
    
    // Insert the elements into the buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = arr[i] / numBuckets;
        insertNode(&buckets[bucketIndex], arr[i]);
    }
    
    // Concatenate the buckets into the sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            arr[index] = current->data;
            current = current->next;
            index++;
        }
    }
    
    // Free the memory used by the buckets
    for (int i = 0; i < numBuckets; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

// Main function to test the algorithm
int main() {
    int arr[] = { 10, 22, 34, 40, 55, 66, 75, 80 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int numBuckets = 4;

    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bucketSort(arr, size, numBuckets);

    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}