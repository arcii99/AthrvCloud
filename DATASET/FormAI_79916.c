//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Ada Lovelace
// Ada Lovelace C Checksum Calculator
// This program calculates the checksum of an input string using the C language.

#include <stdio.h>
#include <string.h>

// This function takes a string as input and returns its checksum.
int calculate_checksum(char *str) {
    int checksum = 0; // initialize the checksum to zero
    int len = strlen(str); // find the length of the string

    for(int i = 0; i < len; i++) {
        checksum += (int) str[i]; // add each character's ASCII value to the checksum
    }

    return checksum;
}

int main() {
    char str[100]; // create a char array to hold the input string
    int checksum; // create a variable to hold the checksum

    printf("Welcome to the Ada Lovelace Checksum Calculator!\n");
    printf("Please enter a string to calculate its checksum: ");
    fgets(str, 100, stdin); // use fgets to get the input string

    checksum = calculate_checksum(str); // calculate the checksum

    printf("The checksum of your input is: %d\n", checksum);

    return 0;
}