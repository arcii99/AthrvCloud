//FormAI DATASET v1.0 Category: Modern Encryption ; Style: single-threaded
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_SIZE 256 // Key size in bits
#define BLOCK_SIZE 16 // Block size in bytes

typedef unsigned char byte;

// Cipher key as bytes
byte key[KEY_SIZE / 8];

// Cipher state structure
struct cipher_state {
    byte s[256];
    byte i;
    byte j;
};

// Initialize cipher state using key
void init_state(struct cipher_state* state)
{
    int i, j;

    // Initialize s array
    for (i = 0; i < 256; i++)
        state->s[i] = i;

    // Apply key to the s array
    for (i = j = 0; i < 256; i++) {
        byte temp;
        j = (j + state->s[i] + key[i % (KEY_SIZE / 8)]) % 256;
        temp = state->s[i];
        state->s[i] = state->s[j];
        state->s[j] = temp;
    }

    // Reset i and j
    state->i = state->j = 0;
}

// Generate next byte of keystream
byte next_keystream_byte(struct cipher_state* state)
{
    state->i = (state->i + 1) % 256;
    state->j = (state->j + state->s[state->i]) % 256;
    byte temp = state->s[state->i];
    state->s[state->i] = state->s[state->j];
    state->s[state->j] = temp;
    return state->s[(state->s[state->i] + state->s[state->j]) % 256];
}

// Encrypt plaintext using the stream cipher
void encrypt(byte* plaintext, int plaintext_len, byte* ciphertext)
{
    int i;
    struct cipher_state state;

    // Initialize cipher state
    init_state(&state);

    // Generate keystream and perform XOR with plaintext
    for (i = 0; i < plaintext_len; i++)
        ciphertext[i] = plaintext[i] ^ next_keystream_byte(&state);
}

int main()
{
    char plaintext[1024], ciphertext[1024];
    int plaintext_len, i;

    printf("Enter plaintext: ");
    fgets(plaintext, 1024, stdin);
    plaintext_len = strlen(plaintext);

    // Remove newline character added by fgets
    if (plaintext_len > 0 && plaintext[plaintext_len - 1] == '\n')
        plaintext[--plaintext_len] = '\0';

    // Pad plaintext if necessary
    if (plaintext_len % BLOCK_SIZE != 0) {
        int padding = BLOCK_SIZE - plaintext_len % BLOCK_SIZE;
        for (i = 0; i < padding; i++)
            plaintext[plaintext_len + i] = (byte)padding;
        plaintext_len += padding;
    }

    // Generate random key
    FILE* fp = fopen("/dev/urandom", "r");
    fread(key, sizeof(byte), KEY_SIZE / 8, fp);
    fclose(fp);

    // Encrypt plaintext using the stream cipher
    encrypt((byte*)plaintext, plaintext_len, (byte*)ciphertext);

    // Print ciphertext
    printf("Ciphertext:\n");
    for (i = 0; i < plaintext_len; i++)
        printf("%02x ", ciphertext[i]);
    printf("\n");

    return 0;
}