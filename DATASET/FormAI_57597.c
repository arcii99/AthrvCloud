//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: complete
#include <stdio.h>

// Function to calculate checksum
int calc_checksum(char input[], int length) {
    int i, sum = 0;
    
    // Calculate the sum of ASCII values of all characters
    for (i = 0; i < length; i++) {
        sum += (int)input[i];
    }
    
    // Return the checksum
    return sum % 256;
}

int main() {
    char input[100];
    int length, checksum;
    
    // Take user input
    printf("Enter a string (max 100 characters): ");
    fgets(input, 100, stdin);
    
    // Calculate length of string
    length = strlen(input) - 1; // Subtract 1 to remove newline character
    
    // Calculate checksum
    checksum = calc_checksum(input, length);
    
    // Output checksum
    printf("Checksum of the entered string is: %d\n", checksum);
    
    return 0;
}