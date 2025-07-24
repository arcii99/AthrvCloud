//FormAI DATASET v1.0 Category: QR code generator ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_DATA_LENGTH 1000

char* qrCodeGenerator(char* data) {
    int dataLength = strlen(data);

    // Allocate memory for the QR code
    char* qrCode = (char*) malloc(sizeof(char) * (dataLength + 2));

    // Add data to the QR code
    strcpy(qrCode, data);

    // Add error correction code
    int ecc = 0;
    for (int i = 0; i < dataLength; i++) {
        ecc += (int) data[i];
    }
    qrCode[dataLength] = (char) (ecc % 256);
    qrCode[dataLength + 1] = '\0';

    return qrCode;
}

int main() {
    char data[MAX_DATA_LENGTH];

    printf("Enter data to generate QR code:\n");
    fgets(data, MAX_DATA_LENGTH, stdin);

    // Remove newline character
    data[strcspn(data, "\n")] = '\0';

    char* qrCode = qrCodeGenerator(data);

    printf("QR code generated successfully:\n%s\n", qrCode);

    free(qrCode);

    return 0;
}