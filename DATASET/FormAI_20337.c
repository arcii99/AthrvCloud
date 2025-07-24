//FormAI DATASET v1.0 Category: Digital Watermarking ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SIZE 1024
#define BITS 32

struct watermark {
    char message[MAX_SIZE];
    int length;
};

void to_binary(unsigned int num, char* binary, int bits) {
    for (int i = bits-1; i >= 0; i--) {
        binary[i] = (num & 1) ? '1' : '0';
        num >>= 1;
    }
}

unsigned int to_decimal(char* binary, int bits) {
    unsigned int result = 0;
    for (int i = 0; i < bits; i++) {
        result <<= 1;
        result |= (binary[i] == '1') ? 1 : 0;
    }
    return result;
}

void embed_watermark(unsigned int* data, int data_size, struct watermark wm) {
    char binary_wm[wm.length * BITS];
    for (int i = 0; i < wm.length; i++) {
        to_binary(wm.message[i], &binary_wm[i * BITS], BITS);
    }
    int j = 0;
    for (int i = 0; i < data_size; i++) {
        to_binary(data[i], &binary_wm[j], BITS);
        j += BITS;
        if (j >= wm.length * BITS) {
            break;
        }
    }
    unsigned int* new_data = malloc(data_size * sizeof(unsigned int));
    j = 0;
    for (int i = 0; i < data_size; i++) {
        char binary_num[BITS];
        to_binary(data[i], binary_num, BITS);
        if (j < wm.length * BITS) {
            binary_num[BITS-1] = binary_wm[j];
            j++;
        }
        new_data[i] = to_decimal(binary_num, BITS);
    }
    memcpy(data, new_data, data_size * sizeof(unsigned int));
    free(new_data);
}

struct watermark extract_watermark(unsigned int* data, int data_size, int wm_length) {
    char binary_wm[wm_length * BITS];
    int j = 0;
    for (int i = 0; i < data_size; i++) {
        char binary_num[BITS];
        to_binary(data[i], binary_num, BITS);
        binary_wm[j] = binary_num[BITS-1];
        j++;
        if (j >= wm_length * BITS) {
            break;
        }
    }
    struct watermark wm;
    wm.length = wm_length;
    for (int i = 0; i < wm_length; i++) {
        wm.message[i] = (char)to_decimal(&binary_wm[i*BITS], BITS);
    }
    return wm;
}

int main() {
    unsigned int data[] = {0x12345678, 0x9ABCDEF0, 0x13579BDF, 0xFEDCBA98};
    struct watermark wm;
    strcpy(wm.message, "This is a watermarked image.");
    wm.length = strlen(wm.message);
    printf("Data before watermarking: 0x%x 0x%x 0x%x 0x%x\n", data[0], data[1], data[2], data[3]);
    embed_watermark(data, 4, wm);
    printf("Data after watermarking: 0x%x 0x%x 0x%x 0x%x\n", data[0], data[1], data[2], data[3]);
    struct watermark extracted_wm = extract_watermark(data, 4, wm.length);
    printf("Extracted watermark: %s\n", extracted_wm.message);
    return 0;
}