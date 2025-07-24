//FormAI DATASET v1.0 Category: Sorting ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ARRAY_SIZE 10

void bubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[ARRAY_SIZE];
    int i;
    srand(time(NULL));

    printf("Generating random numbers...\n");

    for(i = 0; i < ARRAY_SIZE; i++){
        arr[i] = rand() % 100;
    }

    printf("Unsorted array: ");
    for(i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }

    bubbleSort(arr, ARRAY_SIZE);

    printf("\nSorted array: ");
    for(i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}