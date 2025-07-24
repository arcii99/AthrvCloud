//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

unsigned int checksum(char *message, int length)
{
    // initialize sum variable
    unsigned int sum = 0;

    // iterate through each character in message
    for (int i = 0; i < length; i++)
    {
        // add ascii value of character to sum
        sum += (unsigned int) message[i];
    }

    // return the sum
    return sum;
}

int main()
{
    // prompt user for input message
    printf("Please enter the message to calculate the checksum: ");
    char input[100];
    fgets(input, sizeof(input), stdin);

    // calculate checksum of input message
    unsigned int sum = checksum(input, strlen(input));

    // print checksum value
    printf("The checksum of the message is %u\n", sum);

    return 0;
}