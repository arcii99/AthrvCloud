//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include<stdio.h>

// This program sorts an array of integers using quicksort algorithm

void quicksort(int arr[], int low, int high){
    if(low < high){
        int pivotIndex = low;
        int i;
        for(i = low + 1; i <= high; i++){
            if(arr[i] < arr[low]){
                pivotIndex++;
                int temp = arr[i];
                arr[i] = arr[pivotIndex];
                arr[pivotIndex] = temp;
            }
        }
        int temp = arr[low];
        arr[low] = arr[pivotIndex];
        arr[pivotIndex] = temp;
        quicksort(arr, low, pivotIndex - 1);  // Sort the left partition
        quicksort(arr, pivotIndex + 1, high); // Sort the right partition
    }
}

int main(){
    int arr[10] = {5, 9, 3, 4, 1, 8, 6, 7, 2, 0};
    printf("Unsorted array: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    quicksort(arr, 0, 9);
    printf("Sorted array: ");
    for(int i = 0; i < 10; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}