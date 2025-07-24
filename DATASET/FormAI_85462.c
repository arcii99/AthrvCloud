//FormAI DATASET v1.0 Category: QR code reader ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_SIZE 1000

// Helper function to convert hexadecimal to decimal
int hexToDec(char hexDigit) {
    if (hexDigit >= 'A' && hexDigit <= 'F')
        return 10 + hexDigit - 'A';
    else if (hexDigit >= '0' && hexDigit <= '9')
        return hexDigit - '0';
    return -1;
}

// Function to decode QR code
void decodeQRCode(char* qrCode) {
    char* data = malloc(sizeof(char) * MAX_SIZE);
    int pos = 0;
    int i = 0;
    while (qrCode[i] != '\0') {
        if (qrCode[i] == '%') {
            i++;
            int hexValue = hexToDec(qrCode[i]) * 16 + hexToDec(qrCode[i+1]);
            data[pos] = (char)hexValue;
            i += 2;
            pos++;
        }
        else {
            data[pos] = qrCode[i];
            pos++;
            i++;
        }
    }
    printf("Decoded QR Code: %s\n", data);
    free(data);
}

int main() {
    // Read input from console
    char* qrCode = malloc(sizeof(char) * MAX_SIZE);
    printf("Enter QR code: ");
    fgets(qrCode, MAX_SIZE, stdin);
    // Remove newline character at the end
    qrCode[strcspn(qrCode, "\n")] = '\0';
    // Decode QR code
    decodeQRCode(qrCode);
    free(qrCode);
    return 0;
}