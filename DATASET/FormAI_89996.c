//FormAI DATASET v1.0 Category: Sorting ; Style: satisfied
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n) {
    int temp;
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n-i-1; j++){
            if(arr[j] > arr[j+1]){
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}

int main() {
    int n;
    printf("Enter the number of elements of the array: ");
    scanf("%d", &n);
 
    int arr[n];
    printf("Enter %d elements of the array:", n);
    
    for(int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    printf("Before Sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    bubble_sort(arr, n);

    printf("After Sorting: ");
    for(int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}