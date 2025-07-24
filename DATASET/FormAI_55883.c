//FormAI DATASET v1.0 Category: Encryption ; Style: scalable
#include <stdio.h>
#include <stdlib.h>

void encrypt(char *str, int key)
{
    int k = key % 26;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' + k) % 26) + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' + k) % 26) + 'A';
        }
    }
}

void decrypt(char *str, int key)
{
    int k = key % 26;
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z') {
            str[i] = ((str[i] - 'a' - k + 26) % 26) + 'a';
        }
        else if (str[i] >= 'A' && str[i] <= 'Z') {
            str[i] = ((str[i] - 'A' - k + 26) % 26) + 'A';
        }
    }
}

int main()
{
    char str[100];
    printf("Enter a string to encrypt: ");
    fgets(str, sizeof(str), stdin);

    int key;
    printf("Enter a key for encryption: ");
    scanf("%d", &key);

    printf("Original string: %s", str);
    encrypt(str, key);
    printf("Encrypted string: %s", str);
    decrypt(str, key);
    printf("Decrypted string: %s", str);

    return 0;
}