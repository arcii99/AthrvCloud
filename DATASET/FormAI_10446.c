//FormAI DATASET v1.0 Category: QR code reader ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 1024

int main() {

    char qrCode[MAX_LENGTH];
    printf("Please enter the QR code: ");
    fgets(qrCode, MAX_LENGTH, stdin);
    qrCode[strlen(qrCode) - 1] = '\0';  // remove newline character

    // validate input
    if (strlen(qrCode) < 21) {
        printf("Invalid QR code! Must be at least 21 characters long.\n");
        return 1;
    }

    // decode QR code
    char message[MAX_LENGTH];
    int bitCount = 0, i = 0;
    while (i < strlen(qrCode) - 8) {
        int currentDigit = (qrCode[i++] - '0') * 100 + (qrCode[i++] - '0') * 10 + qrCode[i++] - '0';
        int currentChar = currentDigit - bitCount;
        message[bitCount / 3] = currentChar;
        bitCount += 3;
    }
    message[bitCount / 3] = '\0';

    printf("The decoded message is: %s\n", message);

    return 0;
}