//FormAI DATASET v1.0 Category: Chess AI ; Style: Alan Touring
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// global variables
char board[8][8];
char curr_player;
int depth;

// function prototypes
int min_max(int depth, char player);
int get_score();
bool valid_move(int x1, int y1, int x2, int y2);
void make_move(int x1, int y1, int x2, int y2, char player);
void print_board();

int min_max(int depth, char player) {
    // base case
    if(depth == 0) {
        return get_score();
    }

    int max_score = -10000;
    int min_score = 10000;

    // iterate through all possible moves
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] != player) {
                continue;
            }

            for(int x = 0; x < 8; x++) {
                for(int y = 0; y < 8; y++) {
                    if(valid_move(i, j, x, y)) {
                        char temp = board[x][y];
                        make_move(i, j, x, y, player);

                        int score = min_max(depth - 1, player == 'w' ? 'b' : 'w');

                        if(player == curr_player) {
                            if(score > max_score) {
                                max_score = score;
                            }
                        } else {
                            if(score < min_score) {
                                min_score = score;
                            }
                        }

                        // undo move
                        board[i][j] = board[x][y];
                        board[x][y] = temp;
                    }
                }
            }
        }
    }

    return player == curr_player ? max_score : min_score;
}

int get_score() {
    int score = 0;

    // calculate score for current position
    for(int i = 0; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(board[i][j] == 'w') {
                score += 1;
            } else if(board[i][j] == 'b') {
                score -= 1;
            } else if(board[i][j] == 'W') {
                score += 2;
            } else if(board[i][j] == 'B') {
                score -= 2;
            }
        }
    }

    return score;
}

bool valid_move(int x1, int y1, int x2, int y2) {
    // check if move is within bounds
    if(x2 < 0 || x2 > 7 || y2 < 0 || y2 > 7) {
        return false;
    }

    // check if destination is empty
    if(board[x2][y2] != '-') {
        return false;
    }

    // check if diagonal move
    if(abs(x2 - x1) != abs(y2 - y1)) {
        return false;
    }

    // check if single move or jump move
    if(abs(x2 - x1) == 1) {
        if(board[x1][y1] == 'w' && x2 < x1) {
            return false;
        }

        if(board[x1][y1] == 'b' && x2 > x1) {
            return false;
        }

        return true;
    } else if(abs(x2 - x1) == 2) {
        int mid_x = (x1 + x2) / 2;
        int mid_y = (y1 + y2) / 2;

        if(board[mid_x][mid_y] == '-') {
            return false;
        }

        if(board[x1][y1] == 'w' && x2 < x1) {
            return false;
        }

        if(board[x1][y1] == 'b' && x2 > x1) {
            return false;
        }

        return true;
    }

    return false;
}

void make_move(int x1, int y1, int x2, int y2, char player) {
    // make move and update board
    board[x2][y2] = board[x1][y1];
    board[x1][y1] = '-';

    // check for power-up
    if((player == 'w' && x2 == 0) || (player == 'b' && x2 == 7)) {
        board[x2][y2] = player == 'w' ? 'W' : 'B';
    }
}

void print_board() {
    printf("-----------------\n");
    for(int i = 0; i < 8; i++) {
        printf("|");
        for(int j = 0; j < 8; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n-----------------\n");
    }
}

int main() {
    // initialize board
    memset(board, '-', sizeof(board));
    for(int i = 0; i < 3; i++) {
        for(int j = 0; j < 8; j++) {
            if(i % 2 == 0 && j % 2 == 1 || i % 2 == 1 && j % 2 == 0) {
                board[i][j] = 'w';
            }
        }
    }
    for(int i = 5; i < 8; i++) {
        for(int j = 0; j < 8; j++) {
            if(i % 2 == 0 && j % 2 == 1 || i % 2 == 1 && j % 2 == 0) {
                board[i][j] = 'b';
            }
        }
    }

    print_board();

    curr_player = 'w';
    depth = 2;

    // main game loop
    while(true) {
        if(curr_player == 'w') {
            printf("White's turn...\n");
        } else {
            printf("Black's turn...\n");
        }

        // get computer's move
        int max_score = -10000;
        int best_x1, best_y1, best_x2, best_y2;

        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] != curr_player) {
                    continue;
                }

                for(int x = 0; x < 8; x++) {
                    for(int y = 0; y < 8; y++) {
                        if(valid_move(i, j, x, y)) {
                            char temp = board[x][y];
                            make_move(i, j, x, y, curr_player);

                            int score = min_max(depth, curr_player == 'w' ? 'b' : 'w');

                            if(score > max_score) {
                                max_score = score;
                                best_x1 = i;
                                best_y1 = j;
                                best_x2 = x;
                                best_y2 = y;
                            }

                            // undo move
                            board[i][j] = board[x][y];
                            board[x][y] = temp;
                        }
                    }
                }
            }
        }

        // make move
        make_move(best_x1, best_y1, best_x2, best_y2, curr_player);
        printf("Computer moves %c%d to %c%d\n", 'a' + best_y1, 8 - best_x1, 'a' + best_y2, 8 - best_x2);
        print_board();

        // check for game over
        int w_count = 0;
        int b_count = 0;
        for(int i = 0; i < 8; i++) {
            for(int j = 0; j < 8; j++) {
                if(board[i][j] == 'w' || board[i][j] == 'W') {
                    w_count++;
                } else if(board[i][j] == 'b' || board[i][j] == 'B') {
                    b_count++;
                }
            }
        }
        if(w_count == 0) {
            printf("Game over! Black wins!\n");
            break;
        } else if(b_count == 0) {
            printf("Game over! White wins!\n");
            break;
        }

        curr_player = curr_player == 'w' ? 'b' : 'w';
    }

    return 0;
}