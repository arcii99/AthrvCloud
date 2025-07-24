//FormAI DATASET v1.0 Category: Secure Password Generator ; Style: configurable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a secure password
char* generate_password(int len) {
    const char charset[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789@#%&";
    char* password = malloc((len + 1) * sizeof(char));
    srand(time(NULL));
    for (int i = 0; i < len; i++) {
        password[i] = charset[rand() % (sizeof(charset) - 1)];
    }
    password[len] = '\0';
    return password;
}

int main() {
    int password_length;
    printf("Welcome to the Secure Password Generator\n");
    printf("Please enter the length of the password you want to generate: ");
    scanf("%d", &password_length);
    printf("Your secure password is: %s\n", generate_password(password_length));
    return 0;
}