//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: innovative
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Define the maximum length for input strings
#define MAX_LENGTH 100

//Define the maximum number of login attempts
#define MAX_ATTEMPTS 3

//Function to check if a user is authorized
int isAuthorized(char username[MAX_LENGTH], char password[MAX_LENGTH]) {
    //replace the following with your own authentication logic
    if (strcmp(username, "admin") == 0 && strcmp(password, "password123") == 0) {
        return 1;
    } else {
        return 0;
    }
}

//Function to detect intrusion attempts
void detectIntrusion() {
    printf("INTRUSION DETECTED: Too many login attempts with incorrect credentials.\n");
    //Code to send alert email, text message, or phone call to administrator
}

int main() {
    //initialize variables
    char username[MAX_LENGTH], password[MAX_LENGTH];
    int attempts = 0;

    //Get username and password from user
    printf("Enter your username: ");
    fgets(username, MAX_LENGTH, stdin);
    printf("Enter your password: ");
    fgets(password, MAX_LENGTH, stdin);

    //Remove newline character from input strings
    username[strcspn(username, "\n")] = 0;
    password[strcspn(password, "\n")] = 0;

    //Continue asking for credentials until max attempts reached
    while (attempts < MAX_ATTEMPTS) {
        if (isAuthorized(username, password)) {
            printf("Access granted.\n");
            return 0;
        } else {
            attempts++;
            printf("Incorrect username/password combination. Attempt %d of %d.\n", attempts, MAX_ATTEMPTS);
            printf("Enter your username: ");
            fgets(username, MAX_LENGTH, stdin);
            printf("Enter your password: ");
            fgets(password, MAX_LENGTH, stdin);

            //Remove newline character from input strings
            username[strcspn(username, "\n")] = 0;
            password[strcspn(password, "\n")] = 0;
        }
    }

    //If max attempts reached, detect intrusion.
    detectIntrusion();

    return 0;
}