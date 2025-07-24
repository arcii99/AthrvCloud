//FormAI DATASET v1.0 Category: Cryptographic hash fucntionPassword management ; Style: statistical
#include <stdio.h>
#include <string.h>
#include <stdint.h>

// Define constants used for hashing
#define ROTL(x,n) ((x << n) | (x >> (32 - n))) // Left rotate
#define ROTR(x,n) ((x >> n) | (x << (32 - n))) // Right rotate
#define BSWAP(x) (((x) << 24) & 0xff000000u) | (((x) << 8) & 0x00ff0000u) | (((x) >> 8) & 0x0000ff00u) | (((x) >> 24) & 0x000000ffu) // Byte swap
#define CH(x,y,z) ((x & y) ^ (~x & z)) // Choice
#define MAJ(x,y,z) ((x & y) ^ (x & z) ^ (y & z)) // Majority
#define SIG0(x) (ROTR(x,2) ^ ROTR(x,13) ^ ROTR(x,22)) // Sigma-0
#define SIG1(x) (ROTR(x,6) ^ ROTR(x,11) ^ ROTR(x,25)) // Sigma-1
#define EN0(x) (BSWAP(x)) // Endianness conversion for little-endian input
#define EN1(x) (x) // Endianness conversion for big-endian input

// Calculate hash value for a given message
void sha256(const uint8_t *msg, uint32_t len, uint32_t *hash) {
    // Define constants for hash computation
    const uint32_t k[64] = { 
        0x428a2f98u, 0x71374491u, 0xb5c0fbcfu, 0xe9b5dba5u, 0x3956c25bu, 0x59f111f1u, 0x923f82a4u, 0xab1c5ed5u, 
        0xd807aa98u, 0x12835b01u, 0x243185beu, 0x550c7dc3u, 0x72be5d74u, 0x80deb1feu, 0x9bdc06a7u, 0xc19bf174u, 
        0xe49b69c1u, 0xefbe4786u, 0x0fc19dc6u, 0x240ca1ccu, 0x2de92c6fu, 0x4a7484aau, 0x5cb0a9dcu, 0x76f988dau, 
        0x983e5152u, 0xa831c66du, 0xb00327c8u, 0xbf597fc7u, 0xc6e00bf3u, 0xd5a79147u, 0x06ca6351u, 0x14292967u, 
        0x27b70a85u, 0x2e1b2138u, 0x4d2c6dfcu, 0x53380d13u, 0x650a7354u, 0x766a0abbu, 0x81c2c92eu, 0x92722c85u, 
        0xa2bfe8a1u, 0xa81a664bu, 0xc24b8b70u, 0xc76c51a3u, 0xd192e819u, 0xd6990624u, 0xf40e3585u, 0x106aa070u, 
        0x19a4c116u, 0x1e376c08u, 0x2748774cu, 0x34b0bcb5u, 0x391c0cb3u, 0x4ed8aa4au, 0x5b9cca4fu, 0x682e6ff3u, 
        0x748f82eeu, 0x78a5636fu, 0x84c87814u, 0x8cc70208u, 0x90befffau, 0xa4506cebu, 0xbef9a3f7u, 0xc67178f2u
    };
    
    // Define variables for hash computation
    uint32_t w[64], a, b, c, d, e, f, g, h, t1, t2;
    
    // Define initial hash values
    uint32_t H[8] = { 
        0x6a09e667u, 0xbb67ae85u, 0x3c6ef372u, 0xa54ff53au,
        0x510e527fu, 0x9b05688cu, 0x1f83d9abu, 0x5be0cd19u
    };
    
    // Define message schedule
    for (int i = 0; i < 16; i++) {
        w[i] = EN0(((const uint32_t *)msg)[i]);
    }
    for (int i = 16; i < 64; i++) {
        w[i] = SIG1(w[i - 2]) + w[i - 7] + SIG0(w[i - 15]) + w[i - 16];
    }
    
    // Perform hash computation
    for (int i = 0; i < 64; i++) {
        a = H[0]; b = H[1]; c = H[2]; d = H[3]; 
        e = H[4]; f = H[5]; g = H[6]; h = H[7]; 
        
        t1 = h + SIG1(e) + CH(e,f,g) + k[i] + w[i];
        t2 = SIG0(a) + MAJ(a,b,c);
        
        h = g; g = f; f = e; e = d + t1;
        d = c; c = b; b = a; a = t1 + t2;
        
        H[0] = a; H[1] = b; H[2] = c; H[3] = d; 
        H[4] = e; H[5] = f; H[6] = g; H[7] = h;
    }
    
    // Update hash value
    for (int i = 0; i < 8; i++) {
        hash[i] = H[i] + hash[i];
    }
}

int main() {
    // Example usage
    uint8_t msg[] = "password123";
    uint32_t hash[8] = {0};
    sha256(msg, strlen((const char *)msg), hash);
    
    printf("Password hash: ");
    for (int i = 0; i < 8; i++) {
        printf("%08x", hash[i]);
    }
    printf("\n");
    
    return 0;
}