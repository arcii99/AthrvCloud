//FormAI DATASET v1.0 Category: Benchmarking ; Style: puzzling
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000

void generate_random_array(int arr[], int size){
    srand(time(NULL));

    for(int i = 0; i < size; i++){
        arr[i] = rand() % 100000 + 1;
    }
}

void bubble_sort(int arr[], int size){
    for(int i = 0; i < size - 1; i++){
        for(int j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

void quick_sort(int arr[], int low, int high){
    if(low < high){
        int pivot = arr[high];
        int i = low - 1;

        for(int j = low; j <= high - 1; j++){
            if(arr[j] < pivot){
                i++;
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
        int temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;

        int p = i + 1;

        quick_sort(arr, low, p - 1);
        quick_sort(arr, p + 1, high);
    }
}

void print_array(int arr[], int size){
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main(){
    int arr[ARRAY_SIZE];
    generate_random_array(arr, ARRAY_SIZE);

    clock_t start_bubble = clock();
    bubble_sort(arr, ARRAY_SIZE);
    clock_t end_bubble = clock();

    printf("Sorted using bubble sort:\n");
    print_array(arr, ARRAY_SIZE);

    clock_t start_quick = clock();
    quick_sort(arr, 0, ARRAY_SIZE - 1);
    clock_t end_quick = clock();

    printf("Sorted using quick sort:\n");
    print_array(arr, ARRAY_SIZE);

    double time_bubble = (double)(end_bubble - start_bubble) / CLOCKS_PER_SEC;
    double time_quick = (double)(end_quick - start_quick) / CLOCKS_PER_SEC;

    printf("Time taken for bubble sort: %lf seconds\n", time_bubble);
    printf("Time taken for quick sort: %lf seconds\n", time_quick);

    return 0;
}