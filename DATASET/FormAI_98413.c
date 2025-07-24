//FormAI DATASET v1.0 Category: QR code reader ; Style: cheerful
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

int main(void)
{
    printf("Welcome to the C QR Code Reader! Let's scan a code!\n");

    while (true)
    {
        char code[100];
        printf("Please enter a QR code string: ");
        fgets(code, sizeof(code), stdin);

        // Remove trailing newline character from code string
        code[strcspn(code, "\n")] = '\0';

        // Check if code is valid
        if (strcmp(code, "QUIT") == 0)
        {
            printf("Goodbye!\n");
            break;
        }
        else if (strlen(code) < 10)
        {
            printf("Invalid code. Please try again.\n");
            continue;
        }

        // Decode QR code
        printf("Decoding QR code...\n");
        // Code decoding magic happens here

        // Display result to user
        printf("QR code read successfully! Here is the result:\n");
        printf("%s\n", code);

        // Check if user wants to scan another code
        printf("Would you like to scan another code? (y/n): ");
        char answer[2];
        fgets(answer, sizeof(answer), stdin);

        if (tolower(answer[0]) == 'n')
        {
            printf("Goodbye!\n");
            break;
        }
    }

    return EXIT_SUCCESS;
}