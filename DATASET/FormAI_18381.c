//FormAI DATASET v1.0 Category: Chess engine ; Style: multivariable
#include <stdio.h>
#include <stdlib.h>

/* Constants */
#define EMPTY_CELL '-'
#define BOARD_SIZE 8

/* Global Variables */
char board[BOARD_SIZE][BOARD_SIZE];
char color;
char in_check;
int king_x, king_y;

/* Function Declarations */
void printBoard();
void initializeBoard();
int inBounds(int x, int y);
int check(char color);
int inCheckMove(int start_x, int start_y, int end_x, int end_y);
int movePiece(char start_x, char start_y, char end_x, char end_y);
int parseInput(char* input, int num_chars, char* start_x, char* start_y,
               char* end_x, char* end_y);

int main() {
    printf("\nCHESS\n\n");

    initializeBoard();
    color = 'w';
    printBoard();

    int gameover = 0;
    while (!gameover) {
        char input[6];
        fgets(input, 6, stdin);
        char start_x, start_y, end_x, end_y;
        int num_chars = sscanf(input, "%c%c %c%c", &start_x, &start_y,
                               &end_x, &end_y);
        if (num_chars != 4) {
            printf("Invalid input. Please try again.\n");
            continue;
        }

        if (movePiece(start_x, start_y, end_x, end_y)) {
            color = (color == 'w' ? 'b' : 'w');
            printBoard();

            in_check = check(color);
            if (in_check) {
                printf("%c is in check.\n", color);
                gameover = 1;
            }
        }
        else {
            printf("Invalid move. Please try again.\n");
        }
    }

    return 0;
}

void initializeBoard() {
    // Set all board cells to empty spaces
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            board[i][j] = EMPTY_CELL;
        }
    }

    // Add pawns
    for (int i = 0; i < BOARD_SIZE; i++) {
        board[1][i] = 'p';
        board[6][i] = 'P';
    }

    // Add rooks
    board[0][0] = 'r';
    board[0][7] = 'r';
    board[7][0] = 'R';
    board[7][7] = 'R';

    // Add knights
    board[0][1] = 'n';
    board[0][6] = 'n';
    board[7][1] = 'N';
    board[7][6] = 'N';

    // Add bishops
    board[0][2] = 'b';
    board[0][5] = 'b';
    board[7][2] = 'B';
    board[7][5] = 'B';

    // Add queens
    board[0][3] = 'q';
    board[7][3] = 'Q';

    // Add kings
    board[0][4] = 'k';
    board[7][4] = 'K';

    king_x = 0;
    king_y = 4;
}

void printBoard() {
    printf("\n");
    for (int i = BOARD_SIZE - 1; i >= 0; i--) {
        printf("%d ", i+1);
        for (int j = 0; j < BOARD_SIZE; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
    printf("  A B C D E F G H\n\n");
}

int inBounds(int x, int y) {
    return x >= 0 && x < BOARD_SIZE && y >= 0 && y < BOARD_SIZE;
}

int check(char color) {
    // Find the location of the king
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] == (color == 'w' ? 'K' : 'k')) {
                king_x = i;
                king_y = j;
            }
        }
    }

    // Check for any piece that is attacking the king
    for (int i = 0; i < BOARD_SIZE; i++) {
        for (int j = 0; j < BOARD_SIZE; j++) {
            if (board[i][j] != EMPTY_CELL && board[i][j] != 'k' &&
                board[i][j] != 'K' && board[i][j] != (color == 'w' ? 'b' : 'B')) {
                int in_check = inCheckMove(i, j, king_x, king_y);
                if (in_check) {
                    return 1;
                }
            }
        }
    }

    return 0;
}

int inCheckMove(int start_x, int start_y, int end_x, int end_y) {
    int result = movePiece(start_x, start_y, end_x, end_y);
    if (result) {
        board[end_x][end_y] = board[start_x][start_y];
        board[start_x][start_y] = EMPTY_CELL;

        if (board[end_x][end_y] == 'K' || board[end_x][end_y] == 'k') {
            king_x = end_x;
            king_y = end_y;
        }
    }
    return result;
}

int movePiece(char start_x, char start_y, char end_x, char end_y) {
    int x1 = start_x - '1';
    int y1 = start_y - 'A';
    int x2 = end_x - '1';
    int y2 = end_y - 'A';

    if (!inBounds(x1, y1) || !inBounds(x2, y2)) {
        return 0;
    }

    if (board[x1][y1] == EMPTY_CELL) {
        return 0;
    }

    if (color == 'w' && board[x1][y1] >= 'a' && board[x1][y1] <= 'z') {
        return 0;
    }

    if (color == 'b' && board[x1][y1] >= 'A' && board[x1][y1] <= 'Z') {
        return 0;
    }

    // Check if a piece is in the end position
    if (board[x2][y2] != EMPTY_CELL) {
        if (color == 'w' && board[x2][y2] >= 'A' && board[x2][y2] <= 'Z') {
            return 0;
        }
        if (color == 'b' && board[x2][y2] >= 'a' && board[x2][y2] <= 'z') {
            return 0;
        }
    }

    // Check if the piece can make the move
    switch (board[x1][y1]) {
        case 'p': // pawn
            if (color == 'w') {
                if (y2 == y1 && x2 == x1 + 1 && board[x2][y2] == EMPTY_CELL) {
                    board[x2][y2] = 'P';
                    board[x1][y1] = EMPTY_CELL;
                    return 1;
                }
                else if (y2 == y1 + 1 && x2 == x1 + 1 &&
                         board[x2][y2] >= 'A' && board[x2][y2] <= 'Z') {
                    board[x2][y2] = 'P';
                    board[x1][y1] = EMPTY_CELL;
                    return 1;
                }
            }
            else {
                if (y2 == y1 && x2 == x1 - 1 && board[x2][y2] == EMPTY_CELL) {
                    board[x2][y2] = 'p';
                    board[x1][y1] = EMPTY_CELL;
                    return 1;
                }
                else if (y2 == y1 - 1 && x2 == x1 - 1 &&
                         board[x2][y2] >= 'a' && board[x2][y2] <= 'z') {
                    board[x2][y2] = 'p';
                    board[x1][y1] = EMPTY_CELL;
                    return 1;
                }
            }
            break;
        case 'r': // rook
            if (x1 == x2 || y1 == y2) {
                int inc = (x1 == x2 ? (y2 - y1 > 0 ? 1 : -1) : (x2 - x1 > 0 ? 1 : -1));
                int i, j;
                for (i = x1 + (x1 == x2 ? inc : 0), j = y1 + (y1 == y2 ? inc : 0);
                     i != x2 || j != y2; i += (x1 == x2 ? inc : 0), j += (y1 == y2 ? inc : 0)) {
                    if (board[i][j] != EMPTY_CELL) {
                        return 0;
                    }
                }
                board[x2][y2] = 'r';
                board[x1][y1] = EMPTY_CELL;
                return 1;
            }
            break;
        case 'n': // knight
            if ((x2 == x1+2 || x2 == x1-2) && (y2 == y1+1 || y2 == y1-1)) {
                board[x2][y2] = 'n';
                board[x1][y1] = EMPTY_CELL;
                return 1;
            }
            else if ((x2 == x1+1 || x2 == x1-1) && (y2 == y1+2 || y2 == y1-2)) {
                board[x2][y2] = 'n';
                board[x1][y1] = EMPTY_CELL;
                return 1;
            }
            break;
        case 'b': // bishop
            if (abs(x2 - x1) == abs(y2 - y1)) {
                int inc_x = (x2 - x1 > 0 ? 1 : -1);
                int inc_y = (y2 - y1 > 0 ? 1 : -1);
                int i, j;
                for (i = x1 + inc_x, j = y1 + inc_y;
                     i != x2 && j != y2; i += inc_x, j += inc_y) {
                    if (board[i][j] != EMPTY_CELL) {
                        return 0;
                    }
                }
                board[x2][y2] = 'b';
                board[x1][y1] = EMPTY_CELL;
                return 1;
            }
            break;
        case 'q': // queen
            if (x1 == x2 || y1 == y2 || abs(x2 - x1) == abs(y2 - y1)) {
                if (x1 == x2 || y1 == y2) {
                    int inc = (x1 == x2 ? (y2 - y1 > 0 ? 1 : -1) : (x2 - x1 > 0 ? 1 : -1));
                    int i, j;
                    for (i = x1 + (x1 == x2 ? inc : 0), j = y1 + (y1 == y2 ? inc : 0);
                         i != x2 || j != y2; i += (x1 == x2 ? inc : 0), j += (y1 == y2 ? inc : 0)) {
                        if (board[i][j] != EMPTY_CELL) {
                            return 0;
                        }
                    }
                    board[x2][y2] = 'q';
                    board[x1][y1] = EMPTY_CELL;
                    return 1;
                }
                else if (abs(x2 - x1) == abs(y2 - y1)) {
                    int inc_x = (x2 - x1 > 0 ? 1 : -1);
                    int inc_y = (y2 - y1 > 0 ? 1 : -1);
                    int i, j;
                    for (i = x1 + inc_x, j = y1 + inc_y;
                         i != x2 && j != y2; i += inc_x, j += inc_y) {
                        if (board[i][j] != EMPTY_CELL) {
                            return 0;
                        }
                    }
                    board[x2][y2] = 'q';
                    board[x1][y1] = EMPTY_CELL;
                    return 1;
                }
            }
            break;
        case 'K': // white king
            if (x2 == x1 && abs(y2 - y1) == 1) {
                board[x2][y2] = 'K';
                board[x1][y1] = EMPTY_CELL;
                king_x = x2;
                king_y = y2;
                return 1;
            }
            else if (y2 == y1 && abs(x2 - x1) == 1) {
                board[x2][y2] = 'K';
                board[x1][y1] = EMPTY_CELL;
                king_x = x2;
                king_y = y2;
                return 1;
            }
            else if (abs(x2 - x1) == 1 && abs(y2 - y1) == 1) {
                board[x2][y2] = 'K';
                board[x1][y1] = EMPTY_CELL;
                king_x = x2;
                king_y = y2;
                return 1;
            }
            break;
        case 'k': // black king
            if (x2 == x1 && abs(y2 - y1) == 1) {
                board[x2][y2] = 'k';
                board[x1][y1] = EMPTY_CELL;
                king_x = x2;
                king_y = y2;
                return 1;
            }
            else if (y2 == y1 && abs(x2 - x1) == 1) {
                board[x2][y2] = 'k';
                board[x1][y1] = EMPTY_CELL;
                king_x = x2;
                king_y = y2;
                return 1;
            }
            else if (abs(x2 - x1) == 1 && abs(y2 - y1) == 1) {
                board[x2][y2] = 'k';
                board[x1][y1] = EMPTY_CELL;
                king_x = x2;
                king_y = y2;
                return 1;
            }
            break;
    }

    return 0;
}

int parseInput(char* input, int num_chars, char* start_x, char* start_y,
               char* end_x, char* end_y) {
    if (num_chars != 4) {
        return 0;
    }
    if (input[0] < '1' || input[0] > '8') {
        return 0;
    }
    if (input[1] < 'A' || input[1] > 'H') {
        return 0;
    }
    if (input[2] < '1' || input[2] > '8') {
        return 0;
    }
    if (input[3] < 'A' || input[3] > 'H') {
        return 0;
    }

    *start_x = input[0];
    *start_y = input[1];
    *end_x = input[2];
    *end_y = input[3];
    return 1;
}