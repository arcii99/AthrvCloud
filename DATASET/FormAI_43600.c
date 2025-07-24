//FormAI DATASET v1.0 Category: QR code reader ; Style: Cyberpunk
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_QR_SIZE 1024
#define QR_CODE_SIZE 33

typedef struct qr_code {
    int size;
    char data[MAX_QR_SIZE];
} qr_code;

qr_code decode_qr_code(const char *raw_data) {
    qr_code code;
    code.size = 0;
    for (int i = 0; raw_data[i] != '\0'; i += QR_CODE_SIZE) {
        if (strncmp(raw_data + i, "CYB3RPUNK", QR_CODE_SIZE) == 0) {
            int code_size = raw_data[i + QR_CODE_SIZE] - '0';
            if (code_size > MAX_QR_SIZE) {
                fprintf(stderr, "Invalid QR code size!\n");
                exit(1);
            }
            strncpy(code.data, raw_data + i + QR_CODE_SIZE + 1, code_size);
            code.size = code_size;
        }
    }
    return code;
}

int main() {
    char raw_data[] = "CYB3RPUNK18Hello, World!CYB3RPUNK32This is a longer messageCYB3RPUNK5Short";
    qr_code code = decode_qr_code(raw_data);
    printf("Decoded QR code: %.*s\n", code.size, code.data);
    return 0;
}