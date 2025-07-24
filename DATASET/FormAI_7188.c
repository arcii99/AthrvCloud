//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: safe
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define NUM_ATTEMPTS 3
#define MAX_PASSWORD_LENGTH 20

void alert(char* message) {
    printf("INTRUSION ALERT: %s\n", message);
}

int main() {
    char correct_password[MAX_PASSWORD_LENGTH] = "password123";
    char entered_password[MAX_PASSWORD_LENGTH];
    int num_attempts = 0;

    while(num_attempts < NUM_ATTEMPTS) {
        printf("Please enter password: ");
        fgets(entered_password, MAX_PASSWORD_LENGTH, stdin);
        entered_password[strcspn(entered_password, "\n")] = 0; // remove newline character from entered password

        if(strcmp(entered_password, correct_password) == 0) {
            printf("Access granted.\n");
            return 0;
        } else {
            num_attempts++;
            if(num_attempts == NUM_ATTEMPTS) {
                alert("Maximum number of password attempts reached.");
                return 1;
            } else {
                printf("Incorrect password. %d attempts remaining.\n", NUM_ATTEMPTS - num_attempts);
            }
        }
    }

    return 0;
}