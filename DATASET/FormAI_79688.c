//FormAI DATASET v1.0 Category: Benchmarking ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000000

void initialize_array(int arr[]){
    for(int i=0; i<SIZE; i++){
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int arr[]){
    for(int i=0; i<SIZE; i++){
        for(int j=0; j<SIZE-1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int left, int right){
    if(left >= right){
        return;
    }
    int pivot = arr[(left+right)/2];
    int i = left;
    int j = right;
    while(i <= j){
        while(arr[i] < pivot){
            i++;
        }
        while(arr[j] > pivot){
            j--;
        }
        if(i <= j){
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
            i++;
            j--;
        }
    }
    quick_sort(arr, left, j);
    quick_sort(arr, i, right);
}

int main(){
    int arr[SIZE];
    initialize_array(arr);

    clock_t start_time = clock();
    bubble_sort(arr);
    clock_t end_time = clock();

    double time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds to execute\n", time_taken);

    start_time = clock();
    quick_sort(arr, 0, SIZE-1);
    end_time = clock();

    time_taken = ((double)(end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds to execute\n", time_taken);

    return 0;
}