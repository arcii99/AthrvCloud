//FormAI DATASET v1.0 Category: Sorting ; Style: detailed
#include <stdio.h>

void bubble_sort(int arr[], int n){
    int i, j, temp;
    for(i=0; i<n-1; i++){
        for(j=0; j<n-i-1; j++){
            if(arr[j]>arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int arr[] = {5, 2, 7, 1, 3};
    int n = sizeof(arr)/sizeof(arr[0]);
    printf("Unsorted array: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    bubble_sort(arr, n);
    printf("\nSorted array in ascending order: ");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}