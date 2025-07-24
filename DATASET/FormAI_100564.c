//FormAI DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
#include<stdio.h>
#include<stdlib.h>

#define MAX 100 //Maximum number of elements that can be sorted

void selection_sort(int arr[], int n) {
    int i, j, min_idx, temp;
  
    //One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++) {
        //Find the minimum element in unsorted array
        min_idx = i;
        for (j = i+1; j < n; j++)
            if (arr[j] < arr[min_idx])
                min_idx = j;
        //Swap the found minimum element with the first element
        temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}

int main()
{
    int arr[MAX], i, n;

    printf("Enter array size: ");
    scanf("%d",&n);

    printf("Enter %d elements:\n",n);
    for(i=0;i<n;i++)
        scanf("%d",&arr[i]);

    printf("\nOriginal array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    selection_sort(arr, n);

    printf("\nSorted array:\n");
    for(i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}