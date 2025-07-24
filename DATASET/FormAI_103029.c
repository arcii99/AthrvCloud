//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: retro
#include <stdio.h>
#include <stdlib.h>

// Node structure for linked list in bucket.
typedef struct node {
    int data;
    struct node* next;
} Node;

// Function to perform Bucket Sort
void bucketSort(int arr[], int n) {
    // Initialize bucket array with null.
    Node* bucket[10] = { NULL };
 
    // Calculate maximum number in array
    int max_num = arr[0];
    for (int i = 1; i < n; i++) {
        if (max_num < arr[i])
            max_num = arr[i];
    }

    // Calculate partition size
    int partition_size = max_num / 10 + 1;
 
    // Insert elements into respective bucket.
    for (int i = 0; i < n; i++) {
        int partition_index = arr[i] / partition_size;
        Node* new_node = (Node*)malloc(sizeof(Node));
        new_node->data = arr[i];
        new_node->next = NULL;
 
        if (bucket[partition_index] == NULL) {
            bucket[partition_index] = new_node;
        } else {
            Node* temp = bucket[partition_index];
            while (temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = new_node;
        }
    }
 
    // Sort elements in each bucket.
    for (int i = 0; i < 10; i++) {
        Node* current = bucket[i];
        Node* prev = NULL;
 
        while (current != NULL) {
            Node* temp = current->next;
 
            while (temp != NULL && temp->data < current->data) {
                prev = temp;
                temp = temp->next;
            }
 
            if (temp == current->next) {
                prev = current;
            } else {
                prev->next = current;
                current->next = temp;
            }
            current = temp;
        }
    }
 
    // Merge all buckets.
    int index = 0;
    for (int i = 0; i < 10; i++) {
        Node* current = bucket[i];
        while (current != NULL) {
            arr[index++] = current->data;
            current = current->next;
        }
    }
}

// Driver program for testing.
int main() {
    int arr[] = { 8, 5, 3, 2, 6, 9, 1, 0, 4, 7 };
    int n = sizeof(arr) / sizeof(int);
    printf("Original Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Call Bucket Sort function
    bucketSort(arr, n);

    printf("Sorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}