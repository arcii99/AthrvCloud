//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
/* This program implements a simple cryptographic hash function in C.
 * Its hash function uses the MD5 algorithm, which produces a 128-bit hash value.
 *
 * Created by: [Your Name]
 * Date: [Date]
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/md5.h>

void hash_string(unsigned char hash[], char input_string[])
{
    MD5_CTX context;
    MD5_Init(&context);
    MD5_Update(&context, input_string, strlen(input_string));
    MD5_Final(hash, &context);
}

void print_hash(unsigned char hash[])
{
    int i;
    for (i = 0; i < MD5_DIGEST_LENGTH; i++)
    {
        printf("%02x", hash[i]);
    }
}

int main()
{
    char input_string[1000];
    unsigned char hash[MD5_DIGEST_LENGTH];

    // Get input string from user
    printf("Enter a string to hash: ");
    fgets(input_string, sizeof(input_string), stdin);
    input_string[strcspn(input_string, "\n")] = 0;

    // Hash the input string
    hash_string(hash, input_string);

    // Print the hash
    printf("\nHash value of input string: ");
    print_hash(hash);
    printf("\n");

    return 0;
}