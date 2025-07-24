//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 1000000 //Define size of the array

//Swap function to swap two elements of the array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//QuickSort function to sort the array
void quickSort(int arr[], int low, int high){
    if(low < high){
        int pivot = arr[high];
        int i = low - 1;
        for(int j = low; j < high; j++){
            if(arr[j] < pivot){
                i++;
                swap(&arr[j], &arr[i]);
            }
        }
        swap(&arr[i+1], &arr[high]);
        int pi = i + 1;
        quickSort(arr, low, pi - 1);
        quickSort(arr, pi + 1, high);
    }
}

int main(){
    int arr[ARRAY_SIZE];
    srand(time(NULL)); //Seed for rand()

    //Filling array with random integers
    for(int i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % ARRAY_SIZE;
    }

    clock_t t;
    t = clock();

    quickSort(arr, 0, ARRAY_SIZE - 1); //Sorting the array using QuickSort

    t = clock() - t;
    double time_taken = ((double)t)/CLOCKS_PER_SEC; //Calculating time taken by QuickSort

    printf("Sorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++){ //Printing the sorted array
        printf("%d ", arr[i]);
    }

    printf("\nTime taken by QuickSort: %f seconds", time_taken);
    return 0;
}