//FormAI DATASET v1.0 Category: Encryption ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// function to encrypt the given text
void encrypt(char* text, int key) {
    int i;
    for(i = 0; i < strlen(text); i++) {
        if(text[i] >= 'a' && text[i] <= 'z') {
            // shift lowercase letters
            text[i] = (char) ((((text[i] - 'a') + key) % 26) + 'a');
        }
        else if(text[i] >= 'A' && text[i] <= 'Z') {
            // shift uppercase letters
            text[i] = (char) ((((text[i] - 'A') + key) % 26) + 'A');
        }
    }
}

int main() {
    char text[1000];
    int key;

    printf("Enter the text to be encrypted: ");
    fgets(text, sizeof(text), stdin);
    text[strcspn(text, "\n")] = '\0';  // remove the trailing newline character

    printf("Enter the encryption key (0-25): ");
    scanf("%d", &key);

    encrypt(text, key);

    printf("Encrypted Text: %s\n", text);

    return 0;
}