//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: introspective
/* 
 * This is a C Checksum Calculator program which takes a string input from the user
 * and calculates the 8-bit checksum of the input string using one's complement addition.
 * The calculated checksum is then appended to the original string and printed to the console.
 */

#include <stdio.h>
#include <string.h>

// Function to calculate the 8-bit checksum of a given string
unsigned char calculate_checksum(char* str) {
    int i;
    unsigned char checksum = 0;
    int length = strlen(str);

    for (i = 0; i < length; i++) {
        checksum += str[i];
    }

    checksum = ~(checksum & 0xFF);
    return checksum;
}

int main() {
    char input_string[100];
    unsigned char checksum;

    printf("Enter a string to calculate checksum: ");
    fgets(input_string, sizeof(input_string), stdin);

    checksum = calculate_checksum(input_string);

    // Append the checksum to the input string
    sprintf(input_string + strlen(input_string), "%X", checksum);

    printf("Input string with checksum: %s\n", input_string);

    return 0;
}