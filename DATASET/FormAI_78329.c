//FormAI DATASET v1.0 Category: QR code generator ; Style: portable
#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
#include <string.h>

// Define QR code symbol size
#define QR_SIZE 21

// Define QR code version
#define QR_VERSION 1

// Define QR code ECC level 
#define QR_ECC "L"

// QR code data structure
typedef struct QRData {
    uint8_t data[QR_SIZE][QR_SIZE];
} QRData;

// Initialize QR code data
void initQRData(QRData *qrData) {
    memset(qrData->data, 0, sizeof(qrData->data));
}

// Generate QR code
void generateQRCode(char *str, QRData *qrData) {
    int i, j, k, l, m;

    // Generate QR code mask pattern
    uint8_t maskPattern[QR_SIZE][QR_SIZE];
    memset(maskPattern, 0, sizeof(maskPattern));

    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            maskPattern[i][j] = (i + j) % 2;
        }
    }

    // Apply mask pattern to data
    for (i = 0, k = QR_SIZE - 1; k >= 0; k -= 2) {
        for (j = 0; j < QR_SIZE; j++) {
            if (!qrData->data[k][j]) {
                qrData->data[k][j] = str[i++] << 1 | maskPattern[k][j];
            }

            if (i >= strlen(str)) {
                break;
            }

            if (!qrData->data[k - 1][j] && k > 0) {
                qrData->data[k - 1][j] = str[i++] << 1 | maskPattern[k - 1][j];
            }

            if (i >= strlen(str)) {
                break;
            }
        }
    }

    // Print QR code
    for (i = 0; i < QR_SIZE; i++) {
        for (j = 0; j < QR_SIZE; j++) {
            printf("%c", qrData->data[i][j] ? '#' : ' ');
        }
        printf("\n");
    }
}

int main(int argc, char **argv) {
    // Check for input
    if (argc < 2) {
        printf("Usage: ./qr_gen <text>\n");
        return -1;
    }

    // Initialize QR code data
    QRData qrData;
    initQRData(&qrData);

    // Generate QR code
    generateQRCode(argv[1], &qrData);

    return 0;
}