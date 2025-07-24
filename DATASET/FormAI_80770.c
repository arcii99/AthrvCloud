//FormAI DATASET v1.0 Category: Database querying ; Style: multiplayer
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

#define MAX_PLAYERS 10
#define MAX_NAME_LENGTH 20

int main() {
    struct Player {
        char name[MAX_NAME_LENGTH];
        int score;
    } players[MAX_PLAYERS];

    int numPlayers;
    printf("Enter number of players: ");
    scanf("%d", &numPlayers);

    printf("Enter player information:\n");
    for(int i=0; i<numPlayers; i++) {
        printf("Player %d name: ", i+1);
        scanf("%s", players[i].name);
        players[i].score = rand()%100 + 1;
    }

    // Sort the array of players based on scores
    struct Player temp;
    for(int i=0; i<numPlayers-1; i++) {
        for(int j=i+1; j<numPlayers; j++) {
            if(players[i].score < players[j].score) {
                temp = players[i];
                players[i] = players[j];
                players[j] = temp;
            }
        }
    }

    // Querying the database
    printf("\nTop 3 players:\n");
    for(int i=0; i<3; i++) {
        printf("%d. Name: %s\n   Score: %d\n", i+1, players[i].name, players[i].score);
    }

    return 0;
}