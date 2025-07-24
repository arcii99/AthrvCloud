//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: shape shifting
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to calculate checksum using XOR operation
unsigned char calculate_checksum(char* data, int size) {
    unsigned char checksum = 0;
    for (int i = 0; i < size; i++) {
        checksum ^= data[i];
    }
    return checksum;
}

// function to convert decimal to binary
char* decimal_to_binary(unsigned char number) {
    char* binary = (char*)malloc(9 * sizeof(char));
    int i = 0;
    while (number > 0) {
        binary[i++] = (number % 2) + '0';
        number /= 2;
    }
    while (i < 8) {
        binary[i++] = '0';
    }
    binary[i] = '\0';
    return binary;
}

// function to print checksum in binary format
void print_checksum(unsigned char checksum) {
    char* binary = decimal_to_binary(checksum);
    printf("Checksum (binary): %s\n", binary);
    free(binary);
}

int main() {
    char data[256];
    printf("Enter data: ");
    fgets(data, 256, stdin);
    int size = strlen(data) - 1;
    printf("Size: %d\n", size);
    unsigned char checksum = calculate_checksum(data, size);
    printf("Checksum (decimal): %d\n", checksum);
    print_checksum(checksum);
    return 0;
}