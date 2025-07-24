//FormAI DATASET v1.0 Category: Bucket Sort Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define SIZE 10
#define MAX 100

void bucketSort(int arr[], int n) 
{
    int i, j, k;
    int count[SIZE];
    memset(count, 0, sizeof(count));
  
    for (i = 0; i < n; ++i)
        ++count[arr[i]];
  
    for (i = 0, j = 0; i < SIZE; ++i)
        for (k = count[i]; k > 0; --k)
            arr[j++] = i;
}

int main() 
{
    int i;
    int arr[MAX];
    printf("Enter %d elements: ", MAX);
  
    for (i = 0; i < MAX; ++i)
        scanf("%d", &arr[i]);
  
    printf("\nInput array is: \n");
    for (i = 0; i < MAX; ++i)
        printf("%d ", arr[i]);
  
    bucketSort(arr, MAX);
  
    printf("\nOutput array is: \n");
    for (i = 0; i < MAX; ++i)
        printf("%d ", arr[i]);
  
    printf("\n");
    return 0;
}