//FormAI DATASET v1.0 Category: QR code generator ; Style: Cryptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to generate a unique QR code
char* generate_qr_code(int id) {
    // Initialize the QR code buffer
    char* qr_code = (char*) malloc(sizeof(char) * 25);

    // Generate a unique code using the ID
    sprintf(qr_code, "cRYPTiiC#%d", id);

    // Return the QR code
    return qr_code;
}

int main() {
    // Generate QR codes for IDs 1-10
    for (int i = 1; i <= 10; i++) {
        char* qr_code = generate_qr_code(i);

        // Print the QR code
        printf("QR code for ID '%d': %s\n", i, qr_code);

        // Free memory allocated for the QR code
        free(qr_code);
    }

    return 0;
}