//FormAI DATASET v1.0 Category: QR code generator ; Style: modular
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

#define QR_CODE_VERSION 10
#define QR_CODE_PIXEL_SIZE 10

/**
 * Generate and return a QR code as a string
 *
 * @param data The data to be encoded in the QR code
 * @param length The length of the data string
 * @return The QR code as a string
 */
char* generate_qr_code(char* data, int length) {
    // Generate the QR code
    QRcode* qr = QRcode_encodeString(data, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Calculate the size of the QR code in pixels
    int qr_code_size = qr->width * QR_CODE_PIXEL_SIZE;

    // Allocate memory to store the QR code as a string
    char* qr_code_string = malloc(qr_code_size * (qr_code_size + 1) * sizeof(char));

    // Loop through each row of the QR code
    for (int y = 0; y < qr->width; y++) {
        // Loop through each column of the QR code
        int index = (y * qr_code_size) + QR_CODE_PIXEL_SIZE;
        for (int x = 0; x < qr->width; x++) {
            // Get the value of the current pixel in the QR code
            unsigned char value = qr->data[y * qr->width + x];

            // Loop through each pixel in the current module of the QR code
            for (int i = 0; i < QR_CODE_PIXEL_SIZE; i++) {
                // Set the pixel to black if the QR code value is 1, white otherwise
                qr_code_string[index++] = value ? 'X' : ' ';
            }
        }
        // Add a new line after each row of the QR code
        qr_code_string[index] = '\n';
    }

    // Free the QR code memory
    QRcode_free(qr);

    return qr_code_string;
}

int main() {
    char* data = "https://www.github.com";
    char* qr_code = generate_qr_code(data, strlen(data));
    printf("%s", qr_code);
    free(qr_code);
    return 0;
}