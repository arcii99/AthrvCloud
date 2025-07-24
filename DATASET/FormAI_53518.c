//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: Cryptic
#include <stdio.h>

int main() {
    char message[50];
    char watermark[10] = "ABC123";
    char encrypted_message[60];
    int i, j, k;

    printf("Enter your message: ");
    fgets(message, 50, stdin);

    // Embed watermark into message
    for (i = 0, j = 0; i < 50; i++) {
        if (message[i] == '\n' || message[i] == '\0') {
            encrypted_message[j++] = watermark[0];
            encrypted_message[j++] = watermark[1];
            encrypted_message[j++] = watermark[2];
            encrypted_message[j++] = watermark[3];
            encrypted_message[j++] = watermark[4];
            encrypted_message[j++] = watermark[5];
        } else {
            encrypted_message[j++] = message[i];
        }
    }
    printf("Encrypted message: %s\n", encrypted_message);

    // Retrieve watermark from encrypted message
    for (i = 0, j = 0, k = 0; i < 60; i++) {
        if (encrypted_message[i] == '\n' || encrypted_message[i] == '\0') {
            if (encrypted_message[i-6] == watermark[0] &&
                encrypted_message[i-5] == watermark[1] &&
                encrypted_message[i-4] == watermark[2] &&
                encrypted_message[i-3] == watermark[3] &&
                encrypted_message[i-2] == watermark[4] &&
                encrypted_message[i-1] == watermark[5]) {
                printf("Watermark found in message at index %d.\n", k);
            }
            k++;
        } else {
            k++;
        }
    }

    return 0;
}