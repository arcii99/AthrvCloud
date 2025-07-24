//FormAI DATASET v1.0 Category: Benchmarking ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

void bubble_sort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        for(int j=0; j<size-i-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void selection_sort(int *arr, int size){
    for(int i=0; i<size-1; i++){
        int min_idx = i;
        for(int j=i+1; j<size; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[min_idx];
        arr[min_idx] = temp;
    }
}

void insertion_sort(int *arr, int size){
    for(int i=1; i<size; i++){
        int key = arr[i];
        int j = i-1;
        while(j>=0 && arr[j]>key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge(int *arr, int left, int mid, int right){
    int n1 = mid - left + 1;
    int n2 = right - mid;
    
    int L[n1], R[n2];
    
    for(int i=0; i<n1; i++){
        L[i] = arr[left+i];
    }
    for(int i=0; i<n2; i++){
        R[i] = arr[mid+1+i];
    }
    
    int i=0, j=0, k=left;
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

void merge_sort(int *arr, int left, int right){
    if(left < right){
        int mid = left + (right - left) / 2;
        merge_sort(arr, left, mid);
        merge_sort(arr, mid+1, right);
        merge(arr, left, mid, right);
    }
}

void quick_sort(int *arr, int left, int right){
    if(left < right){
        int pivot = arr[right];
        int i = left-1;
        for(int j=left; j<right; j++){
            if(arr[j] <= pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[right];
        arr[right] = temp;
        
        int pi = i+1;
        quick_sort(arr, left, pi-1);
        quick_sort(arr, pi+1, right);
    }
}

int main(){
    int arr1[SIZE], arr2[SIZE], arr3[SIZE], arr4[SIZE], arr5[SIZE];
    
    srand(time(NULL));
    for(int i=0; i<SIZE; i++){
        int num = rand();
        arr1[i] = num;
        arr2[i] = num;
        arr3[i] = num;
        arr4[i] = num;
        arr5[i] = num;
    }
    
    printf("Sorting %d numbers using Bubble Sort...\n", SIZE);
    clock_t start = clock();
    bubble_sort(arr1, SIZE);
    printf("Time taken: %f seconds\n\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    printf("Sorting %d numbers using Selection Sort...\n", SIZE);
    start = clock();
    selection_sort(arr2, SIZE);
    printf("Time taken: %f seconds\n\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    printf("Sorting %d numbers using Insertion Sort...\n", SIZE);
    start = clock();
    insertion_sort(arr3, SIZE);
    printf("Time taken: %f seconds\n\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    printf("Sorting %d numbers using Merge Sort...\n", SIZE);
    start = clock();
    merge_sort(arr4, 0, SIZE-1);
    printf("Time taken: %f seconds\n\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    printf("Sorting %d numbers using Quick Sort...\n", SIZE);
    start = clock();
    quick_sort(arr5, 0, SIZE-1);
    printf("Time taken: %f seconds\n\n", (double)(clock()-start)/CLOCKS_PER_SEC);
    
    return 0;
}