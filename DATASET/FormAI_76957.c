//FormAI DATASET v1.0 Category: QR code reader ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <stdint.h>

#define MAX_QR_CODE_SIZE 1024
#define MAX_QR_CODE_DATA_LENGTH 2956
#define QR_CODE_HEADER "\x02\x01\x05" // QR code version 1, encoding mode 0 (numeric data)

typedef struct QRCode {
    uint8_t header[3]; // QR code header, version, encoding mode
    uint16_t data_length; // length of data
    uint8_t data[MAX_QR_CODE_DATA_LENGTH]; // QR code data
} QRCode;

bool is_qr_code_valid(QRCode qr_code) {
    // QR code header should be "\x02\x01\x05"
    if (memcmp(qr_code.header, QR_CODE_HEADER, 3) != 0) {
        return false;
    }
    // QR code data length should be less than or equal to MAX_QR_CODE_DATA_LENGTH
    if (qr_code.data_length > MAX_QR_CODE_DATA_LENGTH) {
        return false;
    }
    return true;
}

void print_qr_code(QRCode qr_code) {
    printf("Header: %02x%02x%02x\n", qr_code.header[0], qr_code.header[1], qr_code.header[2]);
    printf("Data length: %d\n", qr_code.data_length);
    printf("Data: %s\n", qr_code.data);
}

int main() {
    char qr_code_string[MAX_QR_CODE_SIZE];

    printf("Enter QR code: ");
    fgets(qr_code_string, MAX_QR_CODE_SIZE, stdin);
    
    // remove newline character from input
    qr_code_string[strcspn(qr_code_string, "\n")] = '\0';

    QRCode qr_code;
    memcpy(qr_code.header, QR_CODE_HEADER, 3);
    qr_code.data_length = strlen(qr_code_string);
    memcpy(qr_code.data, qr_code_string, qr_code.data_length);

    if (is_qr_code_valid(qr_code)) {
        printf("Valid QR code:\n");
        print_qr_code(qr_code);
    } else {
        printf("Invalid QR code\n");
    }

    return 0;
}