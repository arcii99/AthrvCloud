//FormAI DATASET v1.0 Category: Game ; Style: shocked
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int players, rounds, i, j, dice, total = 0;
    printf("Welcome to the Shocking Dice Game!\n");
    while(1) {
        printf("How many players? (1-4): ");
        scanf("%d", &players);
        if(players < 1 || players > 4) {
            printf("Invalid number of players!\n");
            continue;
        }
        else {
            break;
        }
    }
    printf("How many rounds? (1-10): ");
    scanf("%d", &rounds);
    srand(time(0));
    for(i = 1; i <= rounds; i++) {
        printf("-----Round %d-----\n", i);
        for(j = 1; j <= players; j++) {
            printf("Player %d's turn. Press enter to roll the dice...", j);
            getchar();
            dice = rand() % 6 + 1;
            printf("You rolled a %d!\n", dice);
            if(dice == 3) {
                printf("Shocking! You lost all your points!\n");
                total = 0;
            }
            else {
                total += dice;
                printf("Your total points is now %d.\n", total);
            }
        }
        printf("End of round %d.\n", i);
    }
    printf("Game over. Final scores:\n");
    for(i = 1; i <= players; i++) {
        printf("Player %d: %d points.\n", i, total);
    }
    return 0;
}