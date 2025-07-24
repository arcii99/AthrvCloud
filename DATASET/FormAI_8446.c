//FormAI DATASET v1.0 Category: Text processing ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define maximum number of players
#define MAX_PLAYERS 10

// Define maximum length of player names
#define MAX_NAME_LEN 20

// Define maximum length of messages
#define MAX_MSG_LEN 100

// Define structure for player
typedef struct {
    char name[MAX_NAME_LEN];
    int score;
} Player;

// Define global player array
Player players[MAX_PLAYERS];

// Define global integer to keep track of number of registered players
int numPlayers = 0;

// Define function to add a new player to the game
void addPlayer(char playerName[]) {
    // Check if maximum number of players has been reached
    if (numPlayers == MAX_PLAYERS) {
        printf("Sorry, maximum number of players has been reached.\n");
        return;
    }
    
    // Add new player to array
    strcpy(players[numPlayers].name, playerName);
    players[numPlayers].score = 0;
    numPlayers++;
    
    // Print confirmation message
    printf("%s has been added to the game!\n", playerName);
}

// Define function to display scoreboard
void displayScoreboard() {
    // Sort players by score (highest to lowest)
    for (int i = 0; i < numPlayers-1; i++) {
        for (int j = i+1; j < numPlayers; j++) {
            if (players[j].score > players[i].score) {
                Player temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }
    
    // Print scoreboard
    printf("Scoreboard:\n");
    printf("-----------\n");
    for (int i = 0; i < numPlayers; i++) {
        printf("%s - %d\n", players[i].name, players[i].score);
    }
}

// Define function to process player messages
void processMessage(char playerName[], char message[]) {
    // Find player
    int playerIndex = -1;
    for (int i = 0; i < numPlayers; i++) {
        if (strcmp(playerName, players[i].name) == 0) {
            playerIndex = i;
            break;
        }
    }
    
    // Handle invalid player
    if (playerIndex == -1) {
        printf("Sorry, player not found.\n");
        return;
    }
    
    // Process message
    if (strncmp(message, "add", 3) == 0) {
        int scoreToAdd = atoi(message + 4);
        printf("%s has earned %d points!\n", playerName, scoreToAdd);
        players[playerIndex].score += scoreToAdd;
    } else {
        printf("Sorry, invalid message.\n");
        return;
    }
}

int main() {
    // Main game loop
    char playerName[MAX_NAME_LEN];
    char message[MAX_MSG_LEN];
    while (1) {
        printf("\nPlease enter your name: ");
        fgets(playerName, MAX_NAME_LEN, stdin);
        playerName[strcspn(playerName, "\n")] = 0;
        if (strlen(playerName) == 0) {
            printf("Sorry, invalid name.\n");
            continue;
        }
        printf("Welcome, %s!\n", playerName);
        printf("Type '/add <points>' to add points to your score.\n");
        printf("Type '/scoreboard' to display the scoreboard.\n");
        printf("Type '/exit' to exit the game.\n");
        while (1) {
            printf("%s> ", playerName);
            fgets(message, MAX_MSG_LEN, stdin);
            message[strcspn(message, "\n")] = 0;
            if (strcmp(message, "/exit") == 0) {
                printf("%s has left the game...\n", playerName);
                break;
            } else if (strcmp(message, "/scoreboard") == 0) {
                displayScoreboard();
            } else if (strncmp(message, "/add ", 5) == 0) {
                processMessage(playerName, message + 1);
            } else {
                printf("Sorry, invalid message.\n");
            }
        }
    }
    
    return 0;
}