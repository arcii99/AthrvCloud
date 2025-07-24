//FormAI DATASET v1.0 Category: QR code generator ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#define QR_CODE_VERSION 1
#define QR_CODE_SIZE 21
#define QR_CODE_SQUARE_SIZE 10

typedef struct {
    uint8_t data[QR_CODE_SIZE][QR_CODE_SIZE];
} qr_code_t;

void print_qr_code(qr_code_t *code) {
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            if (code->data[i][j]) {
                printf("█");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void generate_qr_code(qr_code_t *code, char *str) {
    // TODO: Implement QR code generation algorithm
    // For now, just fill the code with random data
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            code->data[i][j] = rand() % 2;
        }
    }
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <string to generate QR code>\n", argv[0]);
        return 1;
    }

    char *str = argv[1];

    qr_code_t code;
    generate_qr_code(&code, str);

    printf("Generated QR code for \"%s\":\n", str);
    print_qr_code(&code);

    return 0;
}