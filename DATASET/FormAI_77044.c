//FormAI DATASET v1.0 Category: Checkers Game ; Style: thoughtful
#include <stdio.h>
#define BOARD_SIZE 8

char board[BOARD_SIZE][BOARD_SIZE];

/* Initialize the board with pieces */
void init_board() {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if((i+j) % 2 == 1) {
                if(i < 3) board[i][j] = 'O';
                else if(i > 4) board[i][j] = 'X';
                else board[i][j] = '-';
            } else {
                board[i][j] = ' ';
            }
        }
    }
}

/* Display the board */
void display_board() {
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        printf("%d|", BOARD_SIZE-i);
        for(j=0; j<BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n-+-----------------\n");
    }
    printf(" |a|b|c|d|e|f|g|h|\n");
}

/* Get input from user */
void get_input(int* from_row, int* from_col, int* to_row, int* to_col) {
    char from[3], to[3];
    printf("Enter move (ex. a3 b4): ");
    scanf("%s %s", from, to);
    *from_col = from[0] - 'a';
    *from_row = BOARD_SIZE - (from[1] - '0');
    *to_col = to[0] - 'a';
    *to_row = BOARD_SIZE - (to[1] - '0');
}

/* Check if move is valid */
int is_valid_move(int from_row, int from_col, int to_row, int to_col) {
    if(board[from_row][from_col] == '-') return 0;
    if(to_row < 0 || to_row >= BOARD_SIZE || to_col < 0 || to_col >= BOARD_SIZE) return 0;
    if(board[to_row][to_col] != ' ') return 0;
    if(board[from_row][from_col] == 'X') {
        if(to_row - from_row == 1 && abs(to_col - from_col) == 1) return 1;
        else if(to_row - from_row == 2 && abs(to_col - from_col) == 2) {
            int jump_row = (from_row + to_row) / 2;
            int jump_col = (from_col + to_col) / 2;
            if(board[jump_row][jump_col] == 'O') {
                board[jump_row][jump_col] = ' ';
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else if(board[from_row][from_col] == 'O') {
        if(to_row - from_row == -1 && abs(to_col - from_col) == 1) return 1;
        else if(to_row - from_row == -2 && abs(to_col - from_col) == 2) {
            int jump_row = (from_row + to_row) / 2;
            int jump_col = (from_col + to_col) / 2;
            if(board[jump_row][jump_col] == 'X') {
                board[jump_row][jump_col] = ' ';
                return 1;
            } else {
                return 0;
            }
        } else {
            return 0;
        }
    } else {
        return 0;
    }
}

/* Make the move */
void make_move(int from_row, int from_col, int to_row, int to_col) {
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
    if((to_row == 0 && board[to_row][to_col] == 'O') || (to_row == BOARD_SIZE-1 && board[to_row][to_col] == 'X')) {
        board[to_row][to_col] = toupper(board[to_row][to_col]);
    }
}

/* Check if anyone has won */
int has_won() {
    int i, j;
    int x_count = 0;
    int o_count = 0;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            if(board[i][j] == 'X' || board[i][j] == 'K') x_count++;
            else if(board[i][j] == 'O' || board[i][j] == 'k') o_count++;
        }
    }
    if(x_count == 0) return -1;
    else if(o_count == 0) return 1;
    else return 0;
}

/* Main function */
int main() {
    int from_row, from_col, to_row, to_col;
    init_board();
    display_board();
    while(1) {
        get_input(&from_row, &from_col, &to_row, &to_col);
        if(is_valid_move(from_row, from_col, to_row, to_col)) {
            make_move(from_row, from_col, to_row, to_col);
            display_board();
            int winner = has_won();
            if(winner != 0) {
                if(winner == 1) printf("O has won!\n");
                else printf("X has won!\n");
                break;
            }
        } else {
            printf("Invalid move. Try again.\n");
        }
    }
    return 0;
}