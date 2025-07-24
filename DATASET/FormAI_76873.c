//FormAI DATASET v1.0 Category: Sorting ; Style: mathematical
#include <stdio.h>

int main() {
    //User input
    int n;
    printf("Enter the number of elements to be sorted: ");
    scanf("%d", &n);

    int arr[n];
    //User input for array values
    printf("Enter the array values: ");
    for(int i=0; i<n; i++) {
        scanf("%d", &arr[i]);
    }

    //Sort the array in ascending order using bubble sort
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }

    printf("\nSorted array in ascending order: ");
    for(int i=0; i<n; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}