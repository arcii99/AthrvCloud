//FormAI DATASET v1.0 Category: Sorting ; Style: recursive
#include <stdio.h>

void selectionSort(int arr[], int i, int n);
int indexOfMinimum(int arr[], int i, int n);

int main() {
  int arr[] = {64, 25, 12, 22, 11};
  int n = sizeof(arr) / sizeof(arr[0]);

  selectionSort(arr, 0, n-1);

  printf("Sorted array: \n");
  for (int i=0; i < n; i++)
    printf("%d ", arr[i]);
  printf("\n");

  return 0;
}

void selectionSort(int arr[], int i, int n){
    if(i<n){
        int minIndex = indexOfMinimum(arr, i, n);
        int temp=0;
        temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
        selectionSort(arr, i+1, n);
    }
}

int indexOfMinimum(int arr[], int i, int n){
    int minIndex=i;
    for(; i<=n;i++){
        if(arr[i]<arr[minIndex]){
            minIndex=i;
        }
    }
    return minIndex;
}