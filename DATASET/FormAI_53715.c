//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: relaxed
#include <stdio.h>
#include <string.h>
#include <stdint.h>

typedef uint8_t byte;

byte rotl(byte x, byte n) {
    return (x << n) | (x >> (8 - n));
}

byte rotr(byte x, byte n) {
    return (x >> n) | (x << (8 - n));
}

byte mix(byte a, byte b, byte c, byte d) {
    return rotl(a, 1) ^ rotr(b, 2) ^ rotl(c, 3) ^ rotr(d, 4);
}

byte final_mix(byte a, byte b, byte c, byte d) {
    return rotl(a, 5) ^ rotr(b, 4) ^ rotl(c, 3) ^ rotr(d, 2);
}

void hash(const char* input, byte* output) {
    const size_t len = strlen(input);
    byte a = 0x9b, b = 0x3f, c = 0x1a, d = 0x94;
    for (size_t i = 0; i < len; i++) {
        a ^= (byte)input[i];
        b ^= mix((byte)input[i], a, b, c);
        c ^= mix((byte)input[i], b, c, d);
        d ^= mix((byte)input[i], c, d, a);
    }
    a ^= final_mix(a, b, c, d);
    b ^= final_mix(b, c, d, a);
    c ^= final_mix(c, d, a, b);
    d ^= final_mix(d, a, b, c);
    for (size_t i = 0; i < 4; i++) {
        output[i] = (a >> (i * 8)) & 0xff;
        output[i + 4] = (b >> (i * 8)) & 0xff;
        output[i + 8] = (c >> (i * 8)) & 0xff;
        output[i + 12] = (d >> (i * 8)) & 0xff;
    }
}

int main() {
    const char* input = "Hello, world!";
    byte output[16];
    hash(input, output);
    printf("Input: %s\nOutput: ", input);
    for (int i = 0; i < 16; i++) {
        printf("%02x", output[i]);
    }
    printf("\n");
    return 0;
}