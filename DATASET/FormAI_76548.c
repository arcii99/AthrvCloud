//FormAI DATASET v1.0 Category: Tic Tac Toe AI ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>

char player = 'X';
char ai = 'O';
int board[3][3] = {{0,0,0},{0,0,0},{0,0,0}};

void printBoard(){
    printf("\n");
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == 0){
                printf("- ");
            }else if(board[i][j] == 1){
                printf("X ");
            }else{
                printf("O ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

int gameStatus(){
    //Checking Rows
    for(int i=0;i<3;i++){
        if(board[i][0] == board[i][1] && board[i][0] == board[i][2]){
            if(board[i][0] != 0)
                return (board[i][0] == 1) ? -10 : 10;
        }
    }

    //Checking Columns
    for(int i=0;i<3;i++){
        if(board[0][i] == board[1][i] && board[0][i] == board[2][i]){
            if(board[0][i] != 0)
                return (board[0][i] == 1) ? -10 : 10;
        }
    }

    //Checking Diagonals
    if(board[0][0] == board[1][1] && board[0][0] == board[2][2]){
        if(board[0][0] != 0)
            return (board[0][0] == 1) ? -10 : 10;
    }

    if(board[0][2] == board[1][1] && board[0][2] == board[2][0]){
        if(board[0][2] != 0)
            return (board[0][2] == 1) ? -10 : 10;
    }

    //Checking if the game is tied
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(board[i][j] == 0){
                return 0;
            }
        }
    }

    //Game is tied
    return -1;
}

int minimax(int isMax){
    int score = gameStatus();

    //If Maximizer wins, return his/her
    //evaluated score
    if(score == 10)
        return score;

    //If Minimizer wins, return his/her
    //evaluated score
    if(score == -10)
        return score;

    //If there are no more moves and
    //no winner then it is a tie
    if(score == 0)
        return 0;

    //If this maximizer's move
    if(isMax){
        int best = -1000;

        //Traversing all cells
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j] == 0){
                    //Make the move
                    board[i][j] = ai;

                    //Call minimax recursively and choose
                    //the maximum value
                    best = (best > minimax(!isMax)) ? best : minimax(!isMax);

                    //Undo the move
                    board[i][j] = 0;
                }
            }
        }

        return best;
    }else{
        //If this minimizer's move
        int best = 1000;

        //Traversing all cells
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(board[i][j] == 0){
                    //Make the move
                    board[i][j] = player;

                    //Call minimax recursively and choose
                    //the minimum value
                    best = (best < minimax(!isMax)) ? best : minimax(!isMax);

                    //Undo the move
                    board[i][j] = 0;
                }
            }
        }

        return best;
    }
}

void aiMove(){
    int bestVal = -1000;
    int row = -1, col = -1;

    //Traversing all cells
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            //Check if cell is empty
            if(board[i][j] == 0){
                //Make the move
                board[i][j] = ai;

                //Evaluate the move
                int moveVal = minimax(0);

                //Undo the move
                board[i][j] = 0;

                //Update the best value
                if(moveVal > bestVal){
                    row = i;
                    col = j;
                    bestVal = moveVal;
                }
            }
        }
    }

    //Make the move
    board[row][col] = ai;
}

int main(){
    int choice, row, col;

    printf("Welcome to Tic Tac Toe\n");
    printf("======================\n");

    while(1){
        printBoard();

        printf("1. Play as X\n");
        printf("2. Play as O\n");
        printf("3. Quit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        if(choice == 1){
            player = 'X';
            ai = 'O';
            break;
        }else if(choice == 2){
            player = 'O';
            ai = 'X';
            break;
        }else if(choice == 3){
            exit(0);
        }else{
            printf("Invalid Choice!\n");
        }
    }

    printf("Let the games begin!\n");

    while(1){
        if(player == 'X'){
            printf("Your turn!\n");

            while(1){
                printf("Enter the row (1-3): ");
                scanf("%d", &row);

                printf("Enter the column (1-3): ");
                scanf("%d", &col);

                row--;
                col--;

                if(row < 0 || row > 2 || col < 0 || col > 2){
                    printf("Invalid Position!\n");
                }else if(board[row][col] != 0){
                    printf("Position already taken!\n");
                }else{
                    board[row][col] = player;
                    break;
                }
            }

            if(gameStatus() == 10){
                printf("Congratulations! You won!\n");
                printBoard();
                exit(0);
            }else if(gameStatus() == -1){
                printf("Tie Game!\n");
                printBoard();
                exit(0);
            }

            player = 'O';
        }else{
            printf("AI's turn!\n");
            aiMove();

            if(gameStatus() == -10){
                printf("AI wins!\n");
                printBoard();
                exit(0);
            }else if(gameStatus() == -1){
                printf("Tie Game!\n");
                printBoard();
                exit(0);
            }

            player = 'X';
        }
    }

    return 0;
}