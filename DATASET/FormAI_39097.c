//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ENEMY_SHIPS 5
#define MAX_DISTANCE 1000

// Function to generate random distance between user ship and enemy ships
int generateRandomDistance(){
    return rand() % MAX_DISTANCE;
}

// Function to simulate space battle
void spaceBattle(){
    printf("Welcome to the Procedural Space Adventure!\n\n");

    // Generate random distance from user ship to enemy ships
    int enemyShipDistances[MAX_ENEMY_SHIPS];
    for(int i=0; i<MAX_ENEMY_SHIPS; i++){
        enemyShipDistances[i] = generateRandomDistance();
    }

    // Sort the distances in ascending order
    for(int i=0; i<MAX_ENEMY_SHIPS-1; i++){
        for(int j=i+1; j<MAX_ENEMY_SHIPS; j++){
            if(enemyShipDistances[i] > enemyShipDistances[j]){
                int temp = enemyShipDistances[i];
                enemyShipDistances[i] = enemyShipDistances[j];
                enemyShipDistances[j] = temp;
            }
        }
    }

    printf("Enemy Ships Detected!\n");
    for(int i=0; i<MAX_ENEMY_SHIPS; i++){
        printf("Enemy Ship %d at Distance %d\n", i+1, enemyShipDistances[i]);
    }

    // User ship attacks the closest enemy ship
    printf("User Ship Attacks!\n");
    printf("Targeting Enemy Ship at Distance %d\n", enemyShipDistances[0]);
    printf("Firing Laser Beams!\n");

    // Check if user ship is successful in destroying the enemy ship
    int hitProbability = rand() % 100;
    if(hitProbability >= 50){
        printf("Direct Hit! Enemy Ship Destroyed!\n");
    } else {
        printf("Target Missed! Enemy Ship Survived!\n");
    }
}

int main(){
    // Seed the random number generator
    srand(time(NULL));

    // Simulate space battle
    spaceBattle();

    return 0;
}