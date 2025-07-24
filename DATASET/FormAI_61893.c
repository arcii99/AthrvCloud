//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ATTEMPTS 5
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[50];
    char password[MAX_PASSWORD_LENGTH];
    int login_attempts;
} User;

int main() {
    User user;
    user.login_attempts = 0;

    printf("Please enter your username: ");
    scanf("%s", user.username);

    printf("Please enter your password: ");
    scanf("%s", user.password);

    // Simulate an intrusion detection system
    while (user.login_attempts < MAX_ATTEMPTS) {
        if (strcmp(user.password, "correct_password") != 0) {
            user.login_attempts++;
            printf("Incorrect password, please try again (attempt %d/%d)\n", user.login_attempts, MAX_ATTEMPTS);

            printf("Please enter your password: ");
            scanf("%s", user.password);
        } else {
            printf("Welcome, %s!\n", user.username);
            break;
        }
    }

    if (user.login_attempts == MAX_ATTEMPTS) {
        printf("Login failed, too many incorrect attempts\n");
        // Take necessary actions to lockout the user
    }

    return 0;
}