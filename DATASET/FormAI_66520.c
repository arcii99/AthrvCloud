//FormAI DATASET v1.0 Category: Dice Roller ; Style: light-weight
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Function to generate a random number between 1 and 6
int rollDice(){
    int random_number = rand() % 6 + 1;
    return random_number;
}

int main(){
    //Seed the random number generator
    srand(time(NULL));
    
    int num_rolls;
    printf("How many times would you like to roll the dice? ");
    scanf("%d", &num_rolls);
    
    //Declare variables to keep track of the sum and the output of each roll
    int sum = 0;
    int roll;
    
    //Loop through the specified number of rolls, adding each roll to the sum and printing the output
    for(int i = 0; i < num_rolls; i++){
        roll = rollDice();
        printf("Roll %d: %d\n", i+1, roll);
        sum += roll;
    }
    
    //Print the final sum
    printf("Total: %d\n", sum);
    
    return 0;
}