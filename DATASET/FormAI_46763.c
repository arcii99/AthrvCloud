//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>

/* The function calculate_checksum takes in a char array (buf) and its size (size).
It calculates a checksum for the array by adding up the integer value of each character.
It then returns the checksum value as an unsigned 16-bit integer */
unsigned short calculate_checksum(char *buf, size_t size) {
    unsigned int sum = 0;
    for (size_t i = 0; i < size; i++) {
        sum += buf[i];
    }
    return (unsigned short) (sum & 0xFFFF);
}

int main() {
    // Create an array of characters to calculate the checksum for
    char buf[] = {'C', 'h', 'e', 'c', 'k', 's', 'u', 'm', ' ', 'E', 'x', 'a', 'm', 'p', 'l', 'e'};

    // Determine the size of the array
    size_t size = sizeof(buf) / sizeof(buf[0]);

    // Calculate the checksum for the array
    unsigned short checksum = calculate_checksum(buf, size);

    // Print out the original array and its checksum value
    printf("Original Array: ");
    for (size_t i = 0; i < size; i++) {
        printf("%c", buf[i]);
    }
    printf("\nChecksum Value: 0x%04X\n", checksum);

    return 0;
}