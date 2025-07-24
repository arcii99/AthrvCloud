//FormAI DATASET v1.0 Category: Benchmarking ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int i,j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int i, j, minIndex;
    for(i=0; i<n-1; i++){
        minIndex = i;
        for(j=i+1; j<n; j++){
            if(arr[j]<arr[minIndex]){
                minIndex = j;
            }
        }
        swap(&arr[i], &arr[minIndex]);
    }
}

void insertionSort(int arr[], int n){
    int i, j, key;
    for(i=1; i<n; i++){
        key = arr[i];
        j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void quickSort(int arr[], int low, int high){
    int i, j, pivot;
    if(low<high){
        pivot = arr[low];
        i = low+1;
        j = high;
        while(i<=j){
            while(i<=high && arr[i]<=pivot) i++;
            while(j>=low && arr[j]>pivot) j--;
            if(i<j){
                swap(&arr[i], &arr[j]);
            }
        }
        swap(&arr[j], &arr[low]);
        quickSort(arr, low, j-1);
        quickSort(arr, j+1, high);
    }
}

void generateRandomArray(int arr[], int n){
    srand(time(NULL));
    int i;
    for(i=0;i<n;i++){
        arr[i] = rand()%10000 + 1;
    }
}

void displayArray(int arr[], int n){
    int i;
    for(i=0;i<n;i++){
        printf("%d\t", arr[i]);
    }
    printf("\n");
}

int main(){
    int n = 10000;
    int arr1[n], arr2[n], arr3[n], arr4[n];
    generateRandomArray(arr1, n);
    memcpy(arr2, arr1, n*sizeof(arr1[0]));
    memcpy(arr3, arr1, n*sizeof(arr1[0]));
    memcpy(arr4, arr1, n*sizeof(arr1[0]));
    clock_t start, end;
    double time;
    start = clock();
    bubbleSort(arr1, n);
    end = clock();
    time = (double) (end-start)/CLOCKS_PER_SEC;
    printf("Bubble Sort: %lf seconds.\n", time);
    start = clock();
    selectionSort(arr2, n);
    end = clock();
    time = (double) (end-start)/CLOCKS_PER_SEC;
    printf("Selection Sort: %lf seconds.\n", time);
    start = clock();
    insertionSort(arr3, n);
    end = clock();
    time = (double) (end-start)/CLOCKS_PER_SEC;
    printf("Insertion Sort: %lf seconds.\n", time);
    start = clock();
    quickSort(arr4, 0, n-1);
    end = clock();
    time = (double) (end-start)/CLOCKS_PER_SEC;
    printf("Quick Sort: %lf seconds.\n", time);
    return 0;
}