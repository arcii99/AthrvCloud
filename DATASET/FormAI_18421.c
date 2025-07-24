//FormAI DATASET v1.0 Category: Checkers Game ; Style: curious
#include<stdio.h>
#include<stdlib.h>

char board[8][8]; // 2d array to store the checkers board
char player = 'W'; // starting player, 'W' for white and 'B' for black
int moves = 0; // counter to keep track of total moves made in the game

void print_board() {
    printf("   0 1 2 3 4 5 6 7\n"); // column numbers
    for(int i=0; i<8; i++) {
        printf("%d ", i); // row numbers
        for(int j=0; j<8; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
}

int check_move(int r1, int c1, int r2, int c2) {
    // checks if a move is legal
    if(board[r2][c2] != ' ' || abs(r2-r1) != abs(c2-c1) || board[r1][c1] == ' ') {
        return 0;
    }
    if(player == 'W') {
        // white player
        if(board[r1][c1] == 'W') {
            if(r2 < r1) {
                // moves one step forward
                return 0;
            }
            if(abs(r2-r1) == 1) {
                // moves one step diagonally
                return 1;
            }
            else if(abs(r2-r1) == 2) {
                // jumps over opponent's piece
                if(board[(r1+r2)/2][(c1+c2)/2] != 'B') {
                    return 0;
                }
                else {
                    return 2;
                }
            }
        }
        else if(board[r1][c1] == 'W') {
            // kinged white player
            if(abs(r2-r1) == 1) {
                // moves one step diagonally
                return 1;
            }
            else if(abs(r2-r1) == 2) {
                // jumps over opponent's piece
                if(board[(r1+r2)/2][(c1+c2)/2] != 'B' && board[(r1+r2)/2][(c1+c2)/2] != 'b') {
                    return 0;
                }
                else {
                    return 2;
                }
            }
        }
    }
    else {
        // black player
        if(board[r1][c1] == 'B') {
            if(r2 > r1) {
                // moves one step forward
                return 0;
            }
            if(abs(r2-r1) == 1) {
                // moves one step diagonally
                return 1;
            }
            else if(abs(r2-r1) == 2) { 
                // jumps over opponent's piece
                if(board[(r1+r2)/2][(c1+c2)/2] != 'W' && board[(r1+r2)/2][(c1+c2)/2] != 'w') {
                    return 0;
                }
                else {
                    return 2;
                }
            }
        }
        else if(board[r1][c1] == 'b') {
            // kinged black player
            if(abs(r2-r1) == 1) {
                // moves one step diagonally
                return 1;
            }
            else if(abs(r2-r1) == 2) {
                // jumps over opponent's piece
                if(board[(r1+r2)/2][(c1+c2)/2] != 'W' && board[(r1+r2)/2][(c1+c2)/2] != 'w') {
                    return 0;
                }
                else {
                    return 2;
                }
            }
        }
    }
    return 0;
}

void make_move() {
    int r1, c1, r2, c2;

    printf("Enter row and column of the piece you want to move: ");
    scanf("%d %d", &r1, &c1);

    printf("Enter row and column of the position you want to move to: ");
    scanf("%d %d", &r2, &c2);

    int move_type = check_move(r1, c1, r2, c2);
    if(move_type == 0) {
        printf("Invalid move, try again.\n");
        make_move();
    }
    else if(move_type == 1) {
        board[r2][c2] = board[r1][c1];
        board[r1][c1] = ' ';
        if(player == 'W' && r2 == 7) {
            // white player kinged
            board[r2][c2] = 'w';
        }
        else if(player == 'B' && r2 == 0) {
            // black player kinged
            board[r2][c2] = 'b';
        }
        player = (player == 'W' ? 'B' : 'W');
    }
    else if(move_type == 2) {
        board[r2][c2] = board[r1][c1];
        board[r1][c1] = ' ';
        board[(r1+r2)/2][(c1+c2)/2] = ' ';
        if(player == 'W' && r2 == 7) {
            // white player kinged
            board[r2][c2] = 'w';
        }
        else if(player == 'B' && r2 == 0) {
            // black player kinged
            board[r2][c2] = 'b';
        }
        player = (player == 'W' ? 'B' : 'W');
    }
    moves++;
}

int check_winner() {
    // checks if there is a winner
    int w_count = 0;
    int b_count = 0;
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if(board[i][j] == 'W' || board[i][j] == 'w') {
                w_count++;
            }
            else if(board[i][j] == 'B' || board[i][j] == 'b') {
                b_count++;
            }
        }
    }
    if(w_count == 0) {
        return -1; // black wins
    }
    if(b_count == 0) {
        return 1; // white wins
    }
    return 0; // game not over yet
}

int main() {
    // initialize the board
    for(int i=0; i<8; i++) {
        for(int j=0; j<8; j++) {
            if((i+j) % 2 == 0) {
                if(i < 3) {
                    board[i][j] = 'B';
                }
                else if(i > 4) {
                    board[i][j] = 'W';
                }
                else {
                    board[i][j] = ' ';
                }
            }
            else {
                board[i][j] = ' ';
            }
        }
    }

    printf("Welcome to Checkers game!\n");
    printf("White player starts first.\n");
    printf("Enter row and column numbers of the positions you want to move.\n");
    printf("To move diagonally, enter the row and column of the diagonal position.\n");

    while(1) {
        printf("\n");
        print_board();
        make_move();
        int winner = check_winner();
        if(winner != 0) {
            printf("\n");
            print_board();
            printf("\n");
            if(winner == 1) {
                printf("White wins!\n");
            }
            else {
                printf("Black wins!\n");
            }
            printf("Total moves made: %d\n", moves);
            break;
        }
    }

    return 0;
}