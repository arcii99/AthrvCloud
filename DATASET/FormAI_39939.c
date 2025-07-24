//FormAI DATASET v1.0 Category: Sorting ; Style: high level of detail
#include<stdio.h>

void bubble_sort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n-1; i++){
        for(j = i+1; j < n; j++){
            if(arr[i] > arr[j]){
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

int main(){
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the array elements: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    bubble_sort(arr, n);
    printf("Sorted array: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}