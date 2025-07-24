//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: minimalist
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

/* Block size */
#define BLOCK_SIZE 16

/* Cipher rounds */
#define ROUNDS 10

/* Key schedule constant */
#define RCONST(i) (1 << (i - 1))

/* S-Box */
static const uint8_t SBOX[16] = {0xC, 0x5, 0x6, 0xB, 0x9, 0x0, 0xA, 0xD, 0x3, 0xE, 0xF, 0x8, 0x4, 0x7, 0x1, 0x2};

/* Inverted S-Box */
static const uint8_t INV_SBOX[16] = {0x5, 0xE, 0xF, 0x8, 0xC, 0x1, 0x2, 0xD, 0xB, 0x4, 0x6, 0x3, 0x0, 0x9, 0xA, 0x7};

/* Key schedule */
void aes128_key_schedule(const uint8_t *key, uint8_t *rk) {
    /* Copy key to round key */
    memcpy(rk, key, BLOCK_SIZE);

    /* Round constant */
    uint8_t rc = 1;

    for (int i = 4; i < 4 * (ROUNDS + 1); i += 4) {
        /* Rotate left */
        uint8_t temp[4];
        memcpy(temp, rk + i - 4, 4);
        uint8_t t = temp[0];
        temp[0] = temp[1];
        temp[1] = temp[2];
        temp[2] = temp[3];
        temp[3] = t;

        /* Substitution */
        for (int j = 0; j < 4; j++) {
            temp[j] = SBOX[temp[j] >> 4] | (SBOX[temp[j] & 0x0F] << 4);
        }

        /* XOR with round constant */
        temp[0] ^= rc;
        rc = rc << 1 ^ ((rc >> 7) * 0x1B);

        /* XOR with previous word */
        for (int j = 0; j < 4; j++) {
            rk[i + j] = rk[i - 16 + j] ^ temp[j];
        }
    }
}

/* Add round key */
void aes128_add_round_key(uint8_t *state, const uint8_t *rk) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        state[i] ^= rk[i];
    }
}

/* Substitution layer */
void aes128_sub_bytes(uint8_t *state) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        state[i] = SBOX[state[i] >> 4] | (SBOX[state[i] & 0x0F] << 4);
    }
}

/* Inverted substitution layer */
void aes128_inv_sub_bytes(uint8_t *state) {
    for (int i = 0; i < BLOCK_SIZE; i++) {
        state[i] = INV_SBOX[state[i] >> 4] | (INV_SBOX[state[i] & 0x0F] << 4);
    }
}

/* Shift rows */
void aes128_shift_rows(uint8_t *state) {
    /* Second row */
    uint8_t t = state[1];
    state[1] = state[5];
    state[5] = state[9];
    state[9] = state[13];
    state[13] = t;

    /* Third row */
    t = state[2];
    state[2] = state[10];
    state[10] = t;
    t = state[6];
    state[6] = state[14];
    state[14] = t;

    /* Fourth row */
    t = state[15];
    state[15] = state[11];
    state[11] = state[7];
    state[7] = state[3];
    state[3] = t;
}

/* Inverted shift rows */
void aes128_inv_shift_rows(uint8_t *state) {
    /* Second row */
    uint8_t t = state[13];
    state[13] = state[9];
    state[9] = state[5];
    state[5] = state[1];
    state[1] = t;

    /* Third row */
    t = state[10];
    state[10] = state[2];
    state[2] = t;
    t = state[14];
    state[14] = state[6];
    state[6] = t;

    /* Fourth row */
    t = state[3];
    state[3] = state[7];
    state[7] = state[11];
    state[11] = state[15];
    state[15] = t;
}

/* Mix columns */
void aes128_mix_columns(uint8_t *state) {
    for (int i = 0; i < BLOCK_SIZE; i += 4) {
        uint8_t s0 = state[i];
        uint8_t s1 = state[i + 1];
        uint8_t s2 = state[i + 2];
        uint8_t s3 = state[i + 3];
        uint8_t t0 = s0 ^ s1 ^ s2 ^ s3;
        uint8_t t1 = s0;
        uint8_t xtime;

        /* Multiply by 2 */
        xtime = s0 & 0x80 ? 0x1B : 0;
        s0 = (s0 << 1) ^ xtime;

        /* Multiply by 3 */
        xtime = s1 & 0x80 ? 0x1B : 0;
        s1 = (s1 << 1) ^ xtime ^ s0;

        /* Multiply by 2 */
        xtime = s2 & 0x80 ? 0x1B : 0;
        s2 = (s2 << 1) ^ xtime ^ s1;

        /* Multiply by 2 */
        xtime = s3 & 0x80 ? 0x1B : 0;
        s3 = (s3 << 1) ^ xtime ^ s2;

        state[i] = t0 ^ s0 ^ t1;
        state[i + 1] = t0 ^ s1 ^ s0;
        state[i + 2] = t0 ^ s2 ^ s1;
        state[i + 3] = t0 ^ s3 ^ s2;
    }
}

/* Inverted mix columns */
void aes128_inv_mix_columns(uint8_t *state) {
    for (int i = 0; i < BLOCK_SIZE; i += 4) {
        uint8_t s0 = state[i];
        uint8_t s1 = state[i + 1];
        uint8_t s2 = state[i + 2];
        uint8_t s3 = state[i + 3];
        uint8_t t0 = s0 ^ s1 ^ s2 ^ s3;
        uint8_t xtime;

        /* Multiply by 9 */
        xtime = s0 & 0x80 ? 0x1B : 0;
        s0 = (s0 << 1) ^ xtime ^ (s0 << 2) ^ (s0 << 3);
        s1 = s1 ^ (s1 << 1) ^ (s1 << 3);
        s2 = s2 ^ (s2 << 2) ^ (s2 << 3);
        s3 = s3 ^ (s3 << 1) ^ (s3 << 2);

        state[i] = t0 ^ s0 ^ s1 ^ s2 ^ s3;
        state[i + 1] = t0 ^ s0 ^ s1 ^ s3;
        state[i + 2] = t0 ^ s0 ^ s2 ^ s3;
        state[i + 3] = t0 ^ s0 ^ s1 ^ s2;
    }
}

/* AES-128 encryption */
void aes128_encrypt(const uint8_t *key, const uint8_t *input, uint8_t *output) {
    /* Round key */
    uint8_t rk[4 * (ROUNDS + 1)];
    aes128_key_schedule(key, rk);

    /* Initial round */
    aes128_add_round_key(output, key);

    /* ROUNDS-1 rounds */
    for (int i = 1; i < ROUNDS; i++) {
        aes128_sub_bytes(output);
        aes128_shift_rows(output);
        aes128_mix_columns(output);
        aes128_add_round_key(output, rk + 4 * i);
    }

    /* Final round */
    aes128_sub_bytes(output);
    aes128_shift_rows(output);
    aes128_add_round_key(output, rk + 4 * ROUNDS);
}

/* AES-128 decryption */
void aes128_decrypt(const uint8_t *key, const uint8_t *input, uint8_t *output) {
    /* Round key */
    uint8_t rk[4 * (ROUNDS + 1)];
    aes128_key_schedule(key, rk);

    /* Initial round */
    aes128_add_round_key(output, rk + 4 * ROUNDS);
    aes128_inv_shift_rows(output);
    aes128_inv_sub_bytes(output);

    /* ROUNDS-1 rounds */
    for (int i = ROUNDS - 1; i > 0; i--) {
        aes128_add_round_key(output, rk + 4 * i);
        aes128_inv_mix_columns(output);
        aes128_inv_shift_rows(output);
        aes128_inv_sub_bytes(output);
    }

    /* Final round */
    aes128_add_round_key(output, key);
}

int main() {
    /* Test vectors */
    uint8_t key[] = {0x2b, 0x7e, 0x15, 0x16, 0x28, 0xae, 0xd2, 0xa6, 0xab, 0xf7, 0x15, 0x88, 0x09, 0xcf, 0x4f, 0x3c};
    uint8_t input[] = {0x32, 0x43, 0xf6, 0xa8, 0x88, 0x5a, 0x30, 0x8d, 0x31, 0x31, 0x98, 0xa2, 0xe0, 0x37, 0x07, 0x34};
    uint8_t output[BLOCK_SIZE];

    /* Encryption */
    aes128_encrypt(key, input, output);

    /* Print output */
    printf("Encrypted: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", output[i]);
    }
    printf("\n");

    /* Decryption */
    aes128_decrypt(key, output, input);

    /* Print output */
    printf("Decrypted: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", input[i]);
    }
    printf("\n");

    return 0;
}