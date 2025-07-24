//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>

// Define the maximum number of elements in the array
#define MAX_SIZE 10

// Define the maximum number of buckets
#define NUM_BUCKETS 5

// Define the structure of the linked list node
typedef struct node {
    int value;
    struct node *next;
} Node;

// Define the structure of the bucket
typedef struct bucket {
    Node *head;
    Node *tail;
} Bucket;

// Define the bucket sort function
void bucketSort(int arr[], int n) {
    // Create the buckets
    Bucket buckets[NUM_BUCKETS];

    // Initialize the buckets
    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i].head = NULL;
        buckets[i].tail = NULL;
    }

    // Place each element in the appropriate bucket
    for (int i = 0; i < n; i++) {
        int bucketIndex = arr[i] / NUM_BUCKETS;
        Node *newNode = (Node *) malloc(sizeof(Node));
        newNode->value = arr[i];
        newNode->next = NULL;

        if (buckets[bucketIndex].head == NULL) {
            buckets[bucketIndex].head = newNode;
            buckets[bucketIndex].tail = newNode;
        } else {
            buckets[bucketIndex].tail->next = newNode;
            buckets[bucketIndex].tail = newNode;
        }
    }

    // Sort the elements in each bucket using insertion sort
    for (int i = 0; i < NUM_BUCKETS; i++) {
        Node *current = buckets[i].head;

        while (current != NULL) {
            Node *temp = current->next;
            Node *prev = NULL;
            int currentItem = current->value;

            while (temp != NULL && temp->value < currentItem) {
                prev = temp;
                temp = temp->next;
            }

            if (prev == NULL) {
                buckets[i].head = current->next;
            } else {
                prev->next = current->next;
            }

            current->next = temp;

            if (temp == NULL) {
                buckets[i].tail = current;
            }
    
            temp = current->next;
            current = temp;
        }
    }

    // Merge the buckets back into the original array
    int index = 0;

    for (int i = 0; i < NUM_BUCKETS; i++) {
        Node *current = buckets[i].head;

        while (current != NULL) {
            arr[index++] = current->value;
            current = current->next;
        }
    }
}

// Define the main function
int main() {
    int arr[MAX_SIZE] = {3, 8, 0, 4, 7, 2, 5, 1, 9, 6};

    printf("Unsorted array:\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, MAX_SIZE);

    printf("\nSorted array:\n");

    for (int i = 0; i < MAX_SIZE; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}