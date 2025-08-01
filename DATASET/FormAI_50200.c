//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include<stdio.h>

//Recursive function to merge the subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    // Create temporary arrays 
    int L[n1], R[n2];
 
    //Copy data to temporary arrays L[] and R[]
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1+ j];
 
    // Merge the temporary arrays back into arr[left...right]
    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    // Copy the remaining elements of L[]
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    // Copy the remaining elements of R[]
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}
 
// This will sort the array recursively from left to right
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
 
        // Sort first and second halves
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
 
        // Merge the sorted halves
        merge(arr, left, mid, right);
    }
}

int main()
{
    int arr[] = {6, 1, 9, 4, 2, 5, 3, 8, 7};
    int n = sizeof(arr)/sizeof(arr[0]);
 
    printf("Before Sorting: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }

    mergeSort(arr, 0, n - 1);
 
    printf("\n\nAfter Sorting: ");
    for(int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    return 0;
}