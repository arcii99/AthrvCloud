//FormAI DATASET v1.0 Category: QR code generator ; Style: retro
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct QRCode {
    int version;
    char* data;
    int data_len;
    char* error_correction;
    int ec_len;
} QRCode;

int get_version(int data_len) {
    int version = 0;
    if (data_len <= 17) {
        version = 1;
    } else if (data_len <= 32) {
        version = 2;
    } else if (data_len <= 53) {
        version = 3;
    } else if (data_len <= 78) {
        version = 4;
    } else if (data_len <= 106) {
        version = 5;
    } else if (data_len <= 134) {
        version = 6;
    } else if (data_len <= 154) {
        version = 7;
    } else if (data_len <= 192) {
        version = 8;
    } else if (data_len <= 230) {
        version = 9;
    } else if (data_len <= 271) {
        version = 10;
    } else if (data_len <= 321) {
        version = 11;
    } else if (data_len <= 367) {
        version = 12;
    } else if (data_len <= 425) {
        version = 13;
    } else if (data_len <= 458) {
        version = 14;
    } else if (data_len <= 520) {
        version = 15;
    } else if (data_len <= 586) {
        version = 16;
    } else if (data_len <= 644) {
        version = 17;
    }
    return version;
}

char* get_data_bits(char* data) {
    char* data_bits = calloc(9 * strlen(data) + 1, sizeof(char));
    for (int i = 0; i < strlen(data); i++) {
        int num = data[i];
        char* bits = calloc(9, sizeof(char));
        for (int j = 0; j < 8; j++) {
            bits[j] = (num & (1 << j)) ? '1' : '0';
        }
        strcat(data_bits, bits);
        free(bits);
    }
    return data_bits;
}

char* get_error_correction(char* data_bits, int ec_len) {
    char* data_blocks = calloc(ec_len, sizeof(char));
    int block_size = strlen(data_bits) / ec_len;
    int remainder = strlen(data_bits) % ec_len;
    int block_index = 0;
    for (int i = 0; i < strlen(data_bits); i++) {
        if (i == (block_index + 1) * block_size) {
            block_index++;
        }
        data_blocks[block_index] ^= data_bits[i];
    }
    char* error_correction = calloc(9 * ec_len + 1, sizeof(char));
    for (int i = 0; i < ec_len; i++) {
        int num = (data_blocks[i] & 0xFF) ^ 0x5D;
        char* bits = calloc(9, sizeof(char));
        for (int j = 0; j < 8; j++) {
            bits[j] = (num & (1 << j)) ? '1' : '0';
        }
        strcat(error_correction, bits);
        free(bits);
    }
    return error_correction;
}

QRCode generate_qr_code(char* data) {
    QRCode qr_code;
    qr_code.data_len = strlen(data);
    qr_code.version = get_version(qr_code.data_len);
    qr_code.error_correction = "L";
    qr_code.ec_len = (qr_code.version == 1) ? 1 : (qr_code.version <= 10) ? 2 : (qr_code.version <= 34) ? 3 : 4;
    qr_code.data = calloc(9 * qr_code.data_len + 1, sizeof(char));
    strcpy(qr_code.data, get_data_bits(data));
    qr_code.error_correction = calloc(9 * qr_code.ec_len + 1, sizeof(char));
    strcpy(qr_code.error_correction, get_error_correction(qr_code.data, qr_code.ec_len));
    return qr_code;
}

void print_qr_code(QRCode qr_code) {
    printf("QR Code (Version %d):\n", qr_code.version);
    printf("Data: %s\n", qr_code.data);
    printf("Error Correction: %s\n", qr_code.error_correction);
    printf("Encoded Data: %s%s\n", qr_code.data, qr_code.error_correction);
}

int main() {
    char* data = "Hello, World!";
    QRCode qr_code = generate_qr_code(data);
    print_qr_code(qr_code);
    free(qr_code.data);
    free(qr_code.error_correction);
    return 0;
}