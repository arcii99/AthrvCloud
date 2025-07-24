//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: cheerful
#include<stdio.h>
#include<string.h>
#include<openssl/sha.h> // Add OpenSSL library for SHA-256

int main() {
    printf("Hello there! Let's create a cryptographic hash function using SHA-256!\n");

    // Take user input string to hash
    char input[1000];
    printf("Enter the string you want to hash: ");
    scanf("%s",input);

    // Create the SHA-256 hash
    unsigned char hashed[SHA256_DIGEST_LENGTH];
    SHA256(input, strlen(input), hashed);

    printf("The SHA-256 hash for your input string is: ");

    // Print out the hash in hexadecimal format
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x",hashed[i]);
    }
    printf("\n");

    printf("Isn't that neat?! Let's try another string!\n");
    char input2[1000];
    printf("Enter a new string to hash: ");
    scanf("%s",input2);

    // Create the SHA-256 hash for the second input
    unsigned char hashed2[SHA256_DIGEST_LENGTH];
    SHA256(input2, strlen(input2), hashed2);

    printf("The SHA-256 hash for your new input string is: ");

    // Print out the hash in hexadecimal format
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x",hashed2[i]);
    }
    printf("\n");

    printf("Amazing! We've just created a unique cryptographic hash function using SHA-256! See you next time!\n");

    return 0;
}