//FormAI DATASET v1.0 Category: Math exercise ; Style: optimized
#include <stdio.h>

int main() {

    int arr[10]; // Declare an integer array with size 10
    int pos = 0;
    int neg = 0;
    int zero = 0;

    // Loop through the array and populate with user input
    for(int i = 0; i < 10; i++) {
        printf("Enter value for arr[%d]: ", i);
        scanf("%d", &arr[i]);

        // Check if value is positive, negative or zero
        if(arr[i] > 0) {
            pos++;
        } else if(arr[i] < 0) {
            neg++;
        } else {
            zero++;
        }
    }

    // Output the contents of the array
    printf("\nArray Values:\n");
    for(int i = 0; i < 10; i++) {
        printf("%d ", arr[i]);
    }

    // Output some statistics on the array
    printf("\n\nArray Statistics:\n");
    printf("Number of Positive Values: %d\n", pos);
    printf("Number of Negative Values: %d\n", neg);
    printf("Number of Zero Values: %d\n", zero);

    return 0;
}