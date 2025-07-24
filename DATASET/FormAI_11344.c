//FormAI DATASET v1.0 Category: QR code generator ; Style: enthusiastic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator with current time
    int qr_code[21][21] = {0}; // initialize the QR code with 0s

    // generate data to fill QR code
    int i, j;
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
            qr_code[i][j] = rand() % 2; // randomly generate 0 or 1
        }
    }

    // print the generated QR code
    int k;
    for (i = 0; i < 21; i++) {
        for (j = 0; j < 21; j++) {
            if (qr_code[i][j] == 1) {
                printf("██"); // print a filled block
            } else {
                printf("  "); // print an empty block
            }
        }
        printf("\n");
    }

    return 0;
}