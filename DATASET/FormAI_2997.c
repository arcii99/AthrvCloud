//FormAI DATASET v1.0 Category: Checkers Game ; Style: Sherlock Holmes
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define BLACK 'B'
#define WHITE 'W'
#define EMPTY '.'

typedef struct _Position {
    int row;
    int col;
} Position;

typedef struct _Checker {
    char color;
    Position position;
    bool is_king;
} Checker;

typedef struct _Board {
    Checker checkers[8][8];
} Board;

void initialize_board(Board *board) {
    // initialize black checkers
    for (int row = 0; row < 3; row++) {
        for (int col = 0; col < 8; col++) {
            if ((row + col) % 2 == 0) {
                Checker checker = { BLACK, {row, col}, false };
                board->checkers[row][col] = checker;
            } else {
                Checker checker = { EMPTY, {row, col}, false};
                board->checkers[row][col] = checker;
            }
        }
    }

    // initialize white checkers
    for (int row = 5; row < 8; row++) {
        for (int col = 0; col < 8; col++) {            
            if ((row + col) % 2 == 0) {
                Checker checker = { WHITE, {row, col}, false };
                board->checkers[row][col] = checker;
            } else {
                Checker checker = { EMPTY, {row, col}, false};
                board->checkers[row][col] = checker;
            }
        }
    }
}

void print_board(Board board) {
    printf("   0 1 2 3 4 5 6 7\n");
    printf("  -----------------\n");

    for (int row = 0; row < 8; row++) {
        printf("%d ", row);
        for (int col = 0; col < 8; col++) {
            Checker checker = board.checkers[row][col];
            if (checker.color == EMPTY) {
                printf("|%c", checker.color);
            } else if (checker.is_king) {
                printf("|%cK", checker.color);
            } else {
                printf("|%c ", checker.color);
            }
        }
        printf("|\n");
        printf("  -----------------\n");
    }
}

bool is_valid_move(Position from, Position to) {
    int delta_row = to.row - from.row;
    int delta_col = abs(to.col - from.col);

    if (delta_row < 0 || delta_col > 2) {
        return false;
    }

    return true;
}

void move_checker(Board *board, Checker checker, Position to) {
    board->checkers[checker.position.row][checker.position.col] = (Checker) { EMPTY, checker.position, false };
    board->checkers[to.row][to.col] = checker;
    board->checkers[to.row][to.col].position = to;
}

bool game_over(Board board) {
    int black_count = 0;
    int white_count = 0;

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            Checker checker = board.checkers[row][col];
            if (checker.color == BLACK || checker.color == 'K') {
                black_count++;
            } else if (checker.color == WHITE || checker.color == 'Q') {
                white_count++;
            }
        }
    }

    return (black_count == 0 || white_count == 0);
}

Checker get_checker(Board board, int row, int col) {
    if (row < 0 || row > 7 || col < 0 || col > 7) {
        Checker checker = { EMPTY, {-1, -1}, false };
        return checker;
    }
    return board.checkers[row][col];
}

bool is_jump_move(Board board, Checker checker, Position to) {
    int delta_row = to.row - checker.position.row;
    int delta_col = to.col - checker.position.col;

    if (abs(delta_row) != 2 || abs(delta_col) != 2) {
        return false;
    }

    int jump_row = (checker.position.row + to.row) / 2;
    int jump_col = (checker.position.col + to.col) / 2;
    Checker jumped_checker = get_checker(board, jump_row, jump_col);

    if (jumped_checker.color == EMPTY || jumped_checker.color == checker.color) {
        return false;
    }

    return true;
}

bool can_jump(Board board, Checker checker) {
    if (checker.is_king) {
        // check diagonal up-left
        if (is_jump_move(board, checker, (Position) { checker.position.row - 2, checker.position.col - 2 })) {
            return true;
        }
        // check diagonal up-right
        if (is_jump_move(board, checker, (Position) { checker.position.row - 2, checker.position.col + 2 })) {
            return true;
        }
        // check diagonal down-left
        if (is_jump_move(board, checker, (Position) { checker.position.row + 2, checker.position.col - 2 })) {
            return true;
        }
        // check diagonal down-right
        if (is_jump_move(board, checker, (Position) { checker.position.row + 2, checker.position.col + 2 })) {
            return true;
        }
    } else if (checker.color == BLACK) {
        // check diagonal down-left
        if (is_jump_move(board, checker, (Position) { checker.position.row + 2, checker.position.col - 2 })) {
            return true;
        }
        // check diagonal down-right
        if (is_jump_move(board, checker, (Position) { checker.position.row + 2, checker.position.col + 2 })) {
            return true;
        }
    } else if (checker.color == WHITE) {
        // check diagonal up-left
        if (is_jump_move(board, checker, (Position) { checker.position.row - 2, checker.position.col - 2 })) {
            return true;
        }
        // check diagonal up-right
        if (is_jump_move(board, checker, (Position) { checker.position.row - 2, checker.position.col + 2 })) {
            return true;
        }
    }

    return false;
}

void process_jump_move(Board *board, Checker checker, Position to) {
    int jump_row = (checker.position.row + to.row) / 2;
    int jump_col = (checker.position.col + to.col) / 2;
    
    move_checker(board, checker, to);
    board->checkers[jump_row][jump_col] = (Checker) { EMPTY, {-1, -1}, false };
    
    while (can_jump(*board, board->checkers[to.row][to.col])) {
        printf("Jump again!\n");
        Position current_position = board->checkers[to.row][to.col].position;
        printf("Current position: %d %d\n", current_position.row, current_position.col);
        printf("Enter new position: ");
        scanf("%d %d", &to.row, &to.col);
        if (!is_valid_move(current_position, to)) {
            printf("Invalid move!\n");
            continue;
        }
        if (!is_jump_move(*board, board->checkers[to.row][to.col], to)) {
            printf("Invalid move!\n");
            continue;
        }
        process_jump_move(board, board->checkers[to.row][to.col], to);
    }
}

void process_move(Board *board, Checker checker, Position to) {
    if (is_jump_move(*board, checker, to)) {
        process_jump_move(board, checker, to);
    } else {
        move_checker(board, checker, to);
    }

    if (!checker.is_king && ((checker.color == BLACK && to.row == 7) || (checker.color == WHITE && to.row == 0))) {
        board->checkers[to.row][to.col].is_king = true;
        printf("Checker promoted to King!\n");
    }
}

void turn(Board *board, char color) {
    while (true) {
        printf("Turn: %c\n", color);
        printf("Enter position of checker to move (row col): ");
        int row, col;
        scanf("%d %d", &row, &col);

        Checker checker = get_checker(*board, row, col);
        if (checker.color == EMPTY) {
            printf("Invalid checker!\n");
            continue;
        }
        if (checker.color != color) {
            printf("Not your checker!\n");
            continue;
        }

        printf("Enter new position (row col): ");
        Position to;
        scanf("%d %d", &to.row, &to.col);

        if (!is_valid_move(checker.position, to)) {
            printf("Invalid move!\n");
            continue;
        }

        if (!is_jump_move(*board, checker, to) && can_jump(*board, checker)) {
            printf("You must jump!\n");
            continue;
        }

        process_move(board, checker, to);

        if (game_over(*board)) {
            printf("Game over!\n");
            exit(0);
        }

        if (color == BLACK) {
            color = WHITE;
        } else {
            color = BLACK;
        }
    }
}

int main() {
    printf("Welcome to Sherlock Holmes Checkers Game!\n");
    Board board;
    initialize_board(&board);
    print_board(board);
    turn(&board, BLACK);

    return 0;
}