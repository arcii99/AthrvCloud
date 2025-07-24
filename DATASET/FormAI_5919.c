//FormAI DATASET v1.0 Category: Sorting ; Style: peaceful
#include <stdio.h>

#define SIZE 10

void bubbleSort(int arr[], int n){

    for (int i = 0; i < n - 1; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main(){
    int arr[SIZE] = {5, 2, 6, 3, 1, 9, 8, 7, 4, 0};
    
    printf("Original Array: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    
    bubbleSort(arr, SIZE);
    
    printf("\n\nSorted Array: ");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    
    return 0;
}