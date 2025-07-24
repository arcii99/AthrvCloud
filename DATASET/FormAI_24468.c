//FormAI DATASET v1.0 Category: Sorting ; Style: innovative
#include <stdio.h>

void merge(int arr[], int left, int mid, int right) { 
    int i, j, k; 
    int n1 = mid - left + 1; 
    int n2 =  right - mid; 
  
    // create temp arrays
    int L[n1], R[n2]; 
    for (i = 0; i < n1; i++) 
        L[i] = arr[left + i]; 
    for (j = 0; j < n2; j++) 
        R[j] = arr[mid + 1+ j]; 
  
    // Merge the temp arrays back into arr[left..right]
    i = 0; // Initial index of first subarray 
    j = 0; // Initial index of second subarray 
    k = left; // Initial index of merged subarray 
    while (i < n1 && j < n2) { 
        if (L[i] <= R[j]) { 
            arr[k] = L[i]; 
            i++; 
        } 
        else { 
            arr[k] = R[j]; 
            j++; 
        } 
        k++; 
    } 
  
    // Copy the remaining elements of L[], if there are any
    while (i < n1) { 
        arr[k] = L[i]; 
        i++; 
        k++; 
    } 
  
    // Copy the remaining elements of R[], if there are any
    while (j < n2) { 
        arr[k] = R[j]; 
        j++; 
        k++; 
    } 
} 

void mergeSort(int arr[], int left, int right) {
    if (left < right) { 
        int mid = left + (right - left) / 2; 
  
        // Sort first and second halves
        mergeSort(arr, left, mid); 
        mergeSort(arr, mid+1, right); 
  
        merge(arr, left, mid, right); 
    } 
} 

int main() {
    int arr[] = {38, 27, 43, 3, 9, 82, 10}; 
    int arr_size = sizeof(arr) / sizeof(arr[0]); 
  
    printf("Unsorted array: \n"); 
    for (int i = 0; i < arr_size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
  
    mergeSort(arr, 0, arr_size - 1); 
  
    printf("Sorted array: \n"); 
    for (int i = 0; i < arr_size; i++) 
        printf("%d ", arr[i]); 
    printf("\n"); 
    
    return 0;
}