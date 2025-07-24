//FormAI DATASET v1.0 Category: Browser Plugin ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Define the maximum number of players
#define MAX_PLAYERS 5

// Define the maximum length of player names
#define MAX_NAME_LENGTH 20

// Define the maximum number of characters in a message
#define MAX_MESSAGE_LENGTH 100

// Define the delimiter character used to separate fields in messages
#define DELIMITER ','

// Define the structure for holding player information
typedef struct Player {
    char name[MAX_NAME_LENGTH];
    int score;
} Player;

// Define the structure for holding message information
typedef struct Message {
    char sender[MAX_NAME_LENGTH];
    char receiver[MAX_NAME_LENGTH];
    char content[MAX_MESSAGE_LENGTH];
} Message;

// Define a global array of players
Player players[MAX_PLAYERS];

// Keep track of the number of players currently in the game
int numPlayers = 0;

// Define a function for adding a new player
void addPlayer(char *name) {
    // Make sure there is room for the new player
    if (numPlayers < MAX_PLAYERS) {
        // Initialize the new player
        Player p;
        strcpy(p.name, name);
        p.score = 0;

        // Add the player to the array
        players[numPlayers] = p;

        // Increment the number of players in the game
        numPlayers++;
    }
}

// Define a function for sending a message
void sendMessage(char *sender, char *receiver, char *content) {
    // Initialize the message
    Message m;
    strcpy(m.sender, sender);
    strcpy(m.receiver, receiver);
    strcpy(m.content, content);

    // Print the message to the console
    printf("%s -> %s: %s\n", m.sender, m.receiver, m.content);
}

int main() {
    // Add some initial players
    addPlayer("Alice");
    addPlayer("Bob");
    addPlayer("Charlie");

    // Send some messages
    sendMessage("Alice", "Bob", "Hello, Bob!");
    sendMessage("Bob", "Charlie", "Hey, Charlie!");

    return 0;
}