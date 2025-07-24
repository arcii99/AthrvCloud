//FormAI DATASET v1.0 Category: Greedy Algorithms ; Style: accurate
#include<stdio.h>

// function to perform selection sort
void selection_sort(int arr[], int n){
    for(int i=0; i<n-1; i++){
        int index_min = i;
        for(int j=i+1; j<n; j++){
            if(arr[j] < arr[index_min]){
                index_min = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[index_min];
        arr[index_min] = temp;
    }
}

int main(){
    int n;
    printf("Enter size of the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter elements of the array:\n");
    for(int i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    selection_sort(arr, n);
    printf("\nSorted array:\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}