//FormAI DATASET v1.0 Category: QR code generator ; Style: sophisticated
#include <qrencode.h>
#include <stdio.h>

void print_qr_code(QRcode *code) {
    int i, j;
    for (i = 0; i < code->width + 2; i++) {
        putchar('\u2588');
    }
    putchar('\n');
    for (i = 0; i < code->width; i++) {
        putchar('\u2588');
        for (j = 0; j < code->width; j++) {
            if (code->data[i * code->width + j] & 1) {
                putchar(' ');
            } else {
                putchar('\u2588');
            }
        }
        putchar('\u2588');
        putchar('\n');
    }
    for (i = 0; i < code->width + 2; i++) {
        putchar('\u2588');
    }
    putchar('\n');
}

int main(int argc, char **argv) {
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <text>\n", argv[0]);
        return 1;
    }
    QRcode *code = QRcode_encodeString(argv[1], 0, QR_ECLEVEL_Q, QR_MODE_8, 1);
    if (code) {
        print_qr_code(code);
        QRcode_free(code);
        return 0;
    } else {
        fprintf(stderr, "Failed to generate QR code.\n");
        return 1;
    }
}