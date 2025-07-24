//FormAI DATASET v1.0 Category: Password management ; Style: distributed
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>

#define MAX_USERS 100
#define MAX_PASSWORD_LENGTH 20

typedef struct {
    char username[MAX_PASSWORD_LENGTH];
    char password[MAX_PASSWORD_LENGTH];
} User;

int main() {
    // Initialize random seed
    srand(time(0));

    // Initialize users array
    User users[MAX_USERS];
    int num_users = 0;

    // Password management system
    printf("Welcome to the password management system!\n");

    int choice;
    bool running = true;

    while(running) {
        printf("Enter a choice:\n");
        printf("1. Create user\n2. Generate password\n3. Retrieve password\n4. Exit\n");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Create user
                if(num_users >= MAX_USERS) {
                    printf("Maximum number of users reached!\n");
                    break;
                }

                printf("Enter username:\n");
                scanf("%s", users[num_users].username);

                printf("Enter password:\n");
                scanf("%s", users[num_users].password);

                printf("User created successfully!\n");

                num_users++;
                break;
            case 2:
                // Generate password
                char password[MAX_PASSWORD_LENGTH];
                char characters[63] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890!@#$%^&*()_+-=[]{}\\|;':\",./<>?";

                int length;
                printf("Enter length of password:\n");
                scanf("%d", &length);

                for(int i=0; i<length; i++) {
                    password[i] = characters[rand() % 63];
                }

                password[length] = '\0';

                printf("Generated password: %s\n", password);
                break;
            case 3:
                // Retrieve password
                char username[MAX_PASSWORD_LENGTH];
                char* passwordPtr = NULL;
                
                printf("Enter username:\n");
                scanf("%s", username);

                for(int i=0; i<num_users; i++) {
                    if(strcmp(users[i].username, username) == 0) {
                        passwordPtr = users[i].password;
                        break;
                    }
                }

                if(passwordPtr == NULL) {
                    printf("User not found!\n");
                } else {
                    printf("Password: %s\n", passwordPtr);
                }
                break;
            case 4:
                // Exit
                running = false;
                printf("Goodbye!\n");
                break;
            default:
                printf("Invalid choice!\n");
        }
    }

    return 0;
}