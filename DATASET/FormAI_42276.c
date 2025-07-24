//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/evp.h>
#include <openssl/rand.h>

// Function to generate a random salt
void generate_salt(unsigned char *salt, int size) {
    if (!RAND_bytes(salt, size)) {
        perror("Error generating salt");
        exit(EXIT_FAILURE);
    }
}

// Function to create a hash
void create_hash(char *password, unsigned char *salt, unsigned char *hash) {
    EVP_MD_CTX *ctx;
    const EVP_MD *md;

    // Initialize context and select SHA256 message digest algorithm
    ctx = EVP_MD_CTX_new();
    md = EVP_sha256();

    // Initialize context with SHA256 algorithm
    EVP_DigestInit_ex(ctx, md, NULL);

    // Update context with password and salt
    EVP_DigestUpdate(ctx, password, strlen(password));
    EVP_DigestUpdate(ctx, salt, strlen(salt));

    // Finalize context and get hash value
    EVP_DigestFinal_ex(ctx, hash, NULL);

    // Free context memory
    EVP_MD_CTX_free(ctx);
}

// Function to print hash as hexadecimal string
void print_hash(unsigned char *hash) {
    for (int i = 0; i < EVP_MAX_MD_SIZE; i++) {
        printf("%02x", hash[i]);
    }
    printf("\n");
}

// Asynchronous function to create a hash
void create_hash_async(char *password, unsigned char *salt, unsigned char *hash) {
    printf("Hashing password asynchronously...\n");
    create_hash(password, salt, hash);
    printf("Hash created asynchronously: ");
    print_hash(hash);
}

int main() {
    char password[64];
    unsigned char salt[EVP_MAX_MD_SIZE];
    unsigned char hash[EVP_MAX_MD_SIZE];

    // Get password from user
    printf("Enter a password to hash: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0';

    // Generate a random salt
    generate_salt(salt, EVP_MAX_MD_SIZE);

    // Create hash synchronously
    printf("Hashing password synchronously...\n");
    create_hash(password, salt, hash);
    printf("Hash created synchronously: ");
    print_hash(hash);

    // Create hash asynchronously
    create_hash_async(password, salt, hash);

    return 0;
}