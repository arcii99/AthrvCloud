//FormAI DATASET v1.0 Category: Modern Encryption ; Style: authentic
#include <stdio.h>
#include <string.h>

#define KEY_LENGTH 5

void encrypt(char *plaintext, char *key, char *ciphertext);
void decrypt(char *ciphertext, char *key, char *plaintext);

int main()
{
    char plaintext[100] = "This is a secret message. Do not share!";
    char key[KEY_LENGTH] = "abcd";
    char ciphertext[100];

    encrypt(plaintext, key, ciphertext);
    printf("Ciphertext: %s\n", ciphertext);

    char decrypted_text[100];
    decrypt(ciphertext, key, decrypted_text);
    printf("Decrypted Text: %s\n", decrypted_text);
 
    return 0;
}

void encrypt(char *plaintext, char *key, char *ciphertext)
{
    int i, j = 0;
    int plaintext_length = strlen(plaintext);
    int key_length = strlen(key);

    for (i = 0; i < plaintext_length; i++) {
        ciphertext[i] = plaintext[i] ^ key[j];
        j++;
        if (j == key_length) {
            j = 0;
        }
    }
    ciphertext[i] = '\0';
}

void decrypt(char *ciphertext, char *key, char *plaintext)
{
    encrypt(ciphertext, key, plaintext);
}