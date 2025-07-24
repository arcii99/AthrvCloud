//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: excited
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USERNAME_LEN 20
#define MAX_PASSWORD_LEN 20

int main() {
    char username[MAX_USERNAME_LEN];
    char password[MAX_PASSWORD_LEN];
    char secret_code[MAX_PASSWORD_LEN] = "password";
    int login_attempts = 0;

    printf("Welcome to the Intrusion Detection System!\n");
    printf("Please enter your username: ");
    scanf("%s", username);
    printf("Please enter your password: ");
    scanf("%s", password);

    while (login_attempts < 3) {
        if (strcmp(password, secret_code) == 0) {
            printf("Access granted. Welcome, %s!\n", username);
            break;
        } else {
            login_attempts++;
            printf("Access denied. Please try again.\n");
            printf("Please enter your password: ");
            scanf("%s", password);
        }
    }

    if (login_attempts >= 3) {
        printf("Intrusion detected! Too many failed login attempts.\n");
    }

    return 0;
}