//FormAI DATASET v1.0 Category: Checkers Game ; Style: scalable
#include <stdio.h>

#define SIZE 8

char board[SIZE][SIZE];
char player1 = 'R', player2 = 'B';

// initialize the board with pieces
void initialize_board() {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            if ((i+j)%2 == 0) {
                if (i < 3) board[i][j] = player1;
                else if (i > 4) board[i][j] = player2;
                else board[i][j] = ' ';
            }
            else board[i][j] = ' ';
        }
    }
}

// display the board
void display_board() {
    int i, j;
    printf("\n");
    for (i=0; i<SIZE; i++) {
        printf(" %d", SIZE-i);
        for (j=0; j<SIZE; j++) {
            printf("|%c", board[i][j]);
        }
        printf("|\n");
    }
    printf("  ");
    for (i=0; i<SIZE; i++) printf(" %c", 'A'+i);
    printf("\n");
}

// check if the move is valid
int is_valid_move(int x1, int y1, int x2, int y2) {
    if (x2 < 0 || x2 >= SIZE || y2 < 0 || y2 >= SIZE) return 0; // out of board
    if (board[x2][y2] != ' ') return 0; // destination is not empty
    if (board[x1][y1] == player1 || board[x1][y1] == 'x') {
        if (x2 == x1-1 && (y2 == y1-1 || y2 == y1+1)) return 1; // regular move
        if (x2 == x1-2 && (y2 == y1-2 || y2 == y1+2) && board[x1-1][(y1+y2)/2] == player2) return 2; // jump move
    }
    else if (board[x1][y1] == player2 || board[x1][y1] == 'o') {
        if (x2 == x1+1 && (y2 == y1-1 || y2 == y1+1)) return 1; // regular move
        if (x2 == x1+2 && (y2 == y1-2 || y2 == y1+2) && board[x1+1][(y1+y2)/2] == player1) return 2; // jump move
    }
    return 0; // invalid move
}

// make the move
void make_move(int x1, int y1, int x2, int y2) {
    int dx = x2 - x1, dy = y2 - y1;
    if (abs(dx) == 2 && abs(dy) == 2) {
        board[x1+dx/2][y1+dy/2] = ' '; // remove the captured piece
    }
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = ' ';
}

// check if the player has any valid moves
int has_valid_moves(char player) {
    int i, j;
    for (i=0; i<SIZE; i++) {
        for (j=0; j<SIZE; j++) {
            if (board[i][j] == player || board[i][j] == player-'A'+'a') {
                if (is_valid_move(i, j, i-1, j-1) || is_valid_move(i, j, i-1, j+1) 
                 || is_valid_move(i, j, i+1, j-1) || is_valid_move(i, j, i+1, j+1))
                    return 1; // at least one valid move found
            }
        }
    }
    return 0; // no valid moves found
}

// switch players
char switch_player(char player) {
    if (player == player1) return player2;
    else return player1;
}

// main function
int main() {
    initialize_board();
    char current_player = player1;
    int game_over = 0;
    while (!game_over) {
        display_board();
        int x1, y1, x2, y2, valid;
        printf("%c's turn.\n", current_player);
        do {
            printf("Enter a move (e.g. A3 B4): ");
            scanf("%d%d%d%d", &y1, &x1, &y2, &x2);
            x1 = SIZE-x1; x2 = SIZE-x2; // convert row number to array index
            y1--; y2--; // convert column letter to array index
            valid = is_valid_move(x1, y1, x2, y2);
            if (!valid) printf("Invalid move. Try again.\n");
        } while (!valid);
        make_move(x1, y1, x2, y2);
        if ((current_player == player1 && x2 == 0) || (current_player == player2 && x2 == SIZE-1)) {
            board[x2][y2] += 'A'-'a'; // promote the piece
        }
        if (!has_valid_moves(current_player)) {
            printf("%c has no valid move. %c wins!\n", current_player, switch_player(current_player));
            game_over = 1;
        }
        else current_player = switch_player(current_player);
    }
    return 0;
}