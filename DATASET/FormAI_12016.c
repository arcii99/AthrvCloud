//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: mind-bending
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    //seed the random number generator
    srand(time(NULL));

    //set up the bingo card
    int bingoCard[5][5] = {0};
    int calledNumbers[75] = {0};
    int calledCount = 0;
    int playerCount = 0;
    int playerCards[10][5][5] = {0};

    //generate the player's cards
    while (playerCount < 10) {
        int uniqueCard = 1;
        int playerCard[5][5] = {0};

        //fill the card
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 5; j++) {
                if (j == 2 && i == 2) {  //center of the card is free
                    playerCard[i][j] = -1;
                    continue;
                }
                int newNumber;
                int uniqueNumber = 0;
                while (!uniqueNumber) {
                    newNumber = rand() % 15 + 1 + (j * 15);
                    uniqueNumber = 1;
                    for (int k = 0; k < 5; k++) {
                        if (playerCard[i][k] == newNumber) {
                            uniqueNumber = 0;
                            break;
                        }
                    }
                }
                playerCard[i][j] = newNumber;
            }
        }

        //check for uniqueness
        for (int k = 0; k < playerCount; k++) {
            int isDuplicate = 1;
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    if (playerCards[k][i][j] != playerCard[i][j]) {
                        isDuplicate = 0;
                        break;
                    }
                }
                if (!isDuplicate) {
                    break;
                }
            }
            if (isDuplicate) { //if the card is a duplicate, generate a new one
                uniqueCard = 0;
                break;
            }
        }
        if (uniqueCard) {
            for (int i = 0; i < 5; i++) {
                for (int j = 0; j < 5; j++) {
                    playerCards[playerCount][i][j] = playerCard[i][j];
                }
            }
            playerCount++;
        }
    }

    //print the player's cards
    for (int i = 0; i < 10; i++) {
        printf("Player %d's card:\n", i+1);
        for (int j = 0; j < 5; j++) {
            for (int k = 0; k < 5; k++) {
                printf("%2d ", playerCards[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }

    //play the game
    int winningPlayer = -1;
    while (winningPlayer == -1) {
        //call a new number
        int newNumber;
        int uniqueNumber = 0;
        while (!uniqueNumber) {
            newNumber = rand() % 75 + 1;
            uniqueNumber = 1;
            for (int i = 0; i < calledCount; i++) {
                if (calledNumbers[i] == newNumber) {
                    uniqueNumber = 0;
                    break;
                }
            }
        }
        printf("The next number is: %d\n", newNumber);
        calledNumbers[calledCount] = newNumber;
        calledCount++;

        //check for matches on player's cards
        for (int i = 0; i < 10; i++) {
            int hasMatch = 0;
            for (int j = 0; j < 5; j++) {
                for (int k = 0; k < 5; k++) {
                    if (playerCards[i][j][k] == newNumber) {
                        playerCards[i][j][k] = -1; //mark the spot as matched
                        hasMatch = 1;
                        break;
                    }
                }
                if (hasMatch) {
                    break;
                }
            }
            if (hasMatch) {
                printf("Player %d has a match!\n", i+1);
                //check if the player has won
                int allMatched = 1;
                for (int j = 0; j < 5; j++) {
                    for (int k = 0; k < 5; k++) {
                        if (playerCards[i][j][k] != -1) {
                            allMatched = 0;
                            break;
                        }
                    }
                    if (!allMatched) {
                        break;
                    }
                }
                if (allMatched) {
                    winningPlayer = i;
                    break;
                }
            }
        }
    }

    printf("Game over! Player %d wins!\n", winningPlayer+1);

    return 0;
}