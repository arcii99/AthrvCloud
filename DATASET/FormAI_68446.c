//FormAI DATASET v1.0 Category: Sorting ; Style: optimized
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int *b){ // function to swap two integers
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubble_sort(int *arr, int n){ // function to sort the array using bubble sort
    int i,j;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    int size;
    printf("Enter the size of the array: ");
    scanf("%d", &size);
    int arr[size], i;

    srand(time(0)); // seed the random number generator with current time
    for(i = 0; i < size; i++){ // generate random elements for the array
        arr[i] = rand() % 100; 
    }

    bubble_sort(arr, size); // sort the array using bubble sort
    printf("Sorted array: ");
    for(i = 0; i < size; i++){ // print the sorted array
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}