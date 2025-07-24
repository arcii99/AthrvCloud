//FormAI DATASET v1.0 Category: Checkers Game ; Style: artistic
//CHECKERS GAME - ARTISTIC STYLE

#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8
#define NUM_PIECES 12

//STRUCTURE FOR EACH GAME PIECE
typedef struct Piece {
    int row;
    int col;
    char symbol;
    int is_king;
} Piece;

//DRAW THE BOARD WITH PIECES
void draw_board(Piece pieces[]) {
    char board[BOARD_SIZE][BOARD_SIZE];
    int i, j;
    for(i=0; i<BOARD_SIZE; i++) {
        for(j=0; j<BOARD_SIZE; j++) {
            board[i][j] = '-';
        }
    }
    for(i=0; i<NUM_PIECES; i++) {
        Piece piece = pieces[i];
        board[piece.row][piece.col] = piece.symbol;
    }
    printf("  ");
    for(i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
    }
    printf("\n");
    for(i=0; i<BOARD_SIZE; i++) {
        printf("%d ", i);
        for(j=0; j<BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

//MOVE A PIECE TO A NEW POSITION
void move_piece(Piece *piece, int row, int col, int is_capture) {
    piece->row = row;
    piece->col = col;
    if(row == 0 || row == BOARD_SIZE-1) {
        piece->is_king = 1;
        if(piece->symbol == 'o') {
            piece->symbol = 'O';
        }
        else {
            piece->symbol = 'X';
        }
    }
    if(is_capture) {
        printf("Piece captured!\n");
    }
}

//CHECK IF A POSITION IS VALID
int is_valid_position(int row, int col) {
    if(row >= 0 && row < BOARD_SIZE && col >= 0 && col < BOARD_SIZE) {
        return 1;
    }
    return 0;
}

//CHECK IF A MOVE IS VALID
int is_valid_move(Piece pieces[], Piece *piece, int row, int col, int is_capture) {
    if(!is_valid_position(row, col)) {
        return 0;
    }
    int d_row = row - piece->row;
    int d_col = col - piece->col;
    if(piece->is_king || piece->symbol == 'o') {
        if(abs(d_row) == 1 && abs(d_col) == 1) {
            if(!is_capture) {
                return 1;
            }
            if(is_valid_position(row+d_row, col+d_col)) {
                int i;
                for(i=0; i<NUM_PIECES; i++) {
                    Piece *other_piece = &pieces[i];
                    if(other_piece != piece && other_piece->row == row+d_row && other_piece->col == col+d_col) {
                        if(other_piece->symbol == 'X' || other_piece->is_king) {
                            return 1;
                        }
                    }
                }
            }
        }
        else if(abs(d_row) == 2 && abs(d_col) == 2) {
            int i;
            int mid_row = (piece->row + row)/2;
            int mid_col = (piece->col + col)/2;
            for(i=0; i<NUM_PIECES; i++) {
                Piece *other_piece = &pieces[i];
                if(other_piece->row == mid_row && other_piece->col == mid_col) {
                    if(other_piece->symbol == 'X' || other_piece->is_king) {
                        move_piece(other_piece, -1, -1, 1);
                        return 1;
                    }
                }
            }
        }
    }
    if(piece->is_king || piece->symbol == 'X') {
        if(abs(d_row) == 1 && abs(d_col) == 1) {
            if(!is_capture) {
                return 1;
            }
            if(is_valid_position(row+d_row, col+d_col)) {
                int i;
                for(i=0; i<NUM_PIECES; i++) {
                    Piece *other_piece = &pieces[i];
                    if(other_piece != piece && other_piece->row == row+d_row && other_piece->col == col+d_col) {
                        if(other_piece->symbol == 'o' || other_piece->is_king) {
                            return 1;
                        }
                    }
                }
            }
        }
        else if(abs(d_row) == 2 && abs(d_col) == 2) {
            int i;
            int mid_row = (piece->row + row)/2;
            int mid_col = (piece->col + col)/2;
            for(i=0; i<NUM_PIECES; i++) {
                Piece *other_piece = &pieces[i];
                if(other_piece->row == mid_row && other_piece->col == mid_col) {
                    if(other_piece->symbol == 'o' || other_piece->is_king) {
                        move_piece(other_piece, -1, -1, 1);
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

//GET USER MOVE
void get_user_move(Piece pieces[], int player) {
    int piece_index, row, col;
    int moved = 0;
    while(!moved) {
        printf("Player %d:\n", player);
        printf("Enter index of piece to move:");
        scanf("%d", &piece_index);
        printf("Enter row to move to:");
        scanf("%d", &row);
        printf("Enter column to move to:");
        scanf("%d", &col);
        Piece *piece = &pieces[piece_index];
        if(piece->symbol == 'o' && player == 1) {
            if(is_valid_move(pieces, piece, row, col, 0) || is_valid_move(pieces, piece, row, col, 1)) {
                move_piece(piece, row, col, 0);
                moved = 1;
            }
        }
        else if(piece->symbol == 'X' && player == 2) {
            if(is_valid_move(pieces, piece, row, col, 0) || is_valid_move(pieces, piece, row, col, 1)) {
                move_piece(piece, row, col, 0);
                moved = 1;
            }
        }
        if(!moved) {
            printf("Invalid move. Please try again.\n");
        }
    }
}

//CHECK IF GAME IS OVER
int game_over(Piece pieces[]) {
    int counts[2] = {0, 0};
    int i;
    for(i=0; i<NUM_PIECES; i++) {
        Piece piece = pieces[i];
        if(piece.symbol == 'o') {
            counts[0]++;
        }
        else {
            counts[1]++;
        }
    }
    if(counts[0] == 0 || counts[1] == 0) {
        return 1;
    }
    return 0;
}

//MAIN FUNCTION
int main() {
    Piece pieces[NUM_PIECES] = {
        {0, 1, 'o', 0},
        {0, 3, 'o', 0},
        {0, 5, 'o', 0},
        {0, 7, 'o', 0},
        {1, 0, 'o', 0},
        {1, 2, 'o', 0},
        {1, 4, 'o', 0},
        {1, 6, 'o', 0},
        {2, 1, 'o', 0},
        {2, 3, 'o', 0},
        {2, 5, 'o', 0},
        {2, 7, 'o', 0},
    };
    int player = 1;
    draw_board(pieces);
    while(!game_over(pieces)) {
        get_user_move(pieces, player);
        draw_board(pieces);
        if(player == 1) {
            player = 2;
        }
        else {
            player = 1;
        }
    }
    printf("Game over!\n");
    return 0;
}