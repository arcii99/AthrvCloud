//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>

// Define bucket struct
typedef struct Bucket {
    int data;
    struct Bucket* next;
}Bucket;

// Define function to create a bucket
Bucket* createBucket(int data) {
    Bucket* newBucket = (Bucket*)malloc(sizeof(Bucket)); // allocate memory for new bucket
    newBucket->data = data;
    newBucket->next = NULL;

    return newBucket;
}

// Define function to insert data into a bucket
void bucketInsert(Bucket** arr, int index, int data) {
    Bucket* newBucket = createBucket(data); // create new bucket with specified data
    
    // If the bucket array is empty in the specified index, insert the new bucket as the first element
    if (arr[index] == NULL) {
        arr[index] = newBucket;
    }
    // If the bucket array is not empty in the specified index, add the new bucket to the beginning of the linked list
    else {
        newBucket->next = arr[index];
        arr[index] = newBucket;
    }
}

// Define function to sort each bucket separately using insertion sort
void insertionSort(Bucket* bucket) {
    Bucket* temp1 = bucket;
    Bucket* temp2;
    int key;

    while (temp1 != NULL) {
        key = temp1->data;
        temp2 = temp1->next;

        // Apply insertion sort
        while (temp2 != NULL && temp2->data < key) {
            temp1->data = temp2->data;
            temp2->data = key;
            temp1 = temp1->next;
            temp2 = temp1->next;
        }
        temp1->data = key;
        temp1 = temp1->next;
    }
}

// Define the bucket sort function
void bucketSort(int arr[], int n, int range) {
    Bucket** bucketArr = (Bucket**)malloc(range * sizeof(Bucket*)); // Allocate memory for bucket array
    int i, j, index;

    // Initialize each bucket to NULL
    for (i = 0; i < range; i++) {
        bucketArr[i] = NULL;
    }

    // Insert elements into the proper buckets based on their value
    for (i = 0; i < n; i++) {
        index = arr[i] / range;
        bucketInsert(bucketArr, index, arr[i]);
    }

    // Sort each bucket separately using insertion sort
    for (i = 0; i < range; i++) {
        if (bucketArr[i] != NULL) {
            insertionSort(bucketArr[i]);
        }
    }

    // Merge all the buckets back into the original array
    j = 0;
    for (i = 0; i < range; i++) {
        Bucket* temp = bucketArr[i];
        while (temp != NULL) {
            arr[j++] = temp->data;
            temp = temp->next;
        }
    }
}

// Main function for testing
int main() {
    int arr[] = {78, 17, 39, 26, 72, 94, 21, 12, 23, 68};
    int n = sizeof(arr) / sizeof(arr[0]);
    int range = 10; // the range of values that the elements can have

    printf("Unsorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    bucketSort(arr, n, range);

    printf("\nSorted Array:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}