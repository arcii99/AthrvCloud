//FormAI DATASET v1.0 Category: Checkers Game ; Style: calm
#include <stdio.h>
#include <stdlib.h>

#define DIMENSION 8

// a struct to represent a checker piece
typedef struct Checker {
    int x; // x-coordinate on the board
    int y; // y-coordinate on the board
    int is_king; // indicates if the piece is a king or not
    char symbol; // the symbol that represents the piece on the board
} Checker;

int is_valid_move(Checker *piece, int to_x, int to_y, Checker board[DIMENSION][DIMENSION]);
void make_move(Checker *piece, int to_x, int to_y, Checker board[DIMENSION][DIMENSION]);

int main(void) {
    int i, j;
    Checker board[DIMENSION][DIMENSION];
    
    // initialize the board with empty spaces
    for(i = 0; i < DIMENSION; i++) {
        for(j = 0; j < DIMENSION; j++) {
            board[i][j].x = i;
            board[i][j].y = j;
            board[i][j].is_king = 0;
            board[i][j].symbol = '_';
        }
    }
    
    // place the starting pieces
    for(i = 0; i < DIMENSION; i += 2) {
        board[i][0].symbol = 'x';
        board[i+1][1].symbol = 'x';
        board[i][2].symbol = 'x';
        
        board[i+1][DIMENSION-1].symbol = 'o';
        board[i][DIMENSION-2].symbol = 'o';
        board[i+1][DIMENSION-3].symbol = 'o';
    }
    
    // play the game
    int turn = 0; // 0 for player 1, 1 for player 2
    int from_x, from_y, to_x, to_y;
    Checker *selected_piece;
    while(1) {
        // output the board
        for(i = 0; i < DIMENSION; i++) {
            for(j = 0; j < DIMENSION; j++) {
                printf("%c ", board[j][i].symbol);
            }
            printf("\n");
        }
        
        // ask for player input
        printf("Player %d's turn:\n", turn+1);
        printf("Enter the x-coordinate of the piece you want to move: ");
        scanf("%d", &from_x);
        printf("Enter the y-coordinate of the piece you want to move: ");
        scanf("%d", &from_y);
        selected_piece = &board[from_x][from_y];
        
        // make sure the selected piece belongs to the current player
        if(selected_piece->symbol == '_' || (selected_piece->symbol == 'x' && turn == 1) || (selected_piece->symbol == 'o' && turn == 0)) {
            printf("Invalid piece selection.\n");
            continue;
        }
        
        printf("Enter the x-coordinate of the square you want to move to: ");
        scanf("%d", &to_x);
        printf("Enter the y-coordinate of the square you want to move to: ");
        scanf("%d", &to_y);
        
        // make sure the move is valid
        if(!is_valid_move(selected_piece, to_x, to_y, board)) {
            printf("Invalid move.\n");
            continue;
        }
        
        // execute the move
        make_move(selected_piece, to_x, to_y, board);
        
        // check for king status
        if(selected_piece->symbol == 'x' && selected_piece->y == DIMENSION-1) {
            selected_piece->is_king = 1;
            selected_piece->symbol = 'X';
        }
        else if(selected_piece->symbol == 'o' && selected_piece->y == 0) {
            selected_piece->is_king = 1;
            selected_piece->symbol = 'O';
        }
        
        // check for game over
        int player1_count = 0, player2_count = 0;
        for(i = 0; i < DIMENSION; i++) {
            for(j = 0; j < DIMENSION; j++) {
                if(board[i][j].symbol == 'x' || board[i][j].symbol == 'X') player1_count++;
                else if(board[i][j].symbol == 'o' || board[i][j].symbol == 'O') player2_count++;
            }
        }
        if(player1_count == 0 || player2_count == 0) {
            printf("Player %d wins!\n", player1_count > player2_count ? 1 : 2);
            break;
        }
        
        // switch turns
        turn = turn == 0 ? 1 : 0;
    }
    
    return 0;
}

// checks if the move is valid
int is_valid_move(Checker *piece, int to_x, int to_y, Checker board[DIMENSION][DIMENSION]) {
    // check if the move is within the board bounds
    if(to_x < 0 || to_x >= DIMENSION || to_y < 0 || to_y >= DIMENSION) {
        return 0;
    }
    
    // check if the square is already occupied
    if(board[to_x][to_y].symbol != '_') {
        return 0;
    }
    
    // check if it's a normal move
    if(to_x == piece->x+1 || to_x == piece->x-1) {
        if(piece->is_king) {
            if(to_y == piece->y+1 || to_y == piece->y-1) {
                return 1;
            }
        }
        else {
            if(to_y == piece->y+(piece->symbol == 'x' ? 1 : -1)) {
                return 1;
            }
        }
    }
    // check if it's a capture move
    else if(to_x == piece->x+2 || to_x == piece->x-2) {
        if(piece->is_king) {
            if(to_y == piece->y+2 || to_y == piece->y-2) {
                // check if there's a piece to capture
                if(to_x > piece->x && to_y > piece->y) {
                    if(board[piece->x+1][piece->y+1].symbol == (piece->symbol == 'x' ? 'o' : 'x') ||
                       board[piece->x+1][piece->y+1].symbol == (piece->symbol == 'X' ? 'o' : 'x')) {
                        return 1;
                    }
                }
                else if(to_x > piece->x && to_y < piece->y) {
                    if(board[piece->x+1][piece->y-1].symbol == (piece->symbol == 'x' ? 'o' : 'x') ||
                       board[piece->x+1][piece->y-1].symbol == (piece->symbol == 'X' ? 'o' : 'x')) {
                        return 1;
                    }
                }
                else if(to_x < piece->x && to_y > piece->y) {
                    if(board[piece->x-1][piece->y+1].symbol == (piece->symbol == 'x' ? 'o' : 'x') ||
                       board[piece->x-1][piece->y+1].symbol == (piece->symbol == 'X' ? 'o' : 'x')) {
                        return 1;
                    }
                }
                else if(to_x < piece->x && to_y < piece->y) {
                    if(board[piece->x-1][piece->y-1].symbol == (piece->symbol == 'x' ? 'o' : 'x') ||
                       board[piece->x-1][piece->y-1].symbol == (piece->symbol == 'X' ? 'o' : 'x')) {
                        return 1;
                    }
                }
            }
        }
        else {
            if(to_y == piece->y+(piece->symbol == 'x' ? 2 : -2)) {
                // check if there's a piece to capture
                if(to_x > piece->x) {
                    if(board[piece->x+1][piece->y+1].symbol == 'o' || board[piece->x+1][piece->y+1].symbol == 'O') {
                        return 1;
                    }
                }
                else if(to_x < piece->x) {
                    if(board[piece->x-1][piece->y+1].symbol == 'o' || board[piece->x-1][piece->y+1].symbol == 'O') {
                        return 1;
                    }
                }
            }
        }
    }
    
    return 0;
}

// executes the move
void make_move(Checker *piece, int to_x, int to_y, Checker board[DIMENSION][DIMENSION]) {
    board[piece->x][piece->y].symbol = '_';
    board[to_x][to_y].symbol = piece->symbol;
    piece->x = to_x;
    piece->y = to_y;
}