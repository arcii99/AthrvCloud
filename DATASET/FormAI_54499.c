//FormAI DATASET v1.0 Category: Modern Encryption ; Style: decentralized
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define KEY_LENGTH 16
#define BLOCK_SIZE 16

void generateKey(unsigned char *key){
    int i;
    for(i=0; i<KEY_LENGTH; i++){
        key[i] = rand()%256;
    }
}

unsigned char *encrypt(unsigned char *plaintext, unsigned char *key, int len){
    unsigned char *ciphertext = (unsigned char *)malloc(sizeof(unsigned char)*len);
    int i,j,k;
    unsigned char state[BLOCK_SIZE];
    memset(state, 0, BLOCK_SIZE);
    for(i=0; i<len; i+=BLOCK_SIZE){
        for(j=0; j<BLOCK_SIZE; j++){    
            state[j] = plaintext[i+j] ^ state[j];
        }
        for(j=0; j<5; j++){
            for(k=0; k<BLOCK_SIZE; k++){
                state[k] = state[(k+3)%BLOCK_SIZE] ^ state[(k+8)%BLOCK_SIZE] ^ key[(j*BLOCK_SIZE)+k];
            }
        }
        for(j=0; j<BLOCK_SIZE; j++){    
            ciphertext[i+j] = state[j];
        }
    }
    return ciphertext;
}

unsigned char *decrypt(unsigned char *ciphertext, unsigned char *key, int len){
    unsigned char *plaintext = (unsigned char *)malloc(sizeof(unsigned char)*len);
    int i,j,k;
    unsigned char state[BLOCK_SIZE];
    memset(state, 0, BLOCK_SIZE);
    for(i=0; i<len; i+=BLOCK_SIZE){
        for(j=0; j<BLOCK_SIZE; j++){    
            state[j] = ciphertext[i+j];
        }
        for(j=4; j>=0; j--){
            for(k=BLOCK_SIZE-1; k>=0; k--){
                state[k] = state[(k+BLOCK_SIZE-3)%BLOCK_SIZE] ^ state[(k+BLOCK_SIZE-8)%BLOCK_SIZE] ^ key[(j*BLOCK_SIZE)+k];
            }
        }
        for(j=0; j<BLOCK_SIZE; j++){    
            plaintext[i+j] = state[j] ^ ciphertext[i+j-BLOCK_SIZE];
        }
    }
    return plaintext;
}

int main(){
    unsigned char key[KEY_LENGTH];
    generateKey(key);
    
    char plaintext[1024];
    printf("Enter plaintext: ");
    fgets(plaintext, 1024, stdin);
    int len = strlen(plaintext);
    if(plaintext[len-1] == '\n'){
        plaintext[len-1] = 0;
        len--;
    }
    len = (len/BLOCK_SIZE)+1;
    len *= BLOCK_SIZE;
    
    unsigned char *ciphertext = encrypt((unsigned char *)plaintext, key, len);
    printf("Encrypted text: ");
    int i;
    for(i=0; i<len; i++){
        printf("%02x", ciphertext[i]);
    }
    printf("\n");
    
    unsigned char *decryptedtext = decrypt(ciphertext, key, len);
    printf("Decrypted text: %s\n", decryptedtext);
    return 0;
}