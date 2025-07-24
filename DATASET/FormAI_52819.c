//FormAI DATASET v1.0 Category: modern Encryption ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>
#include <pthread.h>

// Function to generate a random key of specified length
void generate_random_key(unsigned char* key, int length) {
    RAND_bytes(key, length);
}

// Function to encrypt the plaintext using AES-256-CBC algorithm
void* encrypt_data(void* arg) {
    // Context structure to hold encryption parameters
    EVP_CIPHER_CTX* context = EVP_CIPHER_CTX_new();
    
    // Key and IV Initialization Vector)
    unsigned char key[EVP_MAX_KEY_LENGTH];
    unsigned char iv[EVP_MAX_IV_LENGTH];
    
    // Generate random key and IV
    generate_random_key(key, EVP_MAX_KEY_LENGTH);
    generate_random_key(iv, EVP_MAX_IV_LENGTH);
    
    // Initialize encryption parameters
    EVP_EncryptInit_ex(context, EVP_aes_256_cbc(), NULL, key, iv);
    
    // Plaintext and ciphertext buffers
    unsigned char* plaintext = (unsigned char*) arg;
    int plaintext_len = strlen(plaintext) + 1;
    int ciphertext_len = plaintext_len + EVP_MAX_BLOCK_LENGTH;
    unsigned char* ciphertext = malloc(ciphertext_len);
    int len;
    
    // Encrypt the plaintext data
    EVP_EncryptUpdate(context, ciphertext, &len, plaintext, plaintext_len);
    
    // Finalize the encryption process
    int final_len;
    EVP_EncryptFinal_ex(context, ciphertext + len, &final_len);
    len += final_len;
    
    // Print the encrypted data and key
    printf("Encrypted Data: ");
    for(int i = 0; i < len; i++) {
        printf("%02x ", ciphertext[i]);
    }
    printf("\nEncrypted Key: ");
    for(int i = 0; i < EVP_MAX_KEY_LENGTH; i++) {
        printf("%02x ", key[i]);
    }
    printf("\n");
    
    // Clean up the context
    EVP_CIPHER_CTX_free(context);
    
    pthread_exit(NULL);
}

int main() {
    // Plaintext data to be encrypted
    char* plaintext = "This is a top-secret message!";
    
    // Create threads for encrypting the data asynchronously
    pthread_t thread1, thread2, thread3, thread4;
    pthread_create(&thread1, NULL, encrypt_data, (void*) plaintext);
    pthread_create(&thread2, NULL, encrypt_data, (void*) plaintext);
    pthread_create(&thread3, NULL, encrypt_data, (void*) plaintext);
    pthread_create(&thread4, NULL, encrypt_data, (void*) plaintext);
    
    // Wait for the threads to complete
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);
    pthread_join(thread3, NULL);
    pthread_join(thread4, NULL);
    
    return 0;
}