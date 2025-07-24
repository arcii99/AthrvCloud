//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LOGIN_ATTEMPTS 3

typedef struct {
    char username[20];
    char password[20];
} User;

int check_login_attempt(User* user, int* attempt);

int main() {
    User user = {"admin", "password"};
    int attempt = 0;

    printf("Welcome to the system. Please enter your login details:\n");

    while (check_login_attempt(&user, &attempt)) {
        printf("Invalid login attempt. Please try again.\n");
        if (attempt == MAX_LOGIN_ATTEMPTS) {
            printf("Maximum login attempts exceeded. Intrusion detected. Exiting program.\n");
            exit(EXIT_SUCCESS);
        }
    }

    printf("Login successful. Access granted.\n");
    return 0;
}

int check_login_attempt(User* user, int* attempt) {
    char username[20];
    char password[20];

    printf("Username: ");
    scanf("%s", username);

    printf("Password: ");
    scanf("%s", password);

    (*attempt)++;

    if (strcmp(user->username, username) == 0 && strcmp(user->password, password) == 0) {
        return 0;
    }

    return 1;
}