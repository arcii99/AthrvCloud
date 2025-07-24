//FormAI DATASET v1.0 Category: Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <time.h>

void encrypt(uint8_t *msg, uint16_t len, uint8_t *key){
    uint16_t i, j, k, t;
    uint8_t S[256], K[256];
    for(i=0; i<256; i++){
        S[i] = i;
        K[i] = key[i % strlen(key)];
    }
    j = 0;
    for(i=0; i<256; i++){
        j = (j + S[i] + K[i]) % 256;
        t = S[i];
        S[i] = S[j];
        S[j] = t;
    }
    i = j = 0;
    for(k=0; k<len; k++){
        i = (i + 1) % 256;
        j = (j + S[i]) % 256;
        t = S[i];
        S[i] = S[j];
        S[j] = t;
        msg[k] ^= S[(S[i] + S[j]) % 256];
    }   
}

int main(){
    uint8_t msg[] = "The quick brown fox jumps over the lazy dog.";
    uint8_t key[] = "SECRETKEY";
    uint16_t len = strlen(msg);
    encrypt(msg, len, key);
    printf("Encrypted message: %s\n", msg);
    encrypt(msg, len, key);
    printf("Decrypted message: %s\n", msg);
    return 0;
}