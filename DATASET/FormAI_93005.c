//FormAI DATASET v1.0 Category: QR code reader ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QR_CODE_SIZE 1024

int main()
{
    char qrCode[MAX_QR_CODE_SIZE];
    printf("Please scan a QR code: ");
    scanf("%s", qrCode);

    bool isValidQRCode = true; //assume it is valid until proven otherwise
    int qrCodeLength = strlen(qrCode);

    //check if the QR code is of the correct size
    if (qrCodeLength != 25)
    {
        isValidQRCode = false;
        printf("Invalid QR code size. Please scan a valid QR code of length 25.");
        return 0;
    }

    //check if the QR code only contains alphanumeric characters
    for (int i = 0; i < qrCodeLength; i++)
    {
        if (!isalnum(qrCode[i]))
        {
            isValidQRCode = false;
            printf("Invalid QR code. Please scan a QR code containing only alphanumeric characters.");
            return 0;
        }
    }

    if (isValidQRCode)
    {
        printf("Valid QR code scanned! The QR code contains: %s", qrCode);
        //TODO: implement code to process the QR code (e.g. store it in a database)
        return 0;
    }
}