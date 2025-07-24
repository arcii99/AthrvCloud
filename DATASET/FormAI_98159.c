//FormAI DATASET v1.0 Category: Data mining ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_PLAYERS 4
#define NUM_ROUNDS 5

typedef struct {
    int id;
    int score;
} Player;

typedef struct {
    int roundNum;
    Player players[NUM_PLAYERS];
} Round;

void generateData(Round* round) {
    // generate random scores for each player
    for (int i = 0; i < NUM_PLAYERS; i++) {
        round->players[i].id = i + 1;
        round->players[i].score = rand() % 100;
    }
}

void printData(Round round) {
    printf("Round %d\n", round.roundNum);
    printf("Player\tScore\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        printf("%d\t%d\n", round.players[i].id, round.players[i].score);
    }
    printf("\n");
}

void getDataMiningResults(Round* round) {
    // sort players by score using selection sort
    for (int i = 0; i < NUM_PLAYERS - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < NUM_PLAYERS; j++) {
            if (round->players[j].score > round->players[maxIdx].score) {
                maxIdx = j;
            }
        }
        if (maxIdx != i) {
            Player temp = round->players[i];
            round->players[i] = round->players[maxIdx];
            round->players[maxIdx] = temp;
        }
    }

    // print results
    printf("Round %d Data Mining Results\n", round->roundNum);
    printf("Winner: Player %d with a score of %d\n", round->players[0].id, round->players[0].score);
    printf("Runner-Up: Player %d with a score of %d\n", round->players[1].id, round->players[1].score);
    printf("Players with scores above 60:\n");
    printf("Player\tScore\n");
    for (int i = 0; i < NUM_PLAYERS; i++) {
        if (round->players[i].score > 60) {
            printf("%d\t%d\n", round->players[i].id, round->players[i].score);
        }
    }
    printf("\n");
}

int main() {
    srand(time(NULL));
    Round rounds[NUM_ROUNDS];

    // generate data for each round and print it out
    for (int i = 0; i < NUM_ROUNDS; i++) {
        rounds[i].roundNum = i + 1;
        generateData(&rounds[i]);
        printData(rounds[i]);
    }

    // print data mining results for each round
    for (int i = 0; i < NUM_ROUNDS; i++) {
        getDataMiningResults(&rounds[i]);
    }

    return 0;
}