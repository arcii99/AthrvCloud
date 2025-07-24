//FormAI DATASET v1.0 Category: Cryptographic hash fucntionPassword management ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    char password[32];
    printf("Enter your password: ");
    scanf("%s", password);

    unsigned char hashed_password[SHA256_DIGEST_LENGTH];
    SHA256(password, strlen(password), hashed_password);

    printf("\nYour hashed password is: ");
    for (int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hashed_password[i]);
    }
    printf("\n");

    return 0;
}