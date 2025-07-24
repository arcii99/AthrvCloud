//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Ephemeral style C Checksum Calculator example program

// Define our checksum calculation function
int calculateChecksum(char* data) {
    int length = strlen(data);
    int sum = 0;

    // Iterate over every byte in the input data and calculate the sum
    for (int i = 0; i < length; i++) {
        sum += (int)data[i];
    }

    // Return the sum as our checksum value
    return sum;
}

int main() {
    // Welcome message
    printf("Welcome to the Ephemeral Checksum Calculator!\n\n");

    // Prompt the user for input data
    printf("Please enter the data you would like to calculate the checksum for: ");
    char input[100];
    fgets(input, sizeof(input), stdin);
    input[strcspn(input, "\n")] = 0; // Remove trailing newline

    // Call our checksum calculation function
    int checksum = calculateChecksum(input);

    // Display the result
    printf("The checksum for '%s' is: %d\n", input, checksum);

    // Goodbye message
    printf("\nThank you for using the Ephemeral Checksum Calculator! Have a nice day.\n");

    return 0;
}