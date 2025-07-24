//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Representing Bingo Board
int board[5][5];

//Function to initialize the board
void init_board() {
    int count = 1;
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            board[i][j] = count++;
        }
    }
}

//Function to display the board
void display_board() {
    printf("----------------------\n");
    printf("| B  | I  | N  | G  | O |\n");
    printf("----------------------\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(board[i][j] < 10) {
                printf("| %d  ", board[i][j]);
            }
            else {
                printf("| %d ", board[i][j]);
            }
        }
        printf("|\n----------------------\n");
    }
}

//Function to check if any player has won
int check_bingo() {
    int count = 0;
    //Checking Rows
    for(int i=0; i<5; i++) {
        int row_count = 0;
        for(int j=0; j<5; j++) {
            if(board[i][j] == -1) {
                row_count++;
            }
        }
        if(row_count == 5) {
            count++;
        }
    }
    //Checking Columns
    for(int i=0; i<5; i++) {
        int col_count = 0;
        for(int j=0; j<5; j++) {
            if(board[j][i] == -1) {
                col_count++;
            }
        }
        if(col_count == 5) {
            count++;
        }
    }
    //Checking Diagonals
    if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) {
        count++;
    }
    if(board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) {
        count++;
    }
    return count;
}

int main() {
    //Initializing the board
    init_board();
    //Displaying the board
    display_board();
    printf("---------------\n");
    printf("Game Begins Now!\n");
    printf("---------------\n");
    //Initializing the Random Number Generator
    srand(time(NULL));
    //Playing the Game
    int number_count = 0;
    while(1) {
        int number = rand()%25 + 1;
        printf("Next Number: %d\n", number);
        //Checking if the number is already marked
        int flag = 0;
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(board[i][j] == number) {
                    board[i][j] = -1;
                    flag = 1;
                    break;
                }
            }
            if(flag == 1) {
                break;
            }
        }
        number_count++;
        printf("Numbers Marked: %d\n", number_count);
        //If any player won
        if(check_bingo() > 0) {
            printf("Bingo!!\n");
            break;
        }
        //If all numbers are marked but no player won
        if(number_count == 25 && check_bingo() == 0) {
            printf("Game Over: No winner!\n");
            break;
        }
        display_board();
    }
}