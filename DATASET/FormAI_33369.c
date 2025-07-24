//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include <stdio.h>
#include <stdlib.h>

char board[3][3];

// function to print the gameboard
void gameboard() {
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            printf("%c ", board[i][j]);
        }
        printf("\n");
    }
}

// function to check if the game is over
int gameover() {
    // check rows
    for(int i=0; i<3; i++) {
        if((board[i][0] == board[i][1]) && (board[i][1] == board[i][2]))
            return 1;
    }
    // check columns
    for(int j=0; j<3; j++) {
        if((board[0][j] == board[1][j]) && (board[1][j] == board[2][j]))
            return 1;
    }
    // check diagonals
    if((board[0][0] == board[1][1]) && (board[1][1] == board[2][2]))
        return 1;
    if((board[0][2] == board[1][1]) && (board[1][1] == board[2][0]))
        return 1;
    // check if full
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ')
                return 0;
        }
    }
    return 2;
}

// recursive function to find the best move for AI
int findBestMove(int x, int y, int depth, int isMax) {
    if(depth == 0)
        return 0;

    int score;
    int bestScore = isMax ? -100 : 100; // initialize bestScore to appropriate value based on isMax
    char player = isMax ? 'X' : 'O'; // set appropriate player based on isMax
    char opponent = isMax ? 'O' : 'X'; // set appropriate opponent based on isMax

    // place move for AI and check for gameover
    board[x][y] = player;
    int gameResult = gameover();

    // if gameover, return score based on result and depth
    if(gameResult == 1) {
        score = isMax ? 10 : -10;
        return score * depth;
    }
    else if(gameResult == 2)
        return 0;

    // recursively call findBestMove for each possible move
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                score = findBestMove(i, j, depth-1, !isMax);
                if(isMax && score > bestScore)
                    bestScore = score;
                if(!isMax && score < bestScore)
                    bestScore = score;
            }
        }
    }

    // undo move before returning bestScore
    board[x][y] = ' ';
    return bestScore;
}

// function for AI to make move
void AIMove() {
    int bestScore = -100;
    int bestX, bestY;
    int score;
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            if(board[i][j] == ' ') {
                score = findBestMove(i, j, 4, 0);
                if(score > bestScore) {
                    bestScore = score;
                    bestX = i;
                    bestY = j;
                }
            }
        }
    }
    board[bestX][bestY] = 'X';
}

// main function to run the game
int main() {
    // initialize board with empty spaces
    for(int i=0; i<3; i++) {
        for(int j=0; j<3; j++) {
            board[i][j] = ' ';
        }
    }

    printf("Welcome to Tic Tac Toe!\n");
    printf("You are 'O', AI is 'X'\n");
    int row, column;
    while(gameover() == 0) { // play until gameover
        printf("Your turn - choose a row (0-2): ");
        scanf("%d", &row);
        printf("Your turn - choose a column (0-2): ");
        scanf("%d", &column);
        if((row < 0 || row > 2) || (column < 0 || column > 2)) { // check for valid input
            printf("Invalid move, try again.\n");
            continue;
        }
        if(board[row][column] != ' ') { // check if space is already taken
            printf("That space is already taken, try again.\n");
            continue;
        }
        board[row][column] = 'O';
        AIMove();
        gameboard();
    }
    int result = gameover();
    if(result == 1) {
        printf("Game over, you lost!\n");
    }
    else if(result == 2) {
        printf("Game over, tie!\n");
    }
    else {
        printf("Error\n");
    }
    return 0;
}