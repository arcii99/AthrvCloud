//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define SIZE 10000

void bubble_sort(int arr[], int size){
    int temp;
    for (int i = 0; i < size - 1; i++){
        for (int j = 0; j < size - i - 1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[SIZE];

    srand(time(NULL));
    for (int i = 0; i < SIZE; i++){
        arr[i] = rand() % 1000;
    }
    
    bubble_sort(arr, SIZE);

    printf("Sorted array:\n");
    for (int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}