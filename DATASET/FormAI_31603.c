//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: statistical
#include <stdio.h>

/*
This program calculates the checksum of a given input string.
The checksum is the sum of all the ASCII values of the characters.
*/

int main() {
    char input[100];
    int checksum = 0;
    
    // Get user input
    printf("Enter a string to calculate the checksum:\n");
    fgets(input, sizeof(input), stdin);
    
    // Calculate checksum
    for (int i = 0; input[i] != '\0'; i++) {
        checksum += (int)input[i];
    }
    
    // Display results
    printf("Checksum: %d\n", checksum);
    
    return 0;
}