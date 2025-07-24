//FormAI DATASET v1.0 Category: Cryptographic hash fucntion ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

int main()
{
    char input_string[100];
    unsigned char output_buffer[SHA256_DIGEST_LENGTH];
    int i;

    printf("Enter the string to be hashed: ");
    scanf("%s", input_string);

    SHA256(input_string, strlen(input_string), output_buffer);

    printf("Hashed String: ");
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        printf("%02x", output_buffer[i]);
    }
    printf("\n");

    return 0;
}