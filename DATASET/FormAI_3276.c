//FormAI DATASET v1.0 Category: QR code generator ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LEN 100

// Function to generate QR code in medieval style
void generateQRCode(char* text) {

    // Character set to generate QR code
    char charset[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789";
    int charset_len = strlen(charset);

    // Initialize size of QR code
    int size = 21;

    // Initialize QR code matrix
    char qrcode[size][size];

    // Fill QR code matrix with random characters from character set
    for(int i=0; i<size; i++) {
        for(int j=0; j<size; j++) {
            int index = rand() % charset_len;
            qrcode[i][j] = charset[index];
        }
    }

    // Insert text in QR code matrix
    int text_len = strlen(text);
    int x = 2, y = 1;
    for(int i=0; i<text_len; i++) {
        qrcode[x][y] = text[i];
        x++;
        if(x >= size-1) {
            x = 2;
            y += 2;
        }
    }

    // Print QR code in medieval style
    printf("*");
    for(int i=0; i<size; i++) {
        printf(" *");
    }
    printf("\n");
    for(int i=0; i<size; i++) {
        printf("* ");
        for(int j=0; j<size; j++) {
            printf("%c ", qrcode[i][j]);
        }
        printf("*\n");
    }
    printf("*");
    for(int i=0; i<size; i++) {
        printf(" *");
    }
    printf("\n");
}

int main() {
    char text[MAX_LEN];
    printf("Enter text to generate QR code in medieval style: ");
    fgets(text, MAX_LEN, stdin);
    generateQRCode(text);
    return 0;
}