//FormAI DATASET v1.0 Category: Table Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define NUM_OF_PLAYERS 2

typedef struct {
    int position;
    int score;
} Player;

int rollDice() {
    return rand() % 6 + 1;
}

int movePlayer(Player *player, int steps) {
    player->position += steps;
    if (player->position >= BOARD_SIZE) {
        player->position = BOARD_SIZE - 1;
        return 1;
    }
    return 0;
}

int activateTile(Player *player) {
    int score = 0;
    switch(player->position) {
        case 2:
            score = 10;
            break;
        case 4:
            score = -5;
            break;
        case 7:
            score = 20;
            break;
        case 9:
            player->score += 50;
            break;
        default:
            break;
    }
    return score;
}

void printBoard(Player players[NUM_OF_PLAYERS]) {
    printf("\n");
    printf("     ");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%2d ", i+1);
    }
    printf("\n");

    for (int i = 0; i < NUM_OF_PLAYERS; i++) {
        printf("P%d:  ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (j == players[i].position) {
                printf("x  ");
            } else {
                printf("-  ");
            }
        }
        printf(" Score: %d", players[i].score);
        printf("\n");
    }
}

int main() {
    srand(time(NULL));
    Player players[NUM_OF_PLAYERS];
    players[0].position = 0;
    players[0].score = 0;
    players[1].position = 0;
    players[1].score = 0;

    int currentPlayer = 0;
    int gameOver = 0;

    while (!gameOver) {
        printf("Player %d's turn. Press enter to roll the dice.", currentPlayer+1);
        getchar();

        int rolledNumber = rollDice();
        printf("You rolled a %d!\n", rolledNumber);

        int moveSuccess = movePlayer(&players[currentPlayer], rolledNumber);
        if (moveSuccess) {
            printf("CONGRATULATIONS! You have reached the end of the board.\n");
            gameOver = 1;
            break;
        }

        int tileScore = activateTile(&players[currentPlayer]);
        printf("You landed on Tile %d and gained %d points!\n", players[currentPlayer].position+1, tileScore);
        players[currentPlayer].score += tileScore;

        printBoard(players);

        currentPlayer = (currentPlayer + 1) % NUM_OF_PLAYERS;
    }

    printf("GAME OVER! Final Scores:\n");
    for (int i = 0; i < NUM_OF_PLAYERS; i++) {
        printf("Player %d: %d\n", i+1, players[i].score);
    }
    return 0;
}