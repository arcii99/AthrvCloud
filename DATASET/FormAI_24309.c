//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include <stdio.h>
#include <stdlib.h>

void bucketSort(float arr[], int n) {

    //Create n buckets
    int i, j;
    int count[n];
    for(i = 0; i < n; i++)
        count[i] = 0;

    //Count the elements in each bucket
    for(i = 0; i < n; i++) {
        int bucket = n*arr[i];
        count[bucket]++;
    }

    //Sort each bucket
    for(i = 0; i < n; i++) {
        int bucket = n*arr[i];

        //Insertion sort
        for(j = count[bucket]-2; j >= 0 && arr[i] < arr[j]; j--) {
            float temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }
        count[bucket]--;
    }
}

int main() {

    printf("Welcome to my unique C bucket sort implementation!\n\n");

    //Create an array of floats
    float arr[] = {0.34, 0.56, 0.23, 0.12, 0.98, 0.87, 0.43, 0.65, 0.21, 0.78};

    //Print the unsorted array
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: ");
    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    //Sort the array using bucket sort
    bucketSort(arr, n);

    //Print the sorted array
    printf("Sorted array: ");
    for(int i = 0; i < n; i++)
        printf("%.2f ", arr[i]);
    printf("\n");

    return 0;
}