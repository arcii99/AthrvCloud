//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: enthusiastic
#include<stdio.h>
#define MAX 1000 // Defining constant MAX as 1000
 
void selectionSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        int min_idx = i;
        for (int j = i+1; j < n; j++)
          if (arr[j] < arr[min_idx])
            min_idx = j;
        int temp = arr[min_idx];
        arr[min_idx] = arr[i];
        arr[i] = temp;
    }
}
 
void printArray(int arr[], int size)
{
    for (int i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}
 
int main()
{
    int arr[MAX], n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    printf("Enter the array elements:\n");
    for(int i=0;i<n;i++)
        scanf("%d", &arr[i]);
    printf("\n");
    printf("Before Sorting: ");
    printArray(arr, n);
    selectionSort(arr, n);
    printf("After Sorting: ");
    printArray(arr, n);
    return 0;
}