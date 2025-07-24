//FormAI DATASET v1.0 Category: QR code generator ; Style: scientific
// This program generates a unique QR code using C

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define QR_CODE_SIZE 21     // Change this value to modify the size of the generated QR code

// Generate a random QR code value based on the current time
char* generate_qr_code() {
    char* qr_code = (char*) malloc((QR_CODE_SIZE + 1) * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < QR_CODE_SIZE; i++) {
        int ascii_value = rand() % 26 + 65;
        qr_code[i] = (char) ascii_value;
    }
    qr_code[QR_CODE_SIZE] = '\0';
    return qr_code;
}

int main() {
    char* qr_code = generate_qr_code();
    printf("Generated QR code: %s\n", qr_code);
    free(qr_code);
    return 0;
}