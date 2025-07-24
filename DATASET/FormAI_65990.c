//FormAI DATASET v1.0 Category: Sorting ; Style: inquisitive
#include <stdio.h>

int main() {
    int arr[50], n, i, j, temp;
    printf("Enter number of elements to sort: "); // Asking the user for the number of elements to sort
    scanf("%d", &n);
    printf("Enter %d elements: ", n); // Asking the user to input the elements
    for(i=0; i<n; i++){
        scanf("%d", &arr[i]);
    }
    printf("Input array is: ");
    for(i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    
    // Sorting algorithm
    for(i=0; i<n-1; i++) {
        for(j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    
    printf("\nSorted array is: ");
    for(i=0; i<n; i++){
        printf(" %d", arr[i]);
    }
    
    return 0;
}