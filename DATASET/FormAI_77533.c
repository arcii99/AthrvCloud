//FormAI DATASET v1.0 Category: QR code reader ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define QR_CODE_SIZE 21 // Size of the QR code matrix

typedef struct qr_code {
    bool data[QR_CODE_SIZE][QR_CODE_SIZE]; // QR code data matrix
    uint8_t version; // QR code version number
    uint8_t error_correction_level; // QR code error correction level
    bool mask[QR_CODE_SIZE][QR_CODE_SIZE]; // QR code mask pattern matrix
} qr_code_t;

qr_code_t* read_qr_code(const char* filename);
void print_qr_code(const qr_code_t* qr_code);
void free_qr_code(qr_code_t* qr_code);

int main(int argc, char* argv[]) {
    if (argc < 2) {
        printf("Usage: %s <filename>\n", argv[0]);
        return 1;
    }
    qr_code_t* qr_code = read_qr_code(argv[1]);
    if (qr_code == NULL) {
        printf("Error reading the QR code.\n");
        return 1;
    }
    print_qr_code(qr_code);
    free_qr_code(qr_code);
    return 0;
}

qr_code_t* read_qr_code(const char* filename) {
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error: failed to open file: %s\n", filename);
        return NULL;
    }
    uint8_t data_length = 0;
    fread(&data_length, sizeof(uint8_t), 1, file);
    uint8_t qr_data[QR_CODE_SIZE * QR_CODE_SIZE / 8] = {0};
    fread(qr_data, sizeof(uint8_t), QR_CODE_SIZE * QR_CODE_SIZE / 8, file);
    fclose(file);
    qr_code_t* qr_code = (qr_code_t*) malloc(sizeof(qr_code_t));
    if (qr_code == NULL) {
        printf("Error: failed to allocate memory for the QR code.\n");
        return NULL;
    }
    memset(qr_code, 0, sizeof(qr_code_t));
    uint8_t* data_ptr = qr_data;
    for (int r = 0; r < QR_CODE_SIZE; r++) {
        for (int c = 0; c < QR_CODE_SIZE / 8; c++) {
            for (int b = 7; b >= 0; b--) {
                qr_code->data[r][c * 8 + (7 - b)] = (*data_ptr >> b) & 0x01;
            }
            data_ptr++;
        }
    }
    qr_code->version = qr_code->data[5][5] + qr_code->data[5][4] * 2 + qr_code->data[5][3] * 4 + qr_code->data[5][2] * 8 + qr_code->data[5][1] * 16 + qr_code->data[5][0] * 32;
    qr_code->error_correction_level = qr_code->data[4][3] + qr_code->data[4][2] * 2 + qr_code->data[4][1] * 4 + qr_code->data[4][0] * 8;
    uint8_t mask_pattern = 0;
    for (int c = 0; c < 6; c++) {
        mask_pattern += qr_code->data[8][QR_CODE_SIZE - c - 1] * (1 << c);
    }
    for (int r = 0; r < QR_CODE_SIZE; r++) {
        for (int c = 0; c < QR_CODE_SIZE; c++) {
            qr_code->mask[r][c] = false;
            switch (mask_pattern) {
                case 0:
                    qr_code->mask[r][c] = (r + c) % 2 == 0;
                    break;
                case 1:
                    qr_code->mask[r][c] = r % 2 == 0;
                    break;
                case 2:
                    qr_code->mask[r][c] = c % 3 == 0;
                    break;
                case 3:
                    qr_code->mask[r][c] = (r + c) % 3 == 0;
                    break;
                case 4:
                    qr_code->mask[r][c] = (r / 2 + c / 3) % 2 == 0;
                    break;
                case 5:
                    qr_code->mask[r][c] = r * c % 2 + r * c % 3 == 0;
                    break;
                case 6:
                    qr_code->mask[r][c] = (r * c % 2 + r * c % 3) % 2 == 0;
                    break;
                case 7:
                    qr_code->mask[r][c] = ((r + c) % 2 + r * c % 3) % 2 == 0;
                    break;
            }
        }
    }
    for (int r = 0; r < QR_CODE_SIZE; r++) {
        for (int c = 0; c < QR_CODE_SIZE; c++) {
            qr_code->data[r][c] ^= qr_code->mask[r][c];
        }
    }
    return qr_code;
}

void print_qr_code(const qr_code_t* qr_code) {
    printf("QR code version: %d\n", qr_code->version);
    printf("QR code error correction level: %d\n", qr_code->error_correction_level);
    printf("QR code data (0 = black, 1 = white):\n");
    for (int r = 0; r < QR_CODE_SIZE; r++) {
        for (int c = 0; c < QR_CODE_SIZE; c++) {
            putchar(qr_code->data[r][c] ? '1' : '0');
        }
        putchar('\n');
    }
}

void free_qr_code(qr_code_t* qr_code) {
    free(qr_code);
}