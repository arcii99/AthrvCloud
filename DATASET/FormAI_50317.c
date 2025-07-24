//FormAI DATASET v1.0 Category: Performance-Critical Component ; Style: standalone
#include<stdio.h>

// size of the array
#define SIZE 100

// function to perform insertion sort
void insertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++){
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key){
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

// main method
int main(){
    int arr[SIZE], n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);

    printf("Enter %d elements in the array:\n", n);
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }

    // call the insertion sort function
    insertionSort(arr, n);

    printf("Sorted array in ascending order:\n");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }

    return 0;
}