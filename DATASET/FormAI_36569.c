//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define ARRAY_SIZE 10000
#define BUCKET_COUNT 10

typedef struct Node {
    int value;
    struct Node* next;
} Node;

void bucketSort(int* arr, int size);
void insert(Node** head, int value);
void paranoidFree(void* ptr);

int main() {
    srand(time(NULL));

    int arr[ARRAY_SIZE];

    // Populate array with random values
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        arr[i] = rand() % 1000;
    }

    // Sort array using bucket sort
    bucketSort(arr, ARRAY_SIZE);

    // Print sorted array
    for (int i = 0; i < ARRAY_SIZE; ++i) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}

// Sorts an array of integers using bucket sort
void bucketSort(int* arr, int size) {
    Node* buckets[BUCKET_COUNT] = { NULL };

    // Insert array elements into buckets
    for (int i = 0; i < size; ++i) {
        int index = (int)arr[i] / BUCKET_COUNT;
        insert(&buckets[index], arr[i]);
    }

    // Sort individual buckets using insertion sort
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        Node* current = buckets[i];
        Node* next;

        // Sort individual bucket using insertion sort
        while (current != NULL) {
            int value = current->value;
            int j = i - 1;
            next = current->next;

            while (j >= 0 && buckets[j] != NULL && value < buckets[j]->value) {
                buckets[j + 1] = buckets[j];
                --j;
            }

            if (j < 0) {
                buckets[0] = current;
            } else {
                buckets[j + 1] = current;
            }

            current->next = buckets[j + 1];
            current = next;
        }
    }

    // Create new array from sorted buckets
    int* tempArr = (int*)malloc(size * sizeof(int));
    if (tempArr == NULL) {
        paranoidFree(tempArr);
        return;
    }

    int j = 0;
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        Node* current = buckets[i];

        while (current != NULL) {
            tempArr[j] = current->value;
            current = current->next;
            ++j;
        }
    }

    // Copy sorted array back into original array
    for (int i = 0; i < size; ++i) {
        arr[i] = tempArr[i];
    }

    // Free memory for temp array and node
    paranoidFree(tempArr);
    for (int i = 0; i < BUCKET_COUNT; ++i) {
        Node* current = buckets[i];

        while (current != NULL) {
            Node* next = current->next;
            paranoidFree(current);
            current = next;
        }
    }
}

// Inserts a new element into the bucket
void insert(Node** head, int value) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    if (newNode == NULL) {
        paranoidFree(newNode);
        return;
    }

    newNode->value = value;
    newNode->next = *head;
    *head = newNode;
}

// A paranoid implementation of the free function
void paranoidFree(void* ptr) {
    if (ptr != NULL) {
        free(ptr);
        ptr = NULL;
    }
}