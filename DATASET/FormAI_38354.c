//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

int main()
{
    int sum = 0, carry = 0, i, len;
    char input[1000];

    // Take user input
    printf("Enter a string: ");
    scanf("%s", input);

    // Calculate the length of the input string
    for(i = 0; input[i] != '\0'; i++);

    len = i;

    // Add all the ASCII values of the characters and keep the carry
    for(i = 0; i < len; i++)
    {
        sum += input[i];
        if(sum > 255)
        {
            carry = 1;
            sum -= 256;
        }
    }

    // If there is a carry, add it to the sum
    if(carry)
    {
        sum += 1;
    }

    // Calculate the 1's complement of the sum
    int ones_complement = ~sum;

    // Checksum is the last 8 bits of the 1's complement
    int checksum = ones_complement & 0x00FF;

    // Print the input string and the corresponding checksum
    printf("Input string: %s\n", input);
    printf("Checksum: %X\n", checksum);

    return 0;
}