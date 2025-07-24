//FormAI DATASET v1.0 Category: Public-Key Algorithm Implementation ; Style: paranoid
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BLOCK_SIZE 16
#define KEY_LENGTH 128
#define MAX_INPUT_LENGTH 1024

/* Key structure */
typedef struct {
    unsigned char key[KEY_LENGTH];
} PublicKey;

/* Encrypt function */
void encrypt(const char *msg, const PublicKey *key, char *cipher) {
    int i, j, k;
    int msg_len = strlen(msg);
    int num_blocks = msg_len / BLOCK_SIZE + 1;

    unsigned char padded_msg[MAX_INPUT_LENGTH];
    memcpy(padded_msg, msg, msg_len);
    memcpy(padded_msg + msg_len, key->key, BLOCK_SIZE - msg_len % BLOCK_SIZE);

    srand(time(NULL));

    for (i = 0; i < num_blocks; i++) {
        unsigned char block[BLOCK_SIZE];
        memcpy(block, padded_msg + i * BLOCK_SIZE, BLOCK_SIZE);

        for (j = 0; j < BLOCK_SIZE; j++) {
            block[j] ^= key->key[j];
        }

        for (j = 0; j < BLOCK_SIZE; j++) {
            for (k = 0; k < 8; k++) {
                int bit = (rand() % 2) ^ ((block[j] >> k) & 1);
                block[j] = (block[j] & ~(1 << k)) | (bit << k);
            }
        }

        memcpy(cipher + i * BLOCK_SIZE, block, BLOCK_SIZE);
    }
    cipher[num_blocks * BLOCK_SIZE] = '\0';
}

int main(void) {
    const PublicKey key = {{0x23, 0x44, 0x57, 0x69, 0x8A, 0xF4, 0xB5, 0xDE, 0x94, 0x82, 0xAC, 0x66, 0x3D, 0xED, 0x9E, 0x7C}};
    char input[MAX_INPUT_LENGTH];
    char cipher[MAX_INPUT_LENGTH];
    int i = 0;

    printf("Enter message to encrypt:\n");
    fgets(input, MAX_INPUT_LENGTH, stdin);
    input[strcspn(input, "\n")] = '\0';

    encrypt(input, &key, cipher);

    printf("Cipher text: ");
    for(i; i < strlen(input); i++) {
        printf("%02x", cipher[i]);
    }
    printf("\n");
    return 0;
}