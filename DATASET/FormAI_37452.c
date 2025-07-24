//FormAI DATASET v1.0 Category: QR code reader ; Style: cheerful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

int main()
{
    printf("*** Welcome to the C QR Code Reader! ***\n\n");
    printf("Please scan your QR code...\n");

    char QRCode[100];
    scanf("%s", QRCode);

    bool validQRCode = true;
    bool reachedEnd = false;
    int currentIndex = 0;

    while (validQRCode && !reachedEnd)
    {
        if (QRCode[currentIndex] != 'C' && QRCode[currentIndex] != 'O' && QRCode[currentIndex] != 'D' && QRCode[currentIndex] != 'E')
        {
            printf("Invalid QR Code. Please rescan.\n");
            validQRCode = false;
        }
        else if (QRCode[currentIndex] == 'E')
        {
            printf("QR Code read successfully!\n");
            reachedEnd = true;
        }

        currentIndex++;
    }

    if (reachedEnd)
    {
        printf("Thank you for scanning your QR code with us!\n");
    }

    return 0;
}