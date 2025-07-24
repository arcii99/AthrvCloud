//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: innovative
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define SIZE 10 //Size of the Array
#define MAX 100 //Maximum Value in Array
#define BUCKETS 5 //Number of Buckets

void printArray(int arr[], int n) {
    printf("[ ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

void bucketSort(int arr[], int n) {
    int i, j, k;
    int min = arr[0];
    int max = arr[0];
    int range;
    float temp;

    for(i=0; i<n; i++) {
        if(arr[i] < min)
            min = arr[i];
        else if(arr[i] > max)
            max = arr[i];
    }

    range = (max - min)/BUCKETS + 1;
    int buckets[BUCKETS][SIZE], bucketIndex[BUCKETS];
    for(i=0; i<BUCKETS; i++) {
        bucketIndex[i] = 0;
    }

    for(i=0; i<n; i++) {
        int bucketPos = (int)((arr[i] - min)/range);
        if(bucketPos >= BUCKETS)
            bucketPos = BUCKETS-1;
        buckets[bucketPos][bucketIndex[bucketPos]] = arr[i];
        bucketIndex[bucketPos]++;
    }

    k = 0;
    for(i=0; i<BUCKETS; i++) {
        for(j=0; j<bucketIndex[i]; j++) {
            arr[k] = buckets[i][j];
            k++;
        }
    }
}

int main() {
    srand(time(0)); //Set random seed
    int arr[SIZE];
    printf("Array before sorting: ");
    for(int i=0; i<SIZE; i++) {
        arr[i] = rand() % MAX; //Generate random numbers between 0 and MAX
    }
    printArray(arr, SIZE);
    bucketSort(arr, SIZE);
    printf("Array after sorting: ");
    printArray(arr, SIZE);
    return 0;
}