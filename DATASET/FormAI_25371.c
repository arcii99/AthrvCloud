//FormAI DATASET v1.0 Category: QR code generator ; Style: mind-bending
#include <stdio.h>

#define QR_CODE_SIZE 21

int main() {
    char code[QR_CODE_SIZE][QR_CODE_SIZE];
    
    // setting up the QR code matrix with neutral color (white)
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            code[i][j] = ' ';
        }
    }
    
    // generating the diagonal pattern in the QR code
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        code[i][i] = '=';
        code[i][QR_CODE_SIZE-i-1] = '=';
    }
    
    // printing the generated QR code
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c ", code[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}