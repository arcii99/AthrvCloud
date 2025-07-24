//FormAI DATASET v1.0 Category: QR code reader ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_CODE_LENGTH 100

int main()
{
    char qrCode[MAX_CODE_LENGTH];
    bool isValidQR = false;

    printf("Welcome to the QR Code Reader Program\n");
    printf("Please enter a valid QR code:\n");
    scanf("%s", qrCode);

    if(strlen(qrCode) < 6)
    {
        printf("Invalid QR Code. Too short.\n");
        return 1;
    }

    // Check if the string starts with "QR-"
    if(strncmp(qrCode, "QR-", 3) == 0)
    {   
        // Check if the rest of the string consists of only digits
        for(int i = 3; qrCode[i] != '\0'; i++)
        {
            if(!isdigit(qrCode[i]))
            {
                printf("Invalid QR Code. Only digits allowed after 'QR-'\n");
                return 1;
            }
        }
        isValidQR = true;
    }

    if(isValidQR)
    {
        printf("QR Code is valid and the code is: %s\n", qrCode);
    }
    else
    {
        printf("Invalid QR Code\n");
    }

    return 0;
}