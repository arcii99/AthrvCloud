//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: thoughtful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/evp.h>

int main(void)
{
    //The message we want to encrypt
    unsigned char message[] = "My secret message";
    
    //The key used to encrypt the message
    unsigned char key[] = "mysecretpassword";
    
    //The initialization vector used for CBC mode
    unsigned char iv[] = "initialvector";
    
    //The buffer to hold the encrypted message
    unsigned char encrypted_message[sizeof(message)];
    memset(encrypted_message, 0, sizeof(encrypted_message));
    
    //The buffer to hold the decrypted message
    unsigned char decrypted_message[sizeof(message)];
    memset(decrypted_message, 0, sizeof(decrypted_message));
    
    //Variables to hold the length of the encrypted and decrypted messages
    int encrypted_message_length = 0, decrypted_message_length = 0;
    
    //The context structure used for encryption and decryption
    EVP_CIPHER_CTX *ctx = NULL;
    
    //Initialization of OpenSSL and creating the context structure
    OpenSSL_add_all_algorithms();
    if(!(ctx = EVP_CIPHER_CTX_new()))
        return 1;
    
    //Setting the encryption key and the initialization vector
    if(1 != EVP_EncryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return 1;

    //Encrypting the message and storing the result in encrypted_message
    if(1 != EVP_EncryptUpdate(ctx, encrypted_message, &encrypted_message_length, message, sizeof(message)))
        return 1;
        
    //Completing the encryption and storing the result in encrypted_message
    if(1 != EVP_EncryptFinal_ex(ctx, encrypted_message + encrypted_message_length, &encrypted_message_length))
        return 1;
    
    //Setting the decryption key and the initialization vector
    if(1 != EVP_DecryptInit_ex(ctx, EVP_aes_256_cbc(), NULL, key, iv))
        return 1;
    
    //Decrypting the message and storing the result in decrypted_message
    if(1 != EVP_DecryptUpdate(ctx, decrypted_message, &decrypted_message_length, encrypted_message, encrypted_message_length))
        return 1;
    
    //Completing the decryption and storing the result in decrypted_message
    if(1 != EVP_DecryptFinal_ex(ctx, decrypted_message + decrypted_message_length, &decrypted_message_length))
        return 1;

    //Printing the original message, the encrypted message and the decrypted message
    printf("Original message: %s\n", message);
    printf("Encrypted message: %s\n", encrypted_message);
    printf("Decrypted message: %s\n", decrypted_message);

    //Cleaning up
    EVP_CIPHER_CTX_free(ctx);
    return 0;
}