//FormAI DATASET v1.0 Category: Sorting ; Style: genious
#include<stdio.h>
#include<stdlib.h>

// Bubble sort implemented with a genius twist
void geniusBubbleSort(int arr[], int n){
    int i, j, temp;
    for (i = 0; i < n - 1; i++){
        for (j = 0; j < n - i - 1; j++){
            if (arr[j] > arr[j + 1]){
                // Here comes the genius twist
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                // Let's print the array after each swap
                printf("Array after swap: ");
                for (int k=0; k<n; k++){
                    printf("%d ", arr[k]);
                }
                printf("\n");
            }
        }
    }
}

int main(){
    int arr[] = {64, 34, 25, 12, 22, 11, 90};
    int n = sizeof(arr) / sizeof(arr[0]);
    printf("Original array: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    geniusBubbleSort(arr, n);

    printf("\nSorted array: ");
    for (int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}