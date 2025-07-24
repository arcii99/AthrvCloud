//FormAI DATASET v1.0 Category: QR code generator ; Style: Ada Lovelace
// Ada Lovelace style QR Code Generator
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define QR_SIZE 21  // QR code size

void print_qr(char code[QR_SIZE][QR_SIZE]) {
    // print QR code
    for (int i = 0; i < QR_SIZE; i++) {
        for (int j = 0; j < QR_SIZE; j++) {
            printf("%c", code[i][j]);
        }
        printf("\n");
    }
}

void generate_qr(const char* message, char code[QR_SIZE][QR_SIZE]) {
    // generate QR code from message
    char bit_string[QR_SIZE * QR_SIZE + 1];
    memset(bit_string, 0, sizeof(bit_string));
    int bit_index = 0;

    // convert message to bit string
    uint8_t *ptr = (uint8_t*)message;
    while (*ptr) {
        for (int i = 7; i >= 0; i--) {
            bit_string[bit_index++] = (*ptr & (1 << i)) ? '1' : '0';
        }
        ptr++;
    }

    // add padding to bit string
    for (int i = bit_index; i < QR_SIZE * QR_SIZE; i++) {
        bit_string[i] = '0';
    }

    // fill QR code matrix
    int x = QR_SIZE / 2;
    int y = QR_SIZE / 2;
    int direction = 0;
    for (int i = 0; i < QR_SIZE * QR_SIZE; i++) {
        code[y][x] = (bit_string[i] == '1') ? 'X' : ' ';
        switch (direction) {
            case 0: y--; break;
            case 1: x++; break;
            case 2: y++; break;
            case 3: x--; break;
        }
        if (y < 0 || y >= QR_SIZE || x < 0 || x >= QR_SIZE || code[y][x] != ' ') {
            // change direction if going out of border or hitting existing bit
            switch (direction) {
                case 0: y++; break;
                case 1: x--; break;
                case 2: y--; break;
                case 3: x++; break;
            }
            direction = (direction + 1) % 4;
            switch (direction) {
                case 0: y--; break;
                case 1: x++; break;
                case 2: y++; break;
                case 3: x--; break;
            }
        }
    }
}

int main() {
    // sample message
    const char* message = "Hello, World!";

    // initialize QR code matrix
    char code[QR_SIZE][QR_SIZE];
    memset(code, ' ', sizeof(code));

    // generate QR code from message
    generate_qr(message, code);

    // print QR code
    print_qr(code);

    return 0;
}