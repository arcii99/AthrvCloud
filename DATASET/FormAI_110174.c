//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define ROWS 10
#define COLS 10
#define SHIP_LENGTH 3
#define MAX_SHIPS 3

void display_board(char board[][COLS]);
void populate_board(char board[][COLS]);
int get_random_row();
int get_random_col();
int already_placed_ship(char board[][COLS], int row, int col);
void place_ship(char board[][COLS], int row, int col, int direction);
int valid_direction(char board[][COLS], int row, int col, int direction);
int player_guess(char board[][COLS], int row, int col, int *num_ships_left);

int main()
{
    char player_board[ROWS][COLS];
    char computer_board[ROWS][COLS];
    int computer_ships[MAX_SHIPS][2];
    int player_ships[MAX_SHIPS][2];
    int player_turn = 1;
    int num_computer_ships = MAX_SHIPS;
    int num_player_ships = MAX_SHIPS;
    int row, col, direction;
    int i, j;

    srand(time(NULL));

    // populate both boards with empty spaces
    populate_board(player_board);
    populate_board(computer_board);

    // place random ships on computer's board
    for (i = 0; i < MAX_SHIPS; i++) {
        do {
            row = get_random_row();
            col = get_random_col();
        } while (already_placed_ship(computer_board, row, col));

        place_ship(computer_board, row, col, rand() % 2);
        computer_ships[i][0] = row;
        computer_ships[i][1] = col;
    }

    // print player's board
    printf("Your board:\n");
    display_board(player_board);

    // place ships on player's board
    for (i = 0; i < MAX_SHIPS; i++) {
        do {
            printf("Place your %d-unit ship (Format: row column direction; 0 = horizontal, 1 = vertical): ", SHIP_LENGTH);
            scanf("%d %d %d", &row, &col, &direction);
        } while (already_placed_ship(player_board, row, col) || !valid_direction(player_board, row, col, direction));

        place_ship(player_board, row, col, direction);
        player_ships[i][0] = row;
        player_ships[i][1] = col;
    }

    // clear console and display both boards
    system("clear");
    printf("Your board:\n");
    display_board(player_board);
    printf("\nComputer's board:\n");
    display_board(computer_board);

    // game loop
    do {
        // player turn
        if (player_turn) {
            printf("\nYour turn to attack. (Format: row column)\n");
            if (player_guess(computer_board, row, col, &num_computer_ships)) {
                printf("You hit a computer's ship!\n");
                for (i = 0; i < MAX_SHIPS; i++) {
                    if (computer_ships[i][0] == row && computer_ships[i][1] == col) {
                        computer_ships[i][0] = -1;
                        computer_ships[i][1] = -1;
                        break;
                    }
                }
            } else {
                printf("You missed.\n");
            }

            if (num_computer_ships == 0) {
                printf("\nCongratulations! You won!\n");
                player_turn = 0;
                break;
            }
        }
        // computer turn
        else {
            printf("\nComputer's turn to attack.\n");
            do {
                row = get_random_row();
                col = get_random_col();
            } while (player_board[row][col] == 'X' || player_board[row][col] == 'O');

            if (player_board[row][col] == '-') {
                printf("Computer missed.\n");
                player_board[row][col] = 'O';
            } else {
                printf("Computer hit your ship!\n");
                for (i = 0; i < MAX_SHIPS; i++) {
                    if (player_ships[i][0] == row && player_ships[i][1] == col) {
                        player_ships[i][0] = -1;
                        player_ships[i][1] = -1;
                        break;
                    }
                }
                player_board[row][col] = 'X';
                num_player_ships--;
            }

            if (num_player_ships == 0) {
                printf("\nSorry, you lost.\n");
                player_turn = 0;
                break;
            }
        }

        player_turn = !player_turn;
    } while (1);

    return 0;
}

void display_board(char board[][COLS])
{
    int i, j;
    printf("   ");
    for (i = 0; i < COLS; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for (i = 0; i < ROWS; i++) {
        printf("%2d ", i);
        for (j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

void populate_board(char board[][COLS])
{
    int i, j;
    for (i = 0; i < ROWS; i++) {
        for (j = 0; j < COLS; j++) {
            board[i][j] = '-';
        }
    }
}

int get_random_row()
{
    return rand() % ROWS;
}

int get_random_col()
{
    return rand() % COLS;
}

int already_placed_ship(char board[][COLS], int row, int col)
{
    int i;
    for (i = 0; i < SHIP_LENGTH; i++) {
        if (row + i < ROWS && board[row + i][col] != '-') {
            return 1;
        }
        if (col + i < COLS && board[row][col + i] != '-') {
            return 1;
        }
        if (row - i >= 0 && board[row - i][col] != '-') {
            return 1;
        }
        if (col - i >= 0 && board[row][col - i] != '-') {
            return 1;
        }
    }
    return 0;
}

void place_ship(char board[][COLS], int row, int col, int direction)
{
    int i;
    for (i = 0; i < SHIP_LENGTH; i++) {
        board[row][col] = 'S';
        if (direction) {
            row++;
        } else {
            col++;
        }
    }
}

int valid_direction(char board[][COLS], int row, int col, int direction)
{
    int i;
    for (i = 0; i < SHIP_LENGTH; i++) {
        if (row + i >= ROWS || col + i >= COLS) {
            return 0;
        }
        if (direction) {
            if (board[row + i][col] != '-') {
                return 0;
            }
        } else {
            if (board[row][col + i] != '-') {
                return 0;
            }
        }
    }
    return 1;
}

int player_guess(char board[][COLS], int row, int col, int *num_ships_left)
{
    printf("Enter row and col to attack: ");
    scanf("%d %d", &row, &col);

    if (board[row][col] == 'S') {
        board[row][col] = 'X';
        (*num_ships_left)--;
        return 1;
    } else {
        board[row][col] = 'O';
        return 0;
    }
}