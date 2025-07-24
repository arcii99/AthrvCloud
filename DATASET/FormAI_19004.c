//FormAI DATASET v1.0 Category: Chess AI ; Style: post-apocalyptic
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define BOARD_SIZE 8

#define WHITE 0
#define BLACK 1

char board[BOARD_SIZE][BOARD_SIZE];

int whiteKx, whiteKy, blackKx, blackKy;
int turn;

void init_board(void);
void print_board(void);
int is_move_valid(int, int, int, int);
int is_in_checkmate(void);
int is_in_stalemate(void);
void move_piece(int, int, int, int);

/* Returns 1 if the move is valid. */
int is_move_valid(int from_x, int from_y, int to_x, int to_y) {
    /* Move is out of bounds */
    if (from_x < 0 || from_x > BOARD_SIZE - 1 || from_y < 0 || from_y > BOARD_SIZE - 1 
    || to_x < 0 || to_x > BOARD_SIZE - 1 || to_y < 0 || to_y > BOARD_SIZE - 1)
        return 0;

    /* Moving to current square */
    if (from_x == to_x && from_y == to_y)
        return 0;

    /* Nonexistent piece */
    if (board[from_x][from_y] == '.')
        return 0;

    /* Friendly fire */
    if ((board[from_x][from_y] < 'a' && board[to_x][to_y] < 'a') || 
        (board[from_x][from_y] > 'Z' && board[to_x][to_y] > 'Z'))
        return 0;

    int dx = (from_x < to_x ? 1 : (from_x == to_x ? 0 : -1));
    int dy = (from_y < to_y ? 1 : (from_y == to_y ? 0 : -1));
    int x = from_x + dx, y = from_y + dy;

    /* Check if path is blocked */
    while (x != to_x || y != to_y) {
        if (board[x][y] != '.')
            return 0;

        x += dx;
        y += dy;
    }


    /* Pawns */
    if (board[from_x][from_y] == 'p' || board[from_x][from_y] == 'P') {
        /* Check if pawn is moving forward */
        if ((board[from_x][from_y] == 'p' && from_x >= to_x) || (board[from_x][from_y] == 'P' && from_x <= to_x))
            return 0;

        /* Capturing */
        if (board[to_x][to_y] != '.' && ((board[from_x][from_y] < 'a' && board[to_x][to_y] >= 'a') || (board[from_x][from_y] > 'Z' && board[to_x][to_y] <= 'Z'))) {
            if (to_x == from_x + 1 || to_x == from_x - 1) {
                if (abs(to_y - from_y) != 1)
                    return 0;
            }
            else 
                return 0;
        }
        /* Non-capturing */
        else {
            /* Two squares */
            if ((board[from_x][from_y] == 'p' && from_x == 6 && to_x == 4) || (board[from_x][from_y] == 'P' && from_x == 1 && to_x == 3)) {
                if (from_y != to_y)
                    return 0;

                if (board[to_x][to_y] != '.')
                    return 0;
            }
            /* One square */
            else {
                if (to_x != from_x - 1 && to_x != from_x + 1)
                    return 0;

                if (abs(to_y - from_y) != 0)
                    return 0;
            }
        }
    }
    /* Rooks */
    else if (board[from_x][from_y] == 'r' || board[from_x][from_y] == 'R') {
        if (from_x != to_x && from_y != to_y)
            return 0;
    }
    /* Knights */
    else if (board[from_x][from_y] == 'n' || board[from_x][from_y] == 'N') {
        if (abs(to_x - from_x) != 2 || abs(to_y - from_y) != 1 || (abs(to_x - from_x) == abs(to_y - from_y)))
            return 0;
    }
    /* Bishops */
    else if (board[from_x][from_y] == 'b' || board[from_x][from_y] == 'B') {
        if (abs(to_x - from_x) != abs(to_y - from_y))
            return 0;
    }
    /* Queens */
    else if (board[from_x][from_y] == 'q' || board[from_x][from_y] == 'Q') {
        if ((from_x != to_x && from_y != to_y) && (abs(to_x - from_x) != abs(to_y - from_y)))
            return 0;
    }
    /* Kings */
    else if (board[from_x][from_y] == 'k' || board[from_x][from_y] == 'K') {
        if (abs(to_x - from_x) > 1 || abs(to_y - from_y) > 1)
            return 0;
    }
    else
        return 0;

    return 1;
}

/* Returns 1 if the current player is in checkmate. */
int is_in_checkmate(void) {
    int kx, ky;
    char c = (turn == WHITE ? 'K' : 'k');

    /* Find the current player's king */
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == c) {
                kx = i;
                ky = j;
                break;
            }
        }
    }

    /* Check if king can escape */
    for (int i = kx - 1; i <= kx + 1; i++) {
        for (int j = ky - 1; j <= ky + 1; j++) {
            if (is_move_valid(kx, ky, i, j) && board[i][j] == '.') {
                char temp = board[i][j];
                move_piece(kx, ky, i, j);

                if (!is_in_checkmate()) {
                    move_piece(i, j, kx, ky);
                    board[i][j] = temp;

                    return 0;
                }

                board[i][j] = temp;
                move_piece(i, j, kx, ky);
            }
        }
    }

    /* Check if any piece can capture the attacking piece */
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((turn == BLACK && board[i][j] >= 'A' && board[i][j] <= 'Z') || 
                (turn == WHITE && board[i][j] >= 'a' && board[i][j] <= 'z')) {
                for (int m = 0; m < BOARD_SIZE; m++) {
                    for (int n = 0; n < BOARD_SIZE; n++) {
                        if (is_move_valid(i, j, m, n)) {
                            char temp = board[m][n];
                            move_piece(i, j, m, n);

                            if (!is_in_checkmate()) {
                                move_piece(m, n, i, j);
                                board[m][n] = temp;

                                return 0;
                            }

                            board[m][n] = temp;
                            move_piece(m, n, i, j);
                        }
                    }
                }
            }
        }
    }

    return 1;
}

/* Returns 1 if the game is in stalemate */
int is_in_stalemate(void) {
    /* Find all legal moves */
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if ((turn == BLACK && board[i][j] >= 'A' && board[i][j] <= 'Z') ||
                (turn == WHITE && board[i][j] >= 'a' && board[i][j] <= 'z')) {
                for (int m = 0; m < BOARD_SIZE; m++) {
                    for (int n = 0; n < BOARD_SIZE; n++) {
                        if (is_move_valid(i, j, m, n)) {
                            char temp = board[m][n];
                            move_piece(i, j, m, n);

                            if (!is_in_checkmate()) {
                                move_piece(m, n, i, j);
                                board[m][n] = temp;

                                return 0;
                            }

                            board[m][n] = temp;
                            move_piece(m, n, i, j);
                        }
                    }
                }
            }
        }
    }

    return 1;
}

/* Moves the piece at (from_x, from_y) to (to_x, to_y) */
void move_piece(int from_x, int from_y, int to_x, int to_y) {
    /* Update kings' positions */
    if (board[from_x][from_y] == 'k') {
        blackKx = to_x;
        blackKy = to_y;
    }
    else if (board[from_x][from_y] == 'K') {
        whiteKx = to_x;
        whiteKy = to_y;
    }

    /* Move the piece */
    board[to_x][to_y] = board[from_x][from_y];
    board[from_x][from_y] = '.';
}

/* Initializes the board to the standard starting position */
void init_board(void) {
    memset(board, '.', BOARD_SIZE * BOARD_SIZE);

    /* Set up pawns */
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'p';
        board[6][i] = 'P';

    }

    /* Set up back rows */
    char back_row[] = {'r', 'n', 'b', 'q', 'k', 'b', 'n', 'r'};
    memcpy(board[0], back_row, BOARD_SIZE);
    for (int i = 0; i < BOARD_SIZE; i++)
        board[0][i] -= ('a' - 'A');
    memcpy(board[7], back_row, BOARD_SIZE);
}

/* Prints the board in a human-readable format */
void print_board(void) {
    printf("+---+---+---+---+---+---+---+---+\n");
    for (int i = 0; i < BOARD_SIZE; i++) {
        printf("|");
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf(" %c |", board[i][j]);
        }
        printf("\n+---+---+---+---+---+---+---+---+\n");
    }
    printf("\n");
}

/* Main function */
int main(void) {
    srand(time(NULL));
    printf("Welcome to Post-Apocalyptic Chess!\n");

    /* Initialize board */
    init_board();

    /* Set up king positions */
    whiteKx = 7, whiteKy = 4;
    blackKx = 0, blackKy = 4;

    /* Set up turn */
    turn = WHITE;

    /* Start the game */
    while (1) {
        print_board();

        /* Check if a king is in checkmate */
        if (is_in_checkmate()) {
            printf("%c is in checkmate! %c wins!\n", (turn == WHITE ? 'K' : 'k'), (turn == WHITE ? 'B' : 'W'));
            break;
        }

        /* Check if the game is in stalemate */
        if (is_in_stalemate()) {
            printf("Stalemate!\n");
            break;
        }

        /* Take player input */
        int from_x, from_y, to_x, to_y;
        printf("%c's turn. Enter move (e.g. a2a4): ", (turn == WHITE ? 'W' : 'B'));
        char* input = (char*) malloc(6 * sizeof(char));
        scanf("%s", input);
        from_y = input[0] - 'a';
        from_x = '8' - input[1];
        to_y = input[2] - 'a';
        to_x = '8' - input[3];

        /* Check if move is valid */
        if (!is_move_valid(from_x, from_y, to_x, to_y)) {
            printf("Invalid move. Try again.\n\n");
            continue;
        }

        /* Move piece */
        move_piece(from_x, from_y, to_x, to_y);
        if (board[to_x][to_y] == 'p' && to_x == 0) { /* Promotion */
            printf("Promote to (q, r, b, k): ");
            char c;
            scanf(" %c", &c);
            board[to_x][to_y] = c;
        }
        else if (board[to_x][to_y] == 'P' && to_x == 7) {
            printf("Promote to (Q, R, B, K): ");
            char c;
            scanf(" %c", &c);
            board[to_x][to_y] = c;
        }

        /* Switch turn */
        turn = (turn == WHITE ? BLACK : WHITE);
        free(input);
    }

    return 0;
}