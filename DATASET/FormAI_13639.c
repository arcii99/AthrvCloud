//FormAI DATASET v1.0 Category: QR code generator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <qrencode.h>

int main(int argc, char *argv[]) {
    const char *code_text = "Example QR code text";
    QRcode *qr_code = QRcode_encodeString(code_text, 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    printf("QR code text: %s", code_text);
    printf("\nGenerated QR code: \n");
    for (int i = 0; i < qr_code->width; i++) {
        for (int j = 0; j < qr_code->width; j++) {
            printf("%c ", qr_code->data[i * qr_code->width + j] ? 'X' : ' ');
        }
        printf("\n");
    }
    QRcode_free(qr_code);
    return 0;
}