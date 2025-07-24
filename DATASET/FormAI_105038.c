//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: standalone
#include <stdio.h>

int main() {
    int i, n, sum = 0;
    printf("Enter the number of integers: ");
    scanf("%d", &n);

    // Allocate memory for array
    int *arr = (int *) malloc(n * sizeof(int));

    // Take input from user
    printf("Enter the integers: ");
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
        sum += arr[i];
    }

    // Calculate the checksum
    int checksum = ~(sum % 256);

    // Print the checksum
    printf("The checksum is: %d\n", checksum);

    // Free the memory
    free(arr);
    return 0;
}