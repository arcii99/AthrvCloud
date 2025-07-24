//FormAI DATASET v1.0 Category: Sorting ; Style: ephemeral
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

void selectionSort(int arr[], int n){
    int i, j, min_idx;
    for(i=0; i<n-1; i++){
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
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

int main(){
    srand(time(NULL));
    int n = 50, i;
    int arr[n];

    //Generating random array
    printf("Random Array before sorting:\n");
    for(i=0; i<n; i++){
        arr[i] = rand()%100;
        printf("%d ", arr[i]);
    }

    //Bubble Sort
    bubbleSort(arr, n);
    printf("\n\nSorted Array using Bubble Sort:\n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    //Selection Sort
    selectionSort(arr, n);
    printf("\n\nSorted Array using Selection Sort:\n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    //Insertion Sort 
    insertionSort(arr, n);
    printf("\n\nSorted Array using Insertion Sort:\n");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n");
    return 0;
}