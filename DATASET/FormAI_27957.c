//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/sha.h>

#define MAX_LEN 1000 // Maximum length of input string

// Function to generate cryptographic hash
char *sherlock_hash(char *input_str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    char *output_str = (char*)malloc(2*SHA256_DIGEST_LENGTH + 1);
    int i;

    // Compute hash using SHA256
    SHA256(input_str, strlen(input_str), hash);

    // Convert hash to hexadecimal string
    for(i = 0; i < SHA256_DIGEST_LENGTH; i++)
        sprintf(output_str + 2*i, "%02x", hash[i]);

    output_str[2*SHA256_DIGEST_LENGTH] = '\0';

    return output_str;
}

// Driver function to test the hash function
int main()
{
    char input_str[MAX_LEN];
    char *output_str;

    printf("Enter the string to be hashed: ");
    fgets(input_str, MAX_LEN, stdin);
    input_str[strcspn(input_str, "\n")] = '\0'; // Remove trailing newline character

    output_str = sherlock_hash(input_str);
    printf("Hash of input string '%s' : %s", input_str, output_str);

    free(output_str);
    return 0;
}