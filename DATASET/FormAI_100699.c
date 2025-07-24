//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: genious
#include <stdio.h>

/**
 * This program calculates the checksum of a user input string by summing up the ASCII values of each character.
 * The final checksum value is then printed to the console.
 */

int main() {
    char input[100];
    int checksum = 0;

    // Get input from the user
    printf("Enter a string to calculate the checksum: ");
    scanf("%s", input);

    // Calculate checksum by summing up ASCII values of each character
    for(int i = 0; input[i] != '\0'; i++) {
        checksum += (int) input[i];
    }

    // Print the final checksum value
    printf("The checksum of '%s' is %d.", input, checksum);

    return 0;
}