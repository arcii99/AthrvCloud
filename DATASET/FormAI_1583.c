//FormAI DATASET v1.0 Category: Dice Roller ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * The following program is a dice roller designed to replicate the experience of rolling actual dice in an interactive
 * and immersive way. The program allows the user to input the number and sides of the dice they wish to roll, and then
 * proceeds to simulate the dice rolls by generating randomized numbers and displaying them to the user.
 */

int main() {
    // Define variables to store input from the user
    int numDice, numSides, i;
    
    // Seed the random number generator with the current time
    srand(time(NULL));
    
    // Greet the user and prompt for number of dice
    printf("Welcome to the Dice Roller! How many dice would you like to roll? ");
    scanf("%d", &numDice);
    
    // Loop through each die and prompt for number of sides
    for (i = 0; i < numDice; i++) {
        printf("How many sides does die %d have? ", i+1);
        scanf("%d", &numSides);
        printf("Rolling die %d...\n\n", i+1);
        
        // Generate a random number between 1 and the number of sides
        int roll = rand() % numSides + 1;
        printf("You rolled a %d!\n", roll);
    }
    
    // Exit the program
    printf("Thanks for rolling with us! Goodbye.\n");
    return 0;
}