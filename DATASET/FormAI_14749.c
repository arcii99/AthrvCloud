//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

int main()
{
    char input[1024];  // store input string
    printf("Enter the input string: ");
    scanf("%s", input);

    unsigned char hash[MD5_DIGEST_LENGTH];  // store the computed MD5 hash value
    MD5(input, strlen(input), hash);

    printf("\nThe MD5 hash value for '%s' is:\n", input);
    for (int i = 0; i < MD5_DIGEST_LENGTH; i++)
        printf("%02x", hash[i]);
    printf("\n");

    return 0;
}