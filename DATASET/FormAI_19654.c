//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: creative
#include <stdio.h>

/* Function to calculate checksum of a given string */
int calculate_checksum(char *str) {
    int len = strlen(str);
    int sum = 0;
    int i;

    /* Iterate through each character in the string */
    for (i = 0; i < len; i++) {
        sum += str[i] * (i + 1); // Calculate the sum of character values multiplied by the character position
    }

    return sum % 256; // Return the result modulo 256 to ensure a single byte checksum
}

int main() {

    char input[50]; // Buffer to hold user input string

    printf("Enter a string to calculate its checksum:\n");
    scanf("%s", input); // Read user input string
    
    int checksum = calculate_checksum(input); // Calculate the checksum of input string
    printf("Checksum of %s is: %d\n", input, checksum); // Display the checksum value

    return 0;
}