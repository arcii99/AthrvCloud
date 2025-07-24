//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: light-weight
#include <stdio.h>

// Function to calculate the 8-bit Checksum for an input string
unsigned char calculateChecksum(char *str) {
    int sum = 0;
    int i;

    // Loop through the input string and add up all the ASCII values
    for (i = 0; str[i] != '\0'; i++) {
        sum += str[i];
    }

    // Calculate the 8-bit checksum by taking the LSB of the sum and subtracting from 256
    return (unsigned char) (256 - (sum & 0xFF));
}

int main() {
    char input[100];
    unsigned char checksum;

    // Get input string from user
    printf("Enter a string: ");
    fgets(input, 100, stdin);

    // Calculate the checksum and print it to the console
    checksum = calculateChecksum(input);
    printf("Checksum: %02X\n", checksum);

    return 0;
}