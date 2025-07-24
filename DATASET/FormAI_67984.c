//FormAI DATASET v1.0 Category: Benchmarking ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_SIZE 100000

// Function declarations
void bubbleSort(int arr[], int size);
void selectionSort(int arr[], int size);
void insertionSort(int arr[], int size);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int mid, int right);
void quickSort(int arr[], int left, int right);
int partition(int arr[], int left, int right);
void printResults(double bubbleTime, double selectionTime, double insertionTime, double mergeTime, double quickTime);

int main() {
    // Initialize array to be sorted
    int arr[MAX_SIZE];
    for (int i = 0; i < MAX_SIZE; i++) {
        arr[i] = rand() % 1000;
    }

    // Start timer for each sort algorithm
    clock_t start, end;
    double bubbleTime, selectionTime, insertionTime, mergeTime, quickTime;

    // Bubble sort
    start = clock();
    bubbleSort(arr, MAX_SIZE);
    end = clock();
    bubbleTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Selection sort
    start = clock();
    selectionSort(arr, MAX_SIZE);
    end = clock();
    selectionTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Insertion sort
    start = clock();
    insertionSort(arr, MAX_SIZE);
    end = clock();
    insertionTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Merge sort
    start = clock();
    mergeSort(arr, 0, MAX_SIZE - 1);
    end = clock();
    mergeTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Quick sort
    start = clock();
    quickSort(arr, 0, MAX_SIZE - 1);
    end = clock();
    quickTime = ((double) (end - start)) / CLOCKS_PER_SEC;

    // Print results
    printResults(bubbleTime, selectionTime, insertionTime, mergeTime, quickTime);

    return 0;
}

void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size - 1; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selectionSort(int arr[], int size) {
    int minIndex, temp;
    for (int i = 0; i < size - 1; i++) {
        minIndex = i;
        for (int j = i + 1; j < size; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex = j;
            }
        }
        if (minIndex != i) {
            temp = arr[i];
            arr[i] = arr[minIndex];
            arr[minIndex] = temp;
        }
    }
}

void insertionSort(int arr[], int size) {
    int j, temp;
    for (int i = 1; i < size; i++) {
        j = i;
        while (j > 0 && arr[j] < arr[j-1]) {
            temp = arr[j];
            arr[j] = arr[j-1];
            arr[j-1] = temp;
            j--;
        }
    }
}

void mergeSort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void merge(int arr[], int left, int mid, int right) {
    int i, j, k;
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = arr[left + i];
    }
    for (j = 0; j < n2; j++) {
        R[j] = arr[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
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
        int partitionIndex = partition(arr, left, right);
        quickSort(arr, left, partitionIndex - 1);
        quickSort(arr, partitionIndex + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    int temp;
    for (int j = left; j < right; j++) {
        if (arr[j] < pivot) {
            i++;
            temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    return i + 1;
}

void printResults(double bubbleTime, double selectionTime, double insertionTime, double mergeTime, double quickTime) {
    printf("Sorting times:\n");
    printf("Bubble sort:    %f seconds\n", bubbleTime);
    printf("Selection sort: %f seconds\n", selectionTime);
    printf("Insertion sort: %f seconds\n", insertionTime);
    printf("Merge sort:     %f seconds\n", mergeTime);
    printf("Quick sort:     %f seconds\n", quickTime);
}