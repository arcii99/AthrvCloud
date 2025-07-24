//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_PASSWORD_LENGTH 20
#define MIN_PASSWORD_LENGTH 8

char* generate_password(int length) {
    char* password = malloc((length + 1) * sizeof(char));
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=[]{},.<>?\\|`~";

    srand((unsigned int) time(NULL));
    for (int i = 0; i < length; i++) {
        int random_index = rand() % (int) (sizeof(charset) - 1);
        password[i] = charset[random_index];
    }
    password[length] = '\0';

    return password;
}

int main() {
    int password_length;
    char* password = NULL;

    printf("Welcome to the Secure Password Generator\n\n");

    while (password == NULL) {
        printf("Enter the desired length of your password (%d-%d): ", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        scanf("%d", &password_length);

        if (password_length < MIN_PASSWORD_LENGTH || password_length > MAX_PASSWORD_LENGTH) {
            printf("Invalid password length. Please enter a number between %d and %d.\n", MIN_PASSWORD_LENGTH, MAX_PASSWORD_LENGTH);
        } else {
            password = generate_password(password_length);
        }
    }

    printf("\nYour secure password is:\n%s\n", password);
    free(password);

    return 0;
}