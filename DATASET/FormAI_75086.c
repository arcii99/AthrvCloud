//FormAI DATASET v1.0 Category: modern Encryption ; Style: content
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

int main()
{
    unsigned char key[] = {"mysecretkey1234"};
    unsigned char iv[] = {"initializationv"};
    unsigned char plaintext[] = {"supersecretmessage1234"};
    unsigned char ciphertext[128];
    unsigned char decrypttext[128];
    int encrypted_length = 0, decrypted_length = 0;

    AES_KEY encrypt_key, decrypt_key;
    AES_set_encrypt_key(key, 128, &encrypt_key);
    AES_set_decrypt_key(key, 128, &decrypt_key);

    AES_cbc_encrypt(plaintext, ciphertext, strlen(plaintext), &encrypt_key, iv, AES_ENCRYPT);
    encrypted_length = strlen((char *)ciphertext);

    AES_cbc_encrypt(ciphertext, decrypttext, encrypted_length, &decrypt_key, iv, AES_DECRYPT);
    decrypted_length = strlen((char *)decrypttext);

    printf("Original message: %s\n", plaintext);
    printf("Encrypted message: ");
    for (int i = 0; i < encrypted_length; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\nDecrypted message: %s\n", decrypttext);

    return 0;
}