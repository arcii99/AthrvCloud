//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: surprised
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    printf("Welcome to the surprise Bingo Game Simulator!\n");
    printf("Prepare for an amazing experience with a fully randomized and entertaining game.\n\n");
    printf("Press ENTER to start the game!\n");
    getchar();

    srand(time(0)); //Seed for generating random numbers based on time

    int board[5][5]; //Bingo board
    int called[75] = {0}; //Numbers that have been called
    int count = 0; //Count of numbers called

    //Fill the board with random numbers
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            int num;
            do {
                num = (rand() % 15) + ((j * 15) + 1); //Generate a random number for each column
            } while(num_exists(board, num));
            board[i][j] = num;
        }
    }

    //Print the Bingo board
    printf("Here's your Bingo card:\n\n");
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(i == 2 && j == 2) printf("  "); //Free space in the middle of the board
            else printf("%2d ", board[i][j]);
        }
        printf("\n");
    }

    //Start the game by calling out random numbers
    printf("\nLet's start the game! Press ENTER to draw a number.\n\n");

    while(count < 75) {
        int num;
        do {
            num = (rand() % 75) + 1; //Generate a random number between 1 and 75
        } while(called[num-1]);
        called[num-1] = 1; //Mark the number as called
        count++;

        printf("Number called: %d\n", num);

        //Check if any numbers on the board match the called number
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(board[i][j] == num) {
                    board[i][j] = -1; //Mark the number as matched
                    printf("Match found at row %d, column %d!\n", i+1, j+1);
                }
            }
        }

        //Check for a Bingo
        if(check_bingo(board)) {
            printf("\nBINGO!! You've won the game!!\n");
            return 0;
        }

        printf("\nPress ENTER to draw another number.\n");
        getchar(); //Wait for the user to press ENTER
    }

    printf("\nSorry, all numbers have been called. Better luck next time!\n");
    return 0;
}

//Check if a number already exists on the board
int num_exists(int board[5][5], int num) {
    for(int i=0; i<5; i++) {
        for(int j=0; j<5; j++) {
            if(board[i][j] == num) return 1;
        }
    }
    return 0;
}

//Check if there is a Bingo on the board
int check_bingo(int board[5][5]) {
    //Check horizontal lines
    for(int i=0; i<5; i++) {
        if(board[i][0] == -1 && board[i][1] == -1 && board[i][2] == -1 && board[i][3] == -1 && board[i][4] == -1) return 1;
    }
    //Check vertical lines
    for(int j=0; j<5; j++) {
        if(board[0][j] == -1 && board[1][j] == -1 && board[2][j] == -1 && board[3][j] == -1 && board[4][j] == -1) return 1;
    }
    //Check diagonal lines
    if(board[0][0] == -1 && board[1][1] == -1 && board[2][2] == -1 && board[3][3] == -1 && board[4][4] == -1) return 1;
    if(board[0][4] == -1 && board[1][3] == -1 && board[2][2] == -1 && board[3][1] == -1 && board[4][0] == -1) return 1;
    return 0;
}