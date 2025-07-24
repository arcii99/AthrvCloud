//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum length of input string
#define MAX_LEN 256

// Define the generator polynomial
#define GENERATOR 0x95

// Calculate the checksum for the given input string
unsigned char calculate_checksum(unsigned char *input_string, int len)
{
    int i;
    unsigned char checksum = 0;

    for (i = 0; i < len; i++)
    {
        checksum ^= input_string[i];
        checksum = (checksum << 1) | (checksum >> 7);
    }
    checksum ^= GENERATOR;

    return checksum;
}

int main()
{
    char input_string[MAX_LEN];
    unsigned char *buffer = NULL;
    unsigned char checksum;
    int len;

    // Collect the input string
    printf("Enter the input string: ");
    scanf("%255s", input_string);
    len = strlen(input_string) + 1;

    // Allocate memory for input string
    buffer = (unsigned char *)malloc(len * sizeof(unsigned char));
    if (buffer == NULL)
    {
        printf("Memory allocation failed!");
        return 1;
    }

    // Copy input string to buffer
    memcpy(buffer, input_string, len);

    // Calculate the checksum
    checksum = calculate_checksum(buffer, len);

    // Print the checksum in a Cyberpunk style
    printf("Checksum: ");
    for (int i = 0; i < 8; i++)
    {
        if ((checksum & (1 << (7 - i))) == 0)
            printf("%c", '0');
        else
            printf("%c", '1');
    }
    printf("\n");

    free(buffer);
    return 0;
}