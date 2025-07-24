//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: single-threaded
#include<stdio.h>
#include<stdlib.h>

void bucketSort(float arr[], int n) 
{ 
    int i, j; 
    float *bucket; 
    bucket = (float*) malloc(n * sizeof(float)); 

    for(i=0; i < n; i++) 
        bucket[i] = 0.0; 

  for(i=0; i < n; i++) 
        ++bucket[(int)(arr[i])]; 

  for(i=0,j=0; i < n; i++) 
        for(; bucket[i]>0;(bucket[i])--) 
            arr[j++]=i; 

  free(bucket); 

} 

int main() 
{ 
    float arr[] = {0.343, 0.243, 0.083, 0.643, 0.643, 0.883};

    int n = sizeof(arr)/sizeof(arr[0]); 
    bucketSort(arr,n);

    printf("Sorted array is \n"); 
    for(int i=0; i<n; i++) 
        printf("%f ",arr[i]); 

    return 0; 
}