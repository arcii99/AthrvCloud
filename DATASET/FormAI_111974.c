//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void generateCard(int card[5][5]) { // function to generate a bingo card
    
    // set seed for random number generation
    srand(time(NULL));
    
    // generate numbers for columns B, I, N, G, O
    for (int col = 0; col < 5; col++) {
        int minNum, maxNum;

        if (col == 0) { // column B has numbers 1-15
            minNum = 1;
            maxNum = 15;
        } else if (col == 1) { // column I has numbers 16-30
            minNum = 16;
            maxNum = 30;
        } else if (col == 2) { // column N has numbers 31-45, with a blank space in the center
            minNum = 31;
            maxNum = 45;
            card[2][2] = 0; // set center space to 0
        } else if (col == 3) { // column G has numbers 46-60
            minNum = 46;
            maxNum = 60;
        } else { // column O has numbers 61-75
            minNum = 61;
            maxNum = 75;
        }
        
        // generate random numbers for each row in that column
        for (int row = 0; row < 5; row++) {
            int randNum;
            do { // keep generating random numbers until one is found that isn't already in the card
                randNum = rand() % (maxNum - minNum + 1) + minNum;
            } while (checkDuplicate(card, randNum, row, col));
            
            // assign the random number to its spot on the card
            card[row][col] = randNum;
        }
    }
}

int checkDuplicate(int card[5][5], int num, int row, int col) { // helper function to check for duplicate numbers in the card
    for (int i = 0; i < 5; i++) {
        if (card[row][i] == num && i != col) { // check row for duplicate
            return 1;
        }
        if (card[i][col] == num && i != row) { // check column for duplicate
            return 1;
        }
    }
    return 0;
}

void printCard(int card[5][5]) { // function to print the bingo card
    printf("=====================\n");
    printf("|  B |  I |  N |  G |  O |\n");
    printf("|----|----|----|----|----|\n");
    for (int row = 0; row < 5; row++) {
        printf("|");
        for (int col = 0; col < 5; col++) {
            if (card[row][col] == 0) { // print space if center spot is 0
                printf("    |");
            } else {
                printf(" %2d |", card[row][col]);
            }
        }
        printf("\n|----|----|----|----|----|\n");
    }
    printf("=====================\n");
}

int main() {
    int card[5][5];
    generateCard(card);
    printCard(card);
    return 0;
}