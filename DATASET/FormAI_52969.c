//FormAI DATASET v1.0 Category: Sorting ; Style: paranoid
#include <stdio.h>

//function to swap two elements in an array
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//function to perform paranoid bubble sort
void paranoidBubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j+1]){
                printf("Oh no! The element at index %d is greater than the element at index %d!\n", j, j+1);
                swap(&arr[j], &arr[j+1]);
                printf("Phew! Disaster averted. The elements have been swapped.\n");
            }
            else{
                printf("Everything is fine. The element at index %d is not greater than the element at index %d.\n", j, j+1);
            }
        }
    }
}

int main(){
    int n = 10;
    int arr[] = {64, 34, 25, 12, 22, 11, 90, 87, 45, 71};

    printf("Before sorting:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nStarting paranoid bubble sort...\n");
    paranoidBubbleSort(arr, n);

    printf("\nAfter sorting:\n");
    for (int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    printf("\n\nPhew, everything is sorted correctly. Time to relax!\n");
    return 0;
}