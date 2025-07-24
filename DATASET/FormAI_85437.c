//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: creative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <openssl/md5.h>

#define MAX_LENGTH 1024

void md5(char* str) {
    unsigned char digest[MD5_DIGEST_LENGTH];
    MD5((unsigned char *) str, strlen(str), digest);

    printf("MD5 Hash Value: ");
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++) {
        printf("%02x", digest[i]);
    }
    printf("\n");
}

int main(void) {
    char str[MAX_LENGTH];
    printf("Enter a string: ");
    fgets(str, MAX_LENGTH, stdin);

    printf("String entered: %s\n", str);

    md5(str);

    return 0;
}