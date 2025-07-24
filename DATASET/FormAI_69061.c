//FormAI DATASET v1.0 Category: Encryption ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int main()
{
    char plaintext[100], key[100], ciphertext[100];
    int i;

    printf("Enter plaintext: ");
    fgets(plaintext, 100, stdin);

    printf("Enter key: ");
    fgets(key, 100, stdin);

    // Removing newline characters from inputs
    plaintext[strcspn(plaintext, "\n")] = 0;
    key[strcspn(key, "\n")] = 0;

    int n = strlen(plaintext);
    srand(time(NULL));
    // Generating random initialization vector
    char iv[16];
    for(i = 0; i < 16; i++)
    {
        iv[i] = rand() % 128;
    }

    // Performing CBC encryption
    char block[16];
    for(i = 0; i < n; i+=16)
    {
        for(int j = 0; j < 16; j++)
        {
            if(i+j >= n)
            {
                block[j] = iv[j];
            }
            else
            {
                block[j] = plaintext[i+j];
            }
            block[j] ^= iv[j];
            block[j] ^= key[j];
            iv[j] = block[j];
        }
        memcpy(ciphertext+i, block, 16);
    }

    printf("Ciphertext: ");
    for(i = 0; i < n; i++)
    {
        printf("%02x", (int) ciphertext[i]);
    }
    printf("\n");

    return 0;
}