//FormAI DATASET v1.0 Category: Sorting ; Style: high level of detail
#include<stdio.h>
#include<stdlib.h>

//function to swap two values
void swap(int *x, int *y){
    int temp = *x;
    *x = *y;
    *y = temp;
}

//function to perform selection sort
void selection_sort(int arr[], int n){
    int i, j, min_index;
    for(i=0; i<n-1; i++){
        min_index = i;
        for(j=i+1; j<n; j++){
            if(arr[j] < arr[min_index]){
                min_index = j;
            }
        }
        swap(&arr[min_index], &arr[i]);
    }
}

int main(){
    int *arr, n, i;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    arr = (int*)malloc(n*sizeof(int));
    printf("Enter the elements: ");
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("\nOriginal array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    selection_sort(arr, n);
    printf("\nSorted array: ");
    for(i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}