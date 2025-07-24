//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: Dennis Ritchie
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_EVENTS 1000   //Maximum number of events to keep track of
#define MAX_LENGTH 50     //Maximum length of event description
#define MAX_USERS 50      //Maximum number of registered users
#define THRESHOLD 5       //Intrusion detection threshold

struct Event {
    time_t timestamp;
    char description[MAX_LENGTH];
};

struct User {
    char username[MAX_LENGTH];
    int login_attempts;
    struct Event events[MAX_EVENTS];
};

int main() {
    struct User users[MAX_USERS];
    int num_users = 0;
    char input[MAX_LENGTH];

    while (1) {
        // Prompt user to enter a username or "quit"
        printf("Enter a username or type 'quit' to exit:\n");
        fgets(input, MAX_LENGTH, stdin);
        input[strcspn(input, "\n")] = '\0';   // Remove newline character

        // Exit the program if user enters "quit"
        if (strcmp(input, "quit") == 0) {
            printf("Exiting program...\n");
            break;
        }

        // Check if user is already registered
        int user_found = 0;
        int i;
        for (i = 0; i < num_users; i++) {
            if (strcmp(users[i].username, input) == 0) {
                user_found = 1;
                break;
            }
        }

        if (user_found) {
            // User is registered, increment login attempts
            users[i].login_attempts++;

            // Add event to user's event log
            time_t current_time;
            char event_description[MAX_LENGTH];
            time(&current_time);
            strftime(event_description, MAX_LENGTH, "User %s logged in at %Y-%m-%d %H:%M:%S", localtime(&current_time));
            struct Event event = { .timestamp = current_time, .description = event_description };
            users[i].events[users[i].login_attempts-1] = event;

            // Check if login attempt exceeds threshold
            if (users[i].login_attempts >= THRESHOLD) {
                printf("INTRUSION ALERT: User %s exceeded login attempt threshold! Event log:\n", users[i].username);
                int j;
                for (j = 0; j < users[i].login_attempts; j++) {
                    printf("%s\n", users[i].events[j].description);
                }
            }
            else {
                printf("User %s logged in successfully. Number of login attempts: %d\n", users[i].username, users[i].login_attempts);
            }
        }
        else {
            // User not found, prompt to register
            if (num_users == MAX_USERS) {
                printf("User limit reached. Cannot register new user.\n");
            }
            else {
                struct User new_user = { .login_attempts = 0 };
                strcpy(new_user.username, input);
                users[num_users] = new_user;
                num_users++;
                printf("User %s registered successfully.\n", input);
            }
        }
    }

    return 0;
}