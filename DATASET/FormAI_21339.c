//FormAI DATASET v1.0 Category: Game ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void drawLine(int n, char symbol);
void rules();

int main()
{
    int amount;     // amount of money that player has in the beginning
    int bettingAmount;  // amount that player bets in each game
    int guess;      // player's guess
    int dice;       // number obtained on the dice
    char choice;    // player's choice to continue playing or exit
    srand(time(0)); // randomizing the seed

    drawLine(60,'_');
    printf("\n\n\n\t\t\tCasino Game\n\n\n\n");
    drawLine(60,'_');

    printf("\nEnter the amount you want to start with: $");
    scanf("%d", &amount);

    do
    {
        system("clear");    // clear screen on linux or mac console
        rules();
        printf("\nYour current balance is $%d\n", amount);

        // get player's betting amount
        do
        {
            printf("Enter money to bet: $");
            scanf("%d", &bettingAmount);
            if(bettingAmount > amount)
            {
                printf("You don't have enough balance\n");
                printf("\nYour current balance is $%d\n", amount);
            }
        }while(bettingAmount > amount);

        // get player's guess
        do
        {
            printf("Guess the number between 1 and 6: ");
            scanf("%d", &guess);
            if(guess <= 0 || guess > 6)
                printf("invalid input. try again\n");
        } while(guess <= 0 || guess > 6);

        dice = rand()%6 + 1; // generate random number

        if(dice == guess)
        {
            printf("\n\nGood Luck!! You won $%d", bettingAmount*6);
            amount += bettingAmount * 6;    // update balance
        }
        else
        {
            printf("Bad Luck. You lost $%d", bettingAmount);
            amount -= bettingAmount;        // update balance
        }

        printf("\nThe winning number was %d\n", dice);
        printf("\nWould you like to continue playing? (Y/N) ");
        scanf(" %c", &choice);
    } while(choice == 'y' || choice == 'Y');

    printf("\n\n\n");
    drawLine(70,'=');
    printf("\n\nThank You! Your Final Balance is $%d\n\n", amount);
    drawLine(70,'=');

    return 0;

}

void drawLine(int n, char symbol)
{
    for(int i=0; i<n; i++)
        printf("%c",symbol);
}

void rules()
{
    system("clear");    // clear screen on linux or mac console
    printf("\n\n\t\tCASINO GAME RULES\n\n");
    printf("\t1. Choose any number between 1 and 6\n");
    printf("\t2. If you win, you will get 6 times the betting amount\n");
    printf("\t3. If you lose, you will lose the betting amount\n\n\n");
}