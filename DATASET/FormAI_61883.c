//FormAI DATASET v1.0 Category: Dice Roller ; Style: Alan Touring
// ALAN TURING STYLE DICE ROLLER

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); //initialize random number generator

    //get number of dice rolls from user
    int num_rolls;
    printf("How many times do you want to roll the dice?");
    scanf("%d", &num_rolls);

    //get number of sides on dice from user
    int num_sides;
    printf("How many sides does your dice have?");
    scanf("%d", &num_sides);

    //Roll the dice
    int roll_count = 0;
    while(roll_count < num_rolls) {
        int roll = rand() % num_sides + 1;
        printf("Roll %d: %d\n", roll_count+1, roll);
        roll_count++;
    }

    return 0;
}