//FormAI DATASET v1.0 Category: Dice Roller ; Style: beginner-friendly
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(0));
    char playAgain = 'Y';
    int totalRolls = 0;
    int totalScore = 0;
    while (playAgain == 'Y') {
        int rolls = 0;
        int score = 0;
        printf("Rolling dice...\n");
        while (1) {
            int roll = rollDice();
            printf("You rolled a %d\n", roll);
            rolls++;
            if (roll == 1) {
                printf("You lose.\n");
                break;
            } else {
                score += roll;
                printf("Your current score is %d\n", score);
                char rollAgain;
                printf("Would you like to roll again? (Y/N) ");
                scanf(" %c", &rollAgain);
                if (rollAgain != 'Y') {
                    printf("Your final score is %d\n", score);
                    break;
                }
            }
        }
        totalRolls += rolls;
        totalScore += score;
        printf("Total rolls: %d\n", totalRolls);
        printf("Average score: %.2f\n", (float)totalScore / totalRolls);
        printf("Do you want to play again? (Y/N) ");
        scanf(" %c", &playAgain);
    }
    printf("Thanks for playing!\n");
    return 0;
}