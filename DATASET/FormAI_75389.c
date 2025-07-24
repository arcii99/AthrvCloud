//FormAI DATASET v1.0 Category: Checkers Game ; Style: secure
#include <stdio.h>

void displayBoard(char board[][8]){
    int i, j;
    printf("       A     B     C     D     E     F     G     H\n");
    printf("     ----- ----- ----- ----- ----- ----- ----- -----\n");
    for (i = 0; i < 8; i++){
        printf("  %d  ",i+1);
        for (j = 0; j < 8; j++){
            printf("|  %c  ",board[i][j]);
        }
        printf("| %d\n",i+1);
        printf("     ----- ----- ----- ----- ----- ----- ----- -----\n");
    }
    printf("       A     B     C     D     E     F     G     H\n");
}

void initializeBoard(char board[][8]){
    int i, j;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if ((i + j) % 2 == 0){
                if (i < 3){
                    board[i][j] = 'b';
                } else if (i > 4){
                    board[i][j] = 'r';
                } else{
                    board[i][j] = '-';
                }
            } else{
                board[i][j] = ' ';
            }
        }
    }
}

void getMove(int move[], char player){
    int validMove = 0;
    char input[64];
    while (!validMove){
        printf("Enter move for player %c (e.g. A3 B4): ", player);
        fgets(input, 63, stdin);
        input[5] = '\0';
        if (sscanf(input, "%d%d%d%d", &move[0], &move[1], &move[2], &move[3]) == 4){
            move[0]--;
            move[1]--;
            move[2]--;
            move[3]--;
            validMove = 1;
        } else{
            printf("Invalid move format!\n");
        }
    }
}

void updateBoard(int move[], char board[][8], char player){
    int dx, dy;
    dx = move[3] - move[1];
    dy = move[2] - move[0];
    board[move[0]][move[1]] = '-';
    if (player == 'r'){
        board[move[2]][move[3]] = 'r';
        if (dy == 2){
            board[move[0] + 1][move[1] + 1] = '-';
        } else if (dy == -2){
            board[move[0] + 1][move[1] - 1] = '-';
        }
    } else{
        board[move[2]][move[3]] = 'b';
        if (dy == 2){
            board[move[0] - 1][move[1] + 1] = '-';
        } else if (dy == -2){
            board[move[0] - 1][move[1] - 1] = '-';
        }
    }
}

int checkEndGame(char board[][8]){
    int i, j, redCount = 0, blackCount = 0;
    for (i = 0; i < 8; i++){
        for (j = 0; j < 8; j++){
            if (board[i][j] == 'r' || board[i][j] == 'R'){
                redCount++;
            } else if (board[i][j] == 'b' || board[i][j] == 'B'){
                blackCount++;
            }
        }   
    }
    if (redCount == 0){
        return 1;
    } else if (blackCount == 0){
        return 2;
    } else{
        return 0;
    }
}

int main(){
    char board[8][8], player = 'r', piece;
    int move[4], gameOver = 0, i;
    initializeBoard(board);
    displayBoard(board);
    while (!gameOver){
        getMove(move, player);
        if (board[move[0]][move[1]] == '-'){
            printf("Invalid move - empty source square.\n");
        } else if (board[move[2]][move[3]] != '-'){
            printf("Invalid move - destination square not empty.\n");
        } else{
            if (player == 'r'){
                piece = board[move[0]][move[1]];
                if (piece != 'r' && piece != 'R'){
                    printf("Invalid move - wrong piece selected.\n");
                } else if (move[2] > move[0] && piece == 'r'){
                    printf("Invalid move - red pieces can only move up the board.\n");
                } else{
                    updateBoard(move, board, player);
                }
            } else{
                piece = board[move[0]][move[1]];
                if (piece != 'b' && piece != 'B'){
                    printf("Invalid move - wrong piece selected.\n");
                } else if (move[2] < move[0] && piece == 'b'){
                    printf("Invalid move - black pieces can only move down the board.\n");
                } else{
                    updateBoard(move, board, player);
                }
            }
            displayBoard(board);
            gameOver = checkEndGame(board);
            player = (player == 'r') ? 'b' : 'r';
        }
    }
    printf("Game over! ");
    if (gameOver == 1){
        printf("Black wins.\n");
    } else{
        printf("Red wins.\n");
    }
    return 0;
}