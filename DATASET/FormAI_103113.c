//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: synchronous
#include<stdio.h>
#include<stdlib.h>

void bucketSort(int array[], int n)
{
    int i, j;
    int count[n]; // count array
    for (i = 0; i < n; i++)
        count[i] = 0;
 
    for (i = 0; i < n; i++)
        (count[array[i]])++;
 
    for (i = 0, j = 0; i < n; i++) 
        for(; count[i] > 0; (count[i])--)
            array[j++] = i;
}
 
int main()
{
    int array[] = {48, 45, 21, 35, 6, 34, 1, 22, 17, 17};
    int n = sizeof(array)/sizeof(array[0]);
    bucketSort(array, n);
 
    printf("Sorted array is \n");
    for (int i=0; i<n; i++)
        printf("%d ",array[i]);
    return 0;
}