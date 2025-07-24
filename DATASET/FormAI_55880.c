//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Function to generate random number between two integers */
int randomNumber(int min, int max) {
    srand(time(0));
    return (rand() % (max - min + 1)) + min;
}

int main() {
    // Initializing variables
    int playerHealth = 100;
    int ghostHealth = 100;
    int roomNumber = 1;
    int numberOfRooms = 10;
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are starting in room number %d\n", roomNumber);
    
    // Looping through the rooms
    while (roomNumber <= numberOfRooms) {
        printf("\n");
        printf("You enter room number %d\n", roomNumber);
        
        // Generating trap or monster
        int event = randomNumber(1, 10);
        if (event <= 4) { // Trap
            printf("You have encountered a trap!\n");
            int damage = randomNumber(10, 20);
            playerHealth -= damage;
            printf("You have taken %d damage\n", damage);
            if (playerHealth <= 0) {
                printf("You have died! Game over!\n");
                return 0;
            }
        } else { // Monster
            printf("You have encountered a ghost!\n");
            printf("You have %d health\n", playerHealth);
            printf("The ghost has %d health\n", ghostHealth);
            
            // Fighting the ghost
            while (ghostHealth > 0) {
                // Player attack
                int playerAttack = randomNumber(10, 20);
                ghostHealth -= playerAttack;
                printf("You have dealt %d damage to the ghost\n", playerAttack);
                if (ghostHealth <= 0) {
                    printf("The ghost is defeated! Congratulations!\n");
                    break;
                }
                
                // Ghost attack
                int ghostAttack = randomNumber(5, 15);
                playerHealth -= ghostAttack;
                printf("The ghost has dealt %d damage to you\n", ghostAttack);
                if (playerHealth <= 0) {
                    printf("You have died! Game over!\n");
                    return 0;
                }
            }
        }
        
        // Moving to next room
        roomNumber++;
        printf("You have cleared room number %d\n", roomNumber-1);
    }
    
    printf("\n");
    printf("Congratulations on completing the Haunted House Simulator!\n");
    printf("Your final health was %d\n", playerHealth);
    
    return 0;
}