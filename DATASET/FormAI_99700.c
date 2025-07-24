//FormAI DATASET v1.0 Category: Benchmarking ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int num_elements = 100000;
    int *arr = (int*) malloc(sizeof(int) * num_elements);

    srand(time(0));
    for(int i = 0; i < num_elements; i++) {
        arr[i] = rand() % 100;
    }

    clock_t start_time, end_time;
    double total_time_taken;

    // testing insertion sort
    start_time = clock();

    for(int i = 1; i < num_elements; i++) {
        int temp = arr[i];
        int j = i - 1;
        while(j >= 0 && arr[j] > temp) {
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = temp;
    }

    end_time = clock();
    total_time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Insertion Sort took %f seconds\n", total_time_taken);

    // testing bubble sort
    start_time = clock();

    for(int i = 0; i < num_elements-1; i++) {
        for(int j = 0; j < num_elements-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    end_time = clock();
    total_time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Bubble Sort took %f seconds\n", total_time_taken);

    // testing quick sort
    start_time = clock();

    quickSort(arr, 0, num_elements-1);

    end_time = clock();
    total_time_taken = ((double) (end_time - start_time)) / CLOCKS_PER_SEC;
    printf("Quick Sort took %f seconds\n", total_time_taken);

    free(arr);

    return 0;
}

void quickSort(int arr[], int left, int right) {
    if(left < right) {
        int index = partition(arr, left, right);
        quickSort(arr, left, index - 1);
        quickSort(arr, index + 1, right);
    }
}

int partition(int arr[], int left, int right) {
    int pivot = arr[right];
    int i = left - 1;
    for(int j = left; j <= right - 1; j++) {
        if(arr[j] <= pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[right];
    arr[right] = temp;
    return i+1;
}