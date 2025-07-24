//FormAI DATASET v1.0 Category: Checkers Game ; Style: Dennis Ritchie
#include <stdio.h>

#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE] = { // Initial board setup
    {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
    {'B', ' ', 'B', ' ', 'B', ' ', 'B', ' '},
    {' ', 'B', ' ', 'B', ' ', 'B', ' ', 'B'},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {' ', ' ', ' ', ' ', ' ', ' ', ' ', ' '},
    {'R', ' ', 'R', ' ', 'R', ' ', 'R', ' '},
    {' ', 'R', ' ', 'R', ' ', 'R', ' ', 'R'},
    {'R', ' ', 'R', ' ', 'R', ' ', 'R', ' '}
};

typedef struct {
    int row;
    int col;
} Move;

void print_board() // Prints the current state of the board
{
    printf("\n   1  2  3  4  5  6  7  8\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d ", i+1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("[%c]", board[i][j]);
        }
        printf("\n");
    }
}

int is_valid_move(char player, Move start, Move end) // Returns 1 if the given move is valid, 0 otherwise
{
    // Make sure player is moving their own piece
    if(board[start.row][start.col] != player) return 0;

    int row_diff = end.row - start.row;
    int col_diff = end.col - start.col;

    // Make sure the move is diagonal and only one row/column away
    if(abs(row_diff) != 1 || abs(col_diff) != 1) return 0;

    // Make sure the end position is empty
    if(board[end.row][end.col] != ' ') return 0;

    return 1;
}

int make_move(char player) // Prompts the player for a move and updates the board accordingly
{
    int valid_move = 0;
    Move start, end;

    while(!valid_move) {
        printf("%c's turn to move.\n", player);
        printf("Enter start and end positions as row,col (e.g. 1,2 3,4): ");
        scanf("%d,%d %d,%d", &start.row, &start.col, &end.row, &end.col);

        if(start.row < 1 || start.row > 8 || start.col < 1 || start.col > 8 || end.row < 1 || end.row > 8 || end.col < 1 || end.col > 8) {
            printf("Invalid row/column number!\n");
            continue;
        }

        if(!is_valid_move(player, start, end)) {
            printf("Invalid move!\n");
            continue;
        }

        // Move is valid, update the board
        board[start.row-1][start.col-1] = ' ';
        board[end.row-1][end.col-1] = player;

        valid_move = 1;
    }

    return 0;
}

int main()
{
    char player = 'R';

    while(1) {
        print_board();
        if(make_move(player)) {
            printf("%c wins!\n", player);
            break;
        }

        // Alternate between red and black players
        if(player == 'R') player = 'B';
        else player = 'R';
    }

    return 0;
}