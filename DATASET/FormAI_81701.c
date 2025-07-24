//FormAI DATASET v1.0 Category: Checkers Game ; Style: protected
#include <stdio.h>
#include <stdlib.h>

#define ROWS 8
#define COLS 8

#define EMPTY  0
#define BLACK  1
#define RED    2
#define BKING  3
#define RKING  4

typedef struct {
    int row;
    int col;
} Position;

typedef struct {
    int board[ROWS][COLS];
    int turn;
} CheckersGame;

void initialize_board(CheckersGame *game) {
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(i%2 == j%2) {
                if(i < 3)
                    game->board[i][j] = BLACK;
                else if(i > 4)
                    game->board[i][j] = RED;
                else
                    game->board[i][j] = EMPTY;
            } else {
                game->board[i][j] = EMPTY;
            }
        }
    }
    game->turn = BLACK;
}

void print_board(CheckersGame game) {
    for(int i = 0; i < ROWS; i++) {
        printf("+---+---+---+---+---+---+---+---+\n");
        for(int j = 0; j < COLS; j++) {
            printf("| %d ", game.board[i][j]);
        }
        printf("|\n");
    }
    printf("+---+---+---+---+---+---+---+---+\n");
}

int is_valid_move(CheckersGame game, Position start, Position end) {
    int piece = game.board[start.row][start.col];
    int row_diff = end.row - start.row;
    int col_diff = end.col - start.col;
    int abs_row_diff = abs(row_diff);
    int abs_col_diff = abs(col_diff);
    
    if(end.row < 0 || end.row >= ROWS)
        return 0;
    if(end.col < 0 || end.col >= COLS)
        return 0;
    if(game.board[end.row][end.col] != EMPTY)
        return 0;
    if(piece == BLACK && game.turn == RED)
        return 0;
    if(piece == RED && game.turn == BLACK)
        return 0;
    
    if(piece == BLACK || piece == BKING) {
        if(row_diff == 1 && abs_col_diff == 1) {
            return 1; // single move
        } else if(row_diff == 2 && abs_col_diff == 2) {
            int jumped_row = start.row + row_diff/2;
            int jumped_col = start.col + col_diff/2;
            if(game.board[jumped_row][jumped_col] == RED || game.board[jumped_row][jumped_col] == RKING)
                return 2; // jump move
        }
    }
    
    if(piece == RED || piece == RKING) {
        if(row_diff == -1 && abs_col_diff == 1) {
            return 1; // single move
        } else if(row_diff == -2 && abs_col_diff == 2) {
            int jumped_row = start.row + row_diff/2;
            int jumped_col = start.col + col_diff/2;
            if(game.board[jumped_row][jumped_col] == BLACK || game.board[jumped_row][jumped_col] == BKING)
                return 2; // jump move
        }
    }
    
    return 0;
}

void play_move(CheckersGame *game, Position start, Position end) {
    int piece = game->board[start.row][start.col];
    game->board[start.row][start.col] = EMPTY;
    game->board[end.row][end.col] = piece;
    
    if(piece == BLACK && end.row == ROWS - 1)
        game->board[end.row][end.col] = BKING;
    if(piece == RED && end.row == 0)
        game->board[end.row][end.col] = RKING;
    
    int row_diff = end.row - start.row;
    int col_diff = end.col - start.col;
    if(abs(row_diff) == 2 && abs(col_diff) == 2) {
        int jumped_row = start.row + row_diff/2;
        int jumped_col = start.col + col_diff/2;
        game->board[jumped_row][jumped_col] = EMPTY;
    }
    game->turn = (game->turn == BLACK) ? RED : BLACK;
}

int is_game_over(CheckersGame game) {
    int black_count = 0;
    int red_count = 0;
    for(int i = 0; i < ROWS; i++) {
        for(int j = 0; j < COLS; j++) {
            if(game.board[i][j] == BLACK || game.board[i][j] == BKING)
                black_count++;
            if(game.board[i][j] == RED || game.board[i][j] == RKING)
                red_count++;
        }
    }
    if(black_count == 0 || red_count == 0)
        return 1;
    else
        return 0;
}

int main() {
    CheckersGame game;
    initialize_board(&game);
    
    while(!is_game_over(game)) {
        printf("Current turn: %s\n", (game.turn == BLACK) ? "BLACK" : "RED");
        print_board(game);
        
        Position start, end;
        printf("Enter starting row and column: ");
        scanf("%d %d", &start.row, &start.col);
        printf("Enter ending row and column: ");
        scanf("%d %d", &end.row, &end.col);
        
        int move_type = is_valid_move(game, start, end);
        if(move_type == 0) {
            printf("Invalid move. Try again.\n");
            continue;
        } else if(move_type == 2) {
            play_move(&game, start, end);
            printf("Jump move made.\n");
        } else {
            play_move(&game, start, end);
        }
    }
    
    printf("Game Over.\n");
    print_board(game);
    printf("Winner: %s\n", (game.turn == BLACK) ? "RED" : "BLACK");
    
    return 0;
}