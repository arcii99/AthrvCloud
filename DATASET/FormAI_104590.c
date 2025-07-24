//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: shocked
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main() {
    //initialize variables and arrays
    int calledNums[75], playerCard[5][5], computerCard[5][5], i, j, num;
    char playAgain = 'Y';
    srand(time(NULL));
    
    //start game loop
    while(playAgain == 'Y') {
        //reset called number array
        for(i=0; i<75; i++) {
            calledNums[i] = 0;
        }
        
        //generate computer card
        for(i=0; i<5; i++) {
            for(j=0; j<5; j++) {
                if(i == 2 && j == 2) {
                    computerCard[i][j] = 0;
                }
                else {
                    num = rand() % 15 + (15 * j) + 1;
                    while(calledNums[num-1] != 0) {
                        num = rand() % 15 + (15 * j) + 1;
                    }
                    computerCard[i][j] = num;
                    calledNums[num-1] = 1;
                }
            }
        }
        
        //generate player card
        printf("\nYour card:\n");
        for(i=0; i<5; i++) {
            for(j=0; j<5; j++) {
                if(i == 2 && j == 2) {
                    playerCard[i][j] = 0;
                }
                else {
                    printf("Enter a number for row %d, column %d: ", i+1, j+1);
                    scanf("%d", &num);
                    while(num > 75 || num < 1 || calledNums[num-1] != 0) {
                        printf("Invalid number, please enter a number not already called between 1 and 75: ");
                        scanf("%d", &num);
                    }
                    playerCard[i][j] = num;
                    calledNums[num-1] = 1;
                }
            }
        }
        
        //start game rounds
        int computerBingo = 0, playerBingo = 0, roundNum = 0, calledNum = 0;
        while(computerBingo == 0 && playerBingo == 0) {
            roundNum++;
            printf("\n\nRound %d:\n", roundNum);
            num = rand() % 75 + 1;
            while(calledNums[num-1] != 0) {
                num = rand() % 75 + 1;
            }
            calledNums[num-1] = 1;
            calledNum = num;
            printf("The called number is: %d\n", calledNum);
            
            //check computer card
            for(i=0; i<5; i++) {
                int bingoCount = 0;
                for(j=0; j<5; j++) {
                    if(computerCard[i][j] == calledNum) {
                        computerCard[i][j] = -1;
                        bingoCount++;
                    }
                }
                if(bingoCount == 5) {
                    computerBingo = 1;
                    break;
                }
            }
            
            //check player card
            printf("\nYour card:\n");
            for(i=0; i<5; i++) {
                for(j=0; j<5; j++) {
                    if(playerCard[i][j] == calledNum) {
                        playerCard[i][j] = -1;
                        printf("X ");
                    }
                    else {
                        printf("%d ", playerCard[i][j]);
                    }
                }
                printf("\n");
            }
            for(i=0; i<5; i++) {
                int bingoCount = 0;
                for(j=0; j<5; j++) {
                    if(playerCard[i][j] == -1) {
                        bingoCount++;
                    }
                }
                if(bingoCount == 5) {
                    playerBingo = 1;
                    break;
                }
            }
        }
        
        //declare winner
        if(computerBingo == 1 && playerBingo == 1) {
            printf("\n\nIt's a tie!");
        }
        else if(computerBingo == 1) {
            printf("\n\nThe computer wins!");
        }
        else {
            printf("\n\nCongratulations, you win!");
        }
        
        //ask to play again
        printf("\n\nDo you want to play again? (Y/N): ");
        scanf(" %c", &playAgain);
        playAgain = toupper(playAgain);
    }
    
    return 0;
}