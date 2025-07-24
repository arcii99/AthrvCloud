//FormAI DATASET v1.0 Category: Text to ASCII art generator ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define ASCII_WIDTH 80
#define ASCII_HEIGHT 30
#define MAX_PLAYERS 4

typedef struct player {
    char name[20];
    int score;
} Player;

Player players[MAX_PLAYERS];
char ASCII[ASCII_HEIGHT][ASCII_WIDTH];
int current_player = 0;

void initializeASCII() {
    int i, j;
    for(i = 0; i < ASCII_HEIGHT; i++) {
        for(j = 0; j < ASCII_WIDTH; j++) {
            ASCII[i][j] = ' ';
        }
    }
}

void renderASCII() {
    int i, j;
    for(i = 0; i < ASCII_HEIGHT; i++) {
        for(j = 0; j < ASCII_WIDTH; j++) {
            printf("%c", ASCII[i][j]);
        }
        printf("\n");
    }
}

void addPlayer() {
    if(current_player >= MAX_PLAYERS) {
        printf("Max players reached.");
        return;
    }
    printf("Enter name for player %d: ", current_player+1);
    scanf("%s", players[current_player].name);
    players[current_player].score = 0;
    current_player++;
}

void updateScore(int playerIndex, int score) {
    if(playerIndex > current_player-1 || playerIndex < 0) {
        printf("Invalid player index.");
        return;
    }
    players[playerIndex].score += score;
}

void updateASCII(char c) {
    int i, j;
    for(i = ASCII_HEIGHT-1; i >= 1; i--) {
        for(j = ASCII_WIDTH-1; j >= 1; j--) {
            ASCII[i][j] = ASCII[i-1][j-1];
        }
    }
    for(j = 0; j < ASCII_WIDTH; j++) {
        ASCII[0][j] = c;
    }
}

void getWinner() {
    int i;
    int max_score = players[0].score;
    int winners[MAX_PLAYERS] = {0};
    winners[0] = 1;
    for(i = 1; i < current_player; i++) {
        if(players[i].score > max_score) {
            max_score = players[i].score;
            memset(winners, 0, sizeof(winners));
            winners[i] = 1;
        }
        else if(players[i].score == max_score) {
            winners[i] = 1;
        }
    }
    printf("Winner(s): ");
    for(i = 0; i < current_player; i++) {
        if(winners[i]) {
            printf("%s ", players[i].name);
        }
    }
}

int main() {
    char input;
    initializeASCII();
    printf("Welcome to the ASCII art game!\n");
    printf("Each player will take turns entering a character to add to the ASCII art.\n");
    printf("The art will scroll up as new characters are added.\n");
    printf("The player with the highest score at the end wins!\n\n");
    int numPlayers;
    printf("How many players? ");
    scanf("%d", &numPlayers);
    for(int i = 0; i < numPlayers; i++) {
        addPlayer();
    }
    while(1) {
        printf("\nCurrent Scores:\n");
        int i;
        for(i = 0; i < current_player; i++) {
            printf("%s: %d\n", players[i].name, players[i].score);
        }
        printf("\nEnter a character: ");
        scanf(" %c", &input);
        updateASCII(input);
        updateScore(current_player-1, 1);
        renderASCII();
    }
    return 0;
}