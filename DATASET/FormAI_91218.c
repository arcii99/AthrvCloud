//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: modular
#include<stdio.h>
#include<stdlib.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bucketSort(int arr[], int n, int max){
    int i, j;
    int *bucket = (int*) malloc(sizeof(int) * max);
    
    for(i = 0; i < max; i++)
        bucket[i] = 0;
        
    for(i = 0; i < n; i++)
        bucket[arr[i]]++;
        
    for(i = 0, j = 0; i < max; i++)
        while(bucket[i] > 0){
            arr[j++] = i;
            bucket[i]--;
        }
}

int main(){
    int arr[] = {9,3,7,4,6,1,5,8,2,0};
    int n = sizeof(arr) / sizeof(arr[0]);
    int max = 0;
    int i;
    for (i = 0; i < n; i++)
        if(arr[i] > max)
            max = arr[i];
    printf("Before Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    bucketSort(arr, n, max);
    
    printf("\n\nAfter Sorting: ");
    for(i = 0; i < n; i++)
        printf("%d ", arr[i]);
        
    return 0;
}