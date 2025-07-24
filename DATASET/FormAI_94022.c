//FormAI DATASET v1.0 Category: Sorting ; Style: grateful
#include <stdio.h>
#define ARRAY_SIZE 10

void bubble_sort(int arr[], int size){
    int temp, flag;
    for(int i = 0; i < size-1; i++){
        flag = 0;
        for(int j = 0; j < size-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
                flag = 1;
            }
        }
        if(flag == 0){
            break;
        }
    }
}

int main(){
    int arr[ARRAY_SIZE] = {9, 2, 1, 4, 7, 8, 5, 6, 3, 0};

    printf("Unsorted Array: ");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }

    bubble_sort(arr, ARRAY_SIZE);

    printf("\nSorted Array: ");
    for(int i = 0; i < ARRAY_SIZE; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}