//FormAI DATASET v1.0 Category: Sorting ; Style: Dennis Ritchie
/* A unique C Sorting program */
#include <stdio.h>

void swap(int *a, int *b);
void bubbleSort(int arr[], int n);
void selectionSort(int arr[], int n);
void insertionSort(int arr[], int n);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);

int main() {
    int arr[] = {23, 11, 56, 9, 76, 33, 81, 62, 44};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Original Array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Bubble Sort
    printf("Sorting using Bubble Sort:\n");
    bubbleSort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Selection Sort
    printf("Sorting using Selection Sort:\n");
    selectionSort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Insertion Sort
    printf("Sorting using Insertion Sort:\n");
    insertionSort(arr, n);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    // Quick Sort
    printf("Sorting using Quick Sort:\n");
    quickSort(arr, 0, n-1);
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");

    return 0;
}

/* Bubble Sort */
void bubbleSort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        for(int j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

/* Selection Sort */
void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for(i=0; i<n-1; i++){
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

/* Insertion Sort */
void insertionSort(int arr[], int n){
    int i, key, j;
    for(i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

/* Quick Sort */
void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = (low-1);
    for(int j=low; j<=high-1; j++){
        if(arr[j]<pivot){
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[high]);
    return (i+1);
}

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}