//FormAI DATASET v1.0 Category: QR code generator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    // Declare variables
    int qrCode[21][21];
    int i, j, r;

    // Initialize random seed
    srand(time(NULL));

    // Fill in corners of QR code
    for (i = 0; i < 7; i++) {
        for (j = 0; j < 7; j++) {
            qrCode[i][j] = 1;
            qrCode[i + 14][j] = 1;
            qrCode[i][j + 14] = 1;
            qrCode[i + 1][j + 1] = 1;
            qrCode[i + 2][j + 2] = 1;
            qrCode[i][j + 14] = 1;
            qrCode[i + 2][j + 10] = 1;
            qrCode[i + 4][j + 12] = 1;
            qrCode[i + 6][j + 4] = 1;
        }
    }

    // Fill in random data modules
    for (i = 7; i < 14; i++) {
        for (j = 0; j < 21; j++) {
            r = rand() % 2;
            qrCode[i][j] = r;
        }
    }
    for (i = 14; i < 21; i++) {
        for (j = 7; j < 14; j++) {
            r = rand() % 2;
            qrCode[i][j] = r;
        }
    }

    // Output QR code
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
            if (qrCode[i][j] == 1) {
                printf("▓▓");
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }

    return 0;
}