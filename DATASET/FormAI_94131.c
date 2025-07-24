//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * This program calculates a unique checksum value for a given input string.
 * The checksum value is calculated by taking the sum of all the ASCII values of the characters in the string,
 * and then multiplying it by a random number generated at runtime.
 */

int main() {
    char input[256];
    int checksum = 0;
    srand(time(NULL)); // Seed the random number generator with current time

    printf("Welcome to the happy checksum calculator!\n");
    printf("Please enter a string to calculate its checksum: ");
    fgets(input, sizeof(input), stdin); // Read string from user input

    // Calculate the checksum by looping through each character in the string
    for (int i = 0; input[i] != '\0'; i++) {
        checksum += (int) input[i]; // Add the ASCII value of each character to checksum
    }

    // Generate a random number between 1 and 10
    int randomNum = rand() % 10 + 1;

    printf("\nThank you for using the happy checksum calculator!\n");
    printf("The checksum value for \"%s\" is: %d\n", input, checksum * randomNum);

    return 0;
}