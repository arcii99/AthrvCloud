//FormAI DATASET v1.0 Category: String manipulation ; Style: Claude Shannon
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *str, int key)
{
    int len = strlen(str);
    for(int i = 0; i < len; i++)
    {
        str[i] ^= key;    // bitwise XOR operation for each character in the string
    }
}

int main()
{
    char str[] = "This is a secret message";
    int key = 0x55;    // random 8-bit key

    printf("Original message: %s\n", str);

    encrypt(str, key);

    printf("Encrypted message: %s\n", str);

    encrypt(str, key);    // decryption using the same key

    printf("Decrypted message: %s\n", str);

    return 0;
}