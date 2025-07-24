//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: recursive
#include <stdio.h>
#include <string.h>

// Constants
#define MAX_ATTEMPTS 3

// Function prototypes
void check_login_attempt(int attempts_left);

int main() {
    // Call the check_login_attempt function to start the login process
    check_login_attempt(MAX_ATTEMPTS);

    return 0;
}

void check_login_attempt(int attempts_left) {
    // Base case: stop recursing if the user has no attempts left
    if (attempts_left == 0) {
        printf("Too many failed login attempts. Exiting.");
        return;
    }

    char password[20];
    printf("Enter your password: ");
    scanf("%s", password);

    // Check if the password is correct
    if (strcmp(password, "mypassword") == 0) {
        printf("Login successful. Welcome, user!\n");
        return;
    } else {
        printf("Incorrect password. %d attempts left.\n", attempts_left - 1);

        // Recursive case: call the function again with the number of attempts reduced
        check_login_attempt(attempts_left - 1);
    }
}