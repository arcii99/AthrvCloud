//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: systematic
#include <stdio.h>
#include <stdlib.h>

/* Function to sort an array using bucket sort */
void bucketSort(int arr[], int n, int k)
{
    int i,j;
    int *bucket=(int*)calloc((k+1), sizeof(int)); 

    /* Counting occurrence of each number in the array and storing it in the corresponding index of the bucket array */
    for (i = 0; i < n; i++) 
        bucket[arr[i]]++;

    /* Sorting the array by placing the elements in the correct order */
    for (i = 0,j=0; i <= k; i++) 
        while ((bucket[i]--) > 0) 
            arr[j++] = i;
}

/* Driver program to test above functions */
int main()
{
    int n, k, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the elements of the array:\n");
    for(i=0;i<n;i++)
      scanf("%d",&arr[i]);
    printf("Enter the range of numbers in the array (0 to k): ");
    scanf("%d",&k);
    bucketSort(arr, n, k); 
    printf("Sorted array is \n");
    for (i=0; i <n; i++)
        printf("%d ", arr[i]);
    printf("\n");
    return 0;
}