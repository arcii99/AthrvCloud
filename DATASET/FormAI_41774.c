//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: peaceful
#include <stdio.h>

void bucketSort(int arr[], int n) 
{ 
    int i, j; 
    int count[n]; 
    for (i = 0; i < n; i++) 
        count[i] = 0; 

    for (i = 0; i < n; i++) 
        (count[arr[i]])++; 

    for (i = 0, j = 0; i < n; i++) 
        for (; count[i]>0; (count[i])--) 
            arr[j++] = i; 
} 

void printArray(int arr[], int n) 
{ 
    int i; 
    for (i = 0; i < n; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
} 

int main() 
{ 
    int arr[] = {10, 15, 4, 56, 23, 27, 15, 16, 30, 45, 17}; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Input Array:\n"); 
    printArray(arr, n); 

    bucketSort(arr, n); 

    printf("Output Array:\n"); 
    printArray(arr, n); 
    return 0; 
}