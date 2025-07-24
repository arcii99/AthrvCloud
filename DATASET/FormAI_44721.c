//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <openssl/sha.h>

// Generate a random salt value
void generateSalt(char* salt) {
    srand(time(NULL));
    for(int i=0; i<16; i++) {
        int randomChar = rand() % 62;
        if(randomChar < 26) salt[i] = 'a' + randomChar;
        else if(randomChar < 52) salt[i] = 'A' + (randomChar - 26);
        else salt[i] = '0' + (randomChar - 52);
    }
    salt[16] = '\0';
}

// Hash a provided password with a given salt using SHA-256
void hashPassword(char* password, char* salt, char* hashedPassword) {
    char passwordWithSalt[50];
    strcpy(passwordWithSalt, password);
    strcat(passwordWithSalt, salt);
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(passwordWithSalt, strlen(passwordWithSalt), hash);
    for(int i=0; i<SHA256_DIGEST_LENGTH; i++) {
        sprintf(hashedPassword + (i * 2), "%02x", hash[i]);
    }
    hashedPassword[64] = '\0';
}

int main() {
    char password[25];
    char salt[17];
    char hashedPassword[65];
    printf("Enter your password:\n");
    scanf("%s", password);
    generateSalt(salt);
    printf("Your salt value is: %s\n", salt);
    hashPassword(password, salt, hashedPassword);
    printf("Your hashed password is: %s\n", hashedPassword);
    return 0;
}