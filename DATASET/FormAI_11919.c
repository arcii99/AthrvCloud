//FormAI DATASET v1.0 Category: QR code generator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_CODE_SIZE 21
#define MAX_DATA_SIZE 100

void generate_qr_code(char* data) {
    char qr_code[QR_CODE_SIZE][QR_CODE_SIZE];

    // Initialize QR code
    memset(qr_code, ' ', QR_CODE_SIZE * QR_CODE_SIZE);

    // Add data to QR code
    int index = 0;
    for (int i = 2; i < QR_CODE_SIZE - 1; i++) {
        for (int j = 2; j < QR_CODE_SIZE - 1; j++) {
            if (data[index] != '\0') {
                qr_code[i][j] = data[index];
                index++;
            } else {
                goto display_qr_code;
            }
        }
    }

    // Display QR code
    display_qr_code:
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        for (int j = 0; j < QR_CODE_SIZE; j++) {
            printf("%c", qr_code[i][j]);
        }
        printf("\n");
    }
}

int main() {
    char data[MAX_DATA_SIZE];

    printf("Enter data: ");
    fgets(data, MAX_DATA_SIZE, stdin);

    generate_qr_code(data);

    return 0;
}