//FormAI DATASET v1.0 Category: Sorting ; Style: calm
#include <stdio.h>

void bubble_sort(int arr[], int n);

int main() {
    int arr[] = {3, 2, 7, 5, 4, 1, 6};
    int n = sizeof(arr)/sizeof(arr[0]);
    
    printf("Before sorting: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    
    bubble_sort(arr, n);
    
    printf("\nAfter sorting: ");
    for(int i=0; i<n; i++)
        printf("%d ", arr[i]);
    
    return 0;
}

void bubble_sort(int arr[], int n) {
    int temp;
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}