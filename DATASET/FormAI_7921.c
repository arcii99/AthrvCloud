//FormAI DATASET v1.0 Category: QR code generator ; Style: brave
#include <stdio.h>
#include <string.h>
#include <qrencode.h>

int main() {
    // Get the input text from the user
    char input_text[128];
    printf("Enter the text to convert to QR code: ");
    scanf("%s", input_text);

    // Encode the input text to a QR code
    QRcode *qr_code = QRcode_encodeString(input_text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);

    // Verify that the QR code was generated successfully
    if (qr_code == NULL) {
        printf("Error generating QR code\n");
        return 0;
    }

    // Print the QR code on the console
    for (int i = 0; i < qr_code->width; i++) {
        for (int j = 0; j < qr_code->width; j++) {
            if (qr_code->data[i * qr_code->width + j] & 1) {
                printf("  ");
            }
            else {
                printf("██");
            }
        }
        printf("\n");
    }

    // Deallocate the QR code memory
    QRcode_free(qr_code);

    return 0;
}