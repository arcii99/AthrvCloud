//FormAI DATASET v1.0 Category: Encryption ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void encrypt(char *input, char *output, int key)
{
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] + key % 26;
        if (output[i] > 'z') {
            output[i] -= 26;
        } else if (output[i] < 'a') {
            output[i] += 26;
        }
    }
}

void decrypt(char *input, char *output, int key)
{
    int len = strlen(input);
    for (int i = 0; i < len; i++) {
        output[i] = input[i] - key % 26;
        if (output[i] > 'z') {
            output[i] -= 26;
        } else if (output[i] < 'a') {
            output[i] += 26;
        }
    }
}

int main()
{
    char message[100], encrypted[100], decrypted[100];
    int key;

    printf("Enter message to encrypt: ");
    fgets(message, 100, stdin);

    printf("Enter key (1-25): ");
    scanf("%d", &key);

    encrypt(message, encrypted, key);
    printf("Encrypted message: %s", encrypted);

    decrypt(encrypted, decrypted, key);
    printf("Decrypted message: %s", decrypted);

    return 0;
}