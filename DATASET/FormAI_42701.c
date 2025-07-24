//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: invasive
#include <stdio.h>
#include <stdlib.h>

/* Function to calculate checksum of a string */
unsigned char checksum(char *word)
{
    unsigned char csum = 0;
    int i = 0;

    while (word[i] != '\0') 
    {
        csum += (unsigned char)word[i];
        i++;
    }

    return csum;
}

/* Main function */
int main()
{
    printf("Welcome to Checksum Calculator!\n");

    /* Prompt the user to enter a string */
    char str[100];
    printf("Please enter a string: ");
    fgets(str, sizeof(str), stdin);

    /* Calculate the checksum */
    unsigned char chksum = checksum(str);

    /* Print the calculated checksum */
    printf("The checksum of the string is: %u\n", chksum);

    return 0;
}