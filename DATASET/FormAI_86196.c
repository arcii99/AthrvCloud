//FormAI DATASET v1.0 Category: Dice Roller ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int i, num;
    char response;

    printf("Welcome to the Dice Roller!\n");
    do {
        printf("Press any key to roll the dice...");
        scanf(" %c", &response);

        srand(time(NULL)); // initializing random number generator
        
        num = rand() % 6 + 1; // generating a random number between 1 and 6
        
        // printing the corresponding dice face based on the number rolled
        printf("\nThe dice rolled a ");
        for(i=0; i<num; i++) {
            printf("*");
        }
        printf("\n");

        printf("Roll again? (y/n): ");
        scanf(" %c", &response);

    } while(response=='y' || response=='Y');

    printf("Thank you for playing the Dice Roller game!\n");

    return 0;
}