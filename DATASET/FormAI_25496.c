//FormAI DATASET v1.0 Category: Sorting ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>

//Function to swap two elements in an array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to perform bubble sort in an array
void bubbleSort(int arr[], int size){
    int i, j;
    for(i = 0; i < size-1; i++){
        int swapped = 0;
        for(j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
                swapped = 1;
            }
        }
        if(!swapped){
            break;
        }
    }
}

int main(){
    int i, n;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter the array elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    bubbleSort(arr, n);

    printf("Sorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}