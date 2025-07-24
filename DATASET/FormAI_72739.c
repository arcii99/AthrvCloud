//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: energetic
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

char board[3][3]; // Tic Tac Toe board
char player = 'X'; // First player is always 'X'.
char computer = 'O'; // The AI/computer is always 'O'.

int countEmptyBoxes() { // Count empty boxes, returns int.
    int emptyBoxes = 0;

    for(int i = 0; i < 3; ++i)
        for(int j = 0; j < 3; ++j)
            if(board[i][j] == ' ')
                ++emptyBoxes;

    return emptyBoxes;
}

bool checkVertical(char c) { // Check vertical winning combinations.
    for(int i = 0; i < 3; ++i)
        if(board[0][i] == c && board[1][i] == c && board[2][i] == c)
            return true;

    return false;
}

bool checkHorizontal(char c) { // Check horizontal winning combinations.
    for(int i = 0; i < 3; ++i)
        if(board[i][0] == c && board[i][1] == c && board[i][2] == c)
            return true;

    return false;
}

bool checkDiagonal(char c) { // Check diagonal winning combinations.
    if(board[0][0] == c && board[1][1] == c && board[2][2] == c)
        return true;
    else if(board[0][2] == c && board[1][1] == c && board[2][0] == c)
        return true;
        
    return false;
}

bool checkWinning(char c) { // Check if current player wins.
    if(checkVertical(c) == true || checkHorizontal(c) == true || checkDiagonal(c) == true)
        return true;
        
    return false;
}

void printBoard() { // Print Tic Tac Toe board.

    printf("\n\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("\t_____|_____|_____\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("\t_____|_____|_____\n");

    printf("\t     |     |     \n");
    printf("\t  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("\t     |     |     \n");

    printf("\n\n");
}

bool checkDraw() { // Check if game is draw.
    if(countEmptyBoxes() == 0 && checkWinning(player) == false && checkWinning(computer) == false) {
        printf("\n\nGame Drawn!\n\n");
        return true;
    }

    return false;
}

bool spaceIsOccupied(int row, int col) { // Check if box is already occupied.
    if(board[row][col] == ' ') {
        return false;
    }

    return true;
}

int minimax(int depth, bool isMaximizer) { // AI Function.
    if(checkWinning(computer) == true) { // AI Won.
        return 10;
    } else if(checkWinning(player) == true) { // Player Won.
        return -10;
    } else if(checkDraw() == true) { // If game is Draw.
        return 0;
    }

    int score = 0;

    if(isMaximizer == true) { // If AI's turn.
        int bestScore = -1000; // Best score is set to the minimum possible.

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] == ' ') { // If box is empty.
                    board[i][j] = computer; // Put 'O' on this box.
                    score = minimax(depth + 1, false); // Calculate score for this move.
                    board[i][j] = ' '; // Undo move.
                    if(score > bestScore) { // If score is better than the best stored score, then set new score.
                        bestScore = score;
                    }
                }
            }
        }

        return bestScore; // Return best score.
    } else { // If player's turn.
        int bestScore = 1000; // Best score is set to the maximum possible.

        for(int i = 0; i < 3; ++i) {
            for(int j = 0; j < 3; ++j) {
                if(board[i][j] == ' ') { // If box is empty.
                    board[i][j] = player; // Put 'X' on this box.
                    score = minimax(depth + 1, true); // Calculate score for this move.
                    board[i][j] = ' '; // Undo move.
                    if(score < bestScore) { // If score is better than the best stored score, then set new score.
                        bestScore = score;
                    }
                }
            }
        }

        return bestScore; // Return best score.
    }
}

void AI() { // AI's turn.
    int bestScore = -1000; // Best score is set to the minimum possible.
    int row = -1;
    int col = -1;

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            if(board[i][j] == ' ') { // If box is empty.
                board[i][j] = computer; // Put 'O' on this box.
                int score = minimax(0, false); // Calculate score for this move.
                board[i][j] = ' '; // Undo move.
                if(score > bestScore) { // If score is better than the best stored score, then set new score.
                    bestScore = score;
                    row = i;
                    col = j;
                }
            }
        }
    }

    printf("\nComputer's Move: \n");
    board[row][col] = computer; // Computer/AI played a move.
    printBoard();
}

int main(void) { // Main function.
    system("clear");
    printf("\n\n\tTic Tac Toe:\n\n");
    printf("\tPlayer: %c \n", player);
    printf("\tComputer: %c \n\n\n", computer);
    printf("\t[ NOTE: To Play, Enter Row and Column Separated by Space (Example: 1 2) ]\n\n");
    printf("\t\t\t   1     2     3  \n");
    printf("\t\t\t      |     |     \n");
    printf("\t\t\t1  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("\t\t\t _____|_____|_____\n");
    printf("\t\t\t      |     |     \n");
    printf("\t\t\t2  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("\t\t\t _____|_____|_____\n");
    printf("\t\t\t      |     |     \n");
    printf("\t\t\t3  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("\t\t\t      |     |     \n\n");

    for(int i = 0; i < 3; ++i) {
        for(int j = 0; j < 3; ++j) {
            board[i][j] = ' ';
        }
    }

    while(true) {
        int row, col;

        printf("Your Move: \n"); // Player's turn.
        scanf("%d %d", &row, &col);
        if(spaceIsOccupied(row - 1, col - 1) == true) { // Check if box is already occupied, if yes reenter box number.
            printf("Entered box is already occupied. Please Re-enter!\n");
            continue;
        }
        board[row - 1][col - 1] = player; // Player played a move.
        printBoard();

        if(checkWinning(player) == true) { // If player wins.
            printf("Congratulations! You Won.\n");
            break;
        }

        if(checkDraw() == true) { // If game is draw.
            break;
        }

        AI(); // AI's turn.

        if(checkWinning(computer) == true) { // If computer wins.
            printf("Computer Won! Better Luck Next Time.\n");
            break;
        }

        if(checkDraw() == true) { // If game is draw.
            break;
        }
    }

    return 0;
}