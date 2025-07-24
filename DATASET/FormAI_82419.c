//FormAI DATASET v1.0 Category: Checkers Game ; Style: Ada Lovelace
#include <stdio.h>

//Constants for board size and number of pieces
#define BOARD_SIZE 8
#define NUM_PIECES 12

//Types of pieces
#define EMPTY 0
#define BLACK 1
#define RED 2

//Struct for a position on the board
typedef struct {
    int row;
    int col;
} Position;

//Function to initialize the board
void init_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (i % 2 == j % 2) {
                if (i < 3)
                    board[i][j] = BLACK;
                else if (i > 4)
                    board[i][j] = RED;
                else
                    board[i][j] = EMPTY;
            } else {
                board[i][j] = EMPTY;
            }
        }
    }
}

//Function to print the board
void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j;
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%d", BOARD_SIZE - i);
        for (j = 0; j < BOARD_SIZE; j++) {
            switch (board[i][j]) {
                case EMPTY:
                    printf(" ");
                    break;
                case BLACK:
                    printf("B");
                    break;
                case RED:
                    printf("R");
                    break;
            }
            printf(" ");
        }
        printf("\n");
    }
    printf(" ");
    for (i = 0; i < BOARD_SIZE; i++) {
        printf("%c ", 'a' + i);
    }
    printf("\n");
}

//Function to play a turn
void play_turn(int board[BOARD_SIZE][BOARD_SIZE], int player) {
    Position start, end;
    //Get starting position from player
    printf("%s's turn (B or R). Enter starting position (letter, number): ", player == BLACK ? "Black" : "Red");
    scanf("%c,%d", &start.col, &start.row);
    getchar();
    start.row = BOARD_SIZE - start.row;
    start.col -= 'a';
    //Get ending position from player
    printf("Enter ending position (letter, number): ");
    scanf("%c,%d", &end.col, &end.row);
    getchar();
    end.row = BOARD_SIZE - end.row;
    end.col -= 'a';
    //Check if move is valid and make move if it is
    if (board[start.row][start.col] == player) {
        if (board[end.row][end.col] == EMPTY) {
            if (((player == BLACK && end.row > start.row) || (player == RED && end.row < start.row)) && abs(start.row - end.row) == 1 && abs(start.col - end.col) == 1) {
                board[start.row][start.col] = EMPTY;
                board[end.row][end.col] = player;
            } else if (((player == BLACK && end.row > start.row) || (player == RED && end.row < start.row)) && abs(start.row - end.row) == 2 && abs(start.col - end.col) == 2 && board[(start.row + end.row) / 2][(start.col + end.col) / 2] != player && board[(start.row + end.row) / 2][(start.col + end.col) / 2] != EMPTY) {
                board[start.row][start.col] = EMPTY;
                board[(start.row + end.row) / 2][(start.col + end.col) / 2] = EMPTY;
                board[end.row][end.col] = player;
            } else {
                printf("Invalid move. Try again.\n");
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    } else {
        printf("Invalid move. Try again.\n");
    }
}

//Function to check if the game is over
int game_over(int board[BOARD_SIZE][BOARD_SIZE]) {
    int i, j, black_count = 0, red_count = 0;
    for (i = 0; i < BOARD_SIZE; i++) {
        for (j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == BLACK) {
                black_count++;
            } else if (board[i][j] == RED) {
                red_count++;
            }
        }
    }
    if (black_count == 0 || red_count == 0) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    int game_over_flag = 0;
    init_board(board);
    while (!game_over_flag) {
        print_board(board);
        play_turn(board, BLACK);
        game_over_flag = game_over(board);
        if (!game_over_flag) {
            print_board(board);
            play_turn(board, RED);
            game_over_flag = game_over(board);
        }
    }
    if (game_over_flag) {
        printf("Game over!\n");
    }
    return 0;
}