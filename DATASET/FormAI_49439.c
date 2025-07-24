//FormAI DATASET v1.0 Category: Sorting ; Style: surprised
#include <stdio.h>

int main() {
    int arr[] = { 1, 23, 12, 9, 30, 2, 50 }; 
    int n = sizeof(arr)/sizeof(arr[0]); 
    printf("Before sorting: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Sorting the array using bubble sort...\n");
    for(int i=0; i<n-1; i++) {
        for(int j=0; j<n-i-1; j++) {
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    printf("\nAfter sorting: \n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
    printf("Wow! The array is now sorted.\n");
    return 0;
}