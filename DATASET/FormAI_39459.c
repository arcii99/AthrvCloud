//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BLOCK_SIZE 8
#define KEY_SIZE 8

void encrypt(unsigned char *pt, unsigned char *ct, unsigned char *key) {
    unsigned char r1, r2, r3;
    unsigned char k[257];
    unsigned char s[257];
    int i, j, t, x, y, m;
    
    for (i = 0; i < 256; i++) {
        s[i] = i;
        k[i] = key[i % KEY_SIZE];
    }
    
    j = 0;
    for (i = 0; i < 256; i++) {
        j = (j + s[i] + k[i]) % 256;
        r1 = s[i];
        s[i] = s[j];
        s[j] = r1;
    }
    
    x = 0;
    y = 0;
    for (i = 0; i < BLOCK_SIZE; i++) {
        x = (x + 1) % 256;
        y = (y + s[x]) % 256;
        r1 = s[x];
        s[x] = s[y];
        s[y] = r1;
        t = (s[x] + s[y]) % 256;
        ct[i] = pt[i] ^ s[t];
    }
}

void decrypt(unsigned char *ct, unsigned char *pt, unsigned char *key) {
    encrypt(ct, pt, key);
}

int main() {
    unsigned char pt[50] = "Hello World!";
    unsigned char key[KEY_SIZE] = {0x12, 0x34, 0x56, 0x78, 0x90, 0xAB, 0xCD, 0xEF};
    unsigned char ct[BLOCK_SIZE];
    unsigned char decrypt_text[BLOCK_SIZE];
    
    memset(decrypt_text, 0, BLOCK_SIZE);

    encrypt(pt, ct, key);
    printf("Encrypted Text: ");
    for (int i = 0; i < BLOCK_SIZE; i++) {
        printf("%02x ", ct[i]);
    }
    printf("\n");

    decrypt(ct, decrypt_text, key);
    printf("Decrypted Text: %s", decrypt_text);
    
    return 0;
}