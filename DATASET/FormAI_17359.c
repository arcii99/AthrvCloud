//FormAI DATASET v1.0 Category: QR code reader ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

#define BUF_SIZE 256

typedef struct qr_code {
    char data[BUF_SIZE];
    uint16_t size;
} qr_code_t;

bool is_qr_code(const char *str) {
    bool valid_prefix = (strncmp(str, "QR:", 3) == 0);
    bool valid_length = (strlen(str) == 51);
    return valid_prefix && valid_length;
}

qr_code_t parse_qr_code(const char *str) {
    qr_code_t code;
    strncpy(code.data, str + 3, BUF_SIZE);
    code.data[BUF_SIZE - 1] = '\0';
    code.size = strlen(code.data);
    return code;
}

void print_qr_code(qr_code_t code) {
    printf("QR Code:\n");
    printf("  Data: %s\n", code.data);
    printf("  Size: %d\n", code.size);
}

int main() {
    const char *example_code = "QR:ABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789abcdefghijklmnop";
    if (is_qr_code(example_code)) {
        qr_code_t code = parse_qr_code(example_code);
        print_qr_code(code);
    } else {
        printf("Invalid QR code.\n");
        return 1;
    }
    return 0;
}