//FormAI DATASET v1.0 Category: QR code generator ; Style: recursive
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/**
 * Recursive function to generate QR code.
 * @param level: current level (starting from 0)
 * @param data: array to store the data
 * @param size: size of the array
 * @param code: current QR code generated
 * @param idx: current index of the code
 */
void generate_qr(int level, char *data, int size, char *code, int idx) {
    // base case
    if(level == 0) {
        // add start code
        strcat(code, "1101");
        idx += 4;

        // add data
        for(int i = 0; i < size; i++) {
            char bit[9];
            sprintf(bit, "%08d", atoi(data[i]));
            strcat(code, bit);
            idx += 8;
        }

        // add terminator
        strcat(code, "0000");
        idx += 4;

        // print the code
        printf("%s\n", code);
    }

    // recursive case
    else {
        // left QR code
        char left_code[strlen(code) + 4];
        strcpy(left_code, code);
        strcat(left_code, "01");
        generate_qr(level - 1, data, size, left_code, idx + 2);

        // right QR code
        char right_code[strlen(code) + 4];
        strcpy(right_code, code);
        strcat(right_code, "10");
        generate_qr(level - 1, data, size, right_code, idx + 2);
    }
}

int main() {
    // get data
    char data[10];
    printf("Enter data (up to 10 digits): ");
    scanf("%s", data);
    int size = strlen(data);

    // calculate level and QR code length
    int level = 0, code_len = 0;
    while(code_len < size * 8 + 8) {
        level++;
        code_len = 2 * (1 << level) - 2;
    }

    // generate QR code
    char code[code_len + 1];
    memset(code, 0, sizeof(code));
    generate_qr(level, data, size, code, 0);

    return 0;
}