//FormAI DATASET v1.0 Category: QR code generator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define QR_CODE_SIZE 21

void generate_qr_code(int qr_code[QR_CODE_SIZE][QR_CODE_SIZE]) {
    int i, j;

    // Set all elements to 0
    for (i = 0; i < QR_CODE_SIZE; i++) {
        for (j = 0; j < QR_CODE_SIZE; j++) {
            qr_code[i][j] = 0;
        }
    }

    // Set timing patterns
    for (i = 9; i < QR_CODE_SIZE - 8; i++) {
        qr_code[i][6] = 1;
        qr_code[6][i] = 1;
    }

    // Set format and version information
    for (i = 0; i < 6; i++) {
        qr_code[i][8] = 1;
        qr_code[8][i] = 1;
    }
    qr_code[7][8] = 1;
    qr_code[8][7] = 1;

    for (i = QR_CODE_SIZE - 11; i < QR_CODE_SIZE - 8; i++) {
        for (j = 0; j < 6; j++) {
            qr_code[i][j] = 1;
            qr_code[j][i] = 1;
        }
    }

    // Set alignment patterns
    qr_code[3][3] = 1;
    qr_code[4][3] = 1;
    qr_code[3][4] = 1;

    qr_code[QR_CODE_SIZE - 4][3] = 1;
    qr_code[QR_CODE_SIZE - 4][4] = 1;
    qr_code[QR_CODE_SIZE - 3][3] = 1;

    qr_code[3][QR_CODE_SIZE - 4] = 1;
    qr_code[4][QR_CODE_SIZE - 4] = 1;
    qr_code[3][QR_CODE_SIZE - 3] = 1;

    // Set dark module
    qr_code[8][QR_CODE_SIZE - 8] = 1;

    // Set data bits
    srand(time(NULL));
    for (i = 9; i < QR_CODE_SIZE - 8; i++) {
        for (j = 9; j < QR_CODE_SIZE - 8; j++) {
            qr_code[i][j] = rand() % 2;
        }
    }
}

void print_qr_code(int qr_code[QR_CODE_SIZE][QR_CODE_SIZE]) {
    int i, j;

    for (i = 0; i < QR_CODE_SIZE; i++) {
        for (j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c", qr_code[i][j] ? '█' : ' ');
        }
        printf("\n");
    }
}

int main() {
    int qr_code[QR_CODE_SIZE][QR_CODE_SIZE];

    generate_qr_code(qr_code);
    print_qr_code(qr_code);

    return 0;
}