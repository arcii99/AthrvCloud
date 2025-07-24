//FormAI DATASET v1.0 Category: QR code generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_SIZE 25
#define QR_CODE_SIZE 625

// Define QR Code structure
struct QR_Code {
    int size;
    char content[QR_CODE_SIZE];
};

// Function to generate QR Code
struct QR_Code generateQRCode() {
    // Set random seed
    srand(time(NULL));

    // Create new QR Code object
    struct QR_Code qrCode;
    qrCode.size = QR_SIZE;

    // Generate random data for QR Code
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            qrCode.content[i * QR_SIZE + j] = rand() % 2 ? '1' : '0';
        }
    }

    // Return QR Code
    return qrCode;
}

// Function to print QR Code
void printQRCode(struct QR_Code qrCode) {
    for (int i = 0; i < qrCode.size; i++) {
        for (int j = 0; j < qrCode.size; j++) {
            printf("%c", qrCode.content[i * QR_SIZE + j]);
        }
        printf("\n");
    }
}

// Main function
int main() {
    // Generate and print QR Code
    struct QR_Code qrCode = generateQRCode();
    printQRCode(qrCode);

    // Exit
    return 0;
}