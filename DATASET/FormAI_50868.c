//FormAI DATASET v1.0 Category: modern Encryption ; Style: happy
#include <stdio.h>
#include <string.h>

#define KEY "happyencryption"

void encrypt(char *str) {
    int i, j = 0, k = strlen(KEY);
    for (i = 0; str[i] != '\0'; ++i) {
        str[i] = str[i] ^ KEY[j++];
        if (j == k) {
            j = 0;
        }
    }
}

void decrypt(char *str) {
    encrypt(str);
}

int main() {
    char message[100];
    printf("Enter your message: ");
    scanf("%[^\n]", message); // read input until newline character
    encrypt(message);
    printf("Encrypted message: %s\n", message);
    decrypt(message);
    printf("Decrypted message: %s\n", message);
    return 0;
}