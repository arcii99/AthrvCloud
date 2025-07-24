//FormAI DATASET v1.0 Category: Modern Encryption ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <openssl/aes.h>

void encrypt(char *input, int input_len, char *key, char *output)
{
    AES_KEY aes_key;
    unsigned char iv[AES_BLOCK_SIZE];
    char *padding = NULL;
    int padding_len = 0;
    int output_len = 0;

    memset(iv, 0x00, AES_BLOCK_SIZE);

    if(input_len % 16 != 0)
    {
        padding_len = 16 - (input_len % 16);
        padding = calloc(padding_len, sizeof(char));
        input = realloc(input, input_len + padding_len);
        strcat(input, padding);
        input_len = input_len + padding_len;
        free(padding);
    }

    AES_set_encrypt_key(key, 128, &aes_key);
    AES_cbc_encrypt(input, output, input_len, &aes_key, iv, AES_ENCRYPT);

    output_len = strlen(output);
    printf("Encryption complete. Output: %s, Length: %d\n", output, output_len);
}

int main()
{
    char input[] = "This is a secret message.";
    char key[] = "mysecretkey";
    char *output = calloc(strlen(input), sizeof(char));

    encrypt(input, strlen(input), key, output);

    free(output);
    return 0;
}