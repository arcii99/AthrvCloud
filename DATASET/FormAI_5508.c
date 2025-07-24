//FormAI DATASET v1.0 Category: QR code generator ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define QR_SIZE 11
#define CODE_SIZE 50

const int code[] = {1, 2, 4, 7, 13, 14, 15, 30, 40, 41, 43, 44, 45, 46, 47, 50, 51, 
                    52, 54, 55, 56, 57, 58, 59};

void generate_qr(int qr[QR_SIZE][QR_SIZE], char* data) {
    int i, j, index, x, y;

    // Fill the QR code with 0s
    for(i = 0; i < QR_SIZE; i++) {
        for(j = 0; j < QR_SIZE; j++) {
            qr[i][j] = 0;
        }
    }

    // Insert the code markers
    qr[3][3] = 1;
    qr[3][4] = 1;
    qr[4][3] = 1;
    qr[4][4] = 1;

    // Insert the code
    index = 0;
    for(i = 8; i >= 0; i--) {
        for(j = 8; j >= 0; j--) {
            if(index < CODE_SIZE) {
                if(code[index] == i * QR_SIZE + j + 1) {
                    qr[i][j] = 1;
                    index++;
                }
            }
        }
    }

    // Insert the data
    index = 0;
    x = QR_SIZE - 1;
    y = QR_SIZE - 1;
    while(index < strlen(data)) {
        qr[x][y] = data[index] - '0';
        index++;
        if(index % 2 == 0) {
            if(y > 0) {
                y--;
            } else {
                x--;
            }
        } else {
            if(y < QR_SIZE - 1) {
                y++;
            } else {
                x--;
            }
        }
    }
}

int main() {
    int qr[QR_SIZE][QR_SIZE];
    char data[101];

    printf("Enter data to be encoded in QR code: ");
    scanf("%100s", data);

    generate_qr(qr, data);

    // Print the QR code
    printf("\n");
    for(int i = 0; i < QR_SIZE; i++) {
        for(int j = 0; j < QR_SIZE; j++) {
            if(qr[i][j] == 1) {
                printf("*");
            } else {
                printf(".");
            }
        }
        printf("\n");
    }

    return 0;
}