//FormAI DATASET v1.0 Category: Encryption ; Style: energetic
#include <stdio.h>
#include <string.h>

#define SHIFT_AMOUNT 3 // Caesar Cipher shift amount

// function to perform XOR encryption
void xorEncrypt(unsigned char *data, unsigned char key, size_t len) {
    for (size_t i = 0; i < len; i++) {
        data[i] ^= key;
    }
}

// function to perform Caesar Cipher encryption
void caesarEncrypt(unsigned char *data, size_t len) {
    for (size_t i = 0; i < len; i++) {
        data[i] = (data[i] + SHIFT_AMOUNT) % 256;
    }
}

int main() {
    // prompt the user for input
    printf("Enter the data to be encrypted: ");
    char input[256];
    fgets(input, sizeof(input), stdin);

    // strip the newline character from the input
    input[strcspn(input, "\n")] = 0;

    // convert the input to unsigned char array
    unsigned char data[strlen(input)];
    for (int i = 0; i < strlen(input); i++) {
        data[i] = input[i];
    }

    // encrypt the data
    xorEncrypt(data, 0xC3, strlen(input));
    caesarEncrypt(data, strlen(input));

    // print the encrypted data
    printf("\nEncrypted data: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%02x", data[i]);
    }

    // decrypt the data
    caesarEncrypt(data, strlen(input)); // first undo caesar cipher shift
    xorEncrypt(data, 0xC3, strlen(input)); // then undo XOR encryption

    // print the decrypted data
    printf("\nDecrypted data: ");
    for (int i = 0; i < strlen(input); i++) {
        printf("%c", data[i]);
    }

    return 0;
}