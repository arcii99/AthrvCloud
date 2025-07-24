//FormAI DATASET v1.0 Category: Checkers Game ; Style: realistic
// Checkers Game Program

#include <stdio.h>
#include <stdlib.h>

#define N 8 // Board Size

// Function to initialize game board
void initialize_board(char board[][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if ((i + j) % 2 == 0) {
                if (i < 3) board[i][j] = 'x'; 
                else if (i > 4) board[i][j] = 'o';
                else board[i][j] = ' ';
            } else board[i][j] = ' ';
        }
    }
}

// Function to display board
void display_board(char board[][N]) {
    printf("\n");
    for (int i = 0; i < N; i++) {
        printf("\t %d", i);
    }
    printf("\n");
    printf("   -----------------\n");
    for (int i = 0; i < N; i++) {
        printf("%d |", i);
        for (int j = 0; j < N; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n   -----------------\n");
    }
}

// Function to check if a move is valid or not
int is_valid_move(char board[][N], int start_x, int start_y, int end_x, int end_y, char player) {
    if (board[end_x][end_y] != ' ') return 0;
    if (player == 'x') {
        if (end_x > start_x) return 0;
        if ((start_x - end_x) == 2 && (abs(start_y - end_y) == 2)) {
            if (board[start_x-1][(start_y+end_y)/2] == 'o') return 1;
            else return 0;
        }
        if ((start_x - end_x) == 1 && (abs(start_y - end_y) == 1)) return 1;
    } else {
        if (end_x < start_x) return 0;
        if ((end_x - start_x) == 2 && (abs(start_y - end_y) == 2)) {
            if (board[start_x+1][(start_y+end_y)/2] == 'x') return 1;
            else return 0;
        }
        if ((end_x - start_x) == 1 && (abs(start_y - end_y) == 1)) return 1;
    }
    return 0;
}

// Function to make a move
void make_move(char board[][N], int start_x, int start_y, int end_x, int end_y, char player) {
    board[end_x][end_y] = player;
    board[start_x][start_y] = ' ';
    if (player == 'x' && end_x == 0) board[end_x][end_y] = 'X';
    else if (player == 'o' && end_x == N-1) board[end_x][end_y] = 'O';
    if (abs(start_x - end_x) == 2 && abs(start_y - end_y) == 2) {
        board[(start_x+end_x)/2][(start_y+end_y)/2] = ' ';
    }
}

// Function to check if a player has won
int has_won(char board[][N], char player) {
    int count = 0;
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            if (board[i][j] == player || board[i][j] == (player == 'x' ? 'X' : 'O')) count++;
        }
    }
    return count == 0;
}

// Function to make a computer move
void computer_move(char board[][N], char player) {
    int start_x, start_y, end_x, end_y, found = 0;
    for (int i = 0; i < N && !found; i++) {
        for (int j = 0; j < N && !found; j++) {
            if (board[i][j] == player || board[i][j] == (player == 'x' ? 'X' : 'O')) {
                if (player == 'x') {
                    if (is_valid_move(board, i, j, i-1, j-1, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i-1;
                        end_y = j-1;
                        found = 1;
                    } else if (is_valid_move(board, i, j, i-1, j+1, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i-1;
                        end_y = j+1;
                        found = 1;
                    } else if (is_valid_move(board, i, j, i-2, j-2, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i-2;
                        end_y = j-2;
                        found = 1;
                    } else if (is_valid_move(board, i, j, i-2, j+2, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i-2;
                        end_y = j+2;
                        found = 1;
                    }
                } else {
                    if (is_valid_move(board, i, j, i+1, j-1, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i+1;
                        end_y = j-1;
                        found = 1;
                    } else if (is_valid_move(board, i, j, i+1, j+1, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i+1;
                        end_y = j+1;
                        found = 1;
                    } else if (is_valid_move(board, i, j, i+2, j-2, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i+2;
                        end_y = j-2;
                        found = 1;
                    } else if (is_valid_move(board, i, j, i+2, j+2, player)) {
                        start_x = i;
                        start_y = j;
                        end_x = i+2;
                        end_y = j+2;
                        found = 1;
                    }
                }
            }
        }
    }
    make_move(board, start_x, start_y, end_x, end_y, player);
}

int main() {
    char board[N][N];
    char player = 'x';
    int start_x, start_y, end_x, end_y, valid_move;

    initialize_board(board);
    display_board(board);

    while (!has_won(board, 'x') && !has_won(board, 'o')) {
        printf("%c's turn\n", player);
        if (player == 'o') computer_move(board, player);
        else {
            do {
                printf("Enter start_x: ");
                scanf("%d", &start_x);
                printf("Enter start_y: ");
                scanf("%d", &start_y);
                printf("Enter end_x: ");
                scanf("%d", &end_x);
                printf("Enter end_y: ");
                scanf("%d", &end_y);
                valid_move = is_valid_move(board, start_x, start_y, end_x, end_y, player);
                if (!valid_move) printf("Invalid move! Try again.\n");
            } while (!valid_move);
            make_move(board, start_x, start_y, end_x, end_y, player);
        }
        display_board(board);
        player = player == 'x' ? 'o' : 'x';
    }

    if (has_won(board, 'x')) printf("%c has won the game!\n", 'o');
    else printf("%c has won the game!\n", 'x');

    return 0;
}