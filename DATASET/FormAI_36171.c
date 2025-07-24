//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: ephemeral
// Ephemeral C Checksum Calculator

#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Define variables
    int num, i, checksum = 0;
    
    // Prompt the user for input
    printf("Enter a number: ");
    scanf("%d", &num);
    
    // Calculate the checksum
    while (num != 0) {
        checksum += num % 10;
        num /= 10;
        checksum %= 10;
    }
    
    // Print the checksum
    printf("The checksum is: %d\n", checksum);

    // Exit the program
    return 0;
}