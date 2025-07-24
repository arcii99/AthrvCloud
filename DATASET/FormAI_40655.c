//FormAI DATASET v1.0 Category: modern Encryption ; Style: surprised
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define DELTA 0x9E3779B9
#define ROUNDS 32

void xtea_encrypt(unsigned int *v, unsigned int *k) {
    unsigned int v0=v[0], v1=v[1], sum=0, i;           
    unsigned int delta=DELTA;
    for (i=0; i < ROUNDS; i++) {
        v0 += (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + k[sum & 3]);
        sum += delta;
        v1 += (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + k[(sum>>11) & 3]);
    }
    v[0]=v0; v[1]=v1;
}

void xtea_decrypt(unsigned int *v, unsigned int *k) {
    unsigned int v0=v[0], v1=v[1], sum=ROUNDS*DELTA, i;
    unsigned int delta=DELTA;
    for (i=0; i<ROUNDS; i++) {
        v1 -= (((v0 << 4) ^ (v0 >> 5)) + v0) ^ (sum + k[(sum>>11) & 3]);
        sum -= delta;
        v0 -= (((v1 << 4) ^ (v1 >> 5)) + v1) ^ (sum + k[sum & 3]);
    }
    v[0]=v0; v[1]=v1;
}

int main() {
    unsigned int key[4] = {0xA56BABCD, 0x984365FE, 0x7812E9AC, 0x07ADF023};
    char input[100];
    printf("Please enter a message to encrypt: ");
    fgets(input, 100, stdin);
    input[strcspn(input, "\n")] = 0;
    int len = strlen(input);
    if (len % 8 != 0) {
        int padding = 8 - len % 8;
        for (int i = 0; i < padding; i++) {
            input[len+i] = '0';
        }
        input[len+padding] = '\0';
        len += padding;
    }
    unsigned int block[2];
    int num_blocks = len / 8;
    for (int i = 0; i < num_blocks; i++) {
        block[0] = *((unsigned int*)&input[i*8]);
        block[1] = *((unsigned int*)&input[i*8+4]);
        xtea_encrypt(block, key);
        *((unsigned int*)&input[i*8]) = block[0];
        *((unsigned int*)&input[i*8+4]) = block[1];
    }
    printf("Encrypted message: %s\n", input);
    for (int i = 0; i < num_blocks; i++) {
        block[0] = *((unsigned int*)&input[i*8]);
        block[1] = *((unsigned int*)&input[i*8+4]);
        xtea_decrypt(block, key);
        *((unsigned int*)&input[i*8]) = block[0];
        *((unsigned int*)&input[i*8+4]) = block[1];
    }
    printf("Decrypted message: %s\n", input);
    return 0;
}