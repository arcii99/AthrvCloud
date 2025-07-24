//FormAI DATASET v1.0 Category: Chess engine ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define BOARD_SIZE 8
#define MAX_DEPTH 6

// board representation
typedef struct {
    char pieces[BOARD_SIZE][BOARD_SIZE];
    int whites_move;
} Board;

// print the board
void print_board(Board *board) {
    printf("  a b c d e f g h\n");
    printf(" +----------------+\n");
    for (int y = 0; y < BOARD_SIZE; y++) {
        printf("%d|", y+1);
        for (int x = 0; x < BOARD_SIZE; x++) {
            printf("%c", board->pieces[x][y]);
            if (x < BOARD_SIZE - 1) {
                printf(" ");
            }
        }
        printf("|%d\n", y+1);
    }
    printf(" +----------------+\n");
    printf("  a b c d e f g h\n");
}

// initialize the board
void init_board(Board *board) {
    memset(board->pieces, ' ', BOARD_SIZE * BOARD_SIZE);
    board->whites_move = 1;
    board->pieces[0][0] = 'R'; board->pieces[7][0] = 'R';
    board->pieces[1][0] = 'N'; board->pieces[6][0] = 'N';
    board->pieces[2][0] = 'B'; board->pieces[5][0] = 'B';
    board->pieces[3][0] = 'Q'; board->pieces[4][0] = 'K';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->pieces[i][1] = 'P';
    }
    board->pieces[0][7] = 'r'; board->pieces[7][7] = 'r';
    board->pieces[1][7] = 'n'; board->pieces[6][7] = 'n';
    board->pieces[2][7] = 'b'; board->pieces[5][7] = 'b';
    board->pieces[3][7] = 'q'; board->pieces[4][7] = 'k';
    for (int i = 0; i < BOARD_SIZE; i++) {
        board->pieces[i][6] = 'p';
    }
}

// check if a given square is attacked by a given color
int is_attacked(Board *board, int x, int y, char color) {
    // check attacks from knights
    for (int dx = -2; dx <= 2; dx++) {
        for (int dy = -2; dy <= 2; dy++) {
            if (abs(dx) + abs(dy) == 3) {
                int nx = x + dx;
                int ny = y + dy;
                if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE) {
                    if (board->pieces[nx][ny] == (color == 'w' ? 'N' : 'n')) {
                        return 1;
                    }
                }
            }
        }
    }
    return 0;
}

// reuturn a random number in a range
int rand_range(int min, int max) {
    return min + rand() % (max - min + 1);
}

// evaluate a board position
int eval_board(Board *board) {
    int score = 0;
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            char piece = board->pieces[x][y];
            if (piece == 'P') {
                score += 100;
            } else if (piece == 'p') {
                score -= 100;
            } else if (piece == 'N') {
                score += 300;
            } else if (piece == 'n') {
                score -= 300;
            } else if (piece == 'B') {
                score += 350;
            } else if (piece == 'b') {
                score -= 350;
            } else if (piece == 'R') {
                score += 500;
            } else if (piece == 'r') {
                score -= 500;
            } else if (piece == 'Q') {
                score += 1000;
            } else if (piece == 'q') {
                score -= 1000;
            }
            if (board->whites_move) {
                if (piece == 'P' && y == 6) {
                    score -= rand_range(50, 150);
                }
                if (piece == 'K' && is_attacked(board, x, y, 'w')) {
                    score -= 600;
                }
            } else {
                if (piece == 'p' && y == 1) {
                    score += rand_range(50, 150);
                }
                if (piece == 'k' && is_attacked(board, x, y, 'b')) {
                    score += 600;
                }
            }
        }
    }
    return board->whites_move ? score : -score;
}

// minimax search with alpha-beta pruning
int minimax(Board *board, int depth, int alpha, int beta) {
    if (depth == 0) {
        return eval_board(board);
    }
    int max_score = -1000000;
    int min_score = 1000000;
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if (board->whites_move) {
                if (board->pieces[x][y] == 'P') {
                    for (int dy = -1; dy <= 1; dy += 2) {
                        int nx = x + 1;
                        int ny = y + dy;
                        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE &&
                            board->pieces[nx][ny] != ' ' && board->pieces[nx][ny] != 'P' &&
                            board->pieces[nx][ny] >= 'a' && board->pieces[nx][ny] <= 'z') {
                            // white pawn capture
                            char captured = board->pieces[nx][ny];
                            board->pieces[nx][ny] = 'P';
                            board->pieces[x][y] = ' ';
                            board->whites_move = 0;
                            int score = minimax(board, depth - 1, alpha, beta);
                            if (score < min_score) {
                                min_score = score;
                            }
                            board->pieces[x][y] = 'P';
                            board->pieces[nx][ny] = captured;
                            board->whites_move = 1;
                            if (min_score <= alpha) {
                                return min_score;
                            }
                            beta = beta < min_score ? beta : min_score;
                        }
                    }
                }
            } else {
                if (board->pieces[x][y] == 'p') {
                    for (int dy = -1; dy <= 1; dy += 2) {
                        int nx = x - 1;
                        int ny = y + dy;
                        if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE &&
                            board->pieces[nx][ny] != ' ' && board->pieces[nx][ny] != 'p' &&
                            board->pieces[nx][ny] >= 'A' && board->pieces[nx][ny] <= 'Z') {
                            // black pawn capture
                            char captured = board->pieces[nx][ny];
                            board->pieces[nx][ny] = 'p';
                            board->pieces[x][y] = ' ';
                            board->whites_move = 1;
                            int score = minimax(board, depth - 1, alpha, beta);
                            if (score > max_score) {
                                max_score = score;
                            }
                            board->pieces[x][y] = 'p';
                            board->pieces[nx][ny] = captured;
                            board->whites_move = 0;
                            if (max_score >= beta) {
                                return max_score;
                            }
                            alpha = alpha > max_score ? alpha : max_score;
                        }
                    }
                }
            }
        }
    }
    return board->whites_move ? max_score : min_score;
}

// find the best move for the current position
void make_move(Board *board) {
    int max_score = -1000000;
    int min_score = 1000000;
    int best_x = -1;
    int best_y = -1;
    for (int y = 0; y < BOARD_SIZE; y++) {
        for (int x = 0; x < BOARD_SIZE; x++) {
            if ((board->whites_move && board->pieces[x][y] >= 'A' && board->pieces[x][y] <= 'Z') ||
                (!board->whites_move && board->pieces[x][y] >= 'a' && board->pieces[x][y] <= 'z')) {
                for (int dy = -1; dy <= 1; dy++) {
                    for (int dx = -1; dx <= 1; dx++) {
                        if (dx != 0 || dy != 0) {
                            int nx = x + dx;
                            int ny = y + dy;
                            if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE &&
                                (board->pieces[nx][ny] == ' ' ||
                                (board->whites_move && board->pieces[nx][ny] >= 'a' && board->pieces[nx][ny] <= 'z') ||
                                (!board->whites_move && board->pieces[nx][ny] >= 'A' && board->pieces[nx][ny] <= 'Z'))) {
                                char captured = board->pieces[nx][ny];
                                board->pieces[nx][ny] = board->pieces[x][y];
                                board->pieces[x][y] = ' ';
                                board->whites_move = !board->whites_move;
                                int score = minimax(board, MAX_DEPTH, -1000000, 1000000);
                                if (board->whites_move && score > max_score) {
                                    max_score = score;
                                    best_x = x;
                                    best_y = y;
                                } else if (!board->whites_move && score < min_score) {
                                    min_score = score;
                                    best_x = x;
                                    best_y = y;
                                }
                                board->pieces[x][y] = board->pieces[nx][ny];
                                board->pieces[nx][ny] = captured;
                                board->whites_move = !board->whites_move;
                            }
                        }
                    }
                }
            }
        }
    }
    if (best_x != -1 && best_y != -1) {
        char enemy = board->whites_move ? 'b' : 'w';
        for (int dy = -1; dy <= 1; dy++) {
            for (int dx = -1; dx <= 1; dx++) {
                if (dx != 0 || dy != 0) {
                    int nx = best_x + dx;
                    int ny = best_y + dy;
                    if (nx >= 0 && nx < BOARD_SIZE && ny >= 0 && ny < BOARD_SIZE &&
                        board->pieces[nx][ny] == enemy) {
                        // capture enemy piece
                        board->pieces[nx][ny] = ' ';
                    }
                }
            }
        }
        board->pieces[best_x][best_y] = board->whites_move ? 'P' : 'p';
        board->whites_move = !board->whites_move;
    }
}

int main() {
    srand(42);
    Board board;
    init_board(&board);
    while (1) {
        print_board(&board);
        if (board.whites_move) {
            printf("White's turn.\n");
        } else {
            printf("Black's turn.\n");
        }
        make_move(&board);
    }
    return 0;
}