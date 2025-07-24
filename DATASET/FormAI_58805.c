//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main() {

    char data[100];
    unsigned char hash[MD5_DIGEST_LENGTH];

    printf("Welcome to my happy hash! Please input your string: ");
    fgets(data, 100, stdin);
    data[strcspn(data, "\n")] = 0;

    MD5((unsigned char*) data, strlen(data), hash);

    printf("\nYour hash is: ");
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", hash[i]);
    }
    printf("\nSo happy to have created this unique hash function for you! Keep on hashing!\n");

    return 0;
}