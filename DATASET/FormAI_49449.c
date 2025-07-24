//FormAI DATASET v1.0 Category: Password management ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_PASSWORD_LENGTH 50

// function to check if a character is a valid password character
int isValid(char c) {
    if (isalnum(c) || c == '!' || c == '@' || c == '#' || c == '$' || c == '%' || c == '^' || c == '&') {
        return 1;
    }
    return 0;
}

// function to get a valid password from the user
void getPassword(char *password) {
    int length = 0;
    char c;
    printf("Enter a password: ");
    while (length < MAX_PASSWORD_LENGTH && (c = getchar()) != '\n') {
        if (isValid(c)) {
            password[length++] = c;
        }
    }
    password[length] = '\0';
}

// function to encrypt a password
void encrypt(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        password[i] = password[i] + i + length;
    }
}

// function to decrypt a password
void decrypt(char *password) {
    int length = strlen(password);
    for (int i = 0; i < length; i++) {
        password[i] = password[i] - i - length;
    }
}

int main() {
    char password[MAX_PASSWORD_LENGTH + 1] = {'\0'};
    getPassword(password);
    encrypt(password);
    printf("Encrypted password: %s\n", password);
    decrypt(password);
    printf("Decrypted password: %s\n", password);
    return 0;
}