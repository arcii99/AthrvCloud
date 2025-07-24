//FormAI DATASET v1.0 Category: Sorting ; Style: Ken Thompson
// Ken Thompson Style Sorting Example Program

#include <stdio.h>
#include <stdlib.h>

#define MAX_ARRAY_SIZE 100

int main() {
    
    int array[MAX_ARRAY_SIZE], i, j, temp, n;
    
    // Take user input for the size of the array
    printf("Enter the size of the array (max %d): ", MAX_ARRAY_SIZE);
    scanf("%d", &n);
    
    // Check if the array size is valid
    if (n <= 0 || n > MAX_ARRAY_SIZE) {
        printf("Invalid array size!");
        return 0;
    }
    
    // Take user input for the array elements
    printf("Enter the array elements:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &array[i]);
    }
    
    // Implementing Ken Thompson style sorting algorithm
    for (i = 0; i < n - 1; i++) {
        for (j = i + 1; j < n; j++) {
            if (array[j] < array[i]) {
                temp = array[i];
                array[i] = array[j];
                array[j] = temp;
            }
        }
    }
    
    // Display the sorted array
    printf("Sorted array:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", array[i]);
    }
    
    return 0;
}