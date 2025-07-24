//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: safe
#include<stdio.h>
#include<stdlib.h>
#define MAX 1000000

void printArray(int arr[], int n){
    for(int i=0; i<n; i++) printf("%d  ",arr[i]);
}

void bucketSort(int arr[], int n){
    int i,j;
    int *bucket = (int*)malloc(sizeof(int)*MAX);

    //initialize the bucket count array
    for(i=0; i<MAX; i++) bucket[i] = 0;

    //fill the bucket with appropriate items frequency
    for(i=0; i<n; i++) bucket[arr[i]]++;

    //fill the array with sorted items
    for(i=0,j=0; i<MAX; i++){
        while(bucket[i]>0){
            arr[j++] = i;
            bucket[i]--;
        }
    }
}

int main(){
    int n, arr[MAX], i;
    printf("\nEnter the number of elements in the array: ");
    scanf("%d",&n);
    printf("\nEnter the array elements: ");
    for(i=0; i<n; i++) scanf("%d",&arr[i]);
    printf("\nElements before sorting: ");
    printArray(arr, n);
    bucketSort(arr, n);
    printf("\nElements after sorting: ");
    printArray(arr, n);

    return 0;
}