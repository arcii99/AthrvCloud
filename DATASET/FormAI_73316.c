//FormAI DATASET v1.0 Category: Encryption ; Style: real-life
#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define MAX_STRING_SIZE 1024

char *encrypt(char *plaintext, char *key) {
    int i, j;
    char *ciphertext = malloc(MAX_STRING_SIZE);

    for (i = 0; plaintext[i] != '\0'; i++) {
        if (isalpha(plaintext[i])) {
            for (j = 0; j < strlen(key); j++) {
                if (tolower(plaintext[i]) == tolower(key[j])) {
                    ciphertext[i] = isupper(plaintext[i]) ?
                        toupper(key[j]) : tolower(key[j]);
                    break;
                }
            }

            if (j == strlen(key)) {
                ciphertext[i] = plaintext[i];
            }

        } else {
            ciphertext[i] = plaintext[i];
        }
    }

    return ciphertext;
}

int main() {
    char plaintext[MAX_STRING_SIZE];
    char *ciphertext;
    char key[] = "helloworld";

    printf("Enter plaintext: ");
    fgets(plaintext, MAX_STRING_SIZE, stdin);
    plaintext[strcspn(plaintext, "\n")] = '\0';

    ciphertext = encrypt(plaintext, key);

    printf("Ciphertext: %s\n", ciphertext);

    free(ciphertext);
    return 0;
}