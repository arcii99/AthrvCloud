//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: rigorous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate a secure password */
char* generatePassword(int length) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_+-=";
    char* password = malloc(sizeof(char) * (length + 1));
    srand(time(NULL));
    for (int i = 0; i < length; i++) {
        int index = rand() % (sizeof(charset) - 1);
        password[i] = charset[index];
    }
    password[length] = '\0';
    return password;
}

/* Main function */
int main() {
    int length;
    printf("Enter the length of the password: ");
    scanf("%d", &length);

    if (length < 8) {
        printf("Password length should be greater than or equal to 8\n");
        return 0;
    }

    char* password = generatePassword(length);
    printf("Your secure password is: %s\n", password);
    free(password);

    return 0;
}