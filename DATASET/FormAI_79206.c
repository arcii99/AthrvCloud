//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: brave
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdint.h>

#define ROTL(x, y) ((x << y) | (x >> (32 - y))) /* Rotate left */
#define ROTR(x, y) ((x >> y) | (x << (32 - y))) /* Rotate right */

#define FINALIZATION_MIXING_CONSTANT 0x7b253b0b /* Finalization mixing constant */
#define INITIAL_STATE 0x5f7a9d0e /* Initial state value */

/* Perform one round of mixing */
#define MIX(a, b, c) \
  a -= c; \
  a ^= ROTL(c, 4); \
  c += b; \
  b -= a; \
  b ^= ROTR(a, 6); \
  a += c; \
  c -= b; \
  c ^= ROTL(b, 8); \
  b += a; \
  a -= c; \
  a ^= ROTR(c, 16); \
  c += b; \
  b -= a; \
  b ^= ROTL(a, 19); \
  a += c; \
  c -= b; \
  c ^= ROTR(b, 4); \
  b += a;

/* Pad the message before hash calculation */
void pad(char *message, size_t message_size, uint32_t *padded_data, size_t *padded_size) {
  size_t i;
  uint32_t zero_padding = 0x00000000;

  /* Calculate the number of blocks */
  size_t blocks = ((message_size + 4) / 4) + 2;

  /* Calculate the padded size */
  *padded_size = blocks * 4;

  /* Copy the message into the padded data buffer */
  memcpy(padded_data, message, message_size);

  /* Add the padding */
  memcpy((void*)((uintptr_t)padded_data + message_size), &zero_padding, 4);
  memcpy((void*)((uintptr_t)padded_data + *padded_size - 4), &message_size, 4);
}

/* Calculate the hash of a message */
void hash(const char *message, size_t message_size, char *hash_result) {
  uint32_t padded_data[8192];
  size_t padded_size;
  uint32_t state[4];
  int i, j;

  /* Pad the message */
  pad((char*)message, message_size, padded_data, &padded_size);

  /* Initialize the state vector */
  state[0] = INITIAL_STATE;
  state[1] = INITIAL_STATE;
  state[2] = INITIAL_STATE;
  state[3] = INITIAL_STATE;

  /* Mix the padded data */
  for (i = 0; i < padded_size; i += 16) {
    uint32_t a = state[0], b = state[1], c = state[2], d = state[3];

    /* Mix the data into the state vector */
    for (j = 0; j < 4; j++) {
      a ^= padded_data[i + j];
      MIX(a, b, c);
      d ^= padded_data[i + j];
    }

    /* Mix the state vector */
    MIX(a, b, c);
    MIX(c, d, a);
    MIX(a, b, c);
    MIX(c, d, a);

    /* Update the state vector */
    state[0] = a;
    state[1] = b;
    state[2] = c;
    state[3] = d;
  }

  /* Finalize the hash */
  state[2] ^= FINALIZATION_MIXING_CONSTANT;
  MIX(state[0], state[1], state[2]);
  MIX(state[2], state[3], state[0]);
  MIX(state[0], state[1], state[2]);
  MIX(state[2], state[3], state[0]);
  memcpy(hash_result, state, 16);
}

int main(void) {
  char message[1024];
  char hash_result[16];
  size_t message_size;

  printf("Enter the message to hash: ");
  fgets(message, sizeof(message), stdin);

  message_size = strlen(message) - 1; /* Remove newline character */
  
  /* Calculate the hash of the message */
  hash(message, message_size, hash_result);

  /* Print the hash result in hexadecimal format */
  printf("Hash result: ");
  for (int i = 0; i < 16; i++) {
      printf("%02x", (unsigned char)hash_result[i]);
  }
  printf("\n");

  return 0;
}