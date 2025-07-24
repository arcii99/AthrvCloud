//FormAI DATASET v1.0 Category: Compression algorithms ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_BUFFER_SIZE 1000
#define MAX_CODE_LENGTH 16

int buffer[MAX_BUFFER_SIZE];
int compressed[MAX_BUFFER_SIZE];
int decoded[MAX_BUFFER_SIZE];

typedef struct {
    int value;
    char code[MAX_CODE_LENGTH];
} table_entry;

table_entry encoding_table[256];

void generate_encoding_table(int *data, int size) {
    int i, j;
    int frequency[256] = {0};

    for (i = 0; i < size; i++) {
        frequency[data[i]]++;
    }

    for (i = 0, j = 0; i < 256; i++) {
        if (frequency[i] != 0) {
            encoding_table[j].value = i;
            sprintf(encoding_table[j].code, "%03d", j);
            j++;
        }
    }
}

int lookup_encoding(int value) {
    int i;

    for (i = 0; i < 256; i++) {
        if (encoding_table[i].value == value) {
            return i;
        }
    }

    return -1;
}

void compress(int *data, int size) {
    int i, j, index = 0;
    int bit_pos = 0;
    bool buffer_overflow = false;

    for (i = 0; i < size; i++) {
        int encoded_value = lookup_encoding(data[i]);

        if (encoded_value != -1) {
            int code_length = snprintf(NULL, 0, "%s", encoding_table[encoded_value].code);
            if ((bit_pos + code_length) > 32) {
                buffer_overflow = true;
                break;
            }

            for (j = 0; j < code_length; j++) {
                compressed[index] |= (encoding_table[encoded_value].code[j] - '0') << (31 - (bit_pos + j));
            }

            bit_pos += code_length;
            index = bit_pos / 32;
            bit_pos = bit_pos % 32;
        }
    }

    if (buffer_overflow) {
        printf("Error: compressed buffer overflow!\n");
    } else {
        printf("Compressed data:\n");
        for (i = 0; i <= index; i++) {
            printf("%08X ", compressed[i]);
        }
        printf("\n");
    }
}

void decode(int size) {
    int i, j, index = 0;
    int bit_pos = 0;

    for (i = 0; i < size; i++) {
        for (j = 0; j < 256; j++) {
            int code_length = snprintf(NULL, 0, "%s", encoding_table[j].code);
            if (bit_pos + code_length <= 32) {
                int code = (compressed[index] >> (31 - bit_pos)) & ((1 << code_length) - 1);
                if (code == atoi(encoding_table[j].code)) {
                    decoded[i] = encoding_table[j].value;
                    bit_pos += code_length;
                    index = bit_pos / 32;
                    bit_pos = bit_pos % 32;
                    break;
                }
            }
        }
    }

    printf("Decoded data:\n");
    for (i = 0; i < size; i++) {
        printf("%d ", decoded[i]);
    }
    printf("\n");
}

int main() {
    int i, size;

    for (i = 0; i < MAX_BUFFER_SIZE; i++) {
        buffer[i] = rand() % 256;
    }

    size = MAX_BUFFER_SIZE / 2;
    generate_encoding_table(buffer, size);
    compress(buffer, size);
    decode(size);
    return 0;
}