//FormAI DATASET v1.0 Category: Chess AI ; Style: real-life
#include <stdio.h>
#include <stdlib.h>

// define board size
#define ROWS 8
#define COLS 8

// define player colors
#define WHITE 'W'
#define BLACK 'B'

// define board array
char board[ROWS][COLS];

// function prototypes
void initBoard();
void printBoard();
void makeMove(char);
int getScore(char);
int minimax(int, int, int, int, char);

int main() {
    // initialize the board
    initBoard();
    // print the initial board
    printBoard();
    // prompt user to choose color
    printf("Choose your color (W/B): ");
    char player = getchar();
    fflush(stdin);
    // start the game
    while (1) {
        // make player move
        makeMove(player);
        // print the updated board
        printBoard();
        // check for game over conditions
        int whiteScore = getScore(WHITE);
        int blackScore = getScore(BLACK);
        if (whiteScore + blackScore == ROWS * COLS) {
            printf("Game over!\n");
            if (whiteScore > blackScore)
                printf("White wins with a score of %d-%d!\n", whiteScore, blackScore);
            else if (blackScore > whiteScore)
                printf("Black wins with a score of %d-%d!\n", blackScore, whiteScore);
            else
                printf("It's a tie with a score of %d-%d!\n", whiteScore, blackScore);
            break;
        }
        // make AI move
        char ai = player == WHITE ? BLACK : WHITE;
        printf("AI thinking...\n");
        int bestScore = -1000;
        int bestRow = -1;
        int bestCol = -1;
        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {
                if (board[i][j] == '.') {
                    int score = minimax(i, j, 1, 3, ai);
                    if (score > bestScore) {
                        bestScore = score;
                        bestRow = i;
                        bestCol = j;
                    }
                }
            }
        }
        board[bestRow][bestCol] = ai;
        printf("AI moves at %c%d.\n", bestRow + 'A', bestCol + 1);
        // print the updated board
        printBoard();
        // check for game over conditions
        whiteScore = getScore(WHITE);
        blackScore = getScore(BLACK);
        if (whiteScore + blackScore == ROWS * COLS) {
            printf("Game over!\n");
            if (whiteScore > blackScore)
                printf("White wins with a score of %d-%d!\n", whiteScore, blackScore);
            else if (blackScore > whiteScore)
                printf("Black wins with a score of %d-%d!\n", blackScore, whiteScore);
            else
                printf("It's a tie with a score of %d-%d!\n", whiteScore, blackScore);
            break;
        }
    }
    return 0;
}

// initialize the board
void initBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            board[i][j] = '.';
        }
    }
    board[3][3] = board[4][4] = WHITE;
    board[3][4] = board[4][3] = BLACK;
}

// print the board
void printBoard() {
    printf("  ");
    for (int i = 0; i < COLS; i++) {
        printf("%d ", i + 1);
    }
    printf("\n");
    for (int i = 0; i < ROWS; i++) {
        printf("%c ", i + 'A');
        for (int j = 0; j < COLS; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// make a move for the player
void makeMove(char player) {
    printf("Enter your move (e.g., A1): ");
    char input[3];
    fgets(input, 3, stdin);
    int row = input[0] - 'A';
    int col = input[1] - '1';
    if (row < 0 || row >= ROWS || col < 0 || col >= COLS || board[row][col] != '.') {
        printf("Invalid move!\n");
        makeMove(player);
        return;
    }
    board[row][col] = player;
    int flipRow, flipCol, count;
    // flip pieces in all eight directions
    count = 0;
    for (int i = row - 1; i >= 0; i--) {
        if (board[i][col] == '.') break;
        if (board[i][col] == player) {
            count = row - i - 1;
            break;
        }
    }
    for (int i = row - 1; i >= row - count; i--) {
        board[i][col] = player;
    }
    count = 0;
    for (int i = row + 1; i < ROWS; i++) {
        if (board[i][col] == '.') break;
        if (board[i][col] == player) {
            count = i - row - 1;
            break;
        }
    }
    for (int i = row + 1; i <= row + count; i++) {
        board[i][col] = player;
    }
    count = 0;
    for (int j = col - 1; j >= 0; j--) {
        if (board[row][j] == '.') break;
        if (board[row][j] == player) {
            count = col - j - 1;
            break;
        }
    }
    for (int j = col - 1; j >= col - count; j--) {
        board[row][j] = player;
    }
    count = 0;
    for (int j = col + 1; j < COLS; j++) {
        if (board[row][j] == '.') break;
        if (board[row][j] == player) {
            count = j - col - 1;
            break;
        }
    }
    for (int j = col + 1; j <= col + count; j++) {
        board[row][j] = player;
    }
    count = 0;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (board[i][j] == '.') break;
        if (board[i][j] == player) {
            count = row - i - 1;
            break;
        }
    }
    for (int i = row - 1, j = col - 1; i >= row - count && j >= col - count; i--, j--) {
        board[i][j] = player;
    }
    count = 0;
    for (int i = row - 1, j = col + 1; i >= 0 && j < COLS; i--, j++) {
        if (board[i][j] == '.') break;
        if (board[i][j] == player) {
            count = row - i - 1;
            break;
        }
    }
    for (int i = row - 1, j = col + 1; i >= row - count && j <= col + count; i--, j++) {
        board[i][j] = player;
    }
    count = 0;
    for (int i = row + 1, j = col - 1; i < ROWS && j >= 0; i++, j--) {
        if (board[i][j] == '.') break;
        if (board[i][j] == player) {
            count = i - row - 1;
            break;
        }
    }
    for (int i = row + 1, j = col - 1; i <= row + count && j >= col - count; i++, j--) {
        board[i][j] = player;
    }
    count = 0;
    for (int i = row + 1, j = col + 1; i < ROWS && j < COLS; i++, j++) {
        if (board[i][j] == '.') break;
        if (board[i][j] == player) {
            count = i - row - 1;
            break;
        }
    }
    for (int i = row + 1, j = col + 1; i <= row + count && j <= col + count; i++, j++) {
        board[i][j] = player;
    }
}

// get the score for a player
int getScore(char player) {
    int score = 0;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (board[i][j] == player) score++;
        }
    }
    return score;
}

// make a move using minimax algorithm
int minimax(int row, int col, int depth, int maxDepth, char player) {
    // make move
    char boardCopy[ROWS][COLS];
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            boardCopy[i][j] = board[i][j];
        }
    }
    boardCopy[row][col] = player;
    int flipRow, flipCol, count;
    // flip pieces in all eight directions
    count = 0;
    for (int i = row - 1; i >= 0; i--) {
        if (boardCopy[i][col] == '.') break;
        if (boardCopy[i][col] == player) {
            count = row - i - 1;
            break;
        }
    }
    for (int i = row - 1; i >= row - count; i--) {
        boardCopy[i][col] = player;
    }
    count = 0;
    for (int i = row + 1; i < ROWS; i++) {
        if (boardCopy[i][col] == '.') break;
        if (boardCopy[i][col] == player) {
            count = i - row - 1;
            break;
        }
    }
    for (int i = row + 1; i <= row + count; i++) {
        boardCopy[i][col] = player;
    }
    count = 0;
    for (int j = col - 1; j >= 0; j--) {
        if (boardCopy[row][j] == '.') break;
        if (boardCopy[row][j] == player) {
            count = col - j - 1;
            break;
        }
    }
    for (int j = col - 1; j >= col - count; j--) {
        boardCopy[row][j] = player;
    }
    count = 0;
    for (int j = col + 1; j < COLS; j++) {
        if (boardCopy[row][j] == '.') break;
        if (boardCopy[row][j] == player) {
            count = j - col - 1;
            break;
        }
    }
    for (int j = col + 1; j <= col + count; j++) {
        boardCopy[row][j] = player;
    }
    count = 0;
    for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j--) {
        if (boardCopy[i][j] == '.') break;
        if (boardCopy[i][j] == player) {
            count = row - i - 1;
            break;
        }
    }
    for (int i = row - 1, j = col - 1; i >= row - count && j >= col - count; i--, j--) {
        boardCopy[i][j] = player;
    }
    count = 0;
    for (int i = row - 1, j = col + 1; i >= 0 && j < COLS; i--, j++) {
        if (boardCopy[i][j] == '.') break;
        if (boardCopy[i][j] == player) {
            count = row - i - 1;
            break;
        }
    }
    for (int i = row - 1, j = col + 1; i >= row - count && j <= col + count; i--, j++) {
        boardCopy[i][j] = player;
    }
    count = 0;
    for (int i = row + 1, j = col - 1; i < ROWS && j >= 0; i++, j--) {
        if (boardCopy[i][j] == '.') break;
        if (boardCopy[i][j] == player) {
            count = i - row - 1;
            break;
        }
    }
    for (int i = row + 1, j = col - 1; i <= row + count && j >= col - count; i++, j--) {
        boardCopy[i][j] = player;
    }
    count = 0;
    for (int i = row + 1, j = col + 1; i < ROWS && j < COLS; i++, j++) {
        if (boardCopy[i][j] == '.') break;
        if (boardCopy[i][j] == player) {
            count = i - row - 1;
            break;
        }
    }
    for (int i = row + 1, j = col + 1; i <= row + count && j <= col + count; i++, j++) {
        boardCopy[i][j] = player;
    }
    // evaluate score
    int score = getScore(player);
    if (depth == maxDepth) {
        return score;
    }
    // make next move for other player
    char other = player == WHITE ? BLACK : WHITE;
    int bestScore = player == other ? 1000 : -1000;
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            if (boardCopy[i][j] == '.') {
                int tempScore = minimax(i, j, depth + 1, maxDepth, other);
                if ((player == WHITE && tempScore > bestScore) || (player == BLACK && tempScore < bestScore)) {
                    bestScore = tempScore;
                }
            }
        }
    }
    return score - bestScore;
}