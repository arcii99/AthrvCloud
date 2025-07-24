//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: random
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) (((x) << (y)) | ((x) >> (32 - (y))))
#define ROTR(x, y) (((x) >> (y)) | ((x) << (32 - (y))))
#define CH(x, y, z) (((x) & (y)) ^ (~(x) & (z)))
#define MAJ(x, y, z) (((x) & (y)) ^ ((x) & (z)) ^ ((y) & (z)))
#define EP0(x) (ROTR(x, 2) ^ ROTR(x, 13) ^ ROTR(x, 22))
#define EP1(x) (ROTR(x, 6) ^ ROTR(x, 11) ^ ROTR(x, 25))
#define SIG0(x) (ROTR(x, 7) ^ ROTR(x, 18) ^ ((x) >> 3))
#define SIG1(x) (ROTR(x, 17) ^ ROTR(x, 19) ^ ((x) >> 10))

static const uint32_t k[] = {
    0x428a2f98,
    0x71374491,
    0xb5c0fbcf,
    0xe9b5dba5,
    0x3956c25b,
    0x59f111f1,
    0x923f82a4,
    0xab1c5ed5,
    0xd807aa98,
    0x12835b01,
    0x243185be,
    0x550c7dc3,
    0x72be5d74,
    0x80deb1fe,
    0x9bdc06a7,
    0xc19bf174,
    0xe49b69c1,
    0xefbe4786,
    0x0fc19dc6,
    0x240ca1cc,
    0x2de92c6f,
    0x4a7484aa,
    0x5cb0a9dc,
    0x76f988da,
    0x983e5152,
    0xa831c66d,
    0xb00327c8,
    0xbf597fc7,
    0xc6e00bf3,
    0xd5a79147,
    0x06ca6351,
    0x14292967,
    0x27b70a85,
    0x2e1b2138,
    0x4d2c6dfc,
    0x53380d13,
    0x650a7354,
    0x766a0abb,
    0x81c2c92e,
    0x92722c85,
    0xa2bfe8a1,
    0xa81a664b,
    0xc24b8b70,
    0xc76c51a3,
    0xd192e819,
    0xd6990624,
    0xf40e3585,
    0x106aa070,
    0x19a4c116,
    0x1e376c08,
    0x2748774c,
    0x34b0bcb5,
    0x391c0cb3,
    0x4ed8aa4a,
    0x5b9cca4f,
    0x682e6ff3,
    0x748f82ee,
    0x78a5636f,
    0x84c87814,
    0x8cc70208,
    0x90befffa,
    0xa4506ceb,
    0xbef9a3f7,
    0xc67178f2
};

void sha256(const char *msg, size_t len, uint8_t *hash) {
  uint32_t h[8] = {
      0x6a09e667,
      0xbb67ae85,
      0x3c6ef372,
      0xa54ff53a,
      0x510e527f,
      0x9b05688c,
      0x1f83d9ab,
      0x5be0cd19
  };

  size_t new_len = ((((len + 8) / 64) + 1) * 64) - 8;
  uint8_t *msg_hash = calloc(new_len + 64, 1);
  memcpy(msg_hash, msg, len);
  msg_hash[len] = 0x80;
  uint32_t bit_len = len * 8;
  memcpy(msg_hash + new_len, &bit_len, sizeof(bit_len));

  for (size_t offset = 0; offset < new_len + len;) {
    uint32_t w[64];
    for (int i = 0; i < 16; i++) {
      w[i] = ((uint32_t) msg_hash[offset + i * 4 + 0] << 24) |
             ((uint32_t) msg_hash[offset + i * 4 + 1] << 16) |
             ((uint32_t) msg_hash[offset + i * 4 + 2] << 8) |
             ((uint32_t) msg_hash[offset + i * 4 + 3] << 0);
    }

    for (int i = 16; i < 64; i++) {
      uint32_t s0 = SIG0(w[i - 15]);
      uint32_t s1 = SIG1(w[i - 2]);
      w[i] = w[i - 16] + s0 + w[i - 7] + s1;
    }

    uint32_t a = h[0];
    uint32_t b = h[1];
    uint32_t c = h[2];
    uint32_t d = h[3];
    uint32_t e = h[4];
    uint32_t f = h[5];
    uint32_t g = h[6];
    uint32_t j = h[7];

    for (int i = 0; i < 64; i++) {
      uint32_t S1 = ROTR(e, 6) ^ ROTR(e, 11) ^ ROTR(e, 25);
      uint32_t ch = (e & f) ^ (~e & g);
      uint32_t temp1 = j + S1 + ch + k[i] + w[i];
      uint32_t S0 = ROTR(a, 2) ^ ROTR(a, 13) ^ ROTR(a, 22);
      uint32_t maj = (a & b) ^ (a & c) ^ (b & c);
      uint32_t temp2 = S0 + maj;

      j = g;
      g = f;
      f = e;
      e = d + temp1;
      d = c;
      c = b;
      b = a;
      a = temp1 + temp2;
    }

    h[0] += a;
    h[1] += b;
    h[2] += c;
    h[3] += d;
    h[4] += e;
    h[5] += f;
    h[6] += g;
    h[7] += j;

    offset += 64;
  }

  for (int i = 0; i < 8; i++) {
    hash[i * 4 + 0] = (h[i] >> 24) & 0xff;
    hash[i * 4 + 1] = (h[i] >> 16) & 0xff;
    hash[i * 4 + 2] = (h[i] >> 8) & 0xff;
    hash[i * 4 + 3] = (h[i] >> 0) & 0xff;
  }

  free(msg_hash);
}

int main() {
  char *msg = "The quick brown fox jumps over the lazy dog";
  uint8_t hash[32];
  sha256(msg, strlen(msg), hash);

  printf("Hash: 0x");
  for (int i = 0; i < 32; i++) {
    printf("%.2x", hash[i]);
  }
  printf("\n");
  
  return 0;
}