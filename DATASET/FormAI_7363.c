//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>

// Function to calculate checksum of a string
int calculateChecksum(char string[]) {
    int checksum = 0;  // Initializing checksum variable to 0
    int i = 0;  // Initializing i to 0 for iteration

    // Iterating over each character of string until null character is encountered
    while (string[i] != '\0') {
        checksum += (int) string[i];  // Adding ASCII value of character to checksum
        i++;  // Incrementing i for next iteration
    }

    return checksum;  // Returning final checksum
}

int main() {
    char inputString[100];  // Initializing char array to store user input
    int checksum;  // Initializing integer variable to store final checksum

    // Prompting user to enter a string
    printf("Enter a string: ");

    // Reading user input string and storing it in inputString variable
    fgets(inputString, 100, stdin);

    // Removing newline character from inputString
    inputString[strcspn(inputString, "\n")] = 0;

    // Calling calculateChecksum function to calculate checksum
    checksum = calculateChecksum(inputString);

    // Printing final checksum to console
    printf("Checksum of string '%s' is %d\n", inputString, checksum);

    return 0;  // Exiting program with 0 status
}