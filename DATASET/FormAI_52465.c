//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: all-encompassing
#include <stdio.h>
#include <stdlib.h>

#define MAX_PASSWORD_LENGTH 20
#define MAX_ATTEMPTS 3

int check_password(char* password) {
    // check if password meets security requirements
    if (strlen(password) < 8) {
        return 0;
    }
    if (strchr(password, '!') == NULL && strchr(password, '@') == NULL && strchr(password, '#') == NULL) {
        return 0;
    }
    if (strcmp(password, "password") == 0 || strcmp(password, "12345678") == 0) {
        return 0;
    }
    return 1;
}

int main() {
    char password[MAX_PASSWORD_LENGTH];
    int attempts = 0;
    while (attempts < MAX_ATTEMPTS) {
        printf("Enter your password: ");
        scanf("%s", password);
        if (check_password(password)) {
            // password meets security requirements
            printf("Access granted!\n");
            return 0;
        } else {
            // password does not meet security requirements
            printf("Access denied. Please try again.\n");
            attempts++;
        }
    }
    printf("Maximum attempts reached. Intrusion detected.\n");
    return 1;
}