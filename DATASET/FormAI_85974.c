//FormAI DATASET v1.0 Category: Sorting ; Style: high level of detail
#include <stdio.h>

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void bubbleSort(int arr[], int n){
    int i, j;
    for (i = 0; i < n-1; i++){
        for (j = 0; j < n-i-1; j++){
            if (arr[j] > arr[j+1]){
                swap(&arr[j], &arr[j+1]);
            }
        }
    }
}

int main(){
    int arr[] = {56, 35, 89, 12, 45};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Original array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    bubbleSort(arr, n);
    printf("\nSorted array: \n");
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}