//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: systematic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));    //Seed the randomizer
    
    int health = 100;    //Set player's health to 100
    int steps = 0;    //Initialize steps taken
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("----------------------------------------\n");
    printf("You have just entered a spooky, old abandoned house.\n");
    printf("As you walk around, you hear strange noises and see creepy objects.\n");
    printf("Your goal is to escape the house without dying.\n");
    
    while(health > 0) {    //While the player is alive
        printf("\nHealth: %d\n", health);    //Print player's current health
        
        int decision = rand() % 2;    //Generate a random decision (0 or 1)
        
        if(decision == 0) {    //If 0, encounter a ghost
            printf("\nYou encountered a ghost!\n");
            printf("You lose 20 health points.\n");
            health -= 20;    //Subtract 20 from player's health
        }
        
        else {    //If 1, keep wandering
            printf("\nYou continue to wander around the house.\n");
        }
        
        int item = rand() % 3;    //Generate a random item (0, 1 or 2)
        
        if(item == 0) {    //If 0, discover a weapon
            printf("You have discovered a weapon!\n");
            printf("Your attack power has been increased.\n");
            printf("You gain 10 health points.\n");
            health += 10;    //Add 10 to player's health
        }
        
        else if(item == 1) {    //If 1, find a health potion
            printf("You have found a health potion!\n");
            printf("Your health has been restored.\n");
            health = 100;    //Restore player's health to 100
        }
        
        else {    //If 2, find nothing
            printf("You search around, but find nothing of value.\n");
        }
        
        steps++;
        
        if(steps == 10) {    //If the player has taken 10 steps, encounter the boss
            printf("\nYou have encountered the boss of the haunted house!\n");
            printf("You will need to defeat him in order to escape.\n");
            
            int bossHealth = 50;    //Set boss health to 50
            
            while(bossHealth > 0) {    //While the boss is alive
                printf("\nBoss Health: %d\n", bossHealth);
                
                int attackPower = rand() % 40 + 10;    //Generate a random attack power between 10 and 50
                bossHealth -= attackPower;    //Subtract attack power from boss's health
                
                if(bossHealth <= 0) {    //If boss's health is now 0 or below, the player wins
                    printf("\nCongratulations! You have defeated the boss and escaped the haunted house!\n");
                    return 0;
                }
                
                printf("The boss attacked you!\n");
                printf("You lose 30 health points.\n");
                health -= 30;    //Subtract 30 from player's health
                
                if(health <= 0) {    //If player runs out of health, game over
                    printf("\nGame Over. You died in the haunted house.\n");
                    return 0;
                }
            }
        }
    }
    
    printf("You have died. Game Over.\n");    //If the player runs out of health at any point in the game
    return 0;
}