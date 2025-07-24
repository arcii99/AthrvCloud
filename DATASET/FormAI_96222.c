//FormAI DATASET v1.0 Category: Password Stength Checker ; Style: real-life
#include <stdio.h>
#include <string.h>

int main() {
    char password[20];

    printf("Enter your password: ");
    scanf("%s", password);

    int length = strlen(password);
    int score = 0;

    if (length < 8) {
        printf("Weak password.\n");
        printf("Password should be at least 8 characters long.\n");
        return 0;
    }

    for (int i = 0; i <= length; i++) {
        if (password[i] >= 'A' && password[i] <= 'Z') {
            score += 2;
        }
        else if (password[i] >= 'a' && password[i] <= 'z') {
            score += 2;
        }
        else if (password[i] >= '0' && password[i] <= '9') {
            score += 2;
        }
        else {
            score += 3;
        }
    }

    if (score < 8) {
        printf("Weak password.\n");
        printf("Password should contain both uppercase and lowercase letters, numbers and special characters.\n");
    }
    else if (score < 12) {
        printf("Moderate password.\n");
        printf("Password could be stronger if it contained special characters.\n");
    }
    else {
        printf("Strong password.\n");
    }

    return 0;
}