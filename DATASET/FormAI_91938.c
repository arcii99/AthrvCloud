//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>

// Define the number of buckets
#define NUM_BUCKETS 10

// Define the node structure for the linked list
struct Node {
    int value;
    struct Node* next;
};

// Insert a value into the linked list at the correct position
void insert(struct Node** head, int value) {
    struct Node* newNode = (struct Node*) malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL || (*head)->value >= newNode->value) {
        newNode->next = *head;
        *head = newNode;
    } else {
        struct Node* current = *head;
        while (current->next != NULL && current->next->value < newNode->value) {
            current = current->next;
        }
        newNode->next = current->next;
        current->next = newNode;
    }
}

// Sort the array using bucket sort
void bucketSort(int array[], int size) {
    // Create the buckets as linked lists
    struct Node* buckets[NUM_BUCKETS] = {0};

    // Insert elements into buckets
    for (int i = 0; i < size; i++) {
        int bucketIndex = array[i] / NUM_BUCKETS;
        insert(&buckets[bucketIndex], array[i]);
    }

    // Merge the buckets back into the original array
    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            array[index++] = current->value;
            current = current->next;
        }
    }
}

// Print the array
void printArray(int array[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Test the bucket sort implementation
int main() {
    int array[] = {89, 36, 10, 22, 84, 17, 2, 31};
    int size = sizeof(array) / sizeof(array[0]);

    printf("Unsorted array: ");
    printArray(array, size);

    bucketSort(array, size);

    printf("Sorted array: ");
    printArray(array, size);

    return 0;
}