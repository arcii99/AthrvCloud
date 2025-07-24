//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: decentralized
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#define ROW 5
#define COL 5

// function to generate unique random numbers between 1-25
int* setRandomNumbers(){
    static int random[25];
    int found = 0;
    srand(time(0));
    while(found < 25){
        int n = (rand() % 25) + 1;
        int unique = 1;
        for(int i = 0; i < found; i++){
            if(random[i] == n){
                unique = 0;
                break;
            }
        }
        if(unique){
            random[found] = n;
            found++;
        }
    }
    return random;
}

// function to initialize the bingo board
void initializeBoard(int board[ROW][COL]) {
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            board[i][j] = -1;
        }
    }
}

// function to display the bingo board
void displayBoard(int board[ROW][COL]){
    printf("\tB \tI \tN \tG \tO\n");
    for(int i = 0; i < ROW; i++){
        printf("%d", i+1);
        for(int j = 0; j < COL; j++){
            if(board[i][j] == -1){
                printf("\t-");
            }
            else{
                printf("\t%d", board[i][j]);
            }
        }
        printf("\n");
    }
}

// function to check whether a number exists in the board
int checkIfNumberExists(int board[ROW][COL], int number){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j] == number){
                return 1;
            }
        }
    }
    return 0;
}

// function to mark the number as found on the board
void markNumber(int board[ROW][COL], int number){
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(board[i][j] == number){
                board[i][j] = -1;
            }
        }
    }
}

// function to check if there is a diagonal bingo
int checkDiagonalBingo(int board[ROW][COL]){
    int diag1 = 0;
    int diag2 = 0;
    for(int i = 0; i < ROW; i++){
        for(int j = 0; j < COL; j++){
            if(i == j && board[i][j] == -1){
                diag1++;
            }
            if(i+j == 4 && board[i][j] == -1){
                diag2++;
            }
        }
    }
    if(diag1 == 5 || diag2 == 5){
        return 1;
    }
    return 0;
}

// function to check if there is a row bingo
int checkRowBingo(int board[ROW][COL]){
    for(int i = 0; i < ROW; i++){
        int count = 0;
        for(int j = 0; j < COL; j++){
            if(board[i][j] == -1){
                count++;
            }
        }
        if(count == 5){
            return 1;
        }
    }
    return 0;
}

// function to check if there is a column bingo
int checkColumnBingo(int board[ROW][COL]){
    for(int i = 0; i < ROW; i++){
        int count = 0;
        for(int j = 0; j < COL; j++){
            if(board[j][i] == -1){
                count++;
            }
        }
        if(count == 5){
            return 1;
        }
    }
    return 0;
}

int main(){
    int board[ROW][COL];
    initializeBoard(board);
    int* numbers = setRandomNumbers();
    int index = 0;
    while(1){
        system("clear");
        displayBoard(board);
        int isBingo = checkRowBingo(board) || checkColumnBingo(board) || checkDiagonalBingo(board);
        if(isBingo){
            printf("BINGO!!\n");
            break;
        }
        int number = numbers[index];
        printf("The number is: %d\n", number);
        index++;
        int exists = checkIfNumberExists(board, number);
        if(exists){
            markNumber(board, number);
        }
        else{
            printf("%d does not exist on your board. Press enter to continue.", number);
            getchar();
        }
        if(index == 25){
            printf("GAME OVER! No more numbers left.\n");
            break;
        }
        getchar();
    }
    return 0;
}