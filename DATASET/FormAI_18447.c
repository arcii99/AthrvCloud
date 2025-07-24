//FormAI DATASET v1.0 Category: QR code generator ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_DATA_SIZE 200
#define MAX_QR_CODE_SIZE 21

typedef struct QR_Code {
    char data[MAX_DATA_SIZE];
    int size;
    char code[MAX_QR_CODE_SIZE][MAX_QR_CODE_SIZE];
} QR_Code;

void initialize_code(QR_Code *code) {
    // Set all characters in `code` to ' '
    memset(code->code, ' ', sizeof(code->code));
}

int encode_data(QR_Code *code) {
    // Encode data in `code` into QR code format
    int x = 0, y = 0, i = 0;
    while (i < code->size) {
        if (y >= MAX_QR_CODE_SIZE) {
            // If at the end of a row, move to the next row
            y = 0;
            x++;
        }
        if (x >= MAX_QR_CODE_SIZE) {
            // If maximum size for QR code reached, return error
            return -1;
        }
        code->code[x][y] = code->data[i];
        y++;
        i++;
    }
    return 0;
}

void print_code(QR_Code *code) {
    // Print QR code
    for (int i = 0; i < MAX_QR_CODE_SIZE; i++) {
        for (int j = 0; j < MAX_QR_CODE_SIZE; j++) {
            printf("%c", code->code[i][j]);
        }
        printf("\n");
    }
}

int main() {
    QR_Code code;
    strcpy(code.data, "Hello world!");
    code.size = strlen(code.data);
    initialize_code(&code);
    
    if (encode_data(&code) == -1) {
        printf("Error: Max size for QR code exceeded.");
        exit(1);
    }
    
    print_code(&code);
    
    return 0;
}