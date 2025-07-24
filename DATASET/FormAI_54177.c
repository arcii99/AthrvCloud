//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: retro
#include <stdio.h>
#include <string.h>

// Function to calculate the checksum
unsigned char checksum(char *str) {
    int sum = 0;
    int i;

    for (i = 0; i < strlen(str); i++) {
        sum += (int) str[i];
    }

    // Return the checksum as unsigned char
    return (unsigned char) sum;
}

int main() {

    char str[100];

    // Print the welcome message
    printf("Welcome to the Retro Checksum Calculator!\n\n");

    // Get the user input string
    printf("Enter a string: ");
    scanf("%[^\n]", str);

    // Calculate the checksum
    unsigned char sum = checksum(str);

    // Print the checksum
    printf("\nChecksum of '%s' is: %u\n", str, sum);

    // Print the farewell message
    printf("\nThank you for using the Retro Checksum Calculator!\n");

    return 0;
}