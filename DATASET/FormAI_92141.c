//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>

/**
 * Calculates the C checksum of a given input string.
 *
 * @param input the string to calculate the checksum for
 * @return the checksum value
 */
unsigned int calculateChecksum(char* input) {
    unsigned int checksum = 0;
    int i = 0;

    while (input[i] != '\0') {
        checksum += input[i];
        i++;
    }

    return checksum;
}

int main() {
    printf("Enter a string to calculate the checksum for: ");

    char input[100];
    scanf("%s", input);

    unsigned int checksum = calculateChecksum(input);
    printf("The checksum of %s is: %u\n", input, checksum);

    return 0;
}