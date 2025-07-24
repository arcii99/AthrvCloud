//FormAI DATASET v1.0 Category: Sorting ; Style: sophisticated
#include<stdio.h>

// Function to swap two elements
void swap(int* a, int* b){
  int temp = *a;
  *a = *b;
  *b = temp;
}

// Function to perform Insertion Sort on an array
void insertionSort(int arr[], int n){
  int i, key, j;
  for (i = 1; i < n; i++){
    key = arr[i];
    j = i - 1;

    // Move elements of arr[0..i-1], that are
    // greater than key, to one position ahead
    // of their current position
    while (j >= 0 && arr[j] > key){
      arr[j + 1] = arr[j];
      j = j - 1;
    }
    arr[j + 1] = key;
  }
}

// Function to perform Selection Sort on an array
void selectionSort(int arr[], int n){
  int i, j, min_idx;

  // One by one move boundary of unsorted subarray
  for (i = 0; i < n-1; i++){
    // Find the minimum element in unsorted array
    min_idx = i;
    for (j = i+1; j < n; j++)
      if (arr[j] < arr[min_idx])
        min_idx = j;

    // Swap the found minimum element with the first element
    swap(&arr[min_idx], &arr[i]);
  }
}

// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int n){
  int i, j;
  for (i = 0; i < n-1; i++)
    // Last i elements are already in place
    for (j = 0; j < n-i-1; j++)
      if (arr[j] > arr[j+1])
        swap(&arr[j], &arr[j+1]);
}

// Main function to test the above sorting functions
int main()
{
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Original Array: ");
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n\nSorted Array Using INSERTION SORT: ");
    insertionSort(arr, n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n\nSorted Array Using SELECTION SORT: ");
    selectionSort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    printf("\n\nSorted Array Using BUBBLE SORT: ");
    bubbleSort(arr,n);
    for(int i=0;i<n;i++)
        printf("%d ",arr[i]);

    return 0;
}