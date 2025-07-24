//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: authentic
#include <stdio.h>
#include <stdlib.h>

// Linked List Node
struct Node {
    int value;
    struct Node* next;
};

// Bucket Sort function
void bucketSort(int arr[], int size) {
    int i, j;
    // Create array of linked lists to store the buckets
    struct Node* buckets[size];
    // Initialize all the linked lists as empty
    for(i = 0; i < size; i++) {
        buckets[i] = NULL;
    }
    // Add elements to the buckets
    for(i = 0; i < size; i++) {
        // Calculate the index of the bucket for the current element
        int bucketIndex = size * arr[i] / (100 + 1);
        // Create and insert new node in the bucket
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->value = arr[i];
        newNode->next = buckets[bucketIndex];
        buckets[bucketIndex] = newNode;
    }
    // Sort elements in each bucket using Insertion Sort
    for(i = 0; i < size; i++) {
        struct Node* bucket = buckets[i];
        while(bucket != NULL) {
            int currentValue = bucket->value;
            struct Node* prevNode = NULL;
            struct Node* currentNode = bucket;
            while(currentNode != NULL && currentNode->value < currentValue) {
                prevNode = currentNode;
                currentNode = currentNode->next;
            }
            if(prevNode == NULL) {
                bucket = currentNode->next;
                currentNode->next = buckets[i];
                buckets[i] = currentNode;
            } else {
                bucket = currentNode->next;
                currentNode->next = prevNode->next;
                prevNode->next = currentNode;
            }
        }
    }
    // Copy elements back to the original array
    int index = 0;
    for(i = 0; i < size; i++) {
        struct Node* bucket = buckets[i];
        while(bucket != NULL) {
            arr[index] = bucket->value;
            index++;
            bucket = bucket->next;
        }
    }
}

// Main function
int main() {
    int arr[] = {43, 59, 67, 81, 33, 3, 99, 29, 7, 61, 23, 19, 61};
    int size = sizeof(arr)/sizeof(arr[0]);
    printf("Original Array: ");
    int i;
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    bucketSort(arr, size);
    printf("Sorted Array: ");
    for(i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}