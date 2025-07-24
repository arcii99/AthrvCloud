//FormAI DATASET v1.0 Category: Dice Roller ; Style: medieval
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, rolls, total = 0;
    char choice = 'N';
    srand(time(0));
    printf("Welcome to the Medieval Dice Roller!\n\n");
    do
    {
        printf("How many sides do you want your die to have (4, 6, 8, 10, 12, 20)? ");
        scanf("%d", &sides);
        printf("How many rolls do you want to perform? ");
        scanf("%d", &rolls);
        printf("You have chosen a %d-sided die and want to roll it %d times.\n", sides, rolls);
        printf("\nRolling...\n");
        for (int i = 1; i <= rolls; i++)
        {
            int roll = rand() % sides + 1;
            total += roll;
            printf("Roll %d: %d\n", i, roll);
        }
        printf("\nTotal: %d\n\n", total);
        total = 0;
        printf("Do you want to roll again (Y/N)? ");
        scanf(" %c", &choice); //space before %c to clear buffer
        printf("\n");
    } while (toupper(choice) == 'Y');
    printf("Thank you for using the Medieval Dice Roller. Fare thee well!\n");
    return 0;
}