//FormAI DATASET v1.0 Category: Chess AI ; Style: Romeo and Juliet
#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 8

// Chess board state
int board[BOARD_SIZE][BOARD_SIZE] = {
    {-1,-2,-3,-4,-5,-3,-2,-1},
    {-6,-6,-6,-6,-6,-6,-6,-6},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {0,0,0,0,0,0,0,0},
    {6,6,6,6,6,6,6,6},
    {1,2,3,4,5,3,2,1},
};

// Piece values
int piece_values[6] = {1,5,3,3,9,0};

// Evaluation function
int evaluate_board() {
    int score = 0;
    for(int y = 0; y < BOARD_SIZE; y++) {
        for(int x = 0; x < BOARD_SIZE; x++) {
            int piece = board[y][x];
            if(piece == 0) continue;
            int abs_piece = abs(piece) - 1;
            int piece_value = piece_values[abs_piece];
            score += (piece > 0) ? piece_value : -piece_value;
        }
    }
    return score;
}

// Board drawing function
void draw_board() {
    printf("\n   A  B  C  D  E  F  G  H \n");
    printf("  +--+--+--+--+--+--+--+--+\n");
    for(int y = 0; y < BOARD_SIZE; y++) {
        printf(" %d|", BOARD_SIZE-y);
        for(int x = 0; x < BOARD_SIZE; x++) {
            int piece = board[y][x];
            if(piece == 0) {
                printf("  |");
                continue;
            }
            char symbol;
            switch(abs(piece)) {
            case 1: symbol = 'K'; break;
            case 2: symbol = 'Q'; break;
            case 3: symbol = 'R'; break;
            case 4: symbol = 'B'; break;
            case 5: symbol = 'N'; break;
            case 6: symbol = 'P'; break;
            }
            if(piece < 0) symbol = tolower(symbol);
            printf(" %c|", symbol);
        }
        printf(" %d\n", BOARD_SIZE-y);
        printf("  +--+--+--+--+--+--+--+--+\n");
    }
    printf("   A  B  C  D  E  F  G  H \n\n");
}

// Sample move generation function
int possible_moves(int _board[][BOARD_SIZE], int x, int y, int moves[][2], int* count) {
    if(_board[y][x] == 0) return 0;
    *count = 0;
    int piece = _board[y][x];
    int side = (piece > 0) ? 1 : -1;
    int abs_piece = abs(piece) - 1;
    switch(abs_piece) {
    case 0: // King
        for(int j = -1; j <= 1; j++) {
            for(int i = -1; i <= 1; i++) {
                if(j == 0 && i == 0) continue;
                if(y+j < 0 || y+j >= BOARD_SIZE) continue;
                if(x+i < 0 || x+i >= BOARD_SIZE) continue;
                if(_board[y+j][x+i]*side > 0) continue;
                moves[*count][0] = x+i;
                moves[*count][1] = y+j;
                (*count)++;
            }
        }
        break;
    }
    return *count;
}

// Sample move execution function
void make_move(int _board[][BOARD_SIZE], int start_x, int start_y, int end_x, int end_y) {
    int piece = _board[start_y][start_x];
    _board[start_y][start_x] = 0;
    _board[end_y][end_x] = piece;
}

int main() {
    // Initialize board
    draw_board();

    // Play chess game
    while(1) {
        // White turn
        printf("White's Move:\n");
        int moves[64][2];
        int move_count;
        possible_moves(board, 4, 0, moves, &move_count);
        int best_move = -1;
        int best_score = -9999;
        for(int i = 0; i < move_count; i++) {
            int new_board[BOARD_SIZE][BOARD_SIZE];
            memcpy(new_board, board, BOARD_SIZE*BOARD_SIZE*sizeof(int));
            // Execute move on new board state
            make_move(new_board, 4, 0, moves[i][0], moves[i][1]);
            int score = evaluate_board(new_board);
            if(score > best_score) {
                best_score = score;
                best_move = i;
            }
        }
        make_move(board, 4, 0, moves[best_move][0], moves[best_move][1]);
        draw_board();

        // Black turn
        printf("Black's Move:\n");
        possible_moves(board, 4, 7, moves, &move_count);
        best_move = -1;
        best_score = 9999;
        for(int i = 0; i < move_count; i++) {
            int new_board[BOARD_SIZE][BOARD_SIZE];
            memcpy(new_board, board, BOARD_SIZE*BOARD_SIZE*sizeof(int));
            // Execute move on new board state
            make_move(new_board, 4, 7, moves[i][0], moves[i][1]);
            int score = evaluate_board(new_board);
            if(score < best_score) {
                best_score = score;
                best_move = i;
            }
        }
        make_move(board, 4, 7, moves[best_move][0], moves[best_move][1]);
        draw_board();
    }

    return 0;
}