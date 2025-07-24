//FormAI DATASET v1.0 Category: Data mining ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// define structure for player data
struct PlayerData {
    char playerName[50];
    int playerScore;
    int playerWins;
};

// define structure for game data
struct GameData {
    char gameName[50];
    int numOfPlayers;
    struct PlayerData *players;
};

void printPlayerData(struct PlayerData playerInfo) {
    printf("Name: %s \n", playerInfo.playerName);
    printf("Score: %d \n", playerInfo.playerScore);
    printf("Wins: %d \n", playerInfo.playerWins);
}

void printGameData(struct GameData gameInfo) {
    printf("Game Name: %s \n", gameInfo.gameName);
    printf("Number of Players: %d \n", gameInfo.numOfPlayers);
    printf("Player Information: \n");
    for(int i = 0; i < gameInfo.numOfPlayers; i++) {
        printf("\tPlayer %d: \n", i+1);
        printPlayerData(gameInfo.players[i]);
    }
}

void updateScore(struct GameData *gameInfo, char *playerName, int score) {
    for(int i = 0; i < gameInfo->numOfPlayers; i++) {
        if(strcmp(gameInfo->players[i].playerName, playerName) == 0) {
            gameInfo->players[i].playerScore += score;
            if (score > 10) gameInfo->players[i].playerWins += 1;
        }
    }
}

int main() {

    struct GameData gameInfo;
    strcpy(gameInfo.gameName, "Data Mining Tournament");
    gameInfo.numOfPlayers = 3;

    // allocate memory for players array
    gameInfo.players = (struct PlayerData*) malloc(gameInfo.numOfPlayers * sizeof(struct PlayerData));

    // initialize player data
    strcpy(gameInfo.players[0].playerName, "John");
    gameInfo.players[0].playerScore = 0;
    gameInfo.players[0].playerWins = 0;

    strcpy(gameInfo.players[1].playerName, "Sarah");
    gameInfo.players[1].playerScore = 0;
    gameInfo.players[1].playerWins = 0;

    strcpy(gameInfo.players[2].playerName, "Michael");
    gameInfo.players[2].playerScore = 0;
    gameInfo.players[2].playerWins = 0;

    // print game data
    printf("Initial Game Data: \n");
    printGameData(gameInfo);

    // update player scores
    updateScore(&gameInfo, "John", 5);
    updateScore(&gameInfo, "Sarah", 15);
    updateScore(&gameInfo, "Michael", 10);

    // print updated game data
    printf("\n Updated Game Data: \n");
    printGameData(gameInfo);

    return 0;
}