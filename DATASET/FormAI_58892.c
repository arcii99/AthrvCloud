//FormAI DATASET v1.0 Category: Dice Roller ; Style: multiplayer
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int player1, player2;
    char roll_again;

    srand(time(NULL)); //used to generate random number

    printf("Let's play a dice game!\n\n");

    do {

        printf("Player 1, press ENTER to roll the dice");
        getchar(); //waits for user to press any key before continuing
        player1 = rand() % 6 + 1; //generates random number from 1 to 6
        printf("You rolled a %d!\n", player1);

        printf("Player 2, press ENTER to roll the dice");
        getchar();
        player2 = rand() % 6 + 1;
        printf("You rolled a %d!\n", player2);

        if (player1 > player2) {
            printf("Player 1 wins!\n");
        } else if (player2 > player1) {
            printf("Player 2 wins!\n");
        } else {
            printf("It's a tie!\n");
        }

        printf("Would you like to play again? (Y/N)");
        scanf(" %c", &roll_again); //reads user input
        printf("\n");

    } while (roll_again == 'Y' || roll_again == 'y'); //loop continues until user inputs N or n

    printf("Thanks for playing!\n");

    return 0;
}