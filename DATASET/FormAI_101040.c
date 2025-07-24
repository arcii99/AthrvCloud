//FormAI DATASET v1.0 Category: QR code generator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define MAX_INPUT_LENGTH 256

// Structure representing QR Code
struct QrCode {
    uint8_t version;
    uint8_t size;
    uint8_t *data;
};

// Function to create QR Code
struct QrCode create_qr_code(char *input_data) {
    struct QrCode qr_code;
    qr_code.version = 1;
    qr_code.size = strlen(input_data);
    qr_code.data = (uint8_t *) malloc(qr_code.size * sizeof(uint8_t));
    memcpy(qr_code.data, input_data, qr_code.size * sizeof(uint8_t));
    return qr_code;
}

// Function to display QR Code
void display_qr_code(struct QrCode qr_code) {
    printf("QR Code:\nVersion: %d\nSize: %d\nData: ", qr_code.version, qr_code.size);
    for (int i = 0; i < qr_code.size; i++) {
        printf("%d ", qr_code.data[i]);
    }
}

int main() {
    printf("Enter input data: ");
    char input_data[MAX_INPUT_LENGTH];
    fgets(input_data, MAX_INPUT_LENGTH, stdin);
    struct QrCode qr_code = create_qr_code(input_data);
    display_qr_code(qr_code);
    return 0;
}