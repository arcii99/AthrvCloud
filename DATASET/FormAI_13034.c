//FormAI DATASET v1.0 Category: Dice Roller ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int num, sides, roll;
    
    srand(time(NULL)); //seeds random number generator with current time
    
    printf("Enter the number of dice to roll: ");
    scanf("%d", &num);
    
    printf("Enter the number of sides on each die: ");
    scanf("%d", &sides);
    
    printf("\nRolling %d %d-sided dice...\n\n", num, sides);
    
    for(int i=0; i<num; i++) //loops through rolling specified number of dice
    {
        roll = rand() % sides + 1; //generates random number between 1 and number of sides
        printf("Die %d: %d\n", i+1, roll);
    }
    
    return 0;
}