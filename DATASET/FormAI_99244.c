//FormAI DATASET v1.0 Category: Chess AI ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define BOARD_SIZE 8
#define MAX_MOVES 200

typedef struct {
    int x;
    int y;
} pos_t;

typedef struct {
    pos_t start;
    pos_t end;
    int score;
} move_t;

void print_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    printf("\n  A B C D E F G H\n");
    printf("-----------------\n");
    for(int i = 0; i < BOARD_SIZE; i++) {
        printf("%d|", i+1);
        for(int j = 0; j < BOARD_SIZE; j++) {
            printf("%d ", board[i][j]);
        }
        printf("|\n");
    }
    printf("-----------------\n");
}

void initialize_board(int board[BOARD_SIZE][BOARD_SIZE]) {
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = 0;
        }
    }
}

int get_random_number(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

pos_t get_random_position() {
    pos_t p;
    p.x = get_random_number(0, BOARD_SIZE-1);
    p.y = get_random_number(0, BOARD_SIZE-1);
    return p;
}

int get_score(int board[BOARD_SIZE][BOARD_SIZE], pos_t pos) {
    int score = 0;
    int adjacent_cells[8][2] = {{-1,-1}, {-1,0}, {-1,1}, {0,-1}, {0,1}, {1,-1}, {1,0}, {1,1}};
    for(int i = 0; i < 8; i++) {
        pos_t adj_pos = {pos.x + adjacent_cells[i][0], pos.y + adjacent_cells[i][1]};
        if(adj_pos.x >= 0 && adj_pos.x < BOARD_SIZE && adj_pos.y >= 0 && adj_pos.y < BOARD_SIZE && board[adj_pos.x][adj_pos.y] == 1) {
            score++;
        }
    }
    return score;
}

move_t get_best_move(int board[BOARD_SIZE][BOARD_SIZE]) {
    move_t moves[MAX_MOVES];
    int move_count = 0;
    for(int i = 0; i < BOARD_SIZE; i++) {
        for(int j = 0; j < BOARD_SIZE; j++) {
            if(board[i][j] == 0) {
                moves[move_count].start = (pos_t){i,j};
                for(int k = 0; k < BOARD_SIZE; k++) {
                    for(int l = 0; l < BOARD_SIZE; l++) {
                        if(board[k][l] == 0) {
                            moves[move_count].end = (pos_t){k,l};
                            moves[move_count].score = get_score(board, moves[move_count].end);
                            move_count++;
                        }
                    }
                }
            }
        }
    }
    int best_score = -1;
    int best_move_index = -1;
    for(int i = 0; i < move_count; i++) {
        if(moves[i].score > best_score) {
            best_score = moves[i].score;
            best_move_index = i;
        }
    }
    return moves[best_move_index];
}

int main() {
    int board[BOARD_SIZE][BOARD_SIZE];
    initialize_board(board);
    int move_count = 0;
    print_board(board);
    while(move_count < MAX_MOVES) {
        printf("\nMove %d:\n", move_count+1);
        move_t best_move = get_best_move(board);
        board[best_move.end.x][best_move.end.y] = 1;
        board[best_move.start.x][best_move.start.y] = 2;
        print_board(board);
        move_count++;
    }
    return 0;
}