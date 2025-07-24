//FormAI DATASET v1.0 Category: Table Game ; Style: realistic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    printf("Welcome to the C Table Game!\n");
    printf("You have 100 beans. You can bet any number of beans with each turn.\n");
    printf("If you roll a number greater than or equal to the number of beans you bet, you win!\n");
    printf("If you roll a number less than the number of beans you bet, you lose!\n");
    
    int beans = 100;
    srand(time(NULL));
    
    while (beans > 0) {
        printf("You currently have %d beans.\n", beans);
        
        int bet = -1;
        while (bet < 0 || bet > beans) {
            printf("How many beans would you like to bet? ");
            scanf("%d", &bet);
            
            if (bet < 0) {
                printf("You cannot bet a negative number of beans.\n");
            }
            else if (bet > beans) {
                printf("You cannot bet more beans than you currently have.\n");
            }
        }
        
        int roll = rand() % 10 + 1;
        printf("You rolled a %d.\n", roll);
        
        if (roll >= bet) {
            printf("Congratulations! You won %d beans.\n", bet);
            beans += bet;
        }
        else {
            printf("Sorry, you lost %d beans.\n", bet);
            beans -= bet;
        }
    }
    
    printf("Sorry, you have no more beans to bet. Thanks for playing!\n");
    
    return 0;
}