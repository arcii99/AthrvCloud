//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>

// Function to calculate the checksum
int checksum(int* arr, int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += *(arr+i);
    }
    return sum;
}

int main() {
    int size, *arr;

    // Read size of array from user
    printf("Enter the size of the array: ");
    scanf("%d", &size);

    // Allocate memory for array dynamically
    arr = (int*)malloc(size * sizeof(int));

    // Read array elements from user
    printf("Enter the elements of the array: ");
    for (int i = 0; i < size; i++) {
        scanf("%d", (arr+i));
    }

    // Calculate checksum
    int sum = checksum(arr, size);

    // Print the checksum
    printf("Checksum: %d\n", sum);

    // Free memory allocated for array
    free(arr);

    return 0;
}