//FormAI DATASET v1.0 Category: Encryption ; Style: secure
#include <stdio.h>
#include <string.h>
#include <openssl/aes.h>

//key to be used for encryption and decryption
unsigned char key[16] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF, 0x11, 0x22, 0x33, 0x44, 0x55, 0x66, 0x77, 0x88, 0x99, 0x00};

int main()
{
    //declaration of plaintext and ciphertext
    unsigned char plaintext[128] = {0};
    unsigned char ciphertext[128] = {0};
    
    int input_length;
    
    printf("Enter the text to be encrypted: ");
    fgets((char*)plaintext, 128, stdin);
    
    //removing the newline character added by fgets()
    input_length = strlen((const char*)plaintext);
    plaintext[input_length-1] = '\0';
    input_length--;
    
    //creating the context structure for encryption
    AES_KEY enc_key;
    AES_set_encrypt_key(key, 128, &enc_key);
    
    //encrypting the plaintext
    AES_encrypt(plaintext, ciphertext, &enc_key);

    printf("The encrypted text is: ");
    for(int i=0; i<input_length; i++)
    {
        printf("%02X ", ciphertext[i]);
    }
    printf("\n");
    
    //creating the context structure for decryption
    AES_KEY dec_key;
    AES_set_decrypt_key(key, 128, &dec_key);
    
    //decrypting the ciphertext
    AES_decrypt(ciphertext, plaintext, &dec_key);

    printf("The decrypted text is: %s\n", plaintext);
    
    return 0;
}