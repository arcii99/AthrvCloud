//FormAI DATASET v1.0 Category: modern Encryption ; Style: innovative
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main()
{
    char input_string[100], secret_key[100], encrypted_string[100], decrypted_string[100];
    int i, j, key_length, input_length, option;

    printf("Enter the input string: ");
    fgets(input_string, 100, stdin);
    input_length = strlen(input_string);
    input_string[input_length - 1] = '\0';

    printf("Enter the secret key: ");
    fgets(secret_key, 100, stdin);
    key_length = strlen(secret_key);
    secret_key[key_length - 1] = '\0';

    // Encryption
    for(i = 0, j = 0; i < input_length; i++, j++)
    {
        if(j == key_length)
        {
            j = 0;
        }
        encrypted_string[i] = input_string[i] + secret_key[j];
    }
    encrypted_string[i] = '\0';

    printf("\nEncrypted Message: ");
    printf("%s", encrypted_string);

    // Decryption
    for(i = 0, j = 0; i < input_length; i++, j++)
    {
        if(j == key_length)
        {
            j = 0;
        }
        decrypted_string[i] = encrypted_string[i] - secret_key[j];
    }
    decrypted_string[i] = '\0';

    printf("\nDecrypted Message: ");
    printf("%s", decrypted_string);

    return 0;
}