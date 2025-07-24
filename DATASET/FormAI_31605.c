//FormAI DATASET v1.0 Category: Password management ; Style: enthusiastic
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_USERS 10 // Maximum number of users, can be changed as required
#define MAX_PASS_LENGTH 20 // Maximum length of password, can be changed as required

// Global variables for storing user names and passwords
char usernames[MAX_USERS][MAX_PASS_LENGTH];
char passwords[MAX_USERS][MAX_PASS_LENGTH];

// Function to add a new user to the system
void add_user(int index) {
    printf("\nEnter new username: ");
    scanf("%s", &usernames[index]);
    printf("Enter new password: ");
    scanf("%s", &passwords[index]);
    printf("User added successfully!");
}

// Function to check if the entered username and password are correct
int check_credentials(char username[], char password[]) {
    int i;
    for(i=0; i<MAX_USERS; i++) {
        if(strcmp(username, usernames[i]) == 0 && strcmp(password, passwords[i]) == 0) {
            return 1;
        }
    }
    return 0;
}

int main() {
    int i, choice, user_index;
    char username[MAX_PASS_LENGTH], password[MAX_PASS_LENGTH];

    // Initializing the username and password arrays with dummy values
    for(i=0; i<MAX_USERS; i++) {
        strcpy(usernames[i], "dummy");
        strcpy(passwords[i], "dummy");
    }

    while(1) {
        printf("\n\nWelcome to the Password Management System!\n");
        printf("1. Add new user\n");
        printf("2. Login\n");
        printf("3. Exit\n");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                for(i=0; i<MAX_USERS; i++) {
                    if(strcmp(usernames[i], "dummy") == 0) {
                        add_user(i);
                        break;
                    }
                    else if(i == MAX_USERS-1) {
                        printf("\nError: Maximum number of users reached!\n");
                    }
                }
                break;

            case 2:
                printf("\nEnter username: ");
                scanf("%s", &username);
                printf("Enter password: ");
                scanf("%s", &password);
                if(check_credentials(username, password) == 1) {
                    printf("\nLogin successful!\n");
                }
                else {
                    printf("\nIncorrect username or password!\n");
                }
                break;

            case 3:
                printf("\nExiting the Password Management System...\n");
                exit(0);
                break;

            default:
                printf("\nInvalid choice! Please try again.\n");
        }
    }
    return 0;
}