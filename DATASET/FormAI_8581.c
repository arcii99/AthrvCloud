//FormAI DATASET v1.0 Category: Educational ; Style: genious
#include <stdio.h>

int main() {
    int arr[10] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9};
    
    // Print the original array
    printf("Original Array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    // Swap pairs of elements in the array
    for(int i = 0; i < 10; i += 2) {
        int temp = arr[i];
        arr[i] = arr[i+1];
        arr[i+1] = temp;
    }
    
    // Print the swapped array
    printf("Swapped Array: ");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    return 0;
}