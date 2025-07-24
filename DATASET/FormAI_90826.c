//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complex
#include <stdio.h>

#define ARRAY_SIZE 5000000 // size of array to be sorted
#define MAX_RANDOM_NUMBER 1000 // max random number to be generated

// function to generate random numbers
int generateRandomNumber() {
    return rand() % MAX_RANDOM_NUMBER;
}

// function to print the array
void printArray(int arr[]) {
    for(int i=0; i<ARRAY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// function to merge two subarrays of the main array
void merge(int arr[], int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;
  
    // temporary arrays
    int L[n1], R[n2];
  
    // copying data to the temporary arrays
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];
  
    i = 0;
    j = 0;
    k = l;
  
    // merging the temporary arrays back into the main array
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
  
    // copying the remaining elements of L[]
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
  
    // copying the remaining elements of R[]
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// function for merge sort
void mergeSort(int arr[], int l, int r) {
    if (l < r) {
        // finding the middle point of the array
        int m = l+(r-l)/2;
  
        // sorting the first half of the array
        mergeSort(arr, l, m);
        // sorting the second half of the array
        mergeSort(arr, m+1, r);
  
        // merging the sorted halves
        merge(arr, l, m, r);
    }
}

// main function
int main() {
    // initializing array
    int arr[ARRAY_SIZE];
  
    // generating random numbers and filling array
    for(int i=0; i<ARRAY_SIZE; i++) {
        arr[i] = generateRandomNumber();
    }

    // printing unsorted array
    printf("Unsorted array:\n");
    printArray(arr);

    // sorting the array using merge sort
    mergeSort(arr, 0, ARRAY_SIZE-1);

    // printing sorted array
    printf("Sorted array:\n");
    printArray(arr);

    return 0;
}