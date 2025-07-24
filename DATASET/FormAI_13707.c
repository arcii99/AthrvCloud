//FormAI DATASET v1.0 Category: Bingo Simulator ; Style: peaceful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void displayCard(int *card) {
    printf("**************************\n");
    printf("* B  I  N  G  O          *\n");
    printf("**************************\n");
    for (int i = 0; i < 25; i++) {
        if (i % 5 == 0) {
            printf("\n");
        }
        printf("* %2d ", card[i]);
        if (i == 12) {
            printf("*    Free Space\n");
        }
    }
    printf("\n**************************\n\n");
}

void markNumber(int *card, int number) {
    for (int i = 0; i < 25; i++) {
        if (card[i] == number) {
            card[i] = -1;
        }
    }
}

int checkHorizontal(int *card) {
    for (int i = 0; i < 25; i += 5) {
        if (card[i] == -1 && card[i+1] == -1 && card[i+2] == -1 && card[i+3] == -1 && card[i+4] == -1) {
            return 1;
        }
    }
    return 0;
}

int checkVertical(int *card) {
    for (int i = 0; i < 5; i++) {
        if (card[i] == -1 && card[i+5] == -1 && card[i+10] == -1 && card[i+15] == -1 && card[i+20] == -1) { 
            return 1;
        }
    }
    return 0;
}

int checkDiagonal(int *card) {
    if (card[0] == -1 && card[6] == -1 && card[12] == -1 && card[18] == -1 && card[24] == -1) {
        return 1;
    } else if (card[4] == -1 && card[8] == -1 && card[12] == -1 && card[16] == -1 && card[20] == -1) {
        return 1;
    } else {
        return 0;
    }
}

int main() {
    int card[25] = { 0 };
    int numbersCalled[75] = { 0 };
    int round = 1;

    // Seed the random number generator
    srand(time(NULL));

    // Generate the card
    for (int i = 0; i < 25; i++) {
        int number = rand() % 75 + 1;
        int duplicate = 0;
        for (int j = 0; j < i; j++) {
            if (card[j] == number) {
                duplicate = 1;
            }   
        }
        if (duplicate) {
            i--;
        } else {
            card[i] = number;
        }
    }

    // Display the card
    displayCard(card);

    // Play the game
    while (1) {
        // Check for a winner
        if (checkHorizontal(card) || checkVertical(card) || checkDiagonal(card)) {
            printf("\n\nBINGO! Congratulations, you have won!\n");
            break;
        }

        // Generate a random number
        int number = rand() % 75 + 1;

        // Check for duplicates
        for (int i = 0; i < 75; i++) {
            if (numbersCalled[i] == number) {
                number = rand() % 75 + 1;
                i = -1; // reset index to check from start
            }
        }
        numbersCalled[round-1] = number;

        // Mark the number on the card
        markNumber(card, number);

        // Display the number and the updated card
        printf("Round %d: The number is %d.\n\n", round, number);
        displayCard(card);

        // Check for a tie
        if (round == 75) {
            printf("\n\nTie game. Better luck next time!\n");
            break;
        }

        // Increment the round counter
        round++;
    }

    return 0;
}