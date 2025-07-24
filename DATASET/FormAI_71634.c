//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>

// Define the maximum range of the numbers to be sorted
#define MAX 100

// Define the number of buckets to be used
#define BUCKET_NUM 10

// A structure to represent the buckets
typedef struct Node {
    int val;
    struct Node* next;
} Node;

// Function to insert a node into a bucket
void insert(Node** head, int val) {
    Node* newNode = (Node*) malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;

    if (*head == NULL) {
        *head = newNode;
    } else {
        Node* curr = *head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = newNode;
    }
}

// Function to print the sorted array
void printArr(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Function to perform the bucket sort algorithm
void bucketSort(int arr[], int size) {
    Node* buckets[BUCKET_NUM];
    for (int i = 0; i < BUCKET_NUM; i++) {
        buckets[i] = NULL;
    }

    // Insert elements into the buckets
    for (int i = 0; i < size; i++) {
        int bucketIdx = arr[i] / (MAX / BUCKET_NUM);
        insert(&buckets[bucketIdx], arr[i]);
    }

    // Sort each bucket and merge them
    int idx = 0;
    for (int i = 0; i < BUCKET_NUM; i++) {
        Node* curr = buckets[i];

        // Sort the bucket using insertion sort
        int bucketSize = 0;
        while (curr != NULL) {
            bucketSize++;
            curr = curr->next;
        }

        int bucketArr[bucketSize];
        curr = buckets[i];
        for (int j = 0; j < bucketSize; j++) {
            bucketArr[j] = curr->val;
            curr = curr->next;
        }

        for (int j = 1; j < bucketSize; j++) {
            int key = bucketArr[j];
            int k = j - 1;
            while (k >= 0 && bucketArr[k] > key) {
                bucketArr[k+1] = bucketArr[k];
                k--;
            }
            bucketArr[k+1] = key;
        }

        // Merge the sorted bucket back into the main array
        for (int j = 0; j < bucketSize; j++) {
            arr[idx++] = bucketArr[j];
        }
    }
}

int main() {
    // Generate a random array of integers
    int size = 20;
    int arr[size];
    printf("Original array: ");
    for (int i = 0; i < size; i++) {
        arr[i] = rand() % MAX;
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Perform the bucket sort algorithm
    bucketSort(arr, size);

    // Print the sorted array
    printf("Sorted array: ");
    printArr(arr, size);

    return 0;
}