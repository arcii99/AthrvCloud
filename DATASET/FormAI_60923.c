//FormAI DATASET v1.0 Category: Game ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int score = 0;

int rollDice(){
    //This function randomly generates numbers between 1 and 6 to simulate a dice roll
    srand(time(0));
    int dice = rand() % 6 + 1;
    printf("\nYou rolled a %d.\n",dice);
    return dice;
}

void play(){
    //This function simulates the actual gameplay
    printf("\nPress Enter to roll the dice.");
    getchar();
    int roll = rollDice();
    if(roll == 6){
        score += 6;
        printf("\nYou got a six and earned 6 points! Your current score is %d.\n", score);
        play();
    }
    else if(roll % 2 == 0){
        score += 2;
        printf("\nYou got an even number and earned 2 points! Your current score is %d.\n", score);
        play();
    }
    else{
        printf("\nYou got an odd number and lost your turn. Your current score is %d.\n", score);
    }
}

int main(){
    printf("\nWelcome to the Dice Rolling Game!");
    printf("\nHere are the rules: \n1. Roll the dice by pressing Enter\n2. If you get a six, you earn 6 points and get to roll again\n3. If you get an even number, you earn 2 points and get to roll again\n4. If you get an odd number, you lose your turn\n5. The game ends when you decide to quit\n");

    char choice;
    do{
        play();
        printf("\nPress 'q' to quit or any other key to continue playing: ");
        scanf(" %c",&choice);
    } while(choice != 'q');

    printf("\nThanks for playing! Your final score is %d", score);
    return 0;
}