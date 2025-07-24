//FormAI DATASET v1.0 Category: Sorting ; Style: complete
#include <stdio.h>

// function to swap two elements of an array
void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
 
// function to perform bubble sort on an array
void bubbleSort(int arr[], int n)
{
    for (int i = 0; i < n-1; i++)
    {
        // last i elements are already in place
        for (int j = 0; j < n-i-1; j++)
        {
            // if current element is greater than the next element, swap them
            if (arr[j] > arr[j+1])
            {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

// function to print an array
void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// main function
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted Array: ");
    printArray(arr, n);

    bubbleSort(arr, n);

    printf("Sorted Array: ");
    printArray(arr, n);

    return 0;
}