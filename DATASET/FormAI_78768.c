//FormAI DATASET v1.0 Category: Table Game ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to roll the dice */
int rollDice() {
    return rand() % 6 + 1;
}

/* Function to play one turn */
void playTurn(char* playerName, int* playerScore) {
    int dice1 = rollDice();
    int dice2 = rollDice();
    int sum = dice1 + dice2;
    printf("%s rolled %d and %d\n", playerName, dice1, dice2);
    if (sum == 7) {
        *playerScore += 7;
        printf("Lucky seven! %s scores 7 points!\n", playerName);
    } else {
        printf("Better luck next time!\n");
    }
}

int main() {
    srand(time(NULL)); // Initialize random seed
    
    int player1Score = 0;
    int player2Score = 0;
    
    printf("Welcome to Lucky Seven!\n");
    printf("Roll the dice and try to get lucky!\n");
    
    while (player1Score < 21 && player2Score < 21) {
        playTurn("Player 1", &player1Score);
        playTurn("Player 2", &player2Score);
    }
    
    if (player1Score >= 21 && player2Score >= 21) {
        printf("It's a tie!\n");
    } else if (player1Score >= 21) {
        printf("Player 1 wins!\n");
    } else {
        printf("Player 2 wins!\n");
    }
    
    return 0;
}