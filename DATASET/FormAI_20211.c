//FormAI DATASET v1.0 Category: Sorting ; Style: shocked
#include<stdio.h>

#define ARRAY_SIZE 10

void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){      
        // Last i elements are already sorted 
        for (j = 0; j < n-i-1; j++){ 
            if (arr[j] > arr[j+1]){
                //swap elements
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    printf("Sorting program starting...\n\n");
    
    int arr[ARRAY_SIZE] = {9, 3, 7, 5, 1, 2, 8, 6, 4, 0};
    printf("Unsorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\n");
    
    bubbleSort(arr, ARRAY_SIZE);
    printf("Sorted array: ");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n\nSorting program complete.\n");
}