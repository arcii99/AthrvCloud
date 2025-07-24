//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: excited
/**
 * 
 * Are you ready to compute some checksum? Let's do this!
 * 
 **/

#include <stdio.h>
#include <string.h>

int main() {
    printf("Welcome to the exciting world of C Checksum Calculator!\n");
    printf("This program will calculate the checksum of any given string.\n\n");

    char inputString[100];
    int checksumValue = 0;

    printf("Enter the string (at most 100 characters): \n");
    fgets(inputString, sizeof(inputString), stdin);

    printf("\nCalculating checksum... please wait...\n\n");

    // Begin iterating through each character in the input string
    for (int i = 0; i < strlen(inputString); i++) {
        checksumValue += (int) inputString[i]; // add the ASCII value of each character to the checksum value
    }

    printf("Your checksum value is: %d\n\n", checksumValue);

    printf("Thank you for using the C Checksum Calculator. Stay tuned for more exciting programs!\n");

    return 0;
}