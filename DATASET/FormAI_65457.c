//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h> // OpenSSL library for MD5 hash function 

void md5_hash(unsigned char *str, unsigned char *output) {
    MD5(str, strlen(str), output); //call to MD5 hash function from OpenSSL
}

int main() {
    unsigned char string[] = "This is a test string"; //input string
    unsigned char hash[MD5_DIGEST_LENGTH]; //variable to store hash output
    md5_hash(string, hash); //call to our custom MD5 hash function

    printf("Input string: %s\n", string); //print input string
    printf("Hash output: "); 
    for(int i=0;i<MD5_DIGEST_LENGTH;i++)
        printf("%02x",hash[i]); //print hash output in hexadecimal format

    return 0;
}