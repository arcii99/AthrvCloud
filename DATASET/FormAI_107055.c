//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: introspective
#include<stdio.h>
#include<stdlib.h>

// Function to find the maximum element in the array
int findMax(int arr[], int n){
    int max = arr[0];
    for(int i=1;i<n;i++){
        if(arr[i]>max){
            max = arr[i];
        }
    }
    return max;
}

// Function to perform Bucket Sort
void bucketSort(int arr[], int n){
    // Finding the maximum element in the array
    int max = findMax(arr, n);

    // Creating the buckets
    int numBuckets = max/10 + 1;
    int buckets[numBuckets][n];
    int bucketSizes[numBuckets];

    // Initializing bucket sizes to 0
    for(int i=0;i<numBuckets;i++){
        bucketSizes[i] = 0;
    }

    // Assigning elements to the respective buckets
    for(int i=0;i<n;i++){
        int bucketIndex = arr[i]/10;
        buckets[bucketIndex][bucketSizes[bucketIndex]] = arr[i];
        bucketSizes[bucketIndex]++;
    }

    // Sorting each bucket individually using Insertion Sort
    for(int i=0;i<numBuckets;i++){
        for(int j=1;j<bucketSizes[i];j++){
            int key = buckets[i][j];
            int k = j-1;
            while(k>=0 && buckets[i][k]>key){
                buckets[i][k+1] = buckets[i][k];
                k--;
            }
            buckets[i][k+1] = key;
        }
    }

    // Concatenating all the sorted buckets into the original array
    int index=0;
    for(int i=0;i<numBuckets;i++){
        for(int j=0;j<bucketSizes[i];j++){
            arr[index] = buckets[i][j];
            index++;
        }
    }
}

// Function to print the array
void printArray(int arr[], int n){
    for(int i=0;i<n;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Main Function
int main(){
    int arr[] = {68, 42, 63, 12, 95, 34, 67, 88, 45, 23, 90, 2, 54, 78, 11};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    printArray(arr, n);

    bucketSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}