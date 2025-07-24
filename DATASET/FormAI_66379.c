//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include<stdio.h>
#include<stdlib.h>

//function to generate a random bingo number
int generateBingoNumber(int previousNumbers[], int count) {
    int number;
    do {
        number = rand() % 75 + 1;
    } while(checkPrevious(number, previousNumbers, count));
    return number;
}

//function to check if number has been called before
int checkPrevious(int number, int previousNumbers[], int count) {
    for(int i=0; i<count; i++) {
        if(previousNumbers[i] == number) {
            return 1;
        }
    }
    return 0;
}

//main function
int main() {
    int previousNumbers[75];
    int count = 0;
    char bingo[5][5] = {{'B','I','N','G','O'},
                        {'2','0','3','6','5'},
                        {'1','9','F','4','2'},
                        {'7','1','8','0','4'},
                        {'3','1','4','2','5'}};
    int bingoNumbers[75];
    for(int i=1; i<=75; i++) {
        bingoNumbers[i-1] = i;
    }
    //shuffling the bingo numbers
    for(int i=0; i<75; i++) {
        int temp = bingoNumbers[i];
        int randomIndex = rand()%75;
        bingoNumbers[i] = bingoNumbers[randomIndex];
        bingoNumbers[randomIndex] = temp;
    }
    
    printf("\nWelcome to Bingo Simulator!\n");
    printf("Press any key to generate a new bingo number and show the current game board.\n");
    getchar();
    
    //game loop
    while(count<75) {
        //generate new bingo number
        int number = generateBingoNumber(previousNumbers, count);
        //add number to list of previous numbers
        previousNumbers[count] = number;
        count++;
        printf("\nCurrent Bingo Number: %d\n", number);
        
        //display game board with current number crossed out
        for(int i=0; i<5; i++) {
            for(int j=0; j<5; j++) {
                if(bingo[i][j] == 'X') {
                    printf("%c ", bingo[i][j]);
                }
                else if(bingo[i][j] == (number/10)+48 && bingo[i][j+1] == (number%10)+48) {
                    bingo[i][j] = 'X';
                    printf("%c%c ", bingo[i][j], bingo[i][j+1]);
                }
                else {
                    printf("%c ", bingo[i][j]);
                }
            }
            printf("\n");
        }
        //check for bingo
        if(checkBingo(bingo)) {
            printf("\nBINGO! You win!\n");
            break;
        }
        //wait for user input for next number
        getchar();
    }
    //end of game
    printf("\nGame Over. Thanks for playing!\n");
    return 0;
}

//function to check for bingo
int checkBingo(char bingo[][5]) {
    int count = 0;
    //checking for horizontal line
    for(int i=0; i<5; i++) {
        if(bingo[i][0] == 'X' && bingo[i][1] == 'X' && bingo[i][2] == 'X' && bingo[i][3] == 'X' && bingo[i][4] == 'X') {
            return 1;
        }
    }
    //checking for vertical line
    for(int i=0; i<5; i++) {
        if(bingo[0][i] == 'X' && bingo[1][i] == 'X' && bingo[2][i] == 'X' && bingo[3][i] == 'X' && bingo[4][i] == 'X') {
            return 1;
        }
    }
    //checking for diagonal line
    if(bingo[0][0] == 'X' && bingo[1][1] == 'X' && bingo[2][2] == 'X' && bingo[3][3] == 'X' && bingo[4][4] == 'X') {
        return 1;
    }
    if(bingo[0][4] == 'X' && bingo[1][3] == 'X' && bingo[2][2] == 'X' && bingo[3][1] == 'X' && bingo[4][0] == 'X') {
        return 1;
    }
    return 0;
}