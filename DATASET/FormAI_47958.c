//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: beginner-friendly
#include <stdio.h>

int main() {
    int isAttack = 0;
    int failedLogins = 0;
    char username[20];
    char password[20];

    while (!isAttack) {
        printf("Enter username: ");
        scanf("%s", username);
        printf("Enter password: ");
        scanf("%s", password);

        if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
            printf("Login successful!\n");
            isAttack = 1;
        } else {
            printf("Invalid username or password.\n");
            failedLogins++;

            if (failedLogins == 3) {
                printf("Too many failed login attempts. System shutting down.\n");
                isAttack = 1;
            }
        }
    }

    return 0;
}