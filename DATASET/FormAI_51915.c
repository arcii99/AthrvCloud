//FormAI DATASET v1.0 Category: Modern Encryption ; Style: peaceful
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main()
{
    AES_KEY key;
    unsigned char iv[AES_BLOCK_SIZE];
    unsigned char plaintext[128] = "The quick brown fox jumps over the lazy dog";
    unsigned char ciphertext[AES_BLOCK_SIZE*2];
    unsigned char decryptedtext[128];
    
    // initialize key and iv
    unsigned char *key_data = "mysecretpassword";
    int key_data_len = strlen(key_data);
    memset(iv, 0x00, AES_BLOCK_SIZE);
    AES_set_encrypt_key(key_data, key_data_len*8, &key);
    
    // encrypt plaintext
    AES_cbc_encrypt(plaintext, ciphertext, sizeof(plaintext), &key, iv, AES_ENCRYPT);
    
    // decrypt ciphertext
    AES_set_decrypt_key(key_data, key_data_len*8, &key);
    AES_cbc_encrypt(ciphertext, decryptedtext, sizeof(ciphertext), &key, iv, AES_DECRYPT);
    
    // print results
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for(int i=0; i<AES_BLOCK_SIZE*2; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\nDecryptedtext: %s\n", decryptedtext);
    
    return 0;
}