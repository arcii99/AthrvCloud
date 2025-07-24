//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_PASS_LENGTH 32 // Maximum password length
#define MIN_PASS_LENGTH 8 // Minimum password length

// Function to generate a random character
char random_char() {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789!@#$%^&*()_-+=[]{};:<>,.?/\\|";
    const size_t len = sizeof(charset) / sizeof(char) - 1;
    return charset[rand() % len];
}

// Function to generate a secure password
char* generate_password() {
    srand(time(NULL));
    int length = rand() % (MAX_PASS_LENGTH - MIN_PASS_LENGTH + 1) + MIN_PASS_LENGTH;
    char *password = malloc(sizeof(char) * (length + 1));
    for (int i = 0; i < length; i++) {
        password[i] = random_char();
    }
    password[length] = '\0';
    return password;
}

int main() {
    printf("Generating a secure password...\n");
    char *password = generate_password();
    printf("Your secure password is: ");
    printf("%s\n", password);
    free(password);
    return 0;
}