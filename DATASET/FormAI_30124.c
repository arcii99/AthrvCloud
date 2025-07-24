//FormAI DATASET v1.0 Category: Dice Roller ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int sides, dice, numRolls, i, j, currentRoll, sum;
    int frequency[100] = {0}; //initialize array with zeros
    
    srand(time(NULL)); //seed a random number generator with current time
    
    printf("Enter the number of sides on the dice: ");
    scanf("%d", &sides);
    
    printf("Enter the number of dice: ");
    scanf("%d", &dice);
    
    printf("Enter the number of rolls: ");
    scanf("%d", &numRolls);
    
    //iterate for each roll
    for (i = 0; i < numRolls; i++) {
        sum = 0;
        //roll each die
        for (j = 0; j < dice; j++) {
            currentRoll = (rand() % sides) + 1; //generate random number between 1 and number of sides
            sum += currentRoll; //add to total sum
        }
        frequency[sum - dice]++; //increment the frequency of the particular sum
    }
    
    //output frequency distribution table
    printf("Roll\tFrequency\n");
    for (i = dice; i <= dice * sides; i++) {
        printf("%d\t%d\n", i, frequency[i-dice]);
    }
    
    return 0;
}