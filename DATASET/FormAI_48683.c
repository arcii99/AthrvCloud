//FormAI DATASET v1.0 Category: Sorting ; Style: unmistakable
#include <stdio.h>
#include <stdlib.h>

void printArray(int arr[], int size);
void bubbleSort(int arr[], int size);
void insertionSort(int arr[], int size);
void selectionSort(int arr[], int size);
void merge(int arr[], int left[], int leftSize, int right[], int rightSize);
void mergeSort(int arr[], int size);
void quickSort(int arr[], int left, int right);

int main() {
    int arr[] = { 4, 6, 2, 7, 1, 3, 5};
    int size = sizeof(arr)/sizeof(arr[0]);
    
    printf("Unsorted array: ");
    printArray(arr, size);
    
    bubbleSort(arr, size);
    printf("\nBubble sorted array: ");
    printArray(arr, size);
    
    int arr2[] = { 4, 6, 2, 7, 1, 3, 5};
    insertionSort(arr2, size);
    printf("\nInsertion sorted array: ");
    printArray(arr2, size);
    
    int arr3[] = { 4, 6, 2, 7, 1, 3, 5};
    selectionSort(arr3, size);
    printf("\nSelection sorted array: ");
    printArray(arr3, size);
    
    int arr4[] = { 4, 6, 2, 7, 1, 3, 5};
    mergeSort(arr4, size);
    printf("\nMerge sorted array: ");
    printArray(arr4, size);
    
    int arr5[] = { 4, 6, 2, 7, 1, 3, 5};
    quickSort(arr5, 0, size-1);
    printf("\nQuick sorted array: ");
    printArray(arr5, size);

    return 0;
}

void printArray(int arr[], int size) {
    for(int i = 0; i < size; i++) {
        printf("%d", arr[i]);
        if(i != size-1) printf(", ");
    }
}

void bubbleSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        for(int j=0; j<size-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertionSort(int arr[], int size) {
    for(int i=1; i<size; i++) {
        int j=i-1, key=arr[i];
        while(j>=0 && arr[j]>key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void selectionSort(int arr[], int size) {
    for(int i=0; i<size-1; i++) {
        int minIndex = i;
        for(int j=i+1; j<size; j++) {
            if(arr[j] < arr[minIndex]) minIndex = j;
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i=0, j=0, k=0;
    while(i < leftSize && j < rightSize) {
        if(left[i] < right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }
    while(i < leftSize) {
        arr[k++] = left[i++];
    }
    while(j < rightSize) {
        arr[k++] = right[j++];
    }
}

void mergeSort(int arr[], int size) {
    if(size > 1) {
        int mid = size/2;
        int left[mid], right[size-mid];
        for(int i=0; i<mid; i++) {
            left[i] = arr[i];
        }
        for(int i=mid; i<size; i++) {
            right[i-mid] = arr[i];
        }
        mergeSort(left, mid);
        mergeSort(right, size-mid);
        merge(arr, left, mid, right, size-mid);
    }
}

void quickSort(int arr[], int left, int right) {
    if(left < right) {
        int pivot = arr[left];
        int i = left, j = right;
        while(i < j) {
            while(arr[i] <= pivot && i < right) i++;
            while(arr[j] > pivot) j--;
            if(i < j) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[left];
        arr[left] = arr[j];
        arr[j] = temp;
        quickSort(arr, left, j-1);
        quickSort(arr, j+1, right);
    }
}