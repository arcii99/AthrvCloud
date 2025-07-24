//FormAI DATASET v1.0 Category: Email Client ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>

void encrypt(char* message, int key) {
    for(int i = 0; message[i] != '\0'; ++i) {
        char ch = message[i];
        if(ch >= 'a' && ch <= 'z') {
            message[i] = (ch + key - 97) % 26 + 97;
        } else if(ch >= 'A' && ch <= 'Z') {
            message[i] = (ch + key - 65) % 26 + 65;
        }
    }
}

void decrypt(char* message, int key) {
    encrypt(message, 26 - key);
}

int main() {
    char email[500];
    char recipient[50];
    char subject[100];
    char body[350];
    int key;

    printf("Enter recipient's email address: ");
    scanf("%s", recipient);

    printf("Enter subject line: ");
    scanf(" %[^\n]s", subject);

    printf("Enter body of email: ");
    scanf(" %[^\n]s", body);

    printf("Enter encryption key (0-25): ");
    scanf("%d", &key);

    sprintf(email, "To: %s\nSubject: %s\n\n%s\n", recipient, subject, body);

    encrypt(email, key);
    printf("Encrypted message:\n%s\n", email);

    decrypt(email, key);
    printf("Decrypted message:\n%s\n", email);

    return 0;
}