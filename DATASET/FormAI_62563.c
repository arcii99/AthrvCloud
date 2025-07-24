//FormAI DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdint.h>
#include <string.h>

// Define the maximum length of the QR code
#define MAX_QR_CODE_LENGTH 63

// Define the maximum length of the message contained in the QR code
#define MAX_MESSAGE_LENGTH 255

// Define the structure for holding the QR code data
typedef struct {
    uint8_t version;
    uint8_t size;
    uint8_t data[MAX_QR_CODE_LENGTH];
    char message[MAX_MESSAGE_LENGTH + 1];
} QRCode;

// Function for reading QR code from a file
bool readQRCode(const char *filename, QRCode *qrCode) {
    FILE *fp;
    uint8_t version, size;
    uint8_t data[MAX_QR_CODE_LENGTH];
    char message[MAX_MESSAGE_LENGTH + 1];
    uint8_t i;

    // Open the file
    fp = fopen(filename, "rb");
    if (fp == NULL) {
        return false;
    }

    // Read the version and size of the QR code
    fread(&version, sizeof(version), 1, fp);
    fread(&size, sizeof(size), 1, fp);

    // Read the data of the QR code
    fread(data, sizeof(uint8_t), size, fp);

    // Close the file
    fclose(fp);

    // Convert the data to a message
    for (i = 0; i < size; i++) {
        message[i] = (char)(data[i] + 'a');
    }
    message[size] = '\0';

    // Save the QR code data
    qrCode->version = version;
    qrCode->size = size;
    memcpy(qrCode->data, data, size);
    strcpy(qrCode->message, message);

    return true;
}

int main() {
    QRCode qrCode;

    // Read the QR code from file
    if (!readQRCode("qr_code.dat", &qrCode)) {
        printf("Failed to read QR code from file.");
        return EXIT_FAILURE;
    }

    // Print the QR code data
    printf("Version: %d\n", qrCode.version);
    printf("Size: %d\n", qrCode.size);
    printf("Data: ");
    for (uint8_t i = 0; i < qrCode.size; i++) {
        printf("%d ", qrCode.data[i]);
    }
    printf("\nMessage: %s\n", qrCode.message);

    return EXIT_SUCCESS;
}