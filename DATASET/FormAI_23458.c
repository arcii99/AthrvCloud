//FormAI DATASET v1.0 Category: QR code reader ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_SIZE 100

struct QRCode {
    int data[MAX_SIZE][MAX_SIZE];
    int size;
};

void initialize(struct QRCode *qr_code) {
    for(int i=0; i<MAX_SIZE; i++) {
        for(int j=0; j<MAX_SIZE; j++) {
            qr_code->data[i][j] = 0;
        }
    }
    qr_code->size = 0;
}

void print_qr_code(struct QRCode qr_code) {
    for(int i=0; i<qr_code.size; i++) {
        for(int j=0; j<qr_code.size; j++) {
            if(qr_code.data[i][j] == 1) {
                printf("X");
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

bool read_qr_code(struct QRCode *qr_code) {
    int n;
    printf("Enter the size of the QR code: ");
    scanf("%d", &n);

    if(n > MAX_SIZE) {
        printf("Error: Maximum size exceeded.\n");
        return false;
    }

    qr_code->size = n;

    printf("Enter the QR code (%dx%d):\n", n, n);
    for(int i=0; i<n; i++) {
        for(int j=0; j<n; j++) {
            scanf("%d", &qr_code->data[i][j]);

            if(qr_code->data[i][j] > 1) {
                printf("Error: Invalid code format.\n");
                return false;
            }
        }
    }

    return true;
}

int main() {
    struct QRCode qr_code;
    initialize(&qr_code);

    printf("Welcome to Retro QR Code Reader!\n");

    if(read_qr_code(&qr_code)) {
        printf("Successfully read QR code:\n");
        print_qr_code(qr_code);
    }

    return 0;
}