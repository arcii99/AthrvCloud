//FormAI DATASET v1.0 Category: Encryption ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ENC_SHIFT 3

void encrypt(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c -= 'a';
            c = (c + ENC_SHIFT) % 26;
            c += 'a';
            str[i] = c;
        }
        else if (c >= 'A' && c <= 'Z') {
            c -= 'A';
            c = (c + ENC_SHIFT) % 26;
            c += 'A';
            str[i] = c;
        }
    }
}

void decrypt(char *str)
{
    int len = strlen(str);

    for (int i = 0; i < len; i++) {
        char c = str[i];
        if (c >= 'a' && c <= 'z') {
            c -= 'a';
            c = (c - ENC_SHIFT + 26) % 26;
            c += 'a';
            str[i] = c;
        }
        else if (c >= 'A' && c <= 'Z') {
            c -= 'A';
            c = (c - ENC_SHIFT + 26) % 26;
            c += 'A';
            str[i] = c;
        }
    }
}

int main()
{
    char str[100];

    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);
    str[strcspn(str, "\n")] = '\0';

    encrypt(str);
    printf("Encrypted string: %s\n", str);

    decrypt(str);
    printf("Decrypted string: %s\n", str);

    return 0;
}