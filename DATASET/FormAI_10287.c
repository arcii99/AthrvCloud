//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <time.h>

// Define macros
#define BLOCK_SIZE 8
#define KEY_BIT_SIZE 128
#define MAX_ROUNDS 16

// Define substitution and permutation tables
static const uint8_t S[256] = {
  0x63, 0x7c, 0x77, 0x7b, 0xf2, 0x6b, 0x6f, 0xc5,
  0x30, 0x01, 0x67, 0x2b, 0xfe, 0xd7, 0xab, 0x76,
  0xca, 0x82, 0xc9, 0x7d, 0xfa, 0x59, 0x47, 0xf0,
  0xad, 0xd4, 0xa2, 0xaf, 0x9c, 0xa4, 0x72, 0xc0,
  0xb7, 0xfd, 0x93, 0x26, 0x36, 0x3f, 0xf7, 0xcc,
  0x34, 0xa5, 0xe5, 0xf1, 0x71, 0xd8, 0x31, 0x15,
  0x04, 0xc7, 0x23, 0xc3, 0x18, 0x96, 0x05, 0x9a,
  0x07, 0x12, 0x80, 0xe2, 0xeb, 0x27, 0xb2, 0x75,
  0x09, 0x83, 0x2c, 0x1a, 0x1b, 0x6e, 0x5a, 0xa0,
  0x52, 0x3b, 0xd6, 0xb3, 0x29, 0xe3, 0x2f, 0x84,
  0x53, 0xd1, 0x00, 0xed, 0x20, 0xfc, 0xb1, 0x5b,
  0x6a, 0xcb, 0xbe, 0x39, 0x4a, 0x4c, 0x58, 0xcf,
  0xd0, 0xef, 0xaa, 0xfb, 0x43, 0x4d, 0x33, 0x85,
  0x45, 0xf9, 0x02, 0x7f, 0x50, 0x3c, 0x9f, 0xa8,
  0x51, 0xa3, 0x40, 0x8f, 0x92, 0x9d, 0x38, 0xf5,
  0xbc, 0xb6, 0xda, 0x21, 0x10, 0xff, 0xf3, 0xd2,
  0xcd, 0x0c, 0x13, 0xec, 0x5f, 0x97, 0x44, 0x17,
  0xc4, 0xa7, 0x7e, 0x3d, 0x64, 0x5d, 0x19, 0x73,
  0x60, 0x81, 0x4f, 0xdc, 0x22, 0x2a, 0x90, 0x88,
  0x46, 0xee, 0xb8, 0x14, 0xde, 0x5e, 0x0b, 0xdb,
  0xe0, 0x32, 0x3a, 0x0a, 0x49, 0x06, 0x24, 0x5c,
  0xc2, 0xd3, 0xac, 0x62, 0x91, 0x95, 0xe4, 0x79,
  0xe7, 0xc8, 0x37, 0x6d, 0x8d, 0xd5, 0x4e, 0xa9,
  0x6c, 0x56, 0xf4, 0xea, 0x65, 0x7a, 0xae, 0x08,
  0xba, 0x78, 0x25, 0x2e, 0x1c, 0xa6, 0xb4, 0xc6,
  0xe8, 0xdd, 0x74, 0x1f, 0x4b, 0xbd, 0x8b, 0x8a,
  0x70, 0x3e, 0xb5, 0x66, 0x48, 0x03, 0xf6, 0x0e,
  0x61, 0x35, 0x57, 0xb9, 0x86, 0xc1, 0x1d, 0x9e,
  0xe1, 0xf8, 0x98, 0x11, 0x69, 0xd9, 0x8e, 0x94,
  0x9b, 0x1e, 0x87, 0xe9, 0xce, 0x55, 0x28, 0xdf,
  0x8c, 0xa1, 0x89, 0x0d, 0xbf, 0xe6, 0x42, 0x68,
  0x41, 0x99, 0x2d, 0x0f, 0xb0, 0x54, 0xbb, 0x16
};

static const uint8_t P[8] = { 2, 5, 0, 4, 6, 7, 3, 1 };

// Define data structures for key schedule and round context
typedef struct {
  uint32_t L[18];
  uint32_t R[18];
  uint32_t K[4 * (MAX_ROUNDS + 1)];
} key_schedule;

typedef struct {
  uint32_t L[2];
  uint32_t R[2];
} round_context;

// Function to perform subkey generation
static void key_schedule_generate(const uint8_t* key, key_schedule* ks) {
  uint32_t k0, k1, k2, k3;
  uint32_t t0, t1, t2, t3, t4;
  uint8_t i;

  // Load key into first four words of key schedule
  k0 = (key[0] << 24) | (key[1] << 16) | (key[2] << 8) | key[3];
  k1 = (key[4] << 24) | (key[5] << 16) | (key[6] << 8) | key[7];
  k2 = (key[8] << 24) | (key[9] << 16) | (key[10] << 8) | key[11];
  k3 = (key[12] << 24) | (key[13] << 16) | (key[14] << 8) | key[15];
  ks->K[0] = k0; ks->K[1] = k1; ks->K[2] = k2; ks->K[3] = k3;

  // Compute remaining words of key schedule
  for (i = 0; i < MAX_ROUNDS * 4; ++i) {
    if (i % 4 == 0) {
      t0 = S[(ks->K[i - 3] >> 16) & 0xff] << 24;
      t1 = S[(ks->K[i - 3] >> 8 ) & 0xff] << 16;
      t2 = S[(ks->K[i - 3]      ) & 0xff] << 8;
      t3 = S[(ks->K[i - 3] >> 24) & 0xff];
      t4 = t0 | t1 | t2 | t3;
      ks->K[i] = ks->K[i - 4] ^ t4 ^ (i / 4);
    } else {
      ks->K[i] = ks->K[i - 4] ^ ks->K[i - 1];
    }
  }

  // Compute L and R values for initial round context
  ks->L[0] = 0; ks->R[0] = 0;
  for (i = 0; i < 4; ++i) {
    ks->L[0] |= S[key[i]];
    ks->R[0] |= S[key[i + 4]];
  }
}

// Function to perform one round of encryption
static void round_encrypt(round_context* rc, const uint32_t K) {
  uint32_t t;
  t = (P[(rc->R[0] >> 24) & 0xff] * 0x1000000) |
      (P[(rc->R[0] >> 16) & 0xff] * 0x10000) |
      (P[(rc->R[0] >>  8) & 0xff] * 0x100) |
       P[(rc->R[0]       ) & 0xff];
  t = ((t << 11) | (t >> 21)) ^ rc->L[0] ^ K;

  rc->L[0] = rc->R[0];
  rc->R[0] = t;
}

// Function to perform one round of decryption
static void round_decrypt(round_context* rc, const uint32_t K) {
  uint32_t t;
  t = (P[(rc->R[0] >> 24) & 0xff] * 0x1000000) |
      (P[(rc->R[0] >> 16) & 0xff] * 0x10000) |
      (P[(rc->R[0] >>  8) & 0xff] * 0x100) |
       P[(rc->R[0]       ) & 0xff];
  t ^= rc->L[0] ^ K;
  t = ((t << 21) | (t >> 11));

  rc->L[0] = rc->R[0];
  rc->R[0] = t;
}

// Function to perform encryption or decryption of a message block
static void crypt_block(uint8_t* block, const key_schedule* ks, const int dir) {
  uint32_t* ptr = (uint32_t*)block;
  round_context rc = {
    .L = { ptr[0] },
    .R = { ptr[1] }
  };
  uint8_t i;

  for (i = 0; i < MAX_ROUNDS; ++i) {
    if (dir == 1) {
      round_encrypt(&rc, ks->K[i]);
    } else {
      round_decrypt(&rc, ks->K[MAX_ROUNDS - i]);
    }
  }

  ptr[0] = rc.R[0];
  ptr[1] = rc.L[0];
}

// Main function for encrypting or decrypting a message
static void crypt_message(uint8_t* msg, const size_t size, const key_schedule* ks, const int dir) {
  size_t i;

  for (i = 0; i < size; i += BLOCK_SIZE) {
    crypt_block(msg + i, ks, dir);
  }
}

// Sample main program
int main(int argc, char** argv) {
  // Define sample message and key
  uint8_t message[16] = { 0x00, 0x11, 0x22, 0x33,
                          0x44, 0x55, 0x66, 0x77,
                          0x88, 0x99, 0xaa, 0xbb,
                          0xcc, 0xdd, 0xee, 0xff };
  uint8_t key[16] = { 0x00, 0x01, 0x02, 0x03,
                      0x04, 0x05, 0x06, 0x07,
                      0x08, 0x09, 0x0a, 0x0b,
                      0x0c, 0x0d, 0x0e, 0x0f };
  key_schedule ks;

  // Generate key schedule and encrypt message
  key_schedule_generate(key, &ks);
  crypt_message(message, sizeof(message), &ks, 1);
  printf("Encrypted message: ");
  for (int i = 0; i < sizeof(message); i++) {
    printf("%02x", message[i]);
  }
  printf("\n");

  // Decrypt message and print result
  crypt_message(message, sizeof(message), &ks, -1);
  printf("Decrypted message: ");
  for (int i = 0; i < sizeof(message); i++) {
    printf("%02x", message[i]);
  }
  printf("\n");

  return 0;
}