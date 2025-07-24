//FormAI DATASET v1.0 Category: Table Game ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int player1 = 0, player2 = 0;
    int dice1, dice2;
    srand(time(NULL));
    
    printf("\n\n\t\tWelcome to the Happy C Table Game\n\n");
    printf("*****************************************\n\n");
    printf("\t\tRULES OF THE GAME\n\n");
    printf("*****************************************\n\n");
    printf("1. The game requires two players.\n");
    printf("2. A player can roll the dice once per turn.\n");
    printf("3. The number on the dice determines the number of steps to move forward.\n");
    printf("4. The game ends when one of the players reaches the finish line.\n\n");
    printf("*****************************************\n\n");
    printf("\t\tLET THE GAME BEGIN!\n\n");
    printf("*****************************************\n\n");

    while(player1 < 100 && player2 < 100) {
        printf("Player 1, press 'Enter' to roll the dice.\n");
        getchar();
        dice1 = (rand() % 6) + 1;
        player1 += dice1;
        printf("Player 1, you have moved %d steps forward. You are now at position %d.\n\n", dice1, player1);
        
        printf("Player 2, press 'Enter' to roll the dice.\n");
        getchar();
        dice2 = (rand() % 6) + 1;
        player2 += dice2;
        printf("Player 2, you have moved %d steps forward. You are now at position %d.\n\n", dice2, player2);
    }

    if(player1 >= 100 && player2 >= 100) {
        printf("It's a tie!\n");
    }
    else if(player1 >= 100) {
        printf("Congratulations Player 1, you have won the game!\n");
    }
    else if(player2 >= 100) {
        printf("Congratulations Player 2, you have won the game!\n");
    }

    return 0;
}