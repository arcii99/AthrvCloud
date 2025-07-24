//FormAI DATASET v1.0 Category: QR code reader ; Style: active
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

// Function to convert binary string to integer
int binaryToDecimal(char *binaryString) {
    int result = 0;
    for (int i = 0; i < strlen(binaryString); i++) {
        result = result * 2 + binaryString[i] - '0';
    }
    return result;
}

// Parse QR code and return message
char* readQRCode(char *qrData) {

    // Validate QR code format
    if (strlen(qrData) != 144) {
        return "Invalid QR code format";
    }

    // Extract data
    char *dataStart = strstr(qrData, "0000000100000111");
    if (dataStart == NULL) {
        return "Unable to extract data from QR code";
    }

    // Parse data
    char *data = calloc(1, strlen(dataStart) + 1);
    int dataLength = 0;
    for (int i = 0; i < strlen(dataStart); i+=8) {
        char binaryString[9] = "";
        strncpy(binaryString, dataStart + i, 8);
        int value = binaryToDecimal(binaryString);
        if (value > 128) {
            value -= 128;
            dataLength += value;
        } else {
            strncat(data, dataStart + i + 1, value);
        }
    }

    // Validate data length
    if (strlen(data) != dataLength) {
        return "Invalid data length in QR code";
    }

    return data;
}

int main() {

    // Read QR code from user
    printf("Enter QR code data: ");
    char qrData[145] = "";
    fgets(qrData, 145, stdin);

    // Clean up input
    qrData[strcspn(qrData, "\n")] = '\0';
    for (int i = 0; i < strlen(qrData); i++) {
        qrData[i] = (char) toupper(qrData[i]);
    }

    // Read QR code
    char *qrMessage = readQRCode(qrData);

    // Output result
    printf("QR code message: %s\n", qrMessage);

    // Free memory
    free(qrMessage);

    return 0;
}