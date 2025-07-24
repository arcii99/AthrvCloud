//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: ephemeral
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Define constants */
#define BOARD_SIZE 10
#define MINES_NUM 15

/* Define Structures */
struct coord {
    int x;
    int y;
};

/* Function declarations */
void initialize_board(int board[][BOARD_SIZE]);
void display_board(int board[][BOARD_SIZE], int showMines);
void place_mines(int board[][BOARD_SIZE]);
int open_square(int board[][BOARD_SIZE], struct coord location);
void game_over(int board[][BOARD_SIZE]);
int count_adjacent_mines(int board[][BOARD_SIZE], struct coord location);

/* Main function */
int main() {
    int game_board[BOARD_SIZE][BOARD_SIZE];
    struct coord selected;
    int game_status, mines_remaining;
    char user_selection;

    /* Set up the game board */
    initialize_board(game_board);

    /* Place the mines randomly */
    place_mines(game_board);

    /* Game loop */
    do {
        /* Display the game board */
        display_board(game_board, 0);

        /* Get the user's selection */
        printf("Enter row and column of square (e.g., '3 4'): ");
        scanf("%d %d", &selected.x, &selected.y);

        /* Open the selected square and get game status */
        game_status = open_square(game_board, selected);

        /* Update mines remaining and display message */
        mines_remaining = count_adjacent_mines(game_board, selected);
        printf("%d mines nearby.\n", mines_remaining);

        /* End game if game over */
        if (game_status == -1) {
            game_over(game_board);
            break;
        }

    } while (game_status != 1);

    /* Display the game board with showMines parameter */
    display_board(game_board, 1);

    /* Display game over message */
    printf("Game over! You %s.\n", (game_status == 1) ? "won" : "lost");

    return 0;
}

/* Function definitions */

/* Set all squares on the board to -1 */
void initialize_board(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = -1;
        }
    }
}

/* Display the game board */
void display_board(int board[][BOARD_SIZE], int showMines) {
    int i, j;
    char cell;
    printf("\n  1 2 3 4 5 6 7 8 9 10\n");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d", i+1);
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -1) {
                cell = '.';
            } else if (board[i][j] == -2) {
                cell = '*';
            } else if (board[i][j] == -3) {
                cell = 'F';
            } else if (board[i][j] == -4) {
                cell = '#';
            } else {
                if (showMines && board[i][j] == 9) {
                    cell = '*';
                } else {
                    cell = board[i][j] + '0';
                }
            }
            printf(" %c", cell);
        }
        printf("\n");
    }
}

/* Place the mines on the board */
void place_mines(int board[][BOARD_SIZE]) {
    int i, j, counter = 0;
    srand(time(NULL));
    while (counter < MINES_NUM) {
        i = rand() % BOARD_SIZE;
        j = rand() % BOARD_SIZE;
        if (board[i][j] != -2) {
            board[i][j] = -2;
            counter++;
        }
    }
}

/* Open a square on the board */
int open_square(int board[][BOARD_SIZE], struct coord location) {
    int i, j;
    if (board[location.x-1][location.y-1] == -2) {
        return -1; /* Game over */
    } else {
        /* Recursively open adjacent squares */
        board[location.x-1][location.y-1] = count_adjacent_mines(board, location);
        if (board[location.x-1][location.y-1] == 0) {
            for (i = -1; i <= 1; i++) {
                for (j = -1; j <= 1; j++) {
                    if (location.x+i > 0 && location.x+i <= BOARD_SIZE &&
                        location.y+j > 0 && location.y+j <= BOARD_SIZE &&
                        board[location.x+i-1][location.y+j-1] == -1) {
                        open_square(board, (struct coord){location.x+i, location.y+j});
                    }
                }
            }
        }
        /* Check for win condition */
        for (i = 0; i < BOARD_SIZE; i++) {
            for (j = 0; j < BOARD_SIZE; j++) {
                if (board[i][j] == -1) {
                    return 0; /* Game in progress */
                }
            }
        }
        return 1; /* Game over */
    }
}

/* Display the location of the mines and end the game */
void game_over(int board[][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == -2) {
                board[i][j] = 9;
            }
        }
    }
}

/* Count the number of adjacent mines */
int count_adjacent_mines(int board[][BOARD_SIZE], struct coord location) {
    int i, j, count = 0;
    for (i = -1; i <= 1; i++) {
        for (j = -1; j <= 1; j++) {
            if (location.x+i > 0 && location.x+i <= BOARD_SIZE &&
                location.y+j > 0 && location.y+j <= BOARD_SIZE &&
                board[location.x+i-1][location.y+j-1] == -2) {
                count++;
            }
        }
    }
    return count;
}