//FormAI DATASET v1.0 Category: Memory Game ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4
#define MAX_PLAYERS 4
#define CARDS_NUMBER 8

const char* const cards[] = {"A", "B", "C", "D", "E", "F", "G", "H"};

void print_board_status(int board[BOARD_SIZE][BOARD_SIZE], int board_mask[BOARD_SIZE][BOARD_SIZE])
{
    printf("Board status:\n");

    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board_mask[i][j]) {
                printf("%3s ", cards[board[i][j]]);
            } else {
                printf("  * ");
            }
        }
        printf("\n");
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE] = {0};
    int board_mask[BOARD_SIZE][BOARD_SIZE] = {0};
    int players[MAX_PLAYERS] = {0};
    int player_scores[MAX_PLAYERS] = {0};
    int cards_left = CARDS_NUMBER;
    int current_player = 0;

    // Seed the random number generator
    srand(time(NULL));

    // Add cards to the board
    for (int card = 0; card < CARDS_NUMBER; card++) {
        int added = 0;
        do {
            // Generate random position
            int i = rand() % BOARD_SIZE;
            int j = rand() % BOARD_SIZE;

            // Add this card if the position is empty
            if (board[i][j] == 0) {
                board[i][j] = card;
                added = 1;
            }

        } while (!added);
    }

    // Game loop
    while (cards_left > 0) {
        printf("Current player: %d\n", current_player+1);
        print_board_status(board, board_mask);

        int i1, j1, i2, j2;
        printf("Enter coordinates for first card (i, j): ");
        scanf("%d %d", &i1, &j1);

        // Validate input
        if (i1 < 0 || j1 < 0 || i1 >= BOARD_SIZE || j1 >= BOARD_SIZE) {
            printf("Invalid coordinates\n");
            continue;
        } else if (board_mask[i1][j1]) {
            printf("Card already revealed\n");
            continue;
        }

        printf("Enter coordinates for second card (i, j): ");
        scanf("%d %d", &i2, &j2);

        // Validate input
        if (i2 < 0 || j2 < 0 || i2 >= BOARD_SIZE || j2 >= BOARD_SIZE) {
            printf("Invalid coordinates\n");
            continue;
        } else if (board_mask[i2][j2]) {
            printf("Card already revealed\n");
            continue;
        }

        // Reveal the cards
        board_mask[i1][j1] = 1;
        board_mask[i2][j2] = 1;

        // Check if cards match
        if (board[i1][j1] == board[i2][j2]) {
            printf("Match!\n");
            player_scores[current_player]++;
            cards_left -= 2;
        } else {
            printf("No match...\n");
        }

        current_player = (current_player + 1) % MAX_PLAYERS; // Next player
    }

    // Calculate winner
    int max_score = 0;
    int winner = 0;
    for (int i = 0; i < MAX_PLAYERS; i++) {
        if (player_scores[i] > max_score) {
            max_score = player_scores[i];
            winner = i + 1;
        }
    }

    printf("Game over! Player %d wins with a score of %d\n", winner, max_score);

    return 0; 
}