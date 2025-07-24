//FormAI DATASET v1.0 Category: modern Encryption ; Style: beginner-friendly
#include <stdio.h>
#include <string.h>

void encrypt(char *text, int shift) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a') + shift) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A') + shift) % 26 + 'A';
        }
    }
}

void decrypt(char *text, int shift) {
    int i;
    for (i = 0; i < strlen(text); i++) {
        if (text[i] >= 'a' && text[i] <= 'z') {
            text[i] = ((text[i] - 'a') - shift + 26) % 26 + 'a';
        } else if (text[i] >= 'A' && text[i] <= 'Z') {
            text[i] = ((text[i] - 'A') - shift + 26) % 26 + 'A';
        }
    }
}

int main() {
    char message[1000];
    int shift;
    printf("Enter message to be encrypted: ");
    scanf("%[^\n]s", message);
    printf("Enter shift: ");
    scanf("%d", &shift);
    encrypt(message, shift);
    printf("Encrypted message: %s\n", message);
    decrypt(message, shift);
    printf("Decrypted message: %s\n", message);
    return 0;
}