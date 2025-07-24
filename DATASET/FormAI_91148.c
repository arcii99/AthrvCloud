//FormAI DATASET v1.0 Category: Binary Converter ; Style: sophisticated
#include <stdio.h>
#include <stdint.h>

#define BINARY_STRING_LENGTH  33

struct BinaryArray {
    uint32_t size;
    uint8_t bits[BINARY_STRING_LENGTH];
};

struct BinaryArray ToBinary(uint32_t input) {
    struct BinaryArray binary;
    for (uint32_t i = 0; i < BINARY_STRING_LENGTH; i++) {
        binary.bits[i] = 0;
    }
    binary.size = 0;
    while (input > 0) {
        binary.bits[binary.size++] = input % 2;
        input /= 2;
    }
    return binary;
}

void PrintBinary(struct BinaryArray binary) {
    if (binary.size == 0) {
        printf("0");
    }
    for (uint32_t i = binary.size - 1; i < BINARY_STRING_LENGTH; i--) {
        if (i < 0) {
            break;
        }
        printf("%d", binary.bits[i]);
        if (i % 4 == 0 && i != 0) {
            printf(" ");
        }
    }
    printf("\n");
}

int main(void) {
    uint32_t input = 123456789;
    printf("Binary representation of %d is:\n", input);
    struct BinaryArray binary = ToBinary(input);
    PrintBinary(binary);
    return 0;
}