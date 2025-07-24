//FormAI DATASET v1.0 Category: Dice Roller ; Style: post-apocalyptic
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//function to roll a dice and return the value
int rollDice(){
    int diceRoll = (rand() % 6) + 1;
    return diceRoll;
}

//function to generate a random game scenario
void apocalypse(){
    int scenario = (rand() % 4) + 1;
    switch(scenario){
        case 1:
            printf("A group of raiders ambush you.\n");
            printf("You have to fight them off with dice rolls!\n\n");
            break;
        case 2:
            printf("You stumble upon a hidden stash of supplies.\n");
            printf("You have to roll a higher dice value than 4 to successfully collect them.\n\n");
            break;
        case 3:
            printf("You encounter a group of survivors who need help.\n");
            printf("You have to roll a dice value higher than their combined score to successfully assist them.\n\n");
            break;
        case 4:
            printf("You are chased by a horde of zombies!\n");
            printf("You have to roll a dice value higher than their total count to successfully outrun them.\n\n");
            break;
    }
}

int main(){
    srand(time(0)); //seed the random number generator with current time
    int playerScore = 0; //initialize player score to 0
    int enemyScore = 0; //initialize enemy score to 0
    apocalypse(); //generate a random game scenario
    
    //start the game loop
    while(playerScore < 3 && enemyScore < 3){
        int playerRoll = rollDice(); //roll the dice for the player
        printf("You rolled a %d!\n", playerRoll);
        int enemyRoll = rollDice(); //roll the dice for the enemy
        printf("The enemy rolled a %d!\n\n", enemyRoll);
        
        //check who has won the game scenario
        switch(rand() % 2){
            case 0:
                printf("You won this round!\n");
                playerScore++;
                break;
            case 1:
                printf("The enemy won this round.\n");
                enemyScore++;
                break;
        }
        
        //print the current scores
        printf("Current score: You %d - %d Enemy\n\n", playerScore, enemyScore);
    }
    
    //check who has won the game overall
    if(playerScore > enemyScore){
        printf("CONGRATULATIONS! You have survived the apocalypse!\n");
    }
    else{
        printf("GAME OVER. You have been defeated by the apocalypse.\n");
    }
    
    return 0;
}