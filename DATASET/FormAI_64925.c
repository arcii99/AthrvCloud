//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: creative
#include <stdio.h>

#define SIZE 10

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int j = i;
        while(j > 0 && arr[j] < arr[j - 1]){
            swap(&arr[j], &arr[j - 1]);
            j--;
        }
    }
}

void bucketSort(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    int numBuckets = max / SIZE + 1;
    int** buckets = (int**) malloc(sizeof(int*) * numBuckets);
    for(int i = 0; i < numBuckets; i++){
        buckets[i] = (int*) malloc(sizeof(int) * SIZE);
    }
    for(int i = 0; i < numBuckets; i++){
        int* bucket = buckets[i];
        for(int j = 0; j < SIZE; j++){
            bucket[j] = 0;
        }
    }
    for(int i = 0; i < n; i++){
        int bucketIndex = arr[i] / SIZE;
        int* bucket = buckets[bucketIndex];
        int j = 0;
        while(j < SIZE && bucket[j] != 0 && bucket[j] < arr[i]){
            j++;
        }
        for(int k = SIZE - 1; k > j; k--){
            bucket[k] = bucket[k - 1];
        }
        bucket[j] = arr[i];
    }
    int index = 0;
    for(int i = 0; i < numBuckets; i++){
        int* bucket = buckets[i];
        insertionSort(bucket, SIZE);
        for(int j = 0; j < SIZE; j++){
            arr[index] = bucket[j];
            index++;
        }
    }
    for(int i = 0; i < numBuckets; i++){
        free(buckets[i]);
    }
    free(buckets);
}

int main(){
    int arr[] = {47, 89, 27, 10, 3, 59, 67, 99, 31, 78};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Unsorted Array:\n");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("Sorted Array:\n");
    printArray(arr, n);
    return 0;
}