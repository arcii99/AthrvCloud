//FormAI DATASET v1.0 Category: Modern Encryption ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_hex(unsigned char *data, int len) {
    int i;
    for(i=0; i<len; i++)
        printf("%02x", data[i]);
    printf("\n");
}

void encrypt(unsigned char *key, unsigned char *data, int len) {
    int i;
    for(i=0; i<len; i++) {
        data[i] ^= key[i%16];
        data[i] = ~data[i];
        key[i%16] += i;
    }
}

void decrypt(unsigned char *key, unsigned char *data, int len) {
    int i;
    for(i=0; i<len; i++) {
        key[i%16] += i;
        data[i] = ~data[i];
        data[i] ^= key[i%16];
    }
}

int main() {
    unsigned char key[16] = {0x40, 0xA3, 0x1D, 0x2B, 0xF4, 0x17, 0xBB, 0x08,
                             0xD9, 0x6C, 0x5A, 0xE7, 0xC1, 0x9A, 0x83, 0xFD};
    unsigned char data[] = "This is a secret message";
    int len = strlen(data);

    printf("Original data: ");
    printf("%s\n", data);

    encrypt(key, data, len);

    printf("Encrypted data: ");
    print_hex(data, len);

    decrypt(key, data, len);

    printf("Decrypted data: ");
    printf("%s\n", data);

    return 0;
}