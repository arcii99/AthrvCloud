//FormAI DATASET v1.0 Category: Benchmarking ; Style: Dennis Ritchie
#include<stdio.h>
#include<time.h>

#define ARR_SIZE 1000000

int main(){

    int i, j, temp;
    int arr[ARR_SIZE];

    // Generating random numbers
    srand(time(NULL));
    for(i=0; i<ARR_SIZE; i++){
        arr[i] = rand() % 10000;
    }
    
    // Bubble sort algorithm
    clock_t bubble_t1 = clock();
    for(i=0; i<ARR_SIZE-1; i++){
        for(j=0; j<ARR_SIZE-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    clock_t bubble_t2 = clock();

    // Quick sort algorithm
    void quickSort(int*, int, int);
    clock_t quick_t1 = clock();
    quickSort(arr, 0, ARR_SIZE-1);
    clock_t quick_t2 = clock();

    // Printing sorted array
    printf("Sorted array:\n");
    for(i=0; i<ARR_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Benchmarking
    double bubble_time = ((double) (bubble_t2 - bubble_t1)) / CLOCKS_PER_SEC;
    double quick_time = ((double) (quick_t2 - quick_t1)) / CLOCKS_PER_SEC;
    printf("Time taken for bubble sort: %f seconds\n", bubble_time);
    printf("Time taken for quick sort: %f seconds\n", quick_time);
    
    return 0;
}

// Quick sort implementation
void quickSort(int arr[], int low, int high){

    if(low < high){
        int pivot = arr[high];
        int i = (low - 1);
        int j, temp;

        for(j=low; j<high; j++){
            if(arr[j] <= pivot){
                i++;
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        temp = arr[i+1];
        arr[i+1] = arr[high];
        arr[high] = temp;
        
        int pi = i+1;

        quickSort(arr, low, pi-1);
        quickSort(arr, pi+1, high);
    }

}