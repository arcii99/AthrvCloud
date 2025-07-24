//FormAI DATASET v1.0 Category: Dice Roller ; Style: systematic
// C program to simulate a dice roller

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random number between 1 and 6
int rollDice() {
    return rand() % 6 + 1;
}

int main() {
    srand(time(NULL)); // seed the random number generator with the current time
    
    int numRolls; // number of dice rolls to simulate
    printf("Enter the number of times you want to roll the dice: ");
    scanf("%d", &numRolls);
    
    if(numRolls <= 0) { // error check for negative or zero input
        printf("Invalid input. Please enter a positive number.\n");
        return 0;
    }
    
    printf("\nRolling the dice %d time(s)...\n\n", numRolls);
    
    int rollSum = 0; // variable to keep track of the sum of all rolls
    int i;
    for(i = 0; i < numRolls; i++) {
        int roll = rollDice();
        printf("Roll %d: %d\n", i+1, roll);
        rollSum += roll; // add the roll to the total sum
    }
    
    float average = (float) rollSum / numRolls;
    printf("\nAverage roll: %.2f\n", average);
    
    return 0;
}