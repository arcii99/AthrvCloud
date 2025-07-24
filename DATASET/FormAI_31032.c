//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char password[10];
    int attempts = 0;

    // Setting a fixed password
    char correctPassword[10] = "password";

    while(1) {
        printf("Enter your password: ");
        scanf("%s", password);

        // Comparing the input password with the correct password
        if(strcmp(password, correctPassword) == 0) {
            printf("Access granted!\n");
            break;
        } else {
            attempts++;
        }

        // After 3 unsuccessful attempts, alerting the user about possible intrusion
        if(attempts == 3) {
            printf("Too many unsuccessful attempts, possible intrusion detected!\n");
            break;
        }
    }

    return 0;
}