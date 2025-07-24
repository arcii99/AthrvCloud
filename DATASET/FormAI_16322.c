//FormAI DATASET v1.0 Category: QR code reader ; Style: Donald Knuth
#include <stdio.h>
#include <stdlib.h>

typedef struct qr_code {
    char data[100];
} QRCode;

typedef struct qr_reader {
    QRCode code;
} QRReader;

static QRReader initialize_reader() {
    QRReader reader;
    reader.code = (QRCode) { .data = "" };
    return reader;
}

static void read_code(QRReader *reader, const char *input) {
    int i;
    for (i = 0; input[i] != '\0'; ++i) {
        reader->code.data[i] = input[i];
    }
    reader->code.data[i] = '\0';
}

static void print_code(const QRCode *code) {
    printf("QR Code: %s\n", code->data);
}

int main() {
    QRReader reader = initialize_reader();
    char input[100];

    printf("Enter QR Code data:\n");
    scanf("%s", input);

    read_code(&reader, input);
    print_code(&reader.code);

    return 0;
}