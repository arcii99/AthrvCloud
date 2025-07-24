//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

char* generate_password(int length) {
    char* password = (char*) malloc(sizeof(char) * (length + 1));

    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
    const int charset_size = sizeof(charset) / sizeof(char) - 1;

    srand(time(NULL));

    for (int i = 0; i < length; i++) {
        password[i] = charset[rand() % charset_size];
    }

    password[length] = '\0';

    return password;
}

int main() {
    printf("Welcome! Let's create a secure password!\n\n");

    int length;
    printf("How long should the password be? (minimum 8 characters): ");
    scanf("%d", &length);

    while (length < 8) {
        printf("Password length should be at least 8 characters. Please try again: ");
        scanf("%d", &length);
    }

    char* password = generate_password(length);

    printf("\nYour password is: %s\n\n", password);
    printf("Protect it well!");

    free(password);

    return 0;
}