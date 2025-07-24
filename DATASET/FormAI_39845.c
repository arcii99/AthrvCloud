//FormAI DATASET v1.0 Category: Cryptographic hash fucntionPassword management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define PASSWORD_LENGTH 256
#define HASH_LENGTH SHA256_DIGEST_LENGTH

void sha256(char *string, unsigned char hashed[]);

int main()
{
    char password[PASSWORD_LENGTH];
    unsigned char hashed[HASH_LENGTH];

    printf("Enter your password: ");
    fgets(password, PASSWORD_LENGTH, stdin);
    password[strlen(password)-1] = '\0'; // remove trailing newline

    sha256(password, hashed);

    printf("Your hashed password is: ");
    for (int i=0; i<HASH_LENGTH; i++)
        printf("%02x", hashed[i]);
    printf("\n");

    return 0;
}

void sha256(char *string, unsigned char hashed[])
{
    SHA256_CTX context;
    SHA256_Init(&context);
    SHA256_Update(&context, string, strlen(string));
    SHA256_Final(hashed, &context);
}