//FormAI DATASET v1.0 Category: QR code reader ; Style: authentic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>

/* This program reads a QR code encoded as a string of characters, and decodes it into a message */

#define MAX_QR_CODE_LEN 1000

/* Function to validate a string as a QR code */
bool is_valid_qr_code(char* qr_code) {
    if (strlen(qr_code) % 2 != 0) {
        return false;
    }
    for (int i = 0; i < strlen(qr_code); i++) {
        if (qr_code[i] != '0' && qr_code[i] != '1') {
            return false;
        }
    }
    return true;
}

/* Function to decode a QR code into a message */
char* decode_qr_code(char* qr_code) {
    if (!is_valid_qr_code(qr_code)) {
        return "Invalid QR code";
    }
    char* message = malloc((strlen(qr_code) / 2) + 1);
    for (int i = 0; i < strlen(qr_code); i += 2) {
        char byte[3] = {qr_code[i], qr_code[i+1], '\0'};
        message[i/2] = (char) strtol(byte, NULL, 2);
    }
    message[strlen(qr_code) / 2] = '\0';
    return message;
}

/* Main function to read a QR code and decode it into a message */
int main() {
    char qr_code[MAX_QR_CODE_LEN];
    printf("Please enter the QR code: ");
    fgets(qr_code, MAX_QR_CODE_LEN, stdin);
    qr_code[strcspn(qr_code, "\r\n")] = '\0'; // Remove newline character
    char* message = decode_qr_code(qr_code);
    printf("QR code decoded successfully: %s\n", message);
    free(message);
    return 0;
}