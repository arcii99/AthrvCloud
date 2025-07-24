//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: detailed
#include <stdio.h>

// Function that checks if the game is over
int gameOver(char board[3][3]) {
    // Check for a horizontal win
    for (int i = 0; i < 3; i++) {
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) {
            if (board[i][0] == 'X') return -1;
            else if (board[i][0] == 'O') return 1;
        }
    }
    // Check for a vertical win
    for (int i = 0; i < 3; i++) {
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) {
            if (board[0][i] == 'X') return -1;
            else if (board[0][i] == 'O') return 1;
        }
    }
    // Check for a diagonal win
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) {
        if (board[0][0] == 'X') return -1;
        else if (board[0][0] == 'O') return 1;
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) {
        if (board[0][2] == 'X') return -1;
        else if (board[0][2] == 'O') return 1;
    }
    // Check if the game is a tie
    int count = 0;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') count++;
        }
    }
    if (count == 0) return 0;
    // Game is not over yet
    return 2;
}

// MiniMax function for the AI
int miniMax(char board[3][3], int depth, int isMaxi, int ai) {
    int score = gameOver(board);
    if (score == 1) return depth-10;
    if (score == -1) return 10-depth;
    if (score == 0) return 0;
    
    if (isMaxi) {
        int maxScore = -1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = ai;
                    int currScore = miniMax(board, depth+1, 0, ai);
                    maxScore = currScore > maxScore ? currScore : maxScore;
                    board[i][j] = ' ';
                }
            }
        }
        return maxScore;
    }
    else {
        int minScore = 1000;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[i][j] == ' ') {
                    board[i][j] = ai == 'X' ? 'O' : 'X';
                    int currScore = miniMax(board, depth+1, 1, ai);
                    minScore = currScore < minScore ? currScore : minScore;
                    board[i][j] = ' ';
                }
            }
        }
        return minScore;
    }
}

// Function for the AI to make a move
void aiMove(char board[3][3], int ai) {
    int row, col, maxScore = -1000;
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            if (board[i][j] == ' ') {
                board[i][j] = ai;
                int currScore = miniMax(board, 0, 0, ai);
                if (currScore > maxScore) {
                    maxScore = currScore;
                    row = i;
                    col = j;
                }
                board[i][j] = ' ';
            }
        }
    }
    board[row][col] = ai;
}

// Function to print the board
void printBoard(char board[3][3]) {
    printf("\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            printf(" %c ", board[i][j]);
            if (j < 2) printf("|");
        }
        if (i < 2) printf("\n-----------\n");
    }
    printf("\n");
}

// Function to check for valid input
int validInput(char board[3][3], int row, int col) {
    if (row < 0 || row > 2 || col < 0 || col > 2) {
        printf("Invalid input: out of bounds\n");
        return 0;
    }
    if (board[row][col] != ' ') {
        printf("Invalid input: position already taken\n");
        return 0;
    }
    return 1;
}

int main() {
    char board[3][3];
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            board[i][j] = ' ';
        }
    }
    printf("Welcome to Tic Tac Toe!\nYou are X and the AI is O.\n");
    printf("Enter your moves as row,column\n");
    int aiScore = 0, playerScore = 0;
    while (gameOver(board) == 2) {
        printBoard(board);
        printf("Enter your move: ");
        int row, col;
        scanf("%d,%d", &row, &col);
        if (validInput(board, row, col)) {
            board[row][col] = 'X';
            if (gameOver(board) == 2) {
                aiMove(board, 'O');
            }
        }
    }
    printBoard(board);
    int winner = gameOver(board);
    if (winner == -1) {
        printf("You win!\n");
        playerScore++;
    }
    else if (winner == 1) {
        printf("The AI wins!\n");
        aiScore++;
    }
    else if (winner == 0) {
        printf("It's a tie!\n");
    }
    printf("Player: %d\nAI: %d\n", playerScore, aiScore);

    return 0;
}