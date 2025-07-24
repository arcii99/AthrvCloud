//FormAI DATASET v1.0 Category: Modern Encryption ; Style: future-proof
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    unsigned char key[16];
    unsigned char state[256];
    unsigned char i, j;
} rc4_t;

void rc4_init(rc4_t *rc4, unsigned char *key, size_t key_len) {
    int i;

    for (i = 0; i < 256; i++) {
        rc4->state[i] = (unsigned char)i;
    }

    rc4->i = 0;
    rc4->j = 0;

    for (i = 0; i < 256; i++) {
        rc4->j = (rc4->j + rc4->state[i] + key[i % key_len]) % 256;
        unsigned char tmp = rc4->state[i];
        rc4->state[i] = rc4->state[rc4->j];
        rc4->state[rc4->j] = tmp;
    }

    memcpy(rc4->key, key, key_len);
}

void rc4_encrypt(rc4_t *rc4, unsigned char *in, unsigned char *out, size_t len) {
    int i;

    for (i = 0; i < len; i++) {
        rc4->i = (rc4->i + 1) % 256;
        rc4->j = (rc4->j + rc4->state[rc4->i]) % 256;
        unsigned char tmp = rc4->state[rc4->i];
        rc4->state[rc4->i] = rc4->state[rc4->j];
        rc4->state[rc4->j] = tmp;

        out[i] = in[i] ^ rc4->state[(rc4->state[rc4->i] + rc4->state[rc4->j]) % 256];
    }
}

int main() {
    rc4_t rc4;
    unsigned char key[] = "testkey";
    unsigned char plaintext[] = "hello world!";
    unsigned char ciphertext[sizeof(plaintext)];

    rc4_init(&rc4, key, sizeof(key) - 1);
    rc4_encrypt(&rc4, plaintext, ciphertext, sizeof(plaintext));

    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    int i;
    for (i = 0; i < sizeof(ciphertext); i++) {
        printf("%02x", ciphertext[i]);
    }
    printf("\n");

    return 0;
}