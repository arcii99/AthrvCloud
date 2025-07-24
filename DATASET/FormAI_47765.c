//FormAI DATASET v1.0 Category: QR code reader ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <ctype.h>

#define MAX_LEN 100 // Maximum length of QR code input

int main(void)
{
    char input[MAX_LEN];
    printf("Enter the QR code:\n");
    fgets(input, sizeof(input), stdin);

    // Check if input is a valid QR code
    bool validInput = true;
    int i;
    for (i = 0; i < strlen(input); i++)
    {
        if (!isdigit(input[i]) && input[i] != 'A' && input[i] != 'B' && input[i] != 'C' && input[i] != 'D' && input[i] != 'E' && input[i] != 'F')
        {
            validInput = false;
            break;
        }
    }

    if (!validInput)
    {
        printf("Invalid QR code input. Only 0-9 and A-F characters are allowed.\n");
        return EXIT_FAILURE;
    }

    // Check if input is a secure QR code
    char secretCode[] = "0A10588B624EC1F1D3BDE72";
    if (strlen(input) != strlen(secretCode))
    {
        printf("Invalid QR code. Code length does not match.\n");
        return EXIT_FAILURE;
    }

    for (i = 0; i < strlen(input); i++)
    {
        if (input[i] != secretCode[i])
        {
            printf("WARNING! This is not the original QR code. Please check your source.\n");
            return EXIT_FAILURE;
        }
    }

    // Input is verified
    printf("Valid QR code. Proceeding with code reading...\n");

    // Code reading logic goes here

    return EXIT_SUCCESS;
}