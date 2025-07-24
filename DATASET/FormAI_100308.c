//FormAI DATASET v1.0 Category: Sorting ; Style: standalone
#include<stdio.h>

void bubble_sort(int arr[], int n){
    int i, j, temp;
    for(i = 0; i < n-1; i++){
        for(j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main(){
    int n, i;
    printf("Enter the number of elements in the array: ");
    scanf("%d", &n);
    int arr[n];
    printf("Enter the elements of the array: ");
    for(i = 0; i < n; i++){
        scanf("%d", &arr[i]);
    }
    printf("The unsorted array is: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    bubble_sort(arr, n);
    printf("\nAfter sorting, the array is: ");
    for(i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    return 0;
}