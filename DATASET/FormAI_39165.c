//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generatePassword(int len) {
    char password[len+1];
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{}\\|;':\",./<>?";
    srand(time(NULL));

    for (int i = 0; i < len; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }

    password[len] = '\0';

    printf("Your secure password is: %s\n", password);
}

int main() {
    int password_length;

    printf("Welcome to Retro Password Generator!\n");
    printf("Create a secure password by entering the desired length (must be between 8-30 characters):\n");

    do {
        scanf("%d", &password_length);

        if (password_length < 8 || password_length > 30) {
            printf("Invalid password length. Please enter a number between 8-30:\n");
        }

    } while (password_length < 8 || password_length > 30);

    generatePassword(password_length);

    return 0;
}