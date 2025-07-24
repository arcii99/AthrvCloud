//FormAI DATASET v1.0 Category: QR code reader ; Style: funny
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    printf("Welcome to the hilarious QR code reader!\n");

    char *qrCode = (char*) malloc(100 * sizeof(char));
    printf("Please enter the QR code you want to scan (or 'quit' to exit): ");
    scanf("%s", qrCode);

    while (strcmp(qrCode, "quit") != 0)
    {
        if (strlen(qrCode) != 21)
        {
            printf("Uh oh...this doesn't look like a valid QR code. Are you sure you got it from a legitimate source? Try again (or 'quit' to exit): ");
        }
        else
        {
            printf("Scanning...\n");
            for (int i = 0; i < strlen(qrCode); i++)
            {
                if (qrCode[i] == 'C')
                {
                    printf("C you later...this QR code is invalid. Try again (or 'quit' to exit): ");
                    break;
                }
                else if (qrCode[i] == 'Q')
                {
                    printf("Q is for quality, and this QR code is top notch! Congratulations on a successful scan.\n");
                    break;
                }
            }
        }

        scanf("%s", qrCode);
    }

    free(qrCode);
    printf("Thanks for using the hilarious QR code reader! Come back soon for more laughs.\n");

    return 0;
}