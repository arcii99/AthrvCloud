//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: content
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>

// Implementation of the BearCrypt Hash function

// Our hash is 256 bits (32 bytes) long
#define HASH_SIZE 32

// We have 10 rounds in our hash function
#define ROUNDS 10

// Some random prime numbers
#define PRIME1 4987
#define PRIME2 9833

// Rotate x left by n bits
#define ROTL(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

// Our hash context structure
struct bearctx {
  uint32_t hash[HASH_SIZE / sizeof(uint32_t)]; // The hash value
  uint64_t nbytes; // Total number of bytes hashed so far
  uint32_t buffer[16]; // The buffer for storing the message block
  int buflen; // Number of bytes stored in the buffer
};

// Initial hash value (just some random numbers)
static const uint32_t bear_init_hash[HASH_SIZE / sizeof(uint32_t)] = {
  0x3f92e3f4, 0x5a3f8db8, 0x2c8ec74b, 0x3928d5d0,
  0x7bb6188b, 0x43a41ab4, 0x20d66429, 0x2bd3317f,
  0xb5788b11, 0x5bc1589c, 0x6fe71bbd, 0x43a7cdba,
  0x63da8648, 0xd6590833, 0x26c8e7bc, 0x702ca02c,
};

// Our round function
static uint32_t bear_round(uint32_t x, uint32_t y, uint32_t z, int r) {
  if (r <= 5) {
    return (x ^ (y | ~z)) + 0x5a827999;
  } else if (r <= 9) {
    return (x & y) | (~x & z);
  } else {
    return (x << 10) | (x >> 22);
  }
}

// Process a message block
static void bear_process_block(struct bearctx *ctx) {
  uint32_t a = ctx->hash[0];
  uint32_t b = ctx->hash[1];
  uint32_t c = ctx->hash[2];
  uint32_t d = ctx->hash[3];
  uint32_t e = ctx->hash[4];
  uint32_t f = ctx->hash[5];
  uint32_t g = ctx->hash[6];
  uint32_t h = ctx->hash[7];
  uint32_t t;

  // Perform 10 rounds of mixing
  for (int r = 0; r < ROUNDS; r++) {
    t = bear_round(a, b, c, r) + ctx->buffer[r % 16] + (h * PRIME1);
    h = g;
    g = f;
    f = e;
    e = d + t;
    d = c;
    c = b;
    b = a;
    a = t + ((b & c) | ((~b) & d)) + ((a << 5) | (a >> 27)) + e;
  }

  // Update the hash value
  ctx->hash[0] += a;
  ctx->hash[1] += b;
  ctx->hash[2] += c;
  ctx->hash[3] += d;
  ctx->hash[4] += e;
  ctx->hash[5] += f;
  ctx->hash[6] += g;
  ctx->hash[7] += h;
}

// Initialize the hash context
void bear_init(struct bearctx *ctx) {
  memcpy(ctx->hash, bear_init_hash, sizeof(bear_init_hash));
  ctx->nbytes = 0;
  ctx->buflen = 0;
}

// Update the hash context with some data
void bear_update(struct bearctx *ctx, const void *data, size_t len) {
  const uint8_t *p = data;
  while (len-- > 0) {
    // Add the byte to the buffer
    ctx->buffer[ctx->buflen++] = *p++;
    ctx->nbytes++;

    // If the buffer is full, process it
    if (ctx->buflen == 16) {
      bear_process_block(ctx);
      ctx->buflen = 0;
    }
  }
}

// Finalize the hash and obtain the result
void bear_final(struct bearctx *ctx, void *result) {
  // Pad the message with a 1-bit and some zero bits
  uint8_t pad[64] = {0x80};
  size_t padlen = 64 - ((ctx->nbytes + 8) % 64);
  if (padlen < 8) padlen += 64;
  bear_update(ctx, pad, padlen - 8);

  // Add the message length in bits as a 64-bit big-endian integer
  for (int i = 0; i < 8; i++)
    pad[i] = (ctx->nbytes >> ((7 - i) * 8)) & 0xFF;
  bear_update(ctx, pad, 8);
  
  // Copy the result to the output buffer
  memcpy(result, ctx->hash, HASH_SIZE);
}

// Example usage
int main() {
  const char *msg = "Lorem ipsum dolor sit amet, consectetur adipiscing elit.";
  uint8_t hash[HASH_SIZE];
  struct bearctx ctx;

  bear_init(&ctx);
  bear_update(&ctx, msg, strlen(msg));
  bear_final(&ctx, hash);

  printf("Hash: ");
  for (int i = 0; i < HASH_SIZE; i++)
    printf("%02x", hash[i]);
  printf("\n");

  return 0;
}