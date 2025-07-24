//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Sherlock Holmes
#include <stdio.h>

// Function to calculate the checksum
int calculateChecksum(char *str) {
    int sum = 0;
    int i;
    
    // Loop through the string
    for (i = 0; str[i] != '\0'; i++) {
        // Add the ASCII value of the character to the sum
        sum += str[i];
    }
    
    // Return the sum modulo 26
    return sum % 26;
}

int main() {
    // Declare an array to store the input string
    char input[100];
    
    // Prompt the user for input
    printf("Enter a string: ");
    fgets(input, 100, stdin);
    
    // Calculate the checksum and print the result
    int checksum = calculateChecksum(input);
    printf("The checksum is %c.\n", 'A' + checksum);
    
    return 0;
}