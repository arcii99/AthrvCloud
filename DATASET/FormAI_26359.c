//FormAI DATASET v1.0 Category: Benchmarking ; Style: Ada Lovelace
#include<stdio.h>
#include<time.h>
#define MAX 1000

void insertion_sort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i-1;
        while (j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j = j-1;
        }
        arr[j+1] = key;
    }
}

int create_random_array(int arr[]){
    int i;
    for(i=0;i<MAX;i++){
        arr[i] = rand();
    }
    return MAX;
}

void benchmark_sorting(int arr[], int n){
    clock_t t;

    t = clock();
    insertion_sort(arr, n);
    t = clock() - t;

    printf("Sorting took %f seconds to execute \n", ((double)t)/CLOCKS_PER_SEC);
    printf("Sorted array:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[MAX];
    int n = create_random_array(arr);

    printf("Unsorted array:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    benchmark_sorting(arr, n);

    return 0;
}