//FormAI DATASET v1.0 Category: Alien Invasion Probability Calculator ; Style: funny
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function prototypes
int rollDice();
void greetUser();
void calculateProbability(int diceRoll, int alienFleetSize);

int main(){
    srand(time(0)); //seeding random numbers

    greetUser();

    int alienFleetSize, diceRoll;

    printf("Enter the size of the alien fleet (in number of ships): ");
    scanf("%d", &alienFleetSize);

    diceRoll = rollDice();

    calculateProbability(diceRoll, alienFleetSize);

    return 0;
}

//function to roll a six-sided dice
int rollDice() {
    return (rand() % 6) + 1;
}

//function to greet user in a funny way
void greetUser() {
    printf("*****************************\n");
    printf("* Welcome to the Alienocalypse! *\n");
    printf("*****************************\n\n");
    printf("In this game, you will be given the chance to calculate the probability of an alien invasion!\n");
    printf("But beware, the fate of the world rests in your hands. No pressure!\n");
    printf("Now, let's get started, shall we?\n\n");
}

//function to calculate and output probability of alien invasion
void calculateProbability(int diceRoll, int alienFleetSize){
    float probability = ((float)diceRoll / 6) * ((float)alienFleetSize / 1000) * 100;

    printf("\nThe probability of an alien invasion is %.2f%%\n", probability);

    printf("\nGood luck, and remember: don't panic! Unless the aliens are actually invading. Then, you can panic a little!\n");
}