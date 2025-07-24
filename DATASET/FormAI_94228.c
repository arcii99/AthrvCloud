//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: minimalist
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

// function to get random number within given range
int get_random(int min, int max){
    return (rand() % (max - min + 1)) + min;
}

// main function
int main(){
    srand(time(0)); // seed for random function
    int myShipHP = 100; // initialize my ship's HP
    int enemyShipHP = 100; // initialize enemy ship's HP
    int myAttackPower = 20; // set my ship's attack power
    int enemyAttackPower = 15; // set enemy ship's attack power
    int turnCounter = 1; // set turn counter to 1

    // game loop
    while(myShipHP > 0 && enemyShipHP > 0){
        printf("\nTurn %d\n", turnCounter); // print current turn number

        // player attack phase
        int myDamage = get_random(myAttackPower-10, myAttackPower+10); // calculate damage done by player
        printf("Your ship attacks and deals %d damage to the enemy ship.\n", myDamage);
        enemyShipHP -= myDamage; // reduce enemy ship's HP by player's damage

        // enemy attack phase
        int enemyDamage = get_random(enemyAttackPower-5, enemyAttackPower+15); // calculate damage done by enemy
        printf("The enemy ship attacks and deals %d damage to your ship.\n", enemyDamage);
        myShipHP -= enemyDamage; // reduce player's ship HP by enemy's damage

        // print current HP of both ships
        printf("Your ship's HP: %d\n", myShipHP);
        printf("Enemy ship's HP: %d\n", enemyShipHP);

        turnCounter++; // increment turn counter
    }

    // determine winner
    if(myShipHP <= 0 && enemyShipHP <= 0){
        printf("\nThe battle ended in a draw!");
    }
    else if(myShipHP <= 0){
        printf("\nYou lost the battle.");
    }
    else{
        printf("\nYou won the battle!");
    }

    return 0; // exit program
}