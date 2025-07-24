//FormAI DATASET v1.0 Category: Benchmarking ; Style: mind-bending
#include <stdio.h>
#include <time.h>

int main() {
    clock_t start, end;
    double cpu_time_used;

    //let's initialize an array of 10000 integers
    int my_array[10000];
    for(int i=0; i<10000; i++) {
        my_array[i] = i+1;
    }

    //let's benchmark linear search of an element
    start = clock();
    int index = -1;
    for(int i=0; i<10000; i++) {
        if(my_array[i] == 9999) {
            index = i;
            break;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Linear Search Benchmark: Element found at index %d in %f seconds\n", index, cpu_time_used);

    //let's benchmark binary search of an element
    start = clock();
    int low = 0;
    int high = 9999;
    int mid;
    while(low<=high) {
        mid = (low + high)/2;
        if(my_array[mid] == 9999) {
            index = mid;
            break;
        }
        else if(my_array[mid] < 9999) {
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Binary Search Benchmark: Element found at index %d in %f seconds\n", index, cpu_time_used);

    //let's benchmark sorting of the array using bubble sort
    start = clock();
    for(int i=0; i<10000; i++) {
        for(int j=0; j<10000-i-1; j++) {
            if(my_array[j] > my_array[j+1]) {
                int temp = my_array[j];
                my_array[j] = my_array[j+1];
                my_array[j+1] = temp;
            }
        }
    }
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Bubble Sort Benchmark: Array sorted in %f seconds\n", cpu_time_used);

    //let's benchmark sorting of the array using quick sort
    start = clock();
    quickSort(my_array, 0, 9999);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("Quick Sort Benchmark: Array sorted in %f seconds\n", cpu_time_used);

    return 0;
}

//implementation of quick sort
void quickSort(int arr[], int low, int high) {
    if(low < high) {
        int pi = partition(arr, low, high);
        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high) {
    int pivot = arr[high];
    int i = (low - 1);
    for(int j=low; j<=high-1; j++) {
        if(arr[j] < pivot) {
            i++;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = arr[high];
    arr[high] = temp;
    return (i+1);
}