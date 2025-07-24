//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <pthread.h>

#define SALT_SIZE 16
#define HASH_ALGORITHM EVP_sha384()

void* hash(void *data);

int main() {
    char input[100];
    printf("Enter a message to hash: ");
    fgets(input, 100, stdin);
    printf("Hashing...\n");
    pthread_t tid;
    pthread_create(&tid, NULL, hash, input);
    pthread_join(tid, NULL);
    return 0;
}

void* hash(void *data) {
    char* msg = (char*) data;
    unsigned char salt[SALT_SIZE];
    RAND_bytes(salt, SALT_SIZE);
    int crypted_len, salt_len = SALT_SIZE;
    unsigned char *crypted_salted_msg;
    EVP_MD_CTX *ctx;
    ctx = EVP_MD_CTX_new();
    const EVP_MD *md = HASH_ALGORITHM;
    EVP_DigestInit_ex(ctx, md, NULL);
    EVP_DigestUpdate(ctx, salt, salt_len);
    EVP_DigestUpdate(ctx, (unsigned char*) msg, strlen(msg));
    crypted_salted_msg = (unsigned char*) malloc(EVP_MD_size(md)+salt_len);
    EVP_DigestFinal_ex(ctx, crypted_salted_msg+salt_len, &crypted_len);
    memcpy(crypted_salted_msg, salt, salt_len);
    printf("Crypted Message with salt : ");
    for(int i=0; i<SALT_SIZE; i++)
        printf("%02x", salt[i]);
    for(int i=0; i<crypted_len; i++)
        printf("%02x", crypted_salted_msg[i+salt_len]);
    printf("\n");
    return NULL;
}