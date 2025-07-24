//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 10
#define MAX_SCORE 100
#define BOMB_VALUE -5

/* Function Declarations */
void initialize_board(int board[][BOARD_SIZE], int *player_row, int *player_col);
void print_board(int board[][BOARD_SIZE], int player_row, int player_col, int score);
void update_board(int board[][BOARD_SIZE], int player_row, int player_col, int *score);
int generate_random_num(int max);
void move_player(int board[][BOARD_SIZE], int *player_row, int *player_col, int *score);
void end_game(int score);

/* Main function */
int main(void) {
    int board[BOARD_SIZE][BOARD_SIZE];
    int player_row, player_col;
    int score = 0;

    initialize_board(board, &player_row, &player_col);

    while (score < MAX_SCORE) {
        print_board(board, player_row, player_col, score);
        move_player(board, &player_row, &player_col, &score);
        update_board(board, player_row, player_col, &score);
    }

    end_game(score);

    return 0;
}

/* Function to initialize the game board and place the player */
void initialize_board(int board[][BOARD_SIZE], int *player_row, int *player_col) {
    int i, j;
    srand(time(NULL));

    /* Initialize the board with random numbers */
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = generate_random_num(10);
        }
    }

    /* Place the player at a random position */
    *player_row = generate_random_num(BOARD_SIZE - 1);
    *player_col = generate_random_num(BOARD_SIZE - 1);
}

/* Function to print the current state of the board, player position and score */
void print_board(int board[][BOARD_SIZE], int player_row, int player_col, int score) {
    int i, j;

    system("clear"); /* Clear the console */

    printf("\t\tScore: %d/%d\n\n", score, MAX_SCORE);

    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i == player_row && j == player_col) {
                printf("[P] ");
            } else {
                printf("[%d] ", board[i][j]);
            }
        }
        printf("\n");
    }
    printf("\nUse arrow keys to move. Try to collect points and avoid bombs!\n");
}

/* Function to update the board after the player moves */
void update_board(int board[][BOARD_SIZE], int player_row, int player_col, int *score) {
    if (board[player_row][player_col] == BOMB_VALUE) {
        *score += board[player_row][player_col];
    } else {
        *score += board[player_row][player_col];
        board[player_row][player_col] = generate_random_num(10);
    }
}

/* Function to generate random numbers */
int generate_random_num(int max) {
    return rand() % max;
}

/* Function to move the player according to the arrow keys pressed */
void move_player(int board[][BOARD_SIZE], int *player_row, int *player_col, int *score) {
    char ch;

    /* Read the arrow key pressed */
    ch = getchar();
    while (getchar() != '\n') {} /*Consume remaining inputs*/

    switch (ch) {
        case 'A':
        case 'a':
            if (*player_row > 0) {
                *player_row -= 1;
            }
            break;
        case 'D':
        case 'd':
            if (*player_row < BOARD_SIZE - 1) {
                *player_row += 1;
            }
            break;
        case 'W':
        case 'w':
            if (*player_col > 0) {
                *player_col -= 1;
            }
            break;
        case 'S':
        case 's':
            if (*player_col < BOARD_SIZE - 1) {
                *player_col += 1;
            }
            break;
        default:
            break;
    }
}

/* Function to end the game and display the final score */
void end_game(int score) {
    printf("\n\t\t Game Over \t\t\n");
    printf("\n\t Final Score: %d/%d\n\n", score, MAX_SCORE);
}