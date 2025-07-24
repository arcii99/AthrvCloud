//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Node structure for the linked list representing each bucket
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to print the values in each bucket
void printBuckets(Node** buckets, int numBuckets) {
    for (int i = 0; i < numBuckets; i++) {
        printf("Bucket %d: ", i);
        Node* curr = buckets[i];
        while (curr != NULL) {
            printf("%d ", curr->value);
            curr = curr->next;
        }
        printf("\n");
    }
}

// Function to insert a value into a bucket, maintaining ascending order of values
void insertValue(Node** bucket, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;
    
    if (*bucket == NULL || value < (*bucket)->value) {
        newNode->next = *bucket;
        *bucket = newNode;
    } else {
        Node* curr = *bucket;
        while (curr->next != NULL && value >= curr->next->value) {
            curr = curr->next;
        }
        newNode->next = curr->next;
        curr->next = newNode;
    }
}

// Function to perform bucket sort on an array of integers
void bucketSort(int* arr, int size, int numBuckets) {
    // Create the specified number of empty buckets
    Node** buckets = (Node**)malloc(sizeof(Node*) * numBuckets);
    for (int i = 0; i < numBuckets; i++) {
        buckets[i] = NULL;
    }
    
    // Insert each element into the appropriate bucket
    for (int i = 0; i < size; i++) {
        insertValue(&buckets[arr[i] / numBuckets], arr[i]);
    }
    
    // Print the initial state of the buckets
    printf("Initial Buckets:\n");
    printBuckets(buckets, numBuckets);
    
    // Concatenate the buckets into a sorted array
    int index = 0;
    for (int i = 0; i < numBuckets; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            arr[index] = curr->value;
            index++;
            curr = curr->next;
        }
    }
    
    // Print the final state of the buckets
    printf("\nFinal Buckets:\n");
    printBuckets(buckets, numBuckets);
    
    // Free the memory used by the buckets
    for (int i = 0; i < numBuckets; i++) {
        Node* curr = buckets[i];
        while (curr != NULL) {
            Node* temp = curr;
            curr = curr->next;
            free(temp);
        }
    }
    free(buckets);
}

int main() {
    // Test the bucket sort implementation
    
    int arr[10] = {8, 2, 4, 9, 5, 6, 1, 0, 7, 3};
    int size = 10;
    int numBuckets = 3;
    
    printf("Unsorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    bucketSort(arr, size, numBuckets);
    
    printf("\nSorted Array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    
    return 0;
}