//FormAI DATASET v1.0 Category: QR code reader ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to decode the QR Code
void decodeQRCode(char* qrCodeString) {
    int i, j, k, l;
    int sum = 0;
    int length = strlen(qrCodeString);

    for (i = 0; i < length; i += 12) {
        // Check if it is valid QR Code segment
        if (qrCodeString[i] != 'Q' ||
            qrCodeString[i + 1] != 'R' ||
            qrCodeString[i + 2] != '-' ||
            qrCodeString[i + 10] != '-') {

            printf("Invalid QR Code\n");
            return;
        }

        // Extract the version number from the QR Code
        int version = qrCodeString[i + 3] - '0';
        if (version < 1 || version > 40) {
            printf("Invalid QR Code version\n");
            return;
        }

        // Extract the character count from the QR Code
        int charCount = 0;
        for (j = 0; j < 4; j++) {
            charCount = charCount * 10 + (qrCodeString[i + 4 + j] - '0');
        }

        // Extract the data from the QR Code
        char* data = (char*)malloc((charCount + 1) * sizeof(char));
        for (j = 0, k = i + 8; j < charCount; j++, k += 2) {
            int value = (qrCodeString[k] - '0') * 10 + (qrCodeString[k + 1] - '0');
            data[j] = (char)value;
        }
        data[charCount] = '\0';

        // Calculate the checksum
        l = i + 4 + charCount + 4;
        for (j = i + 4; j < l; j++) {
            sum = sum * 256 + qrCodeString[j];
        }
        sum = sum % 255;

        // Check if the checksum is correct
        if (sum != qrCodeString[l]) {
            printf("Invalid QR Code checksum\n");
            return;
        }

        // Print the data from the QR Code
        printf("QR Code Segment %d at version %d:\n%s\n", (i / 12) + 1, version, data);

        free(data);
    }
}

int main() {
    // Example QR Code string
    char qrCodeString[] =
            "QR-020401-12This is a QR Code.-4076"
            "QR-020402-11It is created using C.-3228"
            "QR-020403-19It can hold data up to 7089 characters.-2310"
            "QR-020404-12Try scanning this QR Code.-999";

    // Decode the QR Code
    decodeQRCode(qrCodeString);

    return 0;
}