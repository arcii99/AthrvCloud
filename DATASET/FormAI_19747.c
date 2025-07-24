//FormAI DATASET v1.0 Category: modern Encryption ; Style: inquisitive
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

int main()
{
    char key[] = "mysecretkey";      // initialize the encryption key
    char input[] = "confidential data that needs to be encrypted"; // input data to be encrypted
    unsigned char iv[] = {0x7a, 0x95, 0xb2, 0x3f, 0x7e, 0xbc, 0x9c, 0xc1, 0x51, 0x5f, 0xce, 0x64, 0xe6, 0xa5, 0x5d, 0x94};   // initialization vector
    unsigned char encrypted_output[sizeof(input)];      // store the encrypted data
    unsigned char decrypted_output[sizeof(input)];      // store the decrypted data

    // initialize AES encryption context with 256-bit key
    AES_KEY encryption_key;
    AES_set_encrypt_key(key, 256, &encryption_key);

    // encrypt the input data
    AES_cbc_encrypt(input, encrypted_output, sizeof(input), &encryption_key, iv, AES_ENCRYPT);

    printf("Encrypted data: ");
    for (int i=0; i<sizeof(input); i++) {
        printf("%02x", encrypted_output[i]);
    }

    // initialize AES decryption context with 256-bit key
    AES_KEY decryption_key;
    AES_set_decrypt_key(key, 256, &decryption_key);

    // decrypt the encrypted data
    AES_cbc_encrypt(encrypted_output, decrypted_output, sizeof(input), &decryption_key, iv, AES_DECRYPT);

    printf("\nDecrypted data: %s", decrypted_output);

    return 0;
}