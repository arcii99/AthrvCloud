//FormAI DATASET v1.0 Category: QR code reader ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>
#include <stdbool.h>

/* Shape-shifting QR code reader */
 
/* Types of QR codes */
#define QR_TYPE_NUMERIC 0
#define QR_TYPE_ALPHANUMERIC 1
#define QR_TYPE_BYTE 2
 
/* Error correction levels */
#define QR_ERROR_LEVEL_L 0
#define QR_ERROR_LEVEL_M 1
#define QR_ERROR_LEVEL_Q 2
#define QR_ERROR_LEVEL_H 3
 
/* Struct representing a QR code */
typedef struct {
    uint8_t type; // QR_TYPE_NUMERIC, QR_TYPE_ALPHANUMERIC or QR_TYPE_BYTE
    uint8_t error_level; // QR_ERROR_LEVEL_L, QR_ERROR_LEVEL_M, QR_ERROR_LEVEL_Q or QR_ERROR_LEVEL_H
    uint8_t version; // QR code version, from 1 to 40
    uint8_t size; // size of the QR code (size*size modules)
    uint8_t** data; // 2D array of data modules
} qr_code;
 
/* Read an integer from a string */
uint32_t read_integer(const char* str) {
    uint32_t value = 0;
    while (*str >= '0' && *str <= '9') {
        value = (value * 10) + (*str - '0');
        str++;
    }
    return value;
}
 
/* Decode a numeric QR code */
void decode_numeric_qr(qr_code code) {
    printf("Numeric QR code detected!\n");
    printf("Contents:\n");
    uint32_t value = 0;
    for (int i = 0; i < code.size; i++) {
        for (int j = 0; j < code.size; j += 3) {
            // Combine groups of 3 digits
            value = (code.data[i][j] * 100) + (code.data[i][j+1] * 10) + code.data[i][j+2];
            printf("%u", value);
        }
        printf("\n");
    }
}
 
/* Decode an alphanumeric QR code */
void decode_alphanumeric_qr(qr_code code) {
    printf("Alphanumeric QR code detected!\n");
    printf("Contents:\n");
    char* str = calloc(code.size*2+1, sizeof(char));
    int index = 0;
    for (int i = 0; i < code.size; i++) {
        for (int j = 0; j < code.size; j += 2) {
            // Combine 2 characters
            uint32_t value = (code.data[i][j] * 45) + code.data[i][j+1];
            if (value < 10) {
                str[index] = '0' + value;
            } else if (value < 36) {
                str[index] = 'A' + (value - 10);
            } else if (value == 36) {
                str[index] = ' ';
            } else if (value == 37) {
                str[index] = '$';
            } else if (value == 38) {
                str[index] = '%';
            } else if (value == 39) {
                str[index] = '*';
            } else if (value == 40) {
                str[index] = '+';
            } else if (value == 41) {
                str[index] = '-';
            } else if (value == 42) {
                str[index] = '.';
            } else if (value == 43) {
                str[index] = '/';
            } else if (value == 44) {
                str[index] = ':';
            } else {
                printf("Invalid alphanumeric value: %u\n", value);
                free(str);
                return;
            }
            index++;
        }
    }
    printf("%s\n", str);
    free(str);
}
 
/* Decode a byte QR code */
void decode_byte_qr(qr_code code) {
    printf("Byte QR code detected!\n");
    printf("Contents:\n");
    for (int i = 0; i < code.size; i++) {
        for (int j = 0; j < code.size; j++) {
            printf("%c", code.data[i][j]);
        }
        printf("\n");
    }
}
 
/* Read a QR code from a file */
qr_code read_qr_from_file(const char* filename) {
    qr_code code;
    code.data = NULL;
    // Open file
    FILE* file = fopen(filename, "rb");
    if (file == NULL) {
        printf("Error opening file: %s\n", filename);
        return code;
    }
    // Read header data
    char header[20];
    fgets(header, sizeof(header), file);
    if (strncmp(header, "QR_CODE ", 8) != 0) {
        printf("Invalid QR code file\n");
        fclose(file);
        return code;
    }
    code.type = header[9] - '0';
    code.error_level = header[10] - '0';
    code.version = header[12] - '0';
    code.size = read_integer(header + 14);
    // Allocate memory for data modules
    code.data = calloc(code.size, sizeof(uint8_t*));
    for (int i = 0; i < code.size; i++) {
        code.data[i] = calloc(code.size, sizeof(uint8_t));
    }
    // Read data modules
    for (int i = 0; i < code.size; i++) {
        for (int j = 0; j < code.size; j++) {
            code.data[i][j] = fgetc(file);
        }
    }
    // Close file
    fclose(file);
    return code;
}
 
int main(int argc, char** argv) {
    if (argc < 2) {
        printf("Please specify a QR code file\n");
        return 0;
    }
    qr_code code = read_qr_from_file(argv[1]);
    if (code.data == NULL) {
        return 0;
    }
    switch (code.type) {
        case QR_TYPE_NUMERIC:
            decode_numeric_qr(code);
            break;
        case QR_TYPE_ALPHANUMERIC:
            decode_alphanumeric_qr(code);
            break;
        case QR_TYPE_BYTE:
            decode_byte_qr(code);
            break;
        default:
            printf("Invalid QR code type: %u\n", code.type);
            break;
    }
    // Free memory
    for (int i = 0; i < code.size; i++) {
        free(code.data[i]);
    }
    free(code.data);
    return 0;
}