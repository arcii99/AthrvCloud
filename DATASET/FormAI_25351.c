//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Declare variables
    int data[100], checksum = 0, size, i;

    // Get input from user
    printf("Enter the number of elements: ");
    scanf("%d", &size);

    // Checking for size of data
    if(size < 1 || size > 100) {
        printf("Invalid input!");
        exit(0);
    }

    // Get data elements from user
    printf("Enter the data elements: ");
    for(i = 0; i < size; i++) {
        scanf("%d", &data[i]);
    }

    // Calculate checksum value
    for(i = 0; i < size; i++) {
        checksum += data[i];
    }

    // Print checksum value
    printf("Checksum Value: %d", checksum);

    return 0;
}