//FormAI DATASET v1.0 Category: Internet Speed Test Application ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define MIN_SPEED 1
#define MAX_SPEED 10

void runSpeedTest(int playerID) {
    int speed = (rand() % (MAX_SPEED - MIN_SPEED + 1)) + MIN_SPEED;
    printf("Player %d's internet speed is %d Mbps.\n", playerID, speed);
}

int main() {
    srand(time(NULL));

    printf("Welcome to the Internet Speed Test game!\n");
    printf("Up to %d players can participate.\n", NUM_PLAYERS);

    // initialize array to keep track of whether each player has participated
    int playersParticipated[NUM_PLAYERS] = {0};
    int numPlayersParticipated = 0;

    // continue until all players have participated
    while (numPlayersParticipated < NUM_PLAYERS) {
        int playerID;
        do {
            printf("Enter player ID (1-%d): ", NUM_PLAYERS);
            scanf("%d", &playerID);
            if (playerID < 1 || playerID > NUM_PLAYERS) {
                printf("Invalid player ID.\n");
            } else if (playersParticipated[playerID-1] == 1) {
                printf("Player %d has already participated.\n", playerID);
                playerID = 0;
            }
        } while (playerID == 0);

        playersParticipated[playerID-1] = 1;
        numPlayersParticipated++;

        runSpeedTest(playerID);
    }

    printf("All players have participated. Thank you for playing!\n");

    return 0;
}