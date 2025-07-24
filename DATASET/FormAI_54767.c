//FormAI DATASET v1.0 Category: QR code generator ; Style: artistic
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <qrencode.h>

int main() {
    char* text = "Hello, world!";
    int size = 10;
    QRcode* code = QRcode_encodeString(text, 0, QR_ECLEVEL_L, QR_MODE_8, 1);
    int liczba = 0;
    if (code != NULL) {
        unsigned char* row = code->data;
        for (int i = 0; i < code->width * code->width; i++) {
            if (i % code->width == 0) {
                printf("\n");
            }
            liczba += *row++;
            if (*row++) {
                printf("#");
            } else {
                printf(" ");
            }
        }
        printf("\nSuma elementow QR: %d\n", liczba);
        QRcode_free(code);
    }
    return 0;
}