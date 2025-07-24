//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>

#define BUCKET_SIZE 10 // Bucket size set to 10

struct Node {
    int data;
    struct Node* next;
};

void addToList(struct Node** head, int data) {
    // Create new node
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    // If head is null, set the new node as head
    if (*head == NULL) {
        *head = newNode;
    } else {
        // Traverse to the end of the list and add new node
        struct Node* temp = *head;

        while (temp->next != NULL) {
            temp = temp->next;
        }

        temp->next = newNode;
    }
}

void printList(struct Node* head) {
    while (head != NULL) {
        printf("%d ", head->data);
        head = head->next;
    }
}

void bucketSort(int arr[], int size) {
    // Create 10 buckets, Initialize with null head
    struct Node* buckets[BUCKET_SIZE];

    for (int i = 0; i < BUCKET_SIZE; i++) {
        buckets[i] = NULL;
    }

    // Add elements to their corresponding buckets
    for (int i = 0; i < size; i++) {
        int index = arr[i]/BUCKET_SIZE;

        addToList(&buckets[index], arr[i]);
    }

    // Traverse through all the buckets and sort each one
    for (int i = 0; i < BUCKET_SIZE; i++) {
        // Sort each bucket with insertion sort
        struct Node* head = buckets[i];
        struct Node* previous = NULL;
        struct Node* current = head;

        while (current != NULL) {
            if (previous != NULL && current->data < previous->data) {
                // Swap the two nodes
                struct Node* temp = current->next;
                previous->next = current->next;
                current->next = previous;

                // Update the pointers
                previous = current;
                current = temp;
            }
            else {
                previous = current;
                current = current->next;
            }
        }

        // Print sorted bucket
        printf("Bucket[%d]: ", i);
        printList(buckets[i]);
        printf("\n");
    }

    // Merge all buckets and update the original array
    int index = 0;

    for (int i = 0; i < BUCKET_SIZE; i++) {
        struct Node* head = buckets[i];

        while (head != NULL) {
            arr[index++] = head->data;
            head = head->next;
        }
    }
}

int main() {
    int arr[] = {27, 35, 12, 17, 18, 23, 44, 9, 58, 64, 24, 1};
    int size = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    printf("\n\nSorting Buckets: \n");
    bucketSort(arr, size);

    printf("\n\nSorted Array: ");

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}