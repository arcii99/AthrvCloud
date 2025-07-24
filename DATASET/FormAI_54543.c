//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: ultraprecise
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define ROWS 5
#define COLS 5

int main(){
    int board[ROWS][COLS];
    int numbers[76];
    int count = 1;
    srand(time(NULL));

    //Initialize the board with zeros
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            board[i][j] = 0;
        }
    }

    //Populate the numbers array with numbers from 1 to 75
    for(int i=0;i<76;i++){
        numbers[i] = i+1;
    }

    //Shuffle the numbers array
    for(int i=0;i<76;i++){
        int temp = numbers[i];
        int randomIndex = rand() % 76;
        numbers[i] = numbers[randomIndex];
        numbers[randomIndex] = temp;
    }

    //Fill the board randomly with numbers from the shuffled array
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(i == 2 && j == 2){
                board[i][j] = 0; //The center square is always empty
            }else{
                board[i][j] = numbers[count++];
            }
        }
    }

    printf("Welcome to Bingo Simulator!\n\n");

    //Display the board
    printf("B   I   N   G   O\n");
    for(int i=0;i<ROWS;i++){
        for(int j=0;j<COLS;j++){
            if(board[i][j] == 0){
                printf("    ");
            }else{
                printf("%-3d ",board[i][j]);
            }
        }
        printf("\n");
    }
    
    printf("\nPress enter to start drawing numbers...");
    getchar();

    //Start drawing numbers until someone wins
    int gameOver = 0;
    while(gameOver == 0){
        int randomIndex = rand() % 76;
        int numberDrawn = numbers[randomIndex];
        printf("\n%d\n",numberDrawn);

        //Mark the number on the board if it exists
        for(int i=0;i<ROWS;i++){
            for(int j=0;j<COLS;j++){
                if(board[i][j] == numberDrawn){
                    board[i][j] = 0;
                    printf("B   I   N   G   O\n");
                    for(int k=0;k<ROWS;k++){
                        for(int l=0;l<COLS;l++){
                            if(board[k][l] == 0){
                                printf("    ");
                            }else{
                                printf("%-3d ",board[k][l]);
                            }
                        }
                        printf("\n");
                    }
                    printf("\n");
                }
            }
        }

        //Check if someone has won
        int rowSum, colSum, diag1Sum=0, diag2Sum=0;
        for(int i=0;i<ROWS;i++){
            rowSum = 0;
            colSum = 0;
            for(int j=0;j<COLS;j++){
                rowSum += board[i][j];
                colSum += board[j][i];
            }
            if(rowSum == 0 || colSum == 0){
                gameOver = 1;
                printf("Bingo! Someone won!\n");
                break;
            }
            diag1Sum += board[i][i];
            diag2Sum += board[i][COLS-i-1];
            if(diag1Sum == 0 || diag2Sum == 0){
                gameOver = 1;
                printf("Bingo! Someone won!\n");
                break;
            }
        }

        printf("\nPress enter to draw the next number...");
        getchar();
    }

    return 0;
}