//FormAI DATASET v1.0 Category: Modern Encryption ; Style: Donald Knuth
/* Donald Knuth Style Modern Encryption Example Program*/

#include <stdio.h>
#include <string.h>

#define BLOCK_SIZE 16

void rotate_left(unsigned char *arr, int size, int amount) {
    while (amount-- > 0) {
        unsigned char temp = arr[0];
        for (int i = 0; i < size - 1; i++) {
            arr[i] = arr[i+1];
        }
        arr[size-1] = temp;
    }
}

void modern_encrypt(unsigned char *input, int size, unsigned char *key, int key_size) {
    unsigned char block[BLOCK_SIZE];
    for (int i = 0; i < size; i += BLOCK_SIZE) {
        memcpy(block, input + i, BLOCK_SIZE);
        for (int j = 0; j < key_size; j++) {
            unsigned char key_byte = key[j];
            rotate_left(block, BLOCK_SIZE, key_byte % BLOCK_SIZE);
            for (int k = 0; k < BLOCK_SIZE; k++) {
                block[k] ^= key_byte;
            }
            rotate_left(key, key_size, key_byte % key_size);
        }
        memcpy(input + i, block, BLOCK_SIZE);
    }
}

int main() {
    unsigned char input[] = "Donald Knuth";
    unsigned char key[] = "The Art of Computer Programming";
    int input_size = strlen(input);
    int key_size = strlen(key);
    printf("Original string: %s\n", input);
    modern_encrypt(input, input_size, key, key_size);
    printf("Encrypted string: ");
    for (int i = 0; i < input_size; i++) {
        printf("%02x", input[i]);
    }
    modern_encrypt(input, input_size, key, key_size); // Decrypt
    printf("\nDecrypted string: %s\n", input);
    return 0;
}