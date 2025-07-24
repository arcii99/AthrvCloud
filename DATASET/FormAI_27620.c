//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: relaxed
#include <stdio.h>

// This program will calculate the checksum of a given string
// Note: Checksum is calculated by adding up the ASCII values of all characters in the string
// Convert the sum to a 2-digit hexadecimal value

int main() {
    char str[50];   // Input string
    int sum = 0;    // Sum of ASCII values of characters in the string
    int i;          // Loop index
    char hex[3];    // 2-digit hexadecimal value of the checksum
    
    printf("Enter a string: ");
    scanf("%s", str);
    
    // Calculate the sum of ASCII values of characters in the string
    for (i = 0; i < strlen(str); i++) {
        sum += str[i];
    }
    
    // Convert the sum to a 2-digit hexadecimal value
    sprintf(hex, "%X", sum % 256); // Use modulus operator to keep the value within 2^8 range
    
    printf("Checksum of the string is: 0x%s\n", hex);
    
    return 0;   // Exit program
}