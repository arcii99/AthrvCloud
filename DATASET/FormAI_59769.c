//FormAI DATASET v1.0 Category: Chess engine ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <time.h>

#define BOARD_LENGTH 8
#define MAX_DEPTH 4

typedef struct Move {
    int start_x;
    int start_y;
    int end_x;
    int end_y;
} Move;

typedef struct Board {
    char layout[BOARD_LENGTH][BOARD_LENGTH];
} Board;

Board* create_board() {
    Board* board = malloc(sizeof(Board));
    memset(board->layout, ' ', BOARD_LENGTH * BOARD_LENGTH);
    for (int i = 0; i < BOARD_LENGTH; i++) {
        board->layout[i][1] = 'p';
        board->layout[i][6] = 'P';
    }
    board->layout[0][0] = 'r';
    board->layout[1][0] = 'n';
    board->layout[2][0] = 'b';
    board->layout[3][0] = 'q';
    board->layout[4][0] = 'k';
    board->layout[5][0] = 'b';
    board->layout[6][0] = 'n';
    board->layout[7][0] = 'r';

    board->layout[0][7] = 'R';
    board->layout[1][7] = 'N';
    board->layout[2][7] = 'B';
    board->layout[3][7] = 'Q';
    board->layout[4][7] = 'K';
    board->layout[5][7] = 'B';
    board->layout[6][7] = 'N';
    board->layout[7][7] = 'R';
    return board;
}

void free_board(Board* board) {
    if (board) free(board);
}

Board* copy_board(Board* board) {
    Board* new_board = malloc(sizeof(Board));
    memcpy(new_board->layout, board->layout, BOARD_LENGTH * BOARD_LENGTH);
    return new_board;
}

void print_board(Board* board) {
    printf("  A B C D E F G H\n");
    for (int y = BOARD_LENGTH - 1; y >= 0; y--) {
        printf("%d ", y + 1);
        for (int x = 0; x < BOARD_LENGTH; x++) {
            printf("%c ", board->layout[x][y]);
        }
        printf("%d\n", y + 1);
    }
    printf("  A B C D E F G H\n");
}

bool is_valid_move(Board* board, Move move) {
    char piece = board->layout[move.start_x][move.start_y];
    if (piece == ' ') {
        return false;
    }
    char dest_piece = board->layout[move.end_x][move.end_y];
    if (isupper(piece) == isupper(dest_piece)) {
        return false;
    }
    int x_diff = abs(move.end_x - move.start_x);
    int y_diff = abs(move.end_y - move.start_y);
    switch (piece) {
        case 'p':
        case 'P':
            if (piece == 'p' && move.end_y >= move.start_y) {
                return false;
            } else if (piece == 'P' && move.end_y <= move.start_y) {
                return false;
            }
            if (x_diff == 0) {
                if (abs(move.end_y - move.start_y) == 1 && dest_piece == ' ') {
                    return true;
                } else if (abs(move.end_y - move.start_y) == 2 && (move.start_y == 1 || move.start_y == 6)) {
                    if (dest_piece == ' ' && board->layout[move.start_x][move.start_y + (move.end_y - move.start_y) / 2] == ' ') {
                        return true;
                    }
                }
            } else if (x_diff == 1 && y_diff == 1 && dest_piece != ' ') {
                return true;
            }
            break;
        case 'r':
        case 'R':
            if (x_diff == 0) {
                int direction = move.end_y > move.start_y ? 1 : -1;
                for (int y = move.start_y + direction; y != move.end_y; y += direction) {
                    if (board->layout[move.start_x][y] != ' ') {
                        return false;
                    }
                }
                return true;
            } else if (y_diff == 0) {
                int direction = move.end_x > move.start_x ? 1 : -1;
                for (int x = move.start_x + direction; x != move.end_x; x += direction) {
                    if (board->layout[x][move.start_y] != ' ') {
                        return false;
                    }
                }
                return true;
            }
            break;
        case 'n':
        case 'N':
            if (x_diff == 2 && y_diff == 1) {
                return true;
            } else if (x_diff == 1 && y_diff == 2) {
                return true;
            }
            break;
        case 'b':
        case 'B':
            if (x_diff == y_diff) {
                int x_direction = move.end_x > move.start_x ? 1 : -1;
                int y_direction = move.end_y > move.start_y ? 1 : -1;
                for (int i = 1; i < x_diff; i++) {
                    if (board->layout[move.start_x + i * x_direction][move.start_y + i * y_direction] != ' ') {
                        return false;
                    }
                }
                return true;
            }
            break;
        case 'q':
        case 'Q':
            if (x_diff == 0 || y_diff == 0) {
                return is_valid_move(board, move);
            } else if (x_diff == y_diff) {
                return is_valid_move(board, move);
            }
            break;
        case 'k':
        case 'K':
            if ((x_diff == 1 && y_diff == 0) || (x_diff == 0 && y_diff == 1) || (x_diff == 1 && y_diff == 1)) {
                return true;
            } else if (x_diff == 2 && y_diff == 0 && move.start_y == move.end_y) {
                if (move.start_x < move.end_x) {
                    for (int x = move.start_x + 1; x < move.end_x; x++) {
                        if (board->layout[x][move.start_y] != ' ') {
                            return false;
                        }
                    }
                    if (board->layout[move.end_x][move.start_y] == 'r' && board->layout[move.end_x][move.start_y + 1] == ' ') {
                        return true;
                    }
                } else {
                    for (int x = move.start_x - 1; x > move.end_x; x--) {
                        if (board->layout[x][move.start_y] != ' ') {
                            return false;
                        }
                    }
                    if (board->layout[move.end_x][move.start_y] == 'r' && board->layout[move.end_x][move.start_y - 1] == ' ' && board->layout[move.end_x][move.start_y - 2] == ' ') {
                        return true;
                    }
                }
            }
            break;
        default:
            return false;
    }
    return false;
}

void apply_move(Board* board, Move move) {
    board->layout[move.end_x][move.end_y] = board->layout[move.start_x][move.start_y];
    board->layout[move.start_x][move.start_y] = ' ';
}

void undo_move(Board* board, Move move) {
    board->layout[move.start_x][move.start_y] = board->layout[move.end_x][move.end_y];
    board->layout[move.end_x][move.end_y] = move.end_x + move.end_y % 2 == 0 ? ' ' : '.';
}

int get_piece_value(char piece) {
    switch (piece) {
        case 'p':
            return 1;
        case 'P':
            return -1;
        case 'n':
        case 'b':
            return 3;
        case 'N':
        case 'B':
            return -3;
        case 'r':
            return 5;
        case 'R':
            return -5;
        case 'q':
            return 9;
        case 'Q':
            return -9;
        default:
            return 0;
    }
}

int evaluate_board(Board* board) {
    int score = 0;
    for (int x = 0; x < BOARD_LENGTH; x++) {
        for (int y = 0; y < BOARD_LENGTH; y++) {
            score += get_piece_value(board->layout[x][y]);
        }
    }
    return score;
}

Move get_best_move(Board* board, int current_depth, int target_depth) {
    if (current_depth == target_depth) {
        Move move;
        move.start_x = 0;
        move.start_y = 0;
        move.end_x = 0;
        move.end_y = 0;
        return move;
    }
    Move best_move;
    best_move.start_x = 0;
    best_move.start_y = 0;
    best_move.end_x = 0;
    best_move.end_y = 0;
    int best_score = isupper(board->layout[0][0]) ? -9999 : 9999;
    for (int x = 0; x < BOARD_LENGTH; x++) {
        for (int y = 0; y < BOARD_LENGTH; y++) {
            if ((isupper(board->layout[x][y]) && current_depth % 2 == 0) || (!isupper(board->layout[x][y]) && current_depth % 2 == 1)) {
                for (int move_x = 0; move_x < BOARD_LENGTH; move_x++) {
                    for (int move_y = 0; move_y < BOARD_LENGTH; move_y++) {
                        Move move;
                        move.start_x = x;
                        move.start_y = y;
                        move.end_x = move_x;
                        move.end_y = move_y;
                        if (is_valid_move(board, move)) {
                            Board* new_board = copy_board(board);
                            apply_move(new_board, move);
                            int score = evaluate_board(new_board);
                            if (current_depth == target_depth - 1) {
                                score += rand() % 10;
                            } else {
                                Move result_move = get_best_move(new_board, current_depth + 1, target_depth);
                                if (current_depth % 2 == 0 && evaluate_board(board) < evaluate_board(new_board)) {
                                    score += evaluate_board(new_board) - evaluate_board(board);
                                } else if (current_depth % 2 == 1 && evaluate_board(board) > evaluate_board(new_board)) {
                                    score -= evaluate_board(board) - evaluate_board(new_board);
                                }
                                free_board(new_board);
                            }
                            if ((isupper(board->layout[x][y]) && score > best_score) || (!isupper(board->layout[x][y]) && score < best_score)) {
                                best_move = move;
                                best_score = score;
                            }
                        }
                    }
                }
            }
        }
    }
    return best_move;
}

int main() {
    srand(time(NULL));
    Board* board = create_board();
    print_board(board);
    while (true) {
        printf("Enter move (e.g. e2e4): ");
        char input[5];
        scanf("%s", input);
        Move move;
        move.start_x = input[0] - 97;
        move.start_y = input[1] - 49;
        move.end_x = input[2] - 97;
        move.end_y = input[3] - 49;
        if (is_valid_move(board, move)) {
            apply_move(board, move);
            print_board(board);
        } else {
            printf("Invalid move\n");
        }
        Move computer_move = get_best_move(board, 0, MAX_DEPTH);
        apply_move(board, computer_move);
        printf("Computer moves: %c%d%c%d\n", computer_move.start_x + 97, computer_move.start_y + 1, computer_move.end_x + 97, computer_move.end_y + 1);
        print_board(board);
    }
    free_board(board);
    return 0;
}