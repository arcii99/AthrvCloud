//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: energetic
#include <stdio.h>
#include <time.h>
#include <stdlib.h>

int main() {

    srand(time(NULL)); //seed the random number generator
    
    int numbers[75], row[5][5], usedNumbers[75]; //declare and initialize arrays
    
    for (int i = 0; i < 75; i++) {
        numbers[i] = i + 1; //populate numbers array with 1 to 75
    }
    
    for (int i = 0; i < 5; i++) {
        for (int j = 0; j < 5; j++) {
            row[i][j] = 0; //initialize all positions of bingo card to 0
        }
    }
    
    printf("Welcome to Bingo Simulator!\n\n");
    printf("Press enter to start...\n");
    getchar(); //wait for user to press enter
    
    int numCalled = 0, winner = 0;
    
    while (numCalled < 75 && winner == 0) {
        
        //generate random number that hasn't been called yet
        int randIndex = rand() % (75 - numCalled);
        int randNum = numbers[randIndex];
        numbers[randIndex] = numbers[74 - numCalled]; //swap used number with last unused number
        usedNumbers[numCalled] = randNum;
        
        printf("The number called is: %d\n", randNum);
        
        //mark number on bingo card if it matches
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (row[i][j] == randNum) {
                    row[i][j] = -1; //mark as called
                }
                if (i == 2 && j == 2) { //don't mark center free space
                    continue;
                }
                if (row[i][j] == 0 && i == randNum / 15 && randNum % 15 == j) { //if position is empty and matches called number
                    row[i][j] = randNum;
                }
            }
        }
        
        //print updated bingo card
        printf("\n\n");
        printf("B   I   N   G   O\n");
        printf("------------------\n");
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (row[i][j] == -1) {
                    printf("XX  ");
                } else if (i == 2 && j == 2) {
                    printf("    ");
                } else if (row[i][j] == 0) {
                    printf("    ");
                } else {
                    printf("%-2d  ", row[i][j]);
                }
            }
            printf("\n");
        }
        
        //check for winner
        if (row[0][0] == -1 && row[0][1] == -1 && row[0][2] == -1 && row[0][3] == -1 && row[0][4] == -1) { //horizontal top row
            winner = 1;
        } else if (row[1][0] == -1 && row[1][1] == -1 && row[1][2] == -1 && row[1][3] == -1 && row[1][4] == -1) { //horizontal second row
            winner = 1;
        } else if (row[2][0] == -1 && row[2][1] == -1 && row[2][2] == -1 && row[2][3] == -1 && row[2][4] == -1) { //horizontal third row
            winner = 1;
        } else if (row[3][0] == -1 && row[3][1] == -1 && row[3][2] == -1 && row[3][3] == -1 && row[3][4] == -1) { //horizontal fourth row
            winner = 1;
        } else if (row[4][0] == -1 && row[4][1] == -1 && row[4][2] == -1 && row[4][3] == -1 && row[4][4] == -1) { //horizontal bottom row
            winner = 1;
        } else if (row[0][0] == -1 && row[1][0] == -1 && row[2][0] == -1 && row[3][0] == -1 && row[4][0] == -1) { //vertical left column
            winner = 1;
        } else if (row[0][1] == -1 && row[1][1] == -1 && row[2][1] == -1 && row[3][1] == -1 && row[4][1] == -1) { //vertical second column
            winner = 1;
        } else if (row[0][2] == -1 && row[1][2] == -1 && row[2][2] == -1 && row[3][2] == -1 && row[4][2] == -1) { //vertical third column
            winner = 1;
        } else if (row[0][3] == -1 && row[1][3] == -1 && row[2][3] == -1 && row[3][3] == -1 && row[4][3] == -1) { //vertical fourth column
            winner = 1;
        } else if (row[0][4] == -1 && row[1][4] == -1 && row[2][4] == -1 && row[3][4] == -1 && row[4][4] == -1) { //vertical right column
            winner = 1;
        } else if (row[0][0] == -1 && row[1][1] == -1 && row[2][2] == -1 && row[3][3] == -1 && row[4][4] == -1) { //diagonal top left to bottom right
            winner = 1;
        } else if (row[0][4] == -1 && row[1][3] == -1 && row[2][2] == -1 && row[3][1] == -1 && row[4][0] == -1) { //diagonal top right to bottom left
            winner = 1;
        }
        
        numCalled++; //increment number of called numbers
    }
    
    if (winner == 1) {
        printf("\n\nBINGO! Congratulations, you won!\n\n");
    } else {
        printf("\n\nSorry, you didn't win. Better luck next time!\n\n");
    }
    
    printf("The numbers called were:\n");
    for (int i = 0; i < numCalled; i++) {
        printf("%d ", usedNumbers[i]);
    }
    printf("\n\nThank you for playing Bingo Simulator!\n\n");
    
    return 0;
}