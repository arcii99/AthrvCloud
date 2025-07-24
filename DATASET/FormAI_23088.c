//FormAI DATASET v1.0 Category: Benchmarking ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

void bubbleSort(int arr[], int size);
float quickSort(int arr[], int left, int right);
void mergeSort(int arr[], int left, int right);
void merge(int arr[], int left, int middle, int right);

int main() {
    srand(time(NULL));
    int arr[SIZE];

    // Populate the array with random numbers
    for(int i = 0; i < SIZE; i++) {
        arr[i] = rand() % 100;
    }

    // Measure time taken for bubble sort
    clock_t start = clock();
    bubbleSort(arr, SIZE);
    double bubbleTime = (double)(clock() - start) / CLOCKS_PER_SEC;

    // Measure time taken for quick sort
    start = clock();
    quickSort(arr, 0, SIZE - 1);
    double quickTime = (double)(clock() - start) / CLOCKS_PER_SEC;

    // Measure time taken for merge sort
    start = clock();
    mergeSort(arr, 0, SIZE - 1);
    double mergeTime = (double)(clock() - start) / CLOCKS_PER_SEC;

    printf("Time taken for sorting %d elements:\n", SIZE);
    printf("Bubble Sort: %f seconds\n", bubbleTime);
    printf("Quick Sort: %f seconds\n", quickTime);
    printf("Merge Sort: %f seconds\n", mergeTime);

}

float quickSort(int arr[], int left, int right) {
    if (left < right) {
        int pivot = arr[right];
        int temp;

        int i = left;
        int j = right - 1;
        while(i <= j) {
            while(arr[i] < pivot) {
                i++;
            }
            while(arr[j] > pivot) {
                j--;
            }
            if(i <= j) {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
                i++;
                j--;
            }
        }
        temp = arr[i];
        arr[i] = arr[right];
        arr[right] = temp;

        float time1 = quickSort(arr, left, i - 1);
        float time2 = quickSort(arr, i + 1, right);

        return time1 + time2 + (float)(clock())/CLOCKS_PER_SEC;
    }
    return 0;
}

void mergeSort(int arr[], int left, int right) {
    if(left < right) {
        int middle = (left + right) / 2;
        mergeSort(arr, left, middle);
        mergeSort(arr, middle + 1, right);
        merge(arr, left, middle, right);
    }
}

void merge(int arr[], int left, int middle, int right) {
    int i, j, k;
    int leftSize = middle - left + 1;
    int rightSize = right - middle;

    int leftArr[leftSize], rightArr[rightSize];

    for (i = 0; i < leftSize ;i++) {
        leftArr[i] = arr[left + i];
    }
    for(j = 0; j < rightSize ;j++) {
        rightArr[j] = arr[middle + 1+ j];
    }

    i = 0;
    j = 0;
    k = left;

    while (i < leftSize && j < rightSize) {
        if(leftArr[i] <= rightArr[j]) {
            arr[k++] = leftArr[i++];
        } else {
            arr[k++] = rightArr[j++];
        }
    }
    while(i < leftSize) {
        arr[k++] = leftArr[i++];
    }
    while(j < rightSize) {
        arr[k++] = rightArr[j++];
    }
}

void bubbleSort(int arr[], int size) {
    int temp;
    int sorted = 0;
    while(!sorted) {
        sorted = 1;
        for(int i = 1; i < size; i++) {
            if(arr[i - 1] > arr[i]) {
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                sorted = 0;
            }
        }
    }
}