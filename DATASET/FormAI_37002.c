//FormAI DATASET v1.0 Category: QR code reader ; Style: introspective
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define MAX_LEN 100

bool is_valid_qr_code(char* qr_code) {
    if (strlen(qr_code) != 27) {
        return false;
    }

    if (qr_code[0] != 'C' || qr_code[1] != 'Q' || qr_code[2] != 'R' || qr_code[3] != '-') {
        return false;
    }

    for (int i = 4; i < 26; i++) {
        if (qr_code[i] < '0' || qr_code[i] > '9') {
            return false;
        }
    }

    if (qr_code[26] != '-') {
        return false;
    }

    return true;
}

void parse_qr_code(char* qr_code, char* c, int* num) {
    *c = qr_code[24];
    *num = atoi(&qr_code[4]);
}

int main() {
    char qr_code[MAX_LEN];
    char c;
    int num;

    printf("Enter the QR code: ");
    fgets(qr_code, MAX_LEN, stdin);

    // remove newline character from fgets
    qr_code[strcspn(qr_code, "\n")] = 0;

    if (!is_valid_qr_code(qr_code)) {
        printf("Invalid QR code\n");
        return 1;
    }

    parse_qr_code(qr_code, &c, &num);

    printf("QR code is valid\n");
    printf("C: %c\n", c);
    printf("Num: %d\n", num);

    return 0;
}