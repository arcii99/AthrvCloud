//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

// function to calculate checksum of given input string
unsigned char calcChecksum(char *input)
{
    unsigned char sum = 0;
    while (*input != '\0')
    {
        sum += *input++;
    }
    return sum;
}

int main()
{
    printf("Enter the input string: ");
    char input[100];
    scanf("%s", input); // get input from user

    unsigned char checksum = calcChecksum(input); // calculate checksum

    printf("The checksum of input string '%s' is: %u\n", input, checksum);

    return 0;
}