//FormAI DATASET v1.0 Category: QR code reader ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define QR_CODE_MAX_LENGTH 100

bool isValidQRCodeChar(char c)
{
    if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9'))
    {
        return true;
    }
    return false;
}

bool isValidQRCode(char qrCode[])
{
    int qrCodeLength = strlen(qrCode);
    if (qrCodeLength > QR_CODE_MAX_LENGTH)
    {
        return false;
    }
    for (int i = 0; i < qrCodeLength; i++)
    {
        if (!isValidQRCodeChar(qrCode[i]))
        {
            return false;
        }
    }
    return true;
}

void readQRCode(char qrCode[])
{
    printf("Please scan the QR Code: \n");
    fgets(qrCode, QR_CODE_MAX_LENGTH, stdin);
    qrCode[strcspn(qrCode, "\n")] = '\0'; // remove trailing newline character from input
}

void processQRCode(char qrCode[])
{
    if (isValidQRCode(qrCode))
    {
        printf("QR Code : %s\n", qrCode);
        // Add your custom processing logic here
    }
    else
    {
        printf("Invalid QR code. Please try again.\n");
        readQRCode(qrCode);
        processQRCode(qrCode);
    }
}

int main()
{
    char qrCode[QR_CODE_MAX_LENGTH];
    readQRCode(qrCode);
    processQRCode(qrCode);
    return 0;
}