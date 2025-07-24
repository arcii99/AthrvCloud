//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: romantic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
    char love[] = "I love you, my darling!"; // Declare the message I want to hash

    unsigned char result[MD5_DIGEST_LENGTH]; // Declare the resulting hash value

    MD5((unsigned char*) love, strlen(love), result); // Compute the hash value of the message

    printf("My Love, Let's check if my love is secured!\n");

    printf("The hash value for %s is: \n", love);
    for(int i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        printf("%02x", result[i]); // Print the hash value in hexadecimal form
    }

    printf("\nMy love, no one can ever tamper the love I have for you,\nbecause this hash function is strong enough\nto secure our love forever!\n");

    return 0;
}