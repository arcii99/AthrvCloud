//FormAI DATASET v1.0 Category: System administration ; Style: relaxed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/* global variables */
char password[9] = "password";   // default password is "password"
int fails = 0;   // number of failed login attempts

/* function prototypes */
void login();
void checkPassword(char* input);
void resetPassword();
void systemShutdown();
void displayOptions();
void executeOption(int choice);

int main() {
    printf("Welcome to the System Administration Program!\n");
    printf("Please login to access the system.\n");
    login();
    return 0;
}

/* function to handle user login */
void login() {
    char input[9];
    printf("Password: ");
    fgets(input, 9, stdin);   // read user input from console
    checkPassword(input);
}

/* function to check if user input matches the password */
void checkPassword(char* input) {
    if(strcmp(input, password) == 0) {
        printf("Login successful!\n");
        displayOptions();
    }
    else {
        printf("Incorrect password. Please try again.\n");
        fails++;
        if(fails >= 3) {
            printf("Too many failed login attempts. System will now shut down.\n");
            systemShutdown();
        }
        login();
    }
}

/* function to reset the password */
void resetPassword() {
    char newPass[9];
    printf("Enter new password: ");
    fgets(newPass, 9, stdin);   // read user input from console
    strcpy(password, newPass);
    printf("Password successfully reset!\n");
}

/* function to shut down the system */
void systemShutdown() {
    printf("Shutting down the system...\n");
    exit(0);
}

/* function to display the available options */
void displayOptions() {
    printf("What would you like to do?\n");
    printf("1. Reset the password\n");
    printf("2. Shut down the system\n");
    printf("3. Logout\n");
    printf("Enter the number of your choice: ");
    int choice;
    scanf("%d", &choice);
    executeOption(choice);
}

/* function to execute the user's choice */
void executeOption(int choice) {
    switch(choice) {
        case 1:
            resetPassword();
            displayOptions();
            break;
        case 2:
            systemShutdown();
            break;
        case 3:
            printf("Logging out...\n");
            login();
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            displayOptions();
            break;
    }
}