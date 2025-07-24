//FormAI DATASET v1.0 Category: QR code reader ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>
#include <string.h>

// QR Code definition
typedef struct _QRCode
{
    char version[3];
    char data[100];
    char error_correction_level;
    char mask[2];
} QRCode;

// Function to read QR code from input file
void readQRCode(FILE* file_ptr, QRCode* qr_code)
{
    char buffer[100];

    // Reading version
    fgets(buffer, 3, file_ptr);
    strcpy(qr_code->version, buffer);
    
    // Reading data
    fgets(buffer, 100, file_ptr);
    strcpy(qr_code->data, buffer);
    
    // Reading error correction level
    fgets(buffer, 2, file_ptr);
    qr_code->error_correction_level = buffer[0];

    // Reading mask
    fgets(buffer, 2, file_ptr);
    strcpy(qr_code->mask, buffer);
}

// Function to print QR code data
void printQRCode(QRCode* qr_code)
{
    printf("Version: %s\n", qr_code->version);
    printf("Data: %s\n", qr_code->data);
    printf("Error Correction Level: %c\n", qr_code->error_correction_level);
    printf("Mask: %s\n", qr_code->mask);
}

int main()
{
    // Reading QR code from file
    FILE* file_ptr = fopen("qrcode.txt", "r");
    if (file_ptr == NULL)
    {
        printf("Failed to open file.\n");
        return 1;
    }

    QRCode qr_code;
    readQRCode(file_ptr, &qr_code);
    fclose(file_ptr);

    // Printing QR code data
    printQRCode(&qr_code);

    return 0;
}