//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

// Function to calculate SHA-256 hash of a given message
void SHA256_hash(char* message, char* output)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, message, strlen(message));
    SHA256_Final(hash, &sha256);
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        sprintf(output + (i * 2), "%02x", hash[i]);
    }
    output[64] = '\0';
}

int main()
{
    char message[1000];
    char output[65];
    printf("Enter a message to hash: ");
    fgets(message, 1000, stdin);
    message[strcspn(message, "\n")] = 0;
    SHA256_hash(message, output);
    printf("The SHA-256 hash of the given message is: %s", output);
    return 0;
}