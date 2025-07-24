//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: surprised
#include <stdio.h>

#define MAX_LOGIN_ATTEMPTS 3

int main(void) {

    int loginAttempts = 0;
    int checkSum = 0;
    int userInput = 0;
    char* alertMessage = "INTRUSION DETECTED! LOCKDOWN INITIATED.";

    printf("Welcome to the security system.\n");
    printf("Please enter your user ID:\n");
    scanf("%d", &userInput);

    printf("Please enter your password:\n");
    scanf("%d", &checkSum);

    if (userInput == 12345 && checkSum == 54321) {
        printf("Access granted. Welcome back, user 12345.\n");
    } else {
        printf("Invalid credentials. Please try again.\n");

        while (loginAttempts < MAX_LOGIN_ATTEMPTS) {
            printf("Please enter your user ID:\n");
            scanf("%d", &userInput);

            printf("Please enter your password:\n");
            scanf("%d", &checkSum);

            if (userInput == 12345 && checkSum == 54321) {
                printf("Access granted. Welcome back, user 12345.\n");
                break;
            } else {
                printf("Invalid credentials. Please try again.\n");
            }

            loginAttempts++;
        }

        if (loginAttempts == MAX_LOGIN_ATTEMPTS) {
            printf("%s", alertMessage);
        }
    }

    return 0;
}