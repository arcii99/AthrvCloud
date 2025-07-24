//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: detailed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
 
#define MAX_LOGIN_ATTEMPTS 3
 
int main(int argc, char **argv) {
    // Define variables
    char username[50], password[50];
    int failed_attempts = 0;
    time_t last_login_attempt = 0;
 
    printf("Welcome to the system!\n");
 
    // Loop through login attempts
    while (failed_attempts < MAX_LOGIN_ATTEMPTS) {
        printf("\nEnter your username: ");
        scanf("%s", username);
 
        printf("Enter your password: ");
        scanf("%s", password);
 
        // Check if the login is successful
        if (strcmp(username, "root") == 0 && strcmp(password, "password123") == 0) {
            printf("Successful login!\n");
            break;
        } else {
            printf("Incorrect username or password.\n");
 
            failed_attempts++;
 
            // Check if too many attempts have been made within a short time
            if (failed_attempts >= MAX_LOGIN_ATTEMPTS && difftime(time(NULL), last_login_attempt) < 60) {
                printf("Too many login attempts. Please wait a minute and try again.\n");
                exit(0);
            }
 
            // Reset failed attempts if not within a short time
            if (difftime(time(NULL), last_login_attempt) >= 60) {
                failed_attempts = 1;
            }
 
            last_login_attempt = time(NULL);
        }
    }
 
    return 0;
}