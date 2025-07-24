//FormAI DATASET v1.0 Category: Checksum Calculator ; Style: paranoid
#include <stdio.h>
#include <stdint.h>

#define BLOCK_SIZE 64
#define ROTATE_LEFT(x, n) (((x) << (n)) | ((x) >> (32 - (n))))

uint32_t checksum(uint8_t *data, size_t len) {
    uint32_t a = 0x67452301;
    uint32_t b = 0xefcdab89;
    uint32_t c = 0x98badcfe;
    uint32_t d = 0x10325476;
    
    uint8_t block[BLOCK_SIZE];
    
    for (size_t i = 0; i < len; i += BLOCK_SIZE) {
        // pad block with zeros
        for (size_t j = 0; j < BLOCK_SIZE; j++) {
            block[j] = (i + j < len) ? data[i + j] : 0;
        }
        
        // calculate checksum for this block
        uint32_t aa = a, bb = b, cc = c, dd = d;
        
        // round 1
        for (uint8_t j = 0; j < 16; j++) {
            uint32_t f = (bb & cc) | ((~bb) & dd);
            uint8_t g = j;
            uint32_t tmp = aa + f + ((uint32_t*)block)[g] + 0x5a827999;
            aa = dd;
            dd = cc;
            cc = bb;
            bb = bb + ROTATE_LEFT(tmp, 5);
        }
        
        // round 2
        for (uint8_t j = 16; j < 32; j++) {
            uint32_t f = (bb & dd) | (cc & (~dd));
            uint8_t g = (5 * j + 1) % 16;
            uint32_t tmp = aa + f + ((uint32_t*)block)[g] + 0x6ed9eba1;
            aa = dd;
            dd = cc;
            cc = bb;
            bb = bb + ROTATE_LEFT(tmp, 5);
        }
        
        // round 3
        for (uint8_t j = 32; j < 48; j++) {
            uint32_t f = bb ^ cc ^ dd;
            uint8_t g = (3 * j + 5) % 16;
            uint32_t tmp = aa + f + ((uint32_t*)block)[g] + 0x8f1bbcdc;
            aa = dd;
            dd = cc;
            cc = bb;
            bb = bb + ROTATE_LEFT(tmp, 5);
        }
        
        // round 4
        for (uint8_t j = 48; j < 64; j++) {
            uint32_t f = cc ^ (bb | (~dd));
            uint8_t g = (7 * j) % 16;
            uint32_t tmp = aa + f + ((uint32_t*)block)[g] + 0xca62c1d6;
            aa = dd;
            dd = cc;
            cc = bb;
            bb = bb + ROTATE_LEFT(tmp, 5);
        }
        
        // add result of this block to total checksum
        a += aa;
        b += bb;
        c += cc;
        d += dd;
    }
    
    // concatenate and return final checksum
    uint32_t result[4] = {a, b, c, d};
    return *((uint32_t*)result);
}

int main(void) {
    uint8_t data[] = "This is a message to be checksummed.";
    size_t len = sizeof(data) - 1; // subtract 1 to exclude null terminator
    
    uint32_t crc = checksum(data, len);
    
    printf("Checksum of \"%s\" is: %08x", data, crc);
    
    return 0;
}