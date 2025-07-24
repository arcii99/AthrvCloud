//FormAI DATASET v1.0 Category: Encryption ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Function to perform encryption
void encrypt(char *phrase, char *key) {

    int i, j;
    int phraseLen = strlen(phrase);
    int keyLen = strlen(key);
    char *encryptedPhrase = malloc((phraseLen + 1) * sizeof(char));

    // Encrypt each character one by one
    for (i = 0, j = 0; i < phraseLen; i++, j++) {
        if (j == keyLen) {
            j = 0;
        }

        int c = (phrase[i] + key[j]) % 26;

        // Convert to ASCII value
        c += 'A';

        encryptedPhrase[i] = (char)c;
    }

    encryptedPhrase[i] = '\0';

    printf("Encrypted phrase is: %s\n", encryptedPhrase);

    free(encryptedPhrase);
}

int main() {
    char *phrase = "HELLO";
    char *key = "KEY";

    encrypt(phrase, key);

    return 0;
}