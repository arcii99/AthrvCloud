//FormAI DATASET v1.0 Category: QR code generator ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_STRING_LENGTH 100
#define QR_CODE_SIZE 25

void generateQRCode(char* qrCodeBuffer, char* message) {
    srand(time(NULL)); // Seed the random generator with time
    int i, j;

    for (i = 0; i < QR_CODE_SIZE; i++) {
        qrCodeBuffer[i] = '0' + (rand() % 10); // Generate a random number between 0 and 9
    }
    
    // Copy the message into the central section of the QR code buffer
    int messageLen = strlen(message);
    int start = (QR_CODE_SIZE - messageLen) / 2;
    for (i = start, j = 0; i < start + messageLen; i++, j++) {
        qrCodeBuffer[i] = message[j];
    }
}

int main() {
    char message[MAX_STRING_LENGTH];
    char qrCodeBuffer[QR_CODE_SIZE + 1]; // Add 1 for null terminator

    printf("Enter a message to generate a QR code: ");
    fgets(message, MAX_STRING_LENGTH, stdin);
    message[strcspn(message, "\n")] = 0; // Remove newline character, if present

    generateQRCode(qrCodeBuffer, message);

    printf("QR code for message '%s':\n", message);
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        printf("%c", qrCodeBuffer[i]);
    }
    printf("\n");

    return 0;
}