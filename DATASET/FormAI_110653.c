//FormAI DATASET v1.0 Category: Cryptographic hash function ; Style: careful
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

unsigned char *hash(unsigned char *str)
{
    unsigned long hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    unsigned char *result = calloc(1, sizeof(unsigned char) * 32);

    int i;
    for (i = 0; i < 16; i++)
    {
        sprintf((char *)&result[i * 2], "%02x", (unsigned int)hash);
    }

    return result;
}

int main()
{
    unsigned char *str1 = "This is a test";
    unsigned char *str2 = "This is another test";

    unsigned char *hash1 = hash(str1);
    unsigned char *hash2 = hash(str2);

    printf("Hash of \"%s\": %s\n", str1, hash1);
    printf("Hash of \"%s\": %s\n", str2, hash2);

    free(hash1);
    free(hash2);

    return 0;
}