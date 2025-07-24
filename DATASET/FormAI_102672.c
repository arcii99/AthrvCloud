//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: all-encompassing
// C Checksum Calculator Example Program

#include<stdio.h>
#include<string.h>

// Function to calculate checksum
int calculateChecksum(char data[]) {
    int checksum = 0, i;

    // Loop through each character in the data
    for (i = 0; i < strlen(data); i++) {
        // Add the ASCII value of the character to the checksum
        checksum += (int)data[i];
    }

    // Take the two's complement of the checksum
    checksum = (checksum ^ 0xFF) + 1;

    // Return the checksum
    return checksum;
}

int main() {
    // Declare variables
    char data[50];
    int checksum;

    // Get data from user
    printf("Enter data to calculate checksum: ");
    fgets(data, 50, stdin);

    // Calculate the checksum
    checksum = calculateChecksum(data);

    // Print the checksum
    printf("Checksum of the data is: %d", checksum);

    return 0;
}