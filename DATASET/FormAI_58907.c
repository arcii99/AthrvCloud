//FormAI DATASET v1.0 Category: Benchmarking ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 500000

void fill_array(int arr[]){
    int i;
    for(i = 0; i < SIZE; i++){
        arr[i] = rand() % 100;
    }
}

void bubble_sort(int arr[]){
    int i, j, temp;
    for(i = 0; i < SIZE-1; i++){
        for(j = 0; j < SIZE-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void insertion_sort(int arr[]){
    int i, j, temp;
    for(i = 1; i < SIZE; i++){
        temp = arr[i];
        j = i - 1;
        while(j >= 0 && arr[j] > temp){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }
}

void selection_sort(int arr[]){
    int i, j, min, temp;
    for(i = 0; i < SIZE-1; i++){
        min = i;
        for(j = i+1; j < SIZE; j++){
            if(arr[j] < arr[min]){
                min = j;
            }
        }
        if(min != i){
            temp = arr[i];
            arr[i] = arr[min];
            arr[min] = temp;
        }
    }
}

int main(){
    int arr[SIZE];
    clock_t start_time, end_time;

    fill_array(arr);
    start_time = clock();
    bubble_sort(arr);
    end_time = clock();
    printf("Time taken for bubble sort: %ld microseconds\n", end_time - start_time);

    fill_array(arr);
    start_time = clock();
    insertion_sort(arr);
    end_time = clock();
    printf("Time taken for insertion sort: %ld microseconds\n", end_time - start_time);

    fill_array(arr);
    start_time = clock();
    selection_sort(arr);
    end_time = clock();
    printf("Time taken for selection sort: %ld microseconds\n", end_time - start_time);

    return 0;
}