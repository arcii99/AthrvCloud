//FormAI DATASET v1.0 Category: QR code reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

struct qr_code {
    char data[100];
};

void read_qr_code(struct qr_code *code) {
    printf("Please scan the QR code\n");
    scanf("%s", code->data);
}

void print_qr_code(struct qr_code *code) {
    printf("QR code: %s\n", code->data);
}

bool check_qr_code(struct qr_code *code) {
    // check if the QR code has "C language" as the data
    if(strcmp(code->data, "C language") == 0) {
        return true;
    }
    return false;
}

int main() {
    struct qr_code code;
    read_qr_code(&code);
    print_qr_code(&code);

    if(check_qr_code(&code)) {
        printf("QR code is valid!\n");
    } else {
        printf("Invalid QR code!\n");
    }

    return 0;
}