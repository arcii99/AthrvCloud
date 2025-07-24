//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 100

// Define a node structure for linked list in each bucket
typedef struct node {
    int key;
    struct node* next;
} Node;

// A function to sort a given array using bucket sort algorithm
void bucketSort(int arr[], int n) {
    int i, j;
    Node *bucket[BUCKET_SIZE];

    // Initialize each bucket with NULL as head
    for (i = 0; i < BUCKET_SIZE; i++) {
        bucket[i] = NULL;
    }

    // Create separate linked list for each bucket
    for (i = 0; i < n; i++) {
        Node* newNode = (Node*) malloc(sizeof(Node));
        newNode->key = arr[i];
        newNode->next = NULL;

        // Calculate the index of bucket to place the node
        int index = (int) (arr[i] / BUCKET_SIZE);
        if (bucket[index] == NULL) {
            bucket[index] = newNode;
        } else {
            Node* curr = bucket[index];
            while (curr->next != NULL) {
                curr = curr->next;
            }
            curr->next = newNode;
        }
    }

    // Sort each linked list in every bucket
    for (i = 0; i < BUCKET_SIZE; i++) {
        Node* head = bucket[i];
        if (head != NULL) {
            // Use bubble sort algorithm to sort each linked list
            for (j = 0; j < BUCKET_SIZE; j++) {
                Node* curr = head;
                while (curr->next != NULL) {
                    if (curr->key > curr->next->key) {
                        int temp = curr->key;
                        curr->key = curr->next->key;
                        curr->next->key = temp;
                    }
                    curr = curr->next;
                }
            }
        }
    }

    // Merge all sorted linked lists into the original array
    int k = 0;
    for (i = 0; i < BUCKET_SIZE; i++) {
        Node* curr = bucket[i];
        while (curr != NULL) {
            arr[k++] = curr->key;
            curr = curr->next;
        }
    }
}

// Driver code
int main()
{
    int arr[] = {38, 27, 43, 3, 9, 82, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n);

    printf("\nSorted array: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}