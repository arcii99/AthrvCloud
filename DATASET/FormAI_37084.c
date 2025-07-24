//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: secure
#include<stdio.h>

//Function to swap values of two variables
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

//Function to implement selection sort algorithm
void selectionSort(int arr[], int n){
    int i,j,min_idx;

    for(i=0; i<n-1; i++){
        min_idx = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min_idx]){
                min_idx = j;
            }
        }
        swap(&arr[min_idx], &arr[i]);
    }
}

int main(){
    int arr[] = {23, 45, 12, 67, 89, 54};
    int n = sizeof(arr)/sizeof(arr[0]);
    int i;

    printf("Unsorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    selectionSort(arr, n);

    printf("Sorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}