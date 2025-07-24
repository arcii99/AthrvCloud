//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: random
/*
A unique C Checksum Calculator program
This program generates a checksum for a string by summing the ASCII values of each character
Author: Random Programmer

*/

#include <stdio.h>
#include <string.h>

int main(void)
{
    printf("Welcome to the Checksum Calculator!\n");

    char input[1000];
    printf("Please enter the string you would like to calculate the checksum for: ");
    scanf("%[^\n]", input); // get input string with spaces

    int sum = 0;
    int len = strlen(input);

    for (int i = 0; i < len; i++)
    {
        sum += (int)input[i];
    }

    int checksum = sum % 256;

    printf("\nThe ASCII sum is: %d", sum);
    printf("\nThe checksum is: %d", checksum);

    printf("\nThank you for using the Checksum Calculator!\n");

    return 0;
}