//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: high level of detail
#include <stdio.h>
#include <stdlib.h>

#define NUM_BUCKETS 10

// Node for a linked list
typedef struct Node {
    int value;
    struct Node* next;
} Node;

// Function to insert a value into a linked list
void insertValue(Node** head, int value) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
        return;
    }

    Node* current = *head;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = newNode;
}

// Function to sort a bucket using insertion sort
void sortBucket(int index, int* array, int size, Node** buckets) {
    for (int i = 1; i < size; i++) {
        int key = array[i];
        int j = i - 1;
        while (j >= 0 && array[j] > key) {
            array[j + 1] = array[j];
            j--;
        }
        array[j + 1] = key;
    }

    Node* current = buckets[index];
    for (int i = 0; i < size; i++) {
        current->value = array[i];
        if (i < size - 1) {
            current->next = (Node*) malloc(sizeof(Node));
            current = current->next;
        }
    }
}

// Function to perform bucket sort
void bucketSort(int* array, int size) {
    Node* buckets[NUM_BUCKETS];

    for (int i = 0; i < NUM_BUCKETS; i++) {
        buckets[i] = (Node*) malloc(sizeof(Node));
    }

    int max = array[0];
    for (int i = 1; i < size; i++) {
        if (array[i] > max) {
            max = array[i];
        }
    }

    for (int i = 0; i < size; i++) {
        int index = array[i] / (max / NUM_BUCKETS + 1);
        insertValue(&buckets[index], array[i]);
    }

    for (int i = 0; i < NUM_BUCKETS; i++) {
        int bucketSize = 0;
        Node* current = buckets[i];
        while (current->next != NULL) {
            current = current->next;
            bucketSize++;
        }
        int bucketArray[bucketSize];
        current = buckets[i];
        for (int j = 0; j < bucketSize; j++) {
            bucketArray[j] = current->value;
            current = current->next;
        }
        sortBucket(i, bucketArray, bucketSize, buckets);
    }

    int index = 0;
    for (int i = 0; i < NUM_BUCKETS; i++) {
        Node* current = buckets[i];
        while (current->next != NULL) {
            array[index++] = current->value;
            current = current->next;
        }
    }

    for (int i = 0; i < NUM_BUCKETS; i++) {
        free(buckets[i]);
    }
}

// Function to print an array
void printArray(int* array, int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");
}

// Main function
int main() {
    int array[] = {5, 3, 2, 8, 9, 2, 2, 4};
    int size = sizeof(array) / sizeof(int);

    printf("Original array: ");
    printArray(array, size);

    bucketSort(array, size);

    printf("Sorted array: ");
    printArray(array, size);

    return 0;
}