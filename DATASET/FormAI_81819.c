//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: intelligent
#include <stdio.h>
#include <stdlib.h>

// Define the bucket data structure
typedef struct Bucket{
    int value;
    struct Bucket* next;
}Bucket;

// Function that inserts an element to a bucket list, sorted in ascending order
void insertElement(Bucket** head, int val){
    Bucket* newBucket = (Bucket*)malloc(sizeof(Bucket));
    newBucket->value = val;

    // If the list is empty or the first element is greater than the value, insert at the beginning
    if(*head == NULL || (*head)->value >= newBucket->value){
        newBucket->next = *head;
        *head = newBucket;
    }
    else{
        Bucket* current = *head;

        // Find the correct position to insert the element
        while(current->next != NULL && current->next->value < newBucket->value){
            current = current->next;
        }

        // Insert the element
        newBucket->next = current->next;
        current->next = newBucket;
    }
}

// Function that performs bucket sort
void bucketSort(int arr[], int n, int numOfBuckets){
    // Create the buckets
    Bucket** buckets = (Bucket**)malloc(numOfBuckets * sizeof(Bucket*));
    for(int i = 0; i < numOfBuckets; i++){
        buckets[i] = NULL;
    }

    // Insert the elements into the correct buckets
    for(int i = 0; i < n; i++){
        int bucketIndex = arr[i] / numOfBuckets;
        insertElement(&buckets[bucketIndex], arr[i]);
    }

    // Merge the buckets into the output array
    int index = 0;
    for(int i = 0; i < numOfBuckets; i++){
        Bucket* current = buckets[i];
        while(current != NULL){
            arr[index++] = current->value;
            current = current->next;
        }
    }
}

// Function that prints an array
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[] = {29, 13, 22, 37, 45, 3, 10, 15};
    int n = sizeof(arr) / sizeof(arr[0]);
    int numOfBuckets = 5;

    printf("Before sorting: ");
    printArray(arr, n);

    bucketSort(arr, n, numOfBuckets);

    printf("After sorting: ");
    printArray(arr, n);

    return 0;
}