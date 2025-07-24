//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: random
#include<stdio.h>

void bucketSort(int arr[], int n){
    int i,j;
    int count[n];
    for (i=0; i < n; i++)
        count[i] = 0;
 
    for (i=0; i < n; i++)
        (count[arr[i]])++;
 
    for (i=0,j=0; i < n; i++)   
        for (; count[i]>0; (count[i])--)
            arr[j++] = i;
}

int main(){
    int arr[] = { 4, 1, 7, 5, 3, 2, 6, 10, 8, 9 };
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;
    printf("Before sorting:\n");
    for(i=0;i<n;i++)
        printf("%d ", arr[i]);
    printf("\n");
    bucketSort(arr, n);
    printf("After sorting:\n");
    for (i=0; i < n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}