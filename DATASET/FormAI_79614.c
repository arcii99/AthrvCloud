//FormAI DATASET v1.0 Category: Sorting ; Style: content
// Sorting Example Program in C

#include<stdio.h>
#include<stdlib.h>

// Function Declarations
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void quickSort(int arr[], int low, int high);
int partition(int arr[], int low, int high);
void mergeSort(int arr[], int l, int r);
void merge(int arr[], int l, int m, int r);
void heapSort(int arr[], int n);
void buildHeap(int arr[], int n);
void heapify(int arr[], int n, int i);
void printArray(int arr[], int size);


int main(){

    int arr[] = {10, 2, 8, 5, 3, 9, 7, 6, 4, 1};
    int size = sizeof(arr)/sizeof(arr[0]);  // Calculating array size

    printf("Original Array: ");
    printArray(arr, size);

    // Calling Bubble Sort Function
    printf("\n\nSorting by Bubble Sort: ");
    bubbleSort(arr, size);
    printArray(arr, size);

    // Calling Selection Sort Function
    printf("\n\nSorting by Selection Sort: ");
    selectionSort(arr, size);
    printArray(arr, size);

    // Calling Insertion Sort Function
    printf("\n\nSorting by Insertion Sort: ");
    insertionSort(arr, size);
    printArray(arr, size);

    // Calling Quick Sort Function
    printf("\n\nSorting by Quick Sort: ");
    quickSort(arr, 0, size-1);
    printArray(arr, size);

    // Calling Merge Sort Function
    printf("\n\nSorting by Merge Sort: ");
    mergeSort(arr, 0, size-1);
    printArray(arr, size);

    // Calling Heap Sort Function
    printf("\n\nSorting by Heap Sort: ");
    heapSort(arr, size);
    printArray(arr, size);

    return 0;
}


// Function to perform Bubble Sort
void bubbleSort(int arr[], int size){

    int temp;
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}


// Function to perform Selection Sort
void selectionSort(int arr[], int size){

    int i, j, minIndex, temp;
    for(i=0; i<size-1; i++){
        minIndex = i;
        for(j=i+1; j<size; j++){
            if(arr[j] < arr[minIndex]){
                minIndex = j;
            }
        }
        temp = arr[minIndex];
        arr[minIndex] = arr[i];
        arr[i] = temp;
    }
}


// Function to perform Insertion Sort
void insertionSort(int arr[], int size){

    int i, j, key;
    for(i=1; i<size; i++){
        key = arr[i];
        j = i - 1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}


// Function to perform Quick Sort
void quickSort(int arr[], int low, int high){

    if(low < high){
        int pIndex = partition(arr, low, high);
        quickSort(arr, low, pIndex-1);
        quickSort(arr, pIndex+1, high);
    }
}

// Function to partition array in Quick sort
int partition(int arr[], int low, int high){

    int pivot = arr[high];
    int i = low - 1, temp;
    for(int j=low; j<=high-1; j++){
        if(arr[j] < pivot){
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return i+1;
}


// Function to perform Merge Sort
void mergeSort(int arr[], int l, int r){

    if(l < r){
        int m = (l+r)/2;
        mergeSort(arr, l, m);
        mergeSort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

// Function to merge arrays in Merge sort
void merge(int arr[], int l, int m, int r){

    int i, j, k;
    int n1 = m-l+1;
    int n2 = r-m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++){
        L[i] = arr[l+i];
    }
    for(j=0; j<n2; j++){
        R[j] = arr[m+j+1];
    }

    i = 0, j = 0, k = l;
    while(i<n1 && j<n2){
        if(L[i] <= R[j]){
            arr[k] = L[i];
            i++;
        }
        else{
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}


// Function to perform Heap Sort
void heapSort(int arr[], int n){

    buildHeap(arr, n);
    for(int i=n-1; i>=0; i--){
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

// Function to build initial Heap
void buildHeap(int arr[], int n){

    for(int i=(n/2)-1; i>=0; i--){
        heapify(arr, n, i);
    }
}

// Function to maintain Heap property recursively
void heapify(int arr[], int n, int i){

    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    int temp;

    if(l<n && arr[l] > arr[largest]){
        largest = l;
    }
    if(r<n && arr[r] > arr[largest]){
        largest = r;
    }

    if(largest != i){
        temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}


// Function to print the array
void printArray(int arr[], int size){

    printf("[");
    for(int i=0; i<size; i++){
        printf("%d", arr[i]);
        if(i != size-1){
            printf(", ");
        }
    }
    printf("]");
}