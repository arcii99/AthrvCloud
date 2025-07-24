//FormAI DATASET v1.0 Category: Sorting ; Style: real-life
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10

void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void selectionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void swap(int *a, int *b);

int main() {
    int arr[SIZE];
    srand(time(NULL));
    
    // Generate random values between 0-99 for array
    for (int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }
    
    printf("Initial Array: ");
    printArray(arr, SIZE);
    
    // Sort array using Bubble Sort
    bubbleSort(arr, SIZE);
    printf("\nBubble Sort: ");
    printArray(arr, SIZE);
    
    // Sort array using Insertion Sort
    insertionSort(arr, SIZE);
    printf("\nInsertion Sort: ");
    printArray(arr, SIZE);
    
    // Sort array using Selection Sort
    selectionSort(arr, SIZE);
    printf("\nSelection Sort: ");
    printArray(arr, SIZE);
    
    // Sort array using Merge Sort
    mergeSort(arr, 0, SIZE-1);
    printf("\nMerge Sort: ");
    printArray(arr, SIZE);
    
    // Sort array using Quick Sort
    quickSort(arr, 0, SIZE-1);
    printf("\nQuick Sort: ");
    printArray(arr, SIZE);
    
    return 0;
}

void printArray(int arr[], int size) {
    printf("[");
    for (int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if (i != size-1) {
            printf(", ");
        }
    }
    printf("]");
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        for (int j = 0; j < size-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for (int i = 1; i < size; i++) {
        int key = arr[i];
        int j = i-1;
        while (j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int size) {
    for (int i = 0; i < size-1; i++) {
        int min_idx = i;
        for (int j = i+1; j < size; j++) {
            if (arr[j] < arr[min_idx]) {
                min_idx = j;
            }
        }
        swap(&arr[i], &arr[min_idx]);
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right-left)/2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
 
    int L[n1], R[n2];
 
    for (i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];
 
    i = 0;
    j = 0;
    k = left;
    
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
 
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pi = partition(arr, left, right);
        quickSort(arr, left, pi-1);
        quickSort(arr, pi+1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;

    for (int j = left; j < right; j++) {
        if (arr[j] <= pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[right]);
    return i+1;
}

void swap(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}