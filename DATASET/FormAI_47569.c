//FormAI DATASET v1.0 Category: QR code generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_LENGTH 128

void generateQR(char *str);
void encrypt(char *str);
void decrypt(char *str);

int main() {
    char input[MAX_LENGTH];

    printf("Enter the text you want to encrypt: ");
    fgets(input, MAX_LENGTH, stdin);

    // Remove newline character from input
    input[strcspn(input, "\n")] = 0;

    // Generate QR code from input
    generateQR(input);

    // Encrypt QR code
    encrypt(input);

    // Decrypt QR code as a paranoid check
    decrypt(input);

    return 0;
}

// Generate QR code using current time as seed
void generateQR(char *str) {
    int i;
    char qrCode[MAX_LENGTH];

    srand(time(NULL));

    for(i = 0; i < 6; i++) {
        qrCode[i] = rand() % 26 + 'A';
    }
    qrCode[i] = '\0';

    strcat(qrCode, str);
    strcat(qrCode, qrCode);

    printf("QR code generated: %s\n", qrCode);
}

// Encrypt QR code by applying XOR operation
void encrypt(char *str) {
    int i;
    char key[] = "paranoia";

    for(i = 0; i < strlen(str); i++) {
        str[i] ^= key[i % 8];
    }

    printf("QR code encrypted: %s\n", str);
}

// Decrypt QR code using the same XOR operation
void decrypt(char *str) {
    int i;
    char key[] = "paranoia";

    for(i = 0; i < strlen(str); i++) {
        str[i] ^= key[i % 8];
    }

    printf("QR code decrypted: %s\n", str);
}