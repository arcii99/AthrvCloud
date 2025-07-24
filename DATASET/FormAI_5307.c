//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/md5.h>

void generate_random_key(unsigned char *key, int key_length)
{
    time_t t;
    srand((unsigned) time(&t));
    int i;
    for (i=0; i<key_length; i++)
    {
        key[i] = rand() % 256;
    }
}

void encrypt_data(unsigned char *data, int data_length, unsigned char *key, int key_length)
{
    int i;
    for (i=0; i<data_length; i++)
    {
        data[i] = data[i] ^ key[i%key_length];
    }
}

void decrypt_data(unsigned char *data, int data_length, unsigned char *key, int key_length)
{
    encrypt_data(data, data_length, key, key_length);
}

void hash_data(unsigned char *data, int data_length, unsigned char *hash)
{
    MD5(data, data_length, hash);
}

int main()
{
    unsigned char key[16];
    generate_random_key(key, 16);
    printf("Generated Key: ");
    int i;
    for (i=0; i<16; i++)
    {
        printf("%02x", key[i]);
    }
    printf("\n");

    unsigned char data[] = "Hello World";
    int data_length = strlen(data);
    printf("Original Data: %s\n", data);

    encrypt_data(data, data_length, key, 16);
    printf("Encrypted Data: ");
    for (i=0; i<data_length; i++)
    {
        printf("%02x", data[i]);
    }
    printf("\n");

    decrypt_data(data, data_length, key, 16);
    printf("Decrypted Data: %s\n", data);

    unsigned char hash[MD5_DIGEST_LENGTH];
    hash_data(data, data_length, hash);
    printf("Hash of Data: ");
    for (i=0; i<MD5_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }
    printf("\n");

    return 0;
}