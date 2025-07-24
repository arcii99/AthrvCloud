//FormAI DATASET v1.0 Category: modern Encryption ; Style: funny
// Hey there, being a chatbot, I've decided to add some fun to your day encryption!
#include <stdio.h>
#include <string.h>

void encrypt(char *input_text, char *encrypted_text);
void decrypt(char *encrypted_text, char *decrypted_text);

int main() {
    char input_text[100];
    char encrypted_text[100];
    char decrypted_text[100];
    
    printf("Hey there, let's play a little game of encryption!\n");
    printf("Tell me something to encrypt: ");
    fgets(input_text, sizeof(input_text), stdin);

    // Time to encrypt!
    encrypt(input_text, encrypted_text);
    printf("\nHere is your encrypted text: %s", encrypted_text);

    // Let's decrypt! 
    decrypt(encrypted_text, decrypted_text);
    printf("Your decrypted text is: %s", decrypted_text);

    return 0;
}

void encrypt(char *input_text, char *encrypted_text) {
    printf("Let's encrypt your message...\n");
    int i;
    for(i = 0; i < strlen(input_text); i++) {
        if(input_text[i] == ' ') {
            encrypted_text[i] = ' ';
        } else {
            encrypted_text[i] = input_text[i] + 3;
        }
    }
    encrypted_text[i] = '\0';
}

void decrypt(char *encrypted_text, char *decrypted_text) {
    printf("Let's decrypt the message to see what you wrote...\n");
    int i;
    for(i = 0; i < strlen(encrypted_text); i++) {
        if(encrypted_text[i] == ' ') {
            decrypted_text[i] = ' ';
        } else {
            decrypted_text[i] = encrypted_text[i] - 3;
        }
    }
    decrypted_text[i] = '\0';
}