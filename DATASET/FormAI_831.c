//FormAI DATASET v1.0 Category: Cryptography Implementation ; Style: Cryptic
// Secret encryption program
#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define MAX_LEN 256

int main()
{
    char message[MAX_LEN], key[MAX_LEN], encrypted[MAX_LEN], decrypted[MAX_LEN];
    int i, j, message_len, key_len, key_value, rand_seed;

    printf("Enter message: ");
    fgets(message, MAX_LEN, stdin);
    message_len = strlen(message) - 1;
    
    printf("Enter key (must be at least as long as the message): ");
    fgets(key, MAX_LEN, stdin);
    key_len = strlen(key) - 1;

    // Generate key value based on seed value from current time
    rand_seed = time(NULL) % 1000;
    srand(rand_seed);
    key_value = rand() % 256;

    // Encrypt message using key
    for (i = 0, j = 0; i < message_len; ++i, ++j)
    {
        if (j == key_len) j = 0;
        encrypted[i] = message[i] ^ key[j] ^ key_value;
    }
    encrypted[i] = '\0';

    printf("Encrypted message: ");
    for (i = 0; i < message_len; ++i)
        printf("%02X", encrypted[i]);
    printf("\n");

    // Decrypt message using key and key value
    for (i = 0, j = 0; i < message_len; ++i, ++j)
    {
        if (j == key_len) j = 0;
        decrypted[i] = encrypted[i] ^ key[j] ^ key_value;
    }
    decrypted[i] = '\0';

    printf("Decrypted message: ");
    printf("%s\n", decrypted);

    return 0;
}