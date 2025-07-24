//FormAI DATASET v1.0 Category: Dice Roller ; Style: authentic
#include <stdio.h>
#include <stdlib.h> // for rand() and srand()

int main() {
    int sides, numOfDice, rollCount, total;
    char choice;
    srand(time(NULL)); // initialize random number generator
    
    do {
        printf("How many sides does your dice have? ");
        scanf("%d", &sides);
        
        printf("How many dice are you rolling? ");
        scanf("%d", &numOfDice);
        
        printf("How many times do you want to roll the dice? ");
        scanf("%d", &rollCount);
        
        total = 0; // reset total to 0 for each roll
        
        for (int i = 0; i < rollCount; i++) {
            printf("Roll %d: ", i+1);
            
            for (int j = 0; j < numOfDice; j++) {
                int roll = rand() % sides + 1; // generate a random number between 1 and sides
                printf("%d ", roll);
                total += roll; // add this roll to the total
            }
            
            printf("\n");
        }
        
        printf("Total: %d\n", total);
        
        printf("Do you want to roll again? (Y/N) ");
        scanf("\n%c", &choice);
    } while (choice == 'Y' || choice == 'y');
    
    printf("Thank you for using the dice roller!\n");
    
    return 0;
}