//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: protected
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BLOCK_SIZE 16
#define KEY_SIZE 16

unsigned char S[256];
unsigned char key[KEY_SIZE];
unsigned char iv[BLOCK_SIZE];

/* The key schedule for AES encryption */
void key_schedule(unsigned char *input_key, unsigned char *round_keys) {
    int i, j, k;
    unsigned char temp[4];

    for (i = 0; i < KEY_SIZE; i++) {
        round_keys[i] = input_key[i];
    }

    for (i = KEY_SIZE; i < KEY_SIZE * 11; i++) {
        for (j = 0; j < 4; j++) {
            temp[j] = round_keys[(i - 1) * 4 + j];
        }
        if (i % KEY_SIZE == 0) {
            // RotWord - the last byte of the word is moved to the front
            unsigned char t = temp[0];
            temp[0] = temp[1];
            temp[1] = temp[2];
            temp[2] = temp[3];
            temp[3] = t;

            // SubWord - each byte is replaced with the S-box value
            temp[0] = S[temp[0]];
            temp[1] = S[temp[1]];
            temp[2] = S[temp[2]];
            temp[3] = S[temp[3]];

            temp[0] ^= 0x01;  // Rcon

        }
        for (k = 0; k < 4; k++) {
            round_keys[i * 4 + k] = round_keys[(i - KEY_SIZE) * 4 + k] ^ temp[k];
        }
    }
}

/* The substitution step  - maps each byte in the block to a new value */
void sub_bytes(unsigned char *state) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        state[i] = S[state[i]];
    }
}

/* The inverse substitution step - maps each byte in the block to its original value */
void inv_sub_bytes(unsigned char *state) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        state[i] = S[state[i] + 256];
    }
}

/* The shift rows step - shifts the second row one byte to the left, the third row two bytes to the left, and the fourth row three bytes to the left. */
void shift_rows(unsigned char *state) {
    unsigned char temp;

    /* shift second row */
    temp = state[1];
    state[1] = state[5];
    state[5] = state[9];
    state[9] = state[13];
    state[13] = temp;

    /* shift third row */
    temp = state[2];
    state[2] = state[10];
    state[10] = temp;
    temp = state[6];
    state[6] = state[14];
    state[14] = temp;

    /* shift fourth row */
    temp = state[15];
    state[15] = state[11];
    state[11] = state[7];
    state[7] = state[3];
    state[3] = temp;
}

/* The inverse shift rows step - shifts the second row one byte to the right, the third row two bytes to the right, and the fourth row three bytes to the right. */
void inv_shift_rows(unsigned char *state) {
    unsigned char temp;

    /* shift second row */
    temp = state[13];
    state[13] = state[9];
    state[9] = state[5];
    state[5] = state[1];
    state[1] = temp;

    /* shift third row */
    temp = state[10];
    state[10] = state[2];
    state[2] = temp;
    temp = state[14];
    state[14] = state[6];
    state[6] = temp;

    /* shift fourth row */
    temp = state[3];
    state[3] = state[7];
    state[7] = state[11];
    state[11] = state[15];
    state[15] = temp;
}

/* The mix columns step - each column of the state is multiplied with a fixed polynomial. */
void mix_columns(unsigned char *state) {
    int i;
    unsigned char a0, a1, a2, a3;
    for (i = 0; i < BLOCK_SIZE; i += 4) {
        a0 = state[i];
        a1 = state[i + 1];
        a2 = state[i + 2];
        a3 = state[i + 3];

        state[i] = 0x02 * a0 ^ 0x03 * a1 ^ a2 ^ a3;
        state[i + 1] = 0x02 * a1 ^ 0x03 * a2 ^ a0 ^ a3;
        state[i + 2] = 0x02 * a2 ^ 0x03 * a3 ^ a0 ^ a1;
        state[i + 3] = 0x02 * a3 ^ 0x03 * a0 ^ a1 ^ a2;
    }
}

/* The inverse mix columns step - each column of the state is multiplied with a fixed polynomial. */
void inv_mix_columns(unsigned char *state) {
    int i;
    unsigned char a0, a1, a2, a3;
    for (i = 0; i < BLOCK_SIZE; i += 4) {
        a0 = state[i];
        a1 = state[i + 1];
        a2 = state[i + 2];
        a3 = state[i + 3];

        state[i] = 0x0e * a0 ^ 0x0b * a1 ^ 0x0d * a2 ^ 0x09 * a3;
        state[i + 1] = 0x09 * a0 ^ 0x0e * a1 ^ 0x0b * a2 ^ 0x0d * a3;
        state[i + 2] = 0x0d * a0 ^ 0x09 * a1 ^ 0x0e * a2 ^ 0x0b * a3;
        state[i + 3] = 0x0b * a0 ^ 0x0d * a1 ^ 0x09 * a2 ^ 0x0e * a3;
    }
}

/* The xor step - each byte of the state is xor'ed with a byte from the round key. */
void add_round_key(unsigned char *state, unsigned char *round_key) {
    int i;
    for (i = 0; i < BLOCK_SIZE; i++) {
        state[i] ^= round_key[i];
    }
}

/* AES encryption of one block */
void aes_encrypt_block(unsigned char *input_block, unsigned char *output_block, unsigned char *round_key) {
    int i;
    unsigned char state[BLOCK_SIZE];

    // Copy the input block to the state
    for (i = 0; i < BLOCK_SIZE; i++) {
        state[i] = input_block[i];
    }

    add_round_key(state, round_key);

    for (i = 1; i < 10; i++) {
        sub_bytes(state);
        shift_rows(state);
        mix_columns(state);
        add_round_key(state, round_key + i * BLOCK_SIZE);
    }

    sub_bytes(state);
    shift_rows(state);
    add_round_key(state, round_key + 10 * BLOCK_SIZE);

    // Copy the state to the output block
    for (i = 0; i < BLOCK_SIZE; i++) {
        output_block[i] = state[i];
    }
}

/* AES decryption of one block */
void aes_decrypt_block(unsigned char *input_block, unsigned char *output_block, unsigned char *round_key) {
    int i;
    unsigned char state[BLOCK_SIZE];

    // Copy the input block to the state
    for (i = 0; i < BLOCK_SIZE; i++) {
        state[i] = input_block[i];
    }

    add_round_key(state, round_key + 10 * BLOCK_SIZE);

    for (i = 9; i > 0; i--) {
        inv_shift_rows(state);
        inv_sub_bytes(state);
        add_round_key(state, round_key + i * BLOCK_SIZE);
        inv_mix_columns(state);

    }

    inv_shift_rows(state);
    inv_sub_bytes(state);
    add_round_key(state, round_key);

    // Copy the state to the output block
    for (i = 0; i < BLOCK_SIZE; i++) {
        output_block[i] = state[i];
    }
}

int main() {
    unsigned char plain_text[] = "Hello, world!";
    unsigned char cipher_text[BLOCK_SIZE];
    unsigned char decrypted_text[BLOCK_SIZE];

    // Initialize the key
    memcpy(key, "abcdefghijklmnop", KEY_SIZE);

    // Initialize S-box
    int i;
    for (i = 0; i < 256; i++) {
        S[i] = i;
    }

    // Initialize the key schedule
    unsigned char round_keys[KEY_SIZE * 11];
    key_schedule(key, round_keys);

    // Encrypt the plain text
    aes_encrypt_block(plain_text, cipher_text, round_keys);
    printf("Plain text: %s\nCipher text: ", plain_text);
    for (i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x", cipher_text[i]);
    }
    printf("\n");

    // Decrypt the cipher text
    aes_decrypt_block(cipher_text, decrypted_text, round_keys);
    printf("Decrypted text: ");
    for (i = 0; i < BLOCK_SIZE; i++) {
        printf("%c", decrypted_text[i]);
    }
    printf("\n");

    return 0;
}