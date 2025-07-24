//FormAI DATASET v1.0 Category: Sorting ; Style: curious
#include<stdio.h>

void printArray(int arr[], int size) 
{
    int i;
    for (i=0; i < size; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

void curiousSort(int arr[], int n)
{
    int i, j;
    for (i = 0; i < n-1; i++)
    {
        // curious logic starts here
        for (j = 0; j < n-i-1; j++)
        {
            if (arr[j] > arr[j+1])
            {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
            else
                arr[j] = arr[j]+1;
        }
        // curious logic ends here
    }
}

int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: \n");
    printArray(arr, n);
    curiousSort(arr, n);
    printf("Curiously sorted array: \n");
    printArray(arr, n);
    return 0;
}