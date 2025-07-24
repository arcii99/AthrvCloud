//FormAI DATASET v1.0 Category: Procedural Space Adventure ; Style: futuristic
#include <stdio.h>
#include <stdlib.h>

int main(){

    int playerHealth = 100;
    int playerShield = 50;
    int playerAmmo = 100;

    printf("Welcome to Space Adventure!\n");
    printf("The year is 2300 and you are an astronaut exploring the galaxy.\n");
    printf("Your mission is to find a rare mineral on planet Zorgon.\n\n");

    // Code for traveling through space
    printf("You board your spaceship and set a course for Zorgon.\n");
    printf("As you travel through space, you encounter a group of space pirates!\n\n");

    int pirateHealth = 75;
    int pirateShield = 25;
    int pirateAmmo = 50;

    // Code for space battle
    printf("Get ready for battle!\n");
    printf("Player health: %d\n", playerHealth);
    printf("Player shield: %d\n", playerShield);
    printf("Player ammo: %d\n\n", playerAmmo);

    printf("Pirate health: %d\n", pirateHealth);
    printf("Pirate shield: %d\n", pirateShield);
    printf("Pirate ammo: %d\n\n", pirateAmmo);

    while(playerHealth > 0 && pirateHealth > 0){

        // Player attacks first
        printf("You fire your laser gun!\n");
        pirateShield -= 10;

        if(pirateShield < 0){
            pirateShield = 0;
        }

        pirateHealth -= 20;

        if(pirateHealth < 0){
            pirateHealth = 0;
        }

        printf("Pirate shield: %d\n", pirateShield);
        printf("Pirate health: %d\n", pirateHealth);

        // Check if pirate is still alive
        if(pirateHealth <= 0){
            printf("You have defeated the space pirates!\n");
            break;
        }

        // Pirate attacks
        printf("The pirate fires their laser gun!\n");
        playerShield -= 10;

        if(playerShield < 0){
            playerShield = 0;
        }

        playerHealth -= 20;

        if(playerHealth < 0){
            playerHealth = 0;
        }

        printf("Player shield: %d\n", playerShield);
        printf("Player health: %d\n\n", playerHealth);

        // Check if player is still alive
        if(playerHealth <= 0){
            printf("Game over! You have been defeated by the space pirates.\n");
            return 0;
        }

        // Check if player is out of ammo
        playerAmmo -= 10;

        if(playerAmmo <= 0){
            printf("You are out of ammo!\n");
            return 0;
        }
    }

    // Arrival at planet Zorgon
    printf("Congratulations! You have defeated the space pirates and arrived at planet Zorgon.\n");
    printf("As you explore the planet, you find the rare mineral you have been searching for.\n");
    printf("Mission complete!\n\n");

    return 0;
}