//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <stdint.h>
#include <string.h>

//Rotate Left Operation
#define ROTL(x, y) ((x << y) | (x >> (32 - y)))

//Ch Operation
#define CH(x, y, z) ((x & y) ^ (~x & z))

//Maj Operation
#define MAJ(x, y, z) ((x & y) ^ (x & z) ^ (y & z))

//Sigma 0 Operation
#define SIGMA0(x) (ROTL(x, 2) ^ ROTL(x, 13) ^ ROTL(x, 22))

//Sigma 1 Operation
#define SIGMA1(x) (ROTL(x, 6) ^ ROTL(x, 11) ^ ROTL(x, 25))

//sigma 2 Operation
#define sigma0(x) (ROTL(x, 7) ^ ROTL(x, 18) ^ (x >> 3))

//sigma 3 Operation
#define sigma1(x) (ROTL(x, 17) ^ ROTL(x, 19) ^ (x >> 10))

//Initial Hash Values
uint32_t H[8] = {
    0x6a09e667,
    0xbb67ae85,
    0x3c6ef372,
    0xa54ff53a,
    0x510e527f,
    0x9b05688c,
    0x1f83d9ab,
    0x5be0cd19
};

//Constants
uint32_t K[64] = {
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

//SHA256 Function
void sha256(uint8_t *message, uint32_t message_len, uint32_t *digest) {
    uint32_t W[64];
    uint32_t a, b, c, d, e, f, g, h;
    uint32_t T1, T2;

    //Hash Computation Variables
    a = H[0];
    b = H[1];
    c = H[2];
    d = H[3];
    e = H[4];
    f = H[5];
    g = H[6];
    h = H[7];

    uint32_t num_blocks = ((message_len + 8) / 64) + 1;
    uint32_t msg_block[num_blocks*16];
    memset(msg_block, 0, num_blocks*16*sizeof(uint32_t));
    memcpy(msg_block, message, message_len);

    //Padding
    msg_block[message_len/4] |= 0x80 << (24 - (message_len % 4)*8);
    msg_block[num_blocks*16 - 1] = message_len*8;

    //Process Message in 512-bit blocks
    for (uint32_t i = 0; i < num_blocks; ++i) {
      for (uint32_t t = 0; t < 16; ++t) {
	  W[t] = msg_block[i*16 + t];
      }
      for (uint32_t t = 16; t < 64; ++t) {
          W[t] = sigma1(W[t - 2]) + W[t - 7] + sigma0(W[t - 15]) + W[t - 16];
      }
      for (uint32_t t = 0; t < 64; ++t) {
	  T1 = h + SIGMA1(e) + CH(e, f, g) + K[t] + W[t];
	  T2 = SIGMA0(a) + MAJ(a, b, c);
	  h = g;
	  g = f;
	  f = e;
	  e = d + T1;
	  d = c;
	  c = b;
	  b = a;
	  a = T1 + T2;
      }
      //Update Hash Values
      H[0] += a;
      H[1] += b;
      H[2] += c;
      H[3] += d;
      H[4] += e;
      H[5] += f;
      H[6] += g;
      H[7] += h;
    }
    //Output Message Digest
    for (uint32_t i = 0; i < 8; ++i) {
        digest[i] = H[i];
    }
}

int main() {
    uint8_t message[] = "Hello, this is a test message";
    uint32_t digest[8];
    sha256(message, strlen(message), digest);

    //Print Message Digest
    for (uint32_t i = 0; i < 8; ++i) {
        printf("%08x ", digest[i]);
    }
    printf("\n");

    return 0;
}