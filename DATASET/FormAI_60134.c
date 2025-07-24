//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main() {
    printf("Thank you for choosing this cryptographic hash function program!\n");

    char message[100];
    printf("Please enter the message you'd like to hash: ");
    scanf("%s", message);

    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256(message, strlen(message), hash);

    printf("The hash of your message is: ");

    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }

    printf("\n");

    printf("We hope this program provided you with the security and peace of mind you were looking for.\n");
    printf("Thank you for your time, and have a great day!\n");
    return 0;
}