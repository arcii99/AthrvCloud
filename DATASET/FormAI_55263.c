//FormAI DATASET v1.0 Category: Benchmarking ; Style: mathematical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define SIZE 1000000

void fill_array(int *arr);
void print_array(int *arr);
void insertion_sort(int *arr);
void merge_sort(int *arr, int l, int r);
void merge(int *arr, int l, int m, int r);

int main() {
    int arr[SIZE];
    double start, end;
  
    fill_array(arr);
    printf("The unsorted array is:\n");
    print_array(arr);

    printf("\nInsertion sort:\n");
    start = clock();
    insertion_sort(arr);
    end = clock();
    printf("The sorted array is:\n");
    print_array(arr);
    printf("Time taken: %lf seconds\n", (end-start)/CLOCKS_PER_SEC);

    fill_array(arr);
    printf("\nMerge sort:\n");
    start = clock();
    merge_sort(arr, 0, SIZE-1);
    end = clock();
    printf("The sorted array is:\n");
    print_array(arr);
    printf("Time taken: %lf seconds\n", (end-start)/CLOCKS_PER_SEC);

    return 0;
}

void fill_array(int *arr) {
    srand(time(NULL));
    for(int i=0; i<SIZE; i++) {
        arr[i] = rand() % 100 + 1; 
    }
}

void print_array(int *arr) {
    for(int i=0; i<SIZE; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertion_sort(int *arr) {
    for(int i=1; i<SIZE; i++) {
        int key = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

void merge_sort(int *arr, int l, int r) {
    if(l < r) {
        int m = l + (r-l)/2;
        merge_sort(arr, l, m);
        merge_sort(arr, m+1, r);
        merge(arr, l, m, r);
    }
}

void merge(int *arr, int l, int m, int r) {
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
    int L[n1], R[n2];
    for(i=0; i<n1; i++) {
        L[i] = arr[l+i];
    }
    for(j=0; j<n2; j++) {
        R[j] = arr[m+1+j];
    }
    i = 0; j = 0; k = l;
    while(i < n1 && j < n2) {
        if(L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
    while(i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}