//FormAI DATASET v1.0 Category: Intrusion detection system ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of players
#define MAX_PLAYERS 5

// Define maximum length of player name
#define MAX_NAME_LEN 20

// Define maximum number of allowed failed login attempts
#define MAX_FAILED_LOGINS 3

// Define structure to store player information
struct Player {
    char name[MAX_NAME_LEN];
    int failedLogins;
};

// Define array of players
struct Player players[MAX_PLAYERS];

// Define function to check if login attempt is valid or not
int isLoginAttemptValid(char* name) {
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        // If player with given name exists
        if (strcmp(players[i].name, name) == 0) {
            // If player has exceeded maximum failed login attempts
            if (players[i].failedLogins >= MAX_FAILED_LOGINS) {
                return 0;
            } else { // Login attempt is valid
                return 1;
            }
        }
    }
    // Player with given name does not exist
    return 0;
}

int main() {
    // Initialize array of players with default values
    int i;
    for (i = 0; i < MAX_PLAYERS; i++) {
        strcpy(players[i].name, "");
        players[i].failedLogins = 0;
    }

    // Main game loop
    while (1) {
        char loginName[MAX_NAME_LEN];
        printf("Enter your name: ");
        fgets(loginName, MAX_NAME_LEN, stdin);

        // Remove newline character from input
        loginName[strcspn(loginName, "\n")] = 0;

        // Check if login attempt is valid
        if (isLoginAttemptValid(loginName)) {
            printf("Welcome back, %s!\n", loginName);
        } else {
            printf("Invalid login attempt.\n");
            // Increment failed login attempts for player with given name
            for (i = 0; i < MAX_PLAYERS; i++) {
                // If player with given name exists
                if (strcmp(players[i].name, loginName) == 0) {
                    players[i].failedLogins++;
                }
            }
        }
    }

    return 0;
}