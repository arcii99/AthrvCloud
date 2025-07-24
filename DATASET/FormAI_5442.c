//FormAI DATASET v1.0 Category: Memory Game ; Style: secure
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 4

void print_board(int game_board[][BOARD_SIZE], int revealed[][BOARD_SIZE]);
void update_stats(int game_board[][BOARD_SIZE], int revealed[][BOARD_SIZE], int x1, int y1, int x2, int y2, int *score, int *remaining_count);
int check_win(int remaining_count);

int main() {
    int game_board[BOARD_SIZE][BOARD_SIZE] = {0};
    int revealed[BOARD_SIZE][BOARD_SIZE] = {0};
    int score = 0;
    int remaining_count = BOARD_SIZE * BOARD_SIZE / 2;

    srand(time(NULL));

    // Initialize the board with random values from 1 to BOARD_SIZE^2/2
    for (int i = 1; i <= BOARD_SIZE * BOARD_SIZE / 2; i++) {
        int count = 0;
        while (count < 2) {
            int x = rand() % BOARD_SIZE;
            int y = rand() % BOARD_SIZE;

            if (game_board[x][y] == 0) {
                game_board[x][y] = i;
                count++;
            }
        }
    }

    // Game loop
    while (1) {
        print_board(game_board, revealed);

        printf("Enter the coordinates of the first card (x y): ");
        int x1, y1;
        scanf("%d %d", &x1, &y1);

        // Ensure that the coordinates are valid
        if (x1 < 0 || x1 >= BOARD_SIZE || y1 < 0 || y1 >= BOARD_SIZE || revealed[x1][y1]) {
            printf("Invalid coordinates.\n");
            continue;
        }

        revealed[x1][y1] = 1;
        print_board(game_board, revealed);

        printf("Enter the coordinates of the second card (x y): ");
        int x2, y2;
        scanf("%d %d", &x2, &y2);

        // Ensure that the coordinates are valid
        if (x2 < 0 || x2 >= BOARD_SIZE || y2 < 0 || y2 >= BOARD_SIZE || revealed[x2][y2]) {
            printf("Invalid coordinates.\n");
            revealed[x1][y1] = 0;
            continue;
        }

        revealed[x2][y2] = 1;

        // Update the score and remaining count
        update_stats(game_board, revealed, x1, y1, x2, y2, &score, &remaining_count);

        // Check if the game has been won
        if (check_win(remaining_count)) {
            printf("Congratulations, you won! Your final score is %d.\n", score);
            break;
        }
    }

    return 0;
}

void print_board(int game_board[][BOARD_SIZE], int revealed[][BOARD_SIZE]) {
    printf("    0 1 2 3\n");
    printf("   ---------\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("%d | ", i);
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (revealed[i][j]) {
                printf("%d ", game_board[i][j]);
            } else {
                printf("  ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

void update_stats(int game_board[][BOARD_SIZE], int revealed[][BOARD_SIZE], int x1, int y1, int x2, int y2, int *score, int *remaining_count) {
    if (game_board[x1][y1] == game_board[x2][y2]) {
        printf("Match found! You earned 10 points.\n");
        *score += 10;
        *remaining_count -= 1;
    } else {
        printf("No match found. You lost 2 points.\n");
        *score -= 2;
        revealed[x1][y1] = 0;
        revealed[x2][y2] = 0;
    }
}

int check_win(int remaining_count) {
    return remaining_count == 0;
}