//FormAI DATASET v1.0 Category: User Input Sanitizer ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LENGTH 20
#define MAX_PASSWORD_LENGTH 25
#define MAX_EMAIL_LENGTH 40

int is_valid_email(const char *email) {
    const char *at_symbol = strchr(email, '@');
    const char *dot = strrchr(email, '.');
    return at_symbol != NULL && dot != NULL && dot > at_symbol;
}

void sanitize_input(char *input) {
    char *cursor = input;
    while (*cursor != '\0') {
        if (*cursor == '<' || *cursor == '>') {
            *cursor = '_';
        }
        cursor++;
    }
}

int main() {
    char username[MAX_USERNAME_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
    char email[MAX_EMAIL_LENGTH];

    printf("Enter a username (max %d characters): ", MAX_USERNAME_LENGTH);
    fgets(username, MAX_USERNAME_LENGTH, stdin);
    username[strcspn(username, "\n")] = '\0'; // remove newline character
    
    printf("Enter a password (max %d characters): ", MAX_PASSWORD_LENGTH);
    fgets(password, MAX_PASSWORD_LENGTH, stdin);
    password[strcspn(password, "\n")] = '\0'; // remove newline character
    
    printf("Enter an email (max %d characters): ", MAX_EMAIL_LENGTH);
    fgets(email, MAX_EMAIL_LENGTH, stdin);
    email[strcspn(email, "\n")] = '\0'; // remove newline character
    
    sanitize_input(username);
    sanitize_input(password);
    
    if (!is_valid_email(email)) {
        printf("Invalid email address!\n");
        exit(1);
    }
    
    printf("Your sanitized username is: %s\n", username);
    printf("Your sanitized password is: %s\n", password);
    printf("Your email is: %s\n", email);
    
    return 0;
}