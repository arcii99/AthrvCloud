//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>

// Define our node structure
typedef struct node {
    int key;
    void *data;
    struct node *next;
} Node;

// Define our bucket structure
typedef struct bucket {
    Node *head;
    Node *tail;
} Bucket;

// Define our Bucket Sort function
void bucketSort(int arr[], int size) {

    // Create our array of Buckets
    Bucket buckets[size];

    // Initialize each bucket
    for (int i = 0; i < size; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    // Determine the maximum value in the array
    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // Distribute each element into its corresponding bucket
    for (int i = 0; i < size; i++) {
        int index = arr[i] * size / (max + 1);
        Node *new_node = malloc(sizeof(Node));
        new_node->key = arr[i];
        new_node->data = NULL;
        new_node->next = NULL;

        if (buckets[index].head == NULL) {
            buckets[index].head = new_node;
            buckets[index].tail = new_node;
        } else {
            buckets[index].tail->next = new_node;
            buckets[index].tail = new_node;
        }
    }

    // Sort each bucket using Insertion Sort
    for (int i = 0; i < size; i++) {
        Node *current = buckets[i].head;
        while (current != NULL) {
            Node *next_node = current->next;

            // Insert current node into the appropriate position within the linked list
            Node *prev_node = NULL;
            Node *temp = buckets[i].head;
            while (temp != current && current->key > temp->key) {
                prev_node = temp;
                temp = temp->next;
            }

            if (prev_node == NULL) {
                current->next = buckets[i].head;
                buckets[i].head = current;
            } else {
                current->next = prev_node->next;
                prev_node->next = current;
            }

            current = next_node;
        }
    }

    // Copy the sorted elements back into the original array
    int index = 0;
    for (int i = 0; i < size; i++) {
        Node *current = buckets[i].head;
        while (current != NULL) {
            arr[index] = current->key;
            index++;
            current = current->next;
        }
    }

    // Free memory associated with linked list nodes
    for (int i = 0; i < size; i++) {
        Node *current = buckets[i].head;
        while (current != NULL) {
            Node *next_node = current->next;
            free(current);
            current = next_node;
        }
    }
}

// Main function for testing the Bucket Sort implementation
int main() {

    // Initialize an array of integers to be sorted
    int arr[10] = {9, 3, 7, 5, 1, 2, 4, 6, 8, 0};
    int size = sizeof(arr) / sizeof(arr[0]);

    // Sort the array using the Bucket Sort algorithm
    bucketSort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}