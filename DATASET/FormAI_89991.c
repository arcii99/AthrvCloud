//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: relaxed
#include<stdio.h>

char board[3][3] = {{'1','2','3'}, {'4','5','6'}, {'7','8','9'}};
char player = 'X';
int row, column;
int checkForWin();

void drawBoard(){
    system("cls");
    printf("\n\nTic Tac Toe\n\n");
    printf("Player 1 (X) - Player 2 (O)\n\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[0][0], board[0][1], board[0][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[1][0], board[1][1], board[1][2]);
    printf("_____|_____|_____\n");
    printf("     |     |     \n");
    printf("  %c  |  %c  |  %c  \n", board[2][0], board[2][1], board[2][2]);
    printf("     |     |     \n");
}

void markBoard(char mark){
    if (row == 1 && column == 1){
        board[0][0] = mark;
    } else if (row == 1 && column == 2){
        board[0][1] = mark;
    } else if (row == 1 && column == 3){
        board[0][2] = mark;
    } else if (row == 2 && column == 1){
        board[1][0] = mark;
    } else if (row == 2 && column == 2){
        board[1][1] = mark;
    } else if (row == 2 && column == 3){
        board[1][2] = mark;
    } else if (row == 3 && column == 1){
        board[2][0] = mark;
    } else if (row == 3 && column == 2){
        board[2][1] = mark;
    } else if (row == 3 && column == 3){
        board[2][2] = mark;
    }
}

void playerTurn(){
    if (player == 'X'){
        printf("Player 1, enter row and column: ");
    } else {
        printf("Player 2, enter row and column: ");
    }
    scanf("%d %d", &row, &column);
    row--;
    column--;
    while (board[row][column] != ' '){
        printf("Invalid move, try again!\n");
        if (player == 'X'){
            printf("Player 1, enter row and column: ");
        } else {
            printf("Player 2, enter row and column: ");
        }
        scanf("%d %d", &row, &column);
        row--;
        column--;
    }
    markBoard(player);
    drawBoard();
}

void computerTurn(){
    int i, j, mark, bestScore = -100, score, done = 0;
    for (i = 0; i < 3; i++){
        for (j = 0; j < 3; j++){
            if (board[i][j] == ' '){
                board[i][j] = 'O';
                score = minimax(0, 1);
                board[i][j] = ' ';
                if (score > bestScore){
                    bestScore = score;
                    row = i;
                    column = j;
                }
            }
        }
    }
    markBoard('O');
    drawBoard();
}

int minimax(int depth, int isMaximizing){
    int i, j, score;
    if (checkForWin() == 1){
        return -10 + depth;
    } else if (checkForWin() == 2){
        return 10 - depth;
    } else if (checkForWin() == 3){
        return 0;
    }
    if (isMaximizing){
        int bestScore = -100;
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                if (board[i][j] == ' '){
                    board[i][j] = 'O';
                    score = minimax(depth + 1, 0);
                    board[i][j] = ' ';
                    if (score > bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    } else {
        int bestScore = 100;
        for (i = 0; i < 3; i++){
            for (j = 0; j < 3; j++){
                if (board[i][j] == ' '){
                    board[i][j] = 'X';
                    score = minimax(depth + 1, 1);
                    board[i][j] = ' ';
                    if (score < bestScore){
                        bestScore = score;
                    }
                }
            }
        }
        return bestScore;
    }
}

int checkForWin(){
    int i;
    for (i = 0; i < 3; i++){
        if (board[i][0] == board[i][1] && board[i][1] == board[i][2]){
            if (board[i][0] == 'X'){
                return 1;
            } else if (board[i][0] == 'O'){
                return 2;
            }
        }
        if (board[0][i] == board[1][i] && board[1][i] == board[2][i]){
            if (board[0][i] == 'X'){
                return 1;
            } else if (board[0][i] == 'O'){
                return 2;
            }
        }
    }
    if (board[0][0] == board[1][1] && board[1][1] == board[2][2]){
        if (board[0][0] == 'X'){
            return 1;
        } else if (board[0][0] == 'O'){
            return 2;
        }
    }
    if (board[0][2] == board[1][1] && board[1][1] == board[2][0]){
        if (board[0][2] == 'X'){
            return 1;
        } else if (board[0][2] == 'O'){
            return 2;
        }
    }
    for (i = 0; i < 3; i++){
        int j;
        for (j = 0; j < 3; j++){
            if (board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 3;
}

int main(){
    int choice, count = 0, flag = 0;
    char userName[20];

    printf("\n\nWelcome to Tic Tac Toe v1.0\n\n");
    printf("Enter your name: ");
    scanf("%s", &userName);

    while (1){
        drawBoard();
        if (player == 'X'){
            playerTurn();
        } else {
            computerTurn();
        }
        count++;
        flag = checkForWin();
        if (flag == 1){
            printf("Congratulations %s, you won!\n\n", userName);
            break;
        } else if (flag == 2){
            printf("Sorry, you lost!\n\n");
            break;
        } else if (flag == 3 && count == 9){
            printf("It's a tie!\n\n");
            break;
        }
        if (player == 'X'){
            player = 'O';
        } else {
            player = 'X';
        }
    }

    printf("Enter 1 to play again or 0 to quit: ");
    scanf("%d", &choice);
    if (choice == 1){
        main();
    } else {
        printf("Thanks for playing!\n\n");
        exit(0);
    }

    return 0;
}