//FormAI DATASET v1.0 Category: QR code generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>

// Function to generate QR code
void generate_qr_code(char *str) {
    // Your QR code generation code here!
    printf("Generating QR code for \"%s\"\n", str);
}

int main() {
    char message[100];
    printf("Welcome to HappyQR!\n");
    printf("Please enter the message you want to generate a QR code for: ");
    scanf("%s", message);

    // Check if message is valid
    if (strlen(message) == 0) {
        printf("Invalid message!\n");
        exit(1);
    }

    // Generate QR code
    generate_qr_code(message);

    printf("Success! Your HappyQR code has been generated!\n");
    return 0;
}