//FormAI DATASET v1.0 Category: Sorting ; Style: creative
#include <stdio.h>
#include <stdlib.h>

void bubbleSort(int arr[], int size){
    int temp, i, j;
    for(i = 0; i < size - 1; i++){
        for(j = 0; j < size - i - 1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {10, 2, 7, 5, 1, 8, 3, 6, 4, 9};
    int size = sizeof(arr) / sizeof(arr[0]);

    printf("Before sorting: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, size);

    printf("\nAfter sorting: ");
    for(int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}