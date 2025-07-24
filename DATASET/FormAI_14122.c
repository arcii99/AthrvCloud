//FormAI DATASET v1.0 Category: Sorting ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

void bubble_sort(int arr[], int n);

int main() {
    int n, i;
    printf("Enter the size of the array:");
    scanf("%d", &n);
    int arr[n];
    for(i=0;i<n;i++) {
        printf("Enter element %d:", i+1);
        scanf("%d", &(arr[i]));
    }
    bubble_sort(arr, n);
    printf("Sorted array:");
    for (i=0;i<n;i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    return 0;
}

void bubble_sort(int arr[], int n) {
    int i, j, temp;
    for(i=0;i<n-1;i++) {
        for(j=0;j<n-i-1;j++) {
            if(arr[j]>arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}