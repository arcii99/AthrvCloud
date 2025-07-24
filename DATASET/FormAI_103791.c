//FormAI DATASET v1.0 Category: Sorting ; Style: genious
#include <stdio.h>

#define SIZE 10

int main() {

    int arr[SIZE] = {2, 4, 6, 9, 1, 7, 8, 5, 3, 0};

    printf("Unsorted Array: \n");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nSorting in Genius Style...\n\n");

    // Genius Sorting Algorithm
    for(int i = 0; i < SIZE; i++){
        for(int j = i+1; j < SIZE; j++){
            if(arr[i] > arr[j]){
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }

    printf("Sorted Array: \n");
    for(int i = 0; i < SIZE; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nGenius Sorting Complete!\n");

    return 0;
}