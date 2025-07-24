//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

#define SIZE 10

struct Bucket {
    float value;
    struct Bucket* next;
};

struct Bucket* createBucket(float value) {
    struct Bucket* bucket = (struct Bucket*) malloc(sizeof(struct Bucket));
    bucket->value = value;
    bucket->next = NULL;
    return bucket;
}

void insert(struct Bucket** bucketArray, float value, int index) {
    if(bucketArray[index] == NULL) {
        bucketArray[index] = createBucket(value);
    } else {
        struct Bucket* prev = NULL;
        struct Bucket* current = bucketArray[index];
        while(current != NULL && current->value < value) {
            prev = current;
            current = current->next;
        }
        if(prev == NULL) {
            struct Bucket* newBucket = createBucket(value);
            newBucket->next = current;
            bucketArray[index] = newBucket;
        } else {
            struct Bucket* newBucket = createBucket(value);
            newBucket->next = prev->next;
            prev->next = newBucket;
        }
    }
}

void bucketSort(float arr[], int n) {
    struct Bucket* bucketArray[n];
    for(int i = 0; i < n; i++) {
        bucketArray[i] = NULL;
    }
    for(int i = 0; i < n; i++) {
        int index = (int) arr[i] * n;
        insert(bucketArray, arr[i], index);
    }
    int j = 0;
    for(int i = 0; i < n; i++) {
        struct Bucket* currentBucket = bucketArray[i];
        while(currentBucket != NULL) {
            arr[j++] = currentBucket->value;
            currentBucket = currentBucket->next;
        }
    }
}

int main() {
    float arr[SIZE] = {0.53, 0.71, 0.22, 0.88, 0.34, 0.92, 0.79, 0.91, 0.42, 0.61};

    printf("Unsorted array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%.2f ", arr[i]);
    }
    
    bucketSort(arr, SIZE);

    printf("\nSorted array: ");
    for(int i = 0; i < SIZE; i++) {
        printf("%.2f ", arr[i]);
    }

    return 0;
}