//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: introspective
#include <stdio.h>

// Function to calculate the C checksum of a given string
int calculate_checksum(char* str) {
    int checksum = 0; // Initialize the checksum to 0

    // Loop through each character of the string
    for(int i = 0; str[i] != '\0'; i++) {
        checksum += (int) str[i]; // Add the ASCII value of the character to the checksum
    }

    checksum = checksum % 256; // Take the modulo 256 of the final sum to get the checksum value
    return checksum; // Return the checksum value
}

int main() {
    char str[100]; // Define a character array to store the input string
    printf("Enter the string: ");
    scanf("%[^\n]%*c", str); // Use scanf to read the whole string, including spaces

    int checksum = calculate_checksum(str); // Call the function to calculate the checksum
    printf("The C checksum of the given string is: %d\n", checksum); // Print the checksum value

    return 0; // End of program
}