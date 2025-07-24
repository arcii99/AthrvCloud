//FormAI DATASET v1.0 Category: Chess engine ; Style: portable
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

#define BOARD_SIZE 8
#define MAX_MOVES 64

char board[BOARD_SIZE][BOARD_SIZE]; // game board
int ai_color = 1; // ai plays white by default

// reset the game board
void reset_board() {
    for(int i=0; i<BOARD_SIZE; i++) {
        for(int j=0; j<BOARD_SIZE; j++) {
            if(i == 1)
                board[i][j] = 'P'; // set black pawn
            else if(i == 6)
                board[i][j] = 'p'; // set white pawn
            else
                board[i][j] = ' '; // set empty cell
        }
    }
}

// print the game board
void print_board() {
    printf("-----------------\n");
    for(int i=0; i<BOARD_SIZE; i++) {
        printf("|");
        for(int j=0; j<BOARD_SIZE; j++) {
            printf("%c|", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

// get index of a given char in an array
int get_index(char arr[], int n, char c) {
    for(int i=0; i<n; i++) {
        if(arr[i] == c) {
            return i;
        }
    }
    return -1;
}

// get the available moves for a given pawn
int get_moves(char p, int row, int col, char moves[MAX_MOVES][3]) {
    int n = 0;
    int dir = (p == 'P' || p == 'R' || p == 'N' || p == 'K') ? -1 : 1; // set the direction for the pawn
    int forward_row = row + dir;
    int x_dir[8] = {-1, -1, 0, 1, 1, 1, 0, -1}; // x direction for moves
    int y_dir[8] = {0, 1, 1, 1, 0, -1, -1, -1}; // y direction for moves
    
    if(p == 'P' || p == 'p') {
        if(board[forward_row][col] == ' ') {
            moves[n][0] = row;
            moves[n][1] = col;
            moves[n][2] = forward_row;
            n++;
            int double_dir = dir * 2; // set the direction for the double move
            int double_forward_row = row + double_dir;
            if((dir == 1 && row == 6) || (dir == -1 && row == 1)) {
                if(board[double_forward_row][col] == ' ') {
                    moves[n][0] = row;
                    moves[n][1] = col;
                    moves[n][2] = double_forward_row;
                    n++;
                }
            }
        }
        
        int attack_dirs[2] = {-1, 1}; // directions to attack
        for(int i=0; i<2; i++) {
            int cur_row = row + dir;
            int cur_col = col + attack_dirs[i];
            if(cur_col < 0 || cur_col > BOARD_SIZE-1)
                continue; // skip if out of board boundary
            if(board[cur_row][cur_col] == ' ') 
                continue; // skip if the cell is empty
            
            if(get_index("pnbrqkPNBRQK", 12, board[cur_row][cur_col]) > -1) {
                moves[n][0] = row;
                moves[n][1] = col;
                moves[n][2] = cur_row;
                moves[n][3] = cur_col;
                n++;
            }
        }
    } else {
        for(int i=0; i<8; i++) {
            int cur_row = row;
            int cur_col = col;
            while(1) {
                cur_row += x_dir[i];
                cur_col += y_dir[i];
                if(cur_row < 0 || cur_row > BOARD_SIZE-1 || cur_col < 0 || cur_col > BOARD_SIZE-1)
                    break; // break if out of board boundary
                if(board[cur_row][cur_col] != ' ') {
                    if(get_index("pnbrqkPNBRQK", 12, board[cur_row][cur_col]) > -1) {
                        moves[n][0] = row;
                        moves[n][1] = col;
                        moves[n][2] = cur_row;
                        moves[n][3] = cur_col;
                        n++;
                    }
                    break;
                }
                
                moves[n][0] = row;
                moves[n][1] = col;
                moves[n][2] = cur_row;
                moves[n][3] = cur_col;
                n++;
            }
        }
    }
    
    return n;
}

// move a pawn to a given position
void move(char moves[MAX_MOVES][3], int n_moves) {
    srand(time(0)); // seed the random generator
    int index = rand() % n_moves; // get a random index from available moves
    int from_row = moves[index][0];
    int from_col = moves[index][1];
    int to_row = moves[index][2];
    int to_col = moves[index][3];
    board[to_row][to_col] = board[from_row][from_col];
    board[from_row][from_col] = ' ';
}

// simulate the game
void simulate_game() {
    reset_board(); // reset the game board
    print_board(); // print the board
    
    int ai_turn = 1; // ai takes first turn
    for(int i=0; i<MAX_MOVES; i++) {
        int n_moves = 0;
        char moves[MAX_MOVES][3];
        char player = (ai_turn == ai_color) ? 'P' : 'p'; // set the current player
        for(int j=0; j<BOARD_SIZE; j++) {
            for(int k=0; k<BOARD_SIZE; k++) {
                if(board[j][k] == player) {
                    int cur_moves = get_moves(player, j, k, moves);
                    for(int l=0; l<cur_moves; l++) {
                        moves[n_moves][0] = j;
                        moves[n_moves][1] = k;
                        n_moves++;
                    }
                }
            }
        }
        
        if(n_moves == 0) {
            printf("Game Over.\n");
            break;
        }
        
        printf("Available moves: %d\n", n_moves);
        if(ai_turn == ai_color) {
            move(moves, n_moves); // ai takes a random move
            printf("AI moves:\n");
        } else {
            int from_row, from_col, to_row, to_col;
            printf("Enter move (from_row from_col to_row to_col): ");
            scanf("%d %d %d %d", &from_row, &from_col, &to_row, &to_col);
            board[to_row][to_col] = board[from_row][from_col];
            board[from_row][from_col] = ' ';
        }
        
        print_board(); // print the board after a move
        ai_turn = (ai_turn == 0) ? 1 : 0; // toggle the turn
    }
}

int main() {
    simulate_game();
    return 0;
}