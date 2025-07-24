//FormAI DATASET v1.0 Category: Modern Encryption ; Style: complete
#include <stdio.h>
#include <openssl/aes.h>

int main()
{
    // Initialize key and message
    unsigned char key[16] = "mysecretpassword";
    unsigned char plaintext[] = "Hello, this is a secret message!";

    // Initialize AES encryption context
    AES_KEY aes_key;
    AES_set_encrypt_key(key, 128, &aes_key);

    // Perform encryption
    unsigned char ciphertext[sizeof(plaintext)];
    AES_encrypt(plaintext, ciphertext, &aes_key);

    // Print result
    printf("Plaintext: %s\n", plaintext);
    printf("Ciphertext: ");
    for (int i = 0; i < sizeof(ciphertext); i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\n");

    return 0;
}