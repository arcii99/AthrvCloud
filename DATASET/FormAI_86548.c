//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 1000000

// Function to generate random array
void generate_random_array(int arr[]){
    for(int i=0;i<SIZE;i++){
        arr[i] = rand()%SIZE;
    }
}

// Function to print array
void print_array(int arr[]){
    for(int i=0;i<SIZE;i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// Quick Sort function (Recursive)
void quick_sort(int arr[], int low, int high){

    if(low<high){
        int pivot = arr[low];
        int i = low;
        int j = high;

        while(i<j){
            while(arr[i]<=pivot && i<high){
                i++;
            }
            while(arr[j]>pivot){
                j--;
            }

            if(i<j){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }

        arr[low] = arr[j];
        arr[j] = pivot;

        // Recursive Calls
        quick_sort(arr, low, j-1);
        quick_sort(arr, j+1, high);      
    }
}

int main(){
    int arr[SIZE];

    // Generating random array
    generate_random_array(arr);

    printf("Array before sorting: \n");
    print_array(arr);

    clock_t start = clock();

    // Quick Sort Function Call
    quick_sort(arr, 0, SIZE-1);

    clock_t end = clock();
    double time_taken = (double)(end - start) / CLOCKS_PER_SEC; 

    printf("Array after sorting: \n");  
    print_array(arr);
    printf("Time taken for sorting: %f sec\n", time_taken);

    return 0;
}