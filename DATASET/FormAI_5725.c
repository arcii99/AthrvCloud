//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: recursive
#include<stdio.h>
#include<stdlib.h>

char gameBoard[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};

int isGameOver();
void drawBoard();
int playerTurn();
int aiTurn(int depth);
int evaluateBoard();
int minimax(int depth, int isMaximizing);

int main(){

    int currentPlayer = 1;
    int isMaximizing = 1; //1 for AI and -1 for human
    int gameOver = 0;

    while(!gameOver){
        
        drawBoard();
        
        if(currentPlayer == 1){
            playerTurn();
            isMaximizing = -1;
        }else{
            aiTurn(0);
            isMaximizing = 1;
        }

        gameOver = isGameOver();

        if(gameOver == 1){
            printf("Player 1 wins!\n");
        }else if(gameOver == -1){
            printf("AI wins!\n");
        }else{
            printf("Draw!\n");
        }

        currentPlayer = -currentPlayer;
    }

    return 0;
}

int isGameOver(){

    int i;

    //check for horizontal wins
    for(i=0;i<3;i++){
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]){
            if(gameBoard[i][0] == 'X'){
                return 1;
            }else if(gameBoard[i][0] == 'O'){
                return -1;
            }
        }
    }

    //check for vertical wins
    for(i=0;i<3;i++){
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]){
            if(gameBoard[0][i] == 'X'){
                return 1;
            }else if(gameBoard[0][i] == 'O'){
                return -1;
            }
        }
    }

    //check for diagonal wins
    if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]){
        if(gameBoard[0][0] == 'X'){
            return 1;
        }else if(gameBoard[0][0] == 'O'){
            return -1;
        }
    }

    if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]){
        if(gameBoard[0][2] == 'X'){
            return 1;
        }else if(gameBoard[0][2] == 'O'){
            return -1;
        }
    }

    //check for draw
    for(i=0;i<3;i++){
        if(gameBoard[i][0] != 'X' && gameBoard[i][0] != 'O'){
            return 0;
        }
    }

    return 2; //2 signifies draw
}

void drawBoard(){

    int i,j;

    for(i=0;i<3;i++){
        for(j=0;j<3;j++){
            printf("%c ", gameBoard[i][j]);
        }
        printf("\n");
    }

    printf("\n");
}

int playerTurn(){

    int move;
    printf("Player 1's turn\n");
    printf("Enter your move (1-9): ");
    scanf("%d", &move);

    if(move < 1 || move > 9){
        printf("Invalid move. Try again.\n");
        return playerTurn();
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    if(gameBoard[row][col] == 'X' || gameBoard[row][col] == 'O'){
        printf("Invalid move. Try again.\n");
        return playerTurn();
    }

    gameBoard[row][col] = 'X';

    return 0;
}

int aiTurn(int depth){

    int move;
    printf("AI's turn\n");

    if(depth == 0){
        move = rand() % 9 + 1;
    }else{
        move = minimax(depth, 1);
    }

    int row = (move - 1) / 3;
    int col = (move - 1) % 3;

    gameBoard[row][col] = 'O';

    return 0;
}

int evaluateBoard(){

    int i;

    //check for horizontal wins
    for(i=0;i<3;i++){
        if(gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2]){
            if(gameBoard[i][0] == 'O'){
                return 10;
            }else if(gameBoard[i][0] == 'X'){
                return -10;
            }
        }
    }

    //check for vertical wins
    for(i=0;i<3;i++){
        if(gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i]){
            if(gameBoard[0][i] == 'O'){
                return 10;
            }else if(gameBoard[0][i] == 'X'){
                return -10;
            }
        }
    }

    //check for diagonal wins
    if(gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2]){
        if(gameBoard[0][0] == 'O'){
            return 10;
        }else if(gameBoard[0][0] == 'X'){
            return -10;
        }
    }

    if(gameBoard[0][2] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][0]){
        if(gameBoard[0][2] == 'O'){
            return 10;
        }else if(gameBoard[0][2] == 'X'){
            return -10;
        }
    }

    return 0;
}

int minimax(int depth, int isMaximizing){

    int i,j;
    int score;
    int bestScore;
    int bestMove;

    int result = evaluateBoard();

    //check for win or draw
    if(result == 10 || result == -10 || result == 0){
        return result;
    }

    if(isMaximizing == 1){
        bestScore = -1000;

        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O'){
                    gameBoard[i][j] = 'O';
                    score = minimax(depth + 1, -1);
                    gameBoard[i][j] = ' ';

                    if(score > bestScore){
                        bestScore = score;
                        bestMove = i * 3 + j + 1;
                    }
                }
            }
        }

        if(depth == 0){
            aiTurn(1);
        }

        return bestScore;

    }else if(isMaximizing == -1){
        bestScore = 1000;

        for(i=0;i<3;i++){
            for(j=0;j<3;j++){
                if(gameBoard[i][j] != 'X' && gameBoard[i][j] != 'O'){
                    gameBoard[i][j] = 'X';
                    score = minimax(depth + 1, 1);
                    gameBoard[i][j] = ' ';

                    if(score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }

        return bestScore;
    }

    return 0;
}