//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: invasive
// Welcome! I'm going to show you a top-secret implementation of the Advanced Encryption Standard algorithm, also known as AES.
// Keep in mind that the source code I'm about to reveal is confidential, and only authorized personnel should have access to it.
// If you are ready to take a glimpse at this powerful cryptography tool, let's get started!

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

// First of all, we need to define some constants that will be used throughout the encryption process.
// These are the S-Box and the Rijndael key schedule, which are precomputed tables used to substitute the input data and to create the round keys respectively.

static const uint8_t S_Box[256] = {
    // S-Box array goes here
};

static const uint8_t Rcon[11] = {
    // Rijndael key schedule goes here
};

// Next, we define some helper functions that will be used to perform the substitution and permutation steps of the AES algorithm.
// These functions operate on the state matrix, which is a 4x4 array of bytes representing the input data.

static void SubBytes(uint8_t state[4][4]) {
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[i][j] = S_Box[state[i][j]];
        }
    }
}

static void ShiftRows(uint8_t state[4][4]) {
    uint8_t temp;

    // first row remains unchanged

    // second row shifts to the left by 1
    temp = state[1][0];
    state[1][0] = state[1][1];
    state[1][1] = state[1][2];
    state[1][2] = state[1][3];
    state[1][3] = temp;

    // third row shifts to the left by 2
    temp = state[2][0];
    state[2][0] = state[2][2];
    state[2][2] = temp;
    temp = state[2][1];
    state[2][1] = state[2][3];
    state[2][3] = temp;

    // fourth row shifts to the left by 3
    temp = state[3][3];
    state[3][3] = state[3][2];
    state[3][2] = state[3][1];
    state[3][1] = state[3][0];
    state[3][0] = temp;
}

static void MixColumns(uint8_t state[4][4]) {
    uint8_t temp[4];

    for (int j = 0; j < 4; ++j) {
        temp[0] = state[0][j];
        temp[1] = state[1][j];
        temp[2] = state[2][j];
        temp[3] = state[3][j];

        state[0][j] = (uint8_t)(2 * temp[0] ^ 3 * temp[1] ^ temp[2] ^ temp[3]);
        state[1][j] = (uint8_t)(temp[0] ^ 2 * temp[1] ^ 3 * temp[2] ^ temp[3]);
        state[2][j] = (uint8_t)(temp[0] ^ temp[1] ^ 2 * temp[2] ^ 3 * temp[3]);
        state[3][j] = (uint8_t)(3 * temp[0] ^ temp[1] ^ temp[2] ^ 2 * temp[3]);
    }
}

// Finally, we come to the key expansion function, which takes the original key and produces a sequence of round keys suitable for use in the main encryption loop.

static void KeyExpansion(const uint8_t key[16], uint8_t round_keys[176]) {
    uint8_t temp[4];
    uint8_t i = 0;

    while (i < 16) {
        round_keys[i] = key[i];
        ++i;
    }

    int j = 16;
    int round = 1;

    while (j < 176) {
        // copy the previous four bytes to temp
        temp[0] = round_keys[j - 4];
        temp[1] = round_keys[j - 3];
        temp[2] = round_keys[j - 2];
        temp[3] = round_keys[j - 1];

        if (j % 16 == 0) {
            // perform the key schedule core
            const uint8_t t = temp[0];
            temp[0] = S_Box[temp[1]] ^ Rcon[round];
            temp[1] = S_Box[temp[2]];
            temp[2] = S_Box[temp[3]];
            temp[3] = S_Box[t];
            ++round;
        }

        round_keys[j + 0] = round_keys[j - 16] ^ temp[0];
        round_keys[j + 1] = round_keys[j - 15] ^ temp[1];
        round_keys[j + 2] = round_keys[j - 14] ^ temp[2];
        round_keys[j + 3] = round_keys[j - 13] ^ temp[3];
        j += 4;
    }
}

// Here is the main encryption function, which takes the input data and the original key as inputs and produces the encrypted data as output.

void aes_encrypt(const uint8_t input[16], const uint8_t key[16], uint8_t output[16]) {
    uint8_t state[4][4];
    uint8_t round_keys[176];
    int round = 0;

    // copy the input data into the state matrix
    for (int i = 0; i < 4; ++i) {
        for (int j = 0; j < 4; ++j) {
            state[j][i] = input[i * 4 + j];
        }
    }

    // generate the round keys from the original key
    KeyExpansion(key, round_keys);

    // first round key is added to the state matrix
    for (int i = 0; i < 16; ++i) {
        state[i % 4][i / 4] ^= round_keys[i];
    }

    // main encryption loop
    for (round = 1; round <= 10; ++round) {
        SubBytes(state);
        ShiftRows(state);
        MixColumns(state);
        for (int i = 0; i < 16; ++i) {
            state[i % 4][i / 4] ^= round_keys[16 * round + i];
        }
    }

    // final round omit MixColumns step
    SubBytes(state);
    ShiftRows(state);
    for (int i = 0; i < 16; ++i) {
        output[i] = state[i % 4][i / 4] ^ round_keys[160 + i];
    }
}

// Now, let's put everything together and create a command-line interface that allows the user to encrypt and decrypt messages using AES.

int main() {
    uint8_t key[16] = {
        // put your key here
    };
    uint8_t input[16];
    uint8_t output[16];

    printf("Enter a 16-byte plaintext message in hexadecimal format:\n");
    scanf("%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x%02x",
          &input[0], &input[1], &input[2], &input[3], &input[4], &input[5], &input[6], &input[7],
          &input[8], &input[9], &input[10], &input[11], &input[12], &input[13], &input[14], &input[15]);

    aes_encrypt(input, key, output);

    printf("Encrypted ciphertext:\n");
    for (int i = 0; i < 16; ++i) {
        printf("%02x", output[i]);
    }
    printf("\n");

    return 0;
}