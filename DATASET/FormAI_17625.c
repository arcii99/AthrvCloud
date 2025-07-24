//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complete
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int numRooms = 8; // total number of rooms in the haunted house
    int currentRoom = 1; // starting room
    int playerHealth = 10; // initial health, maximum health is 20
    int playerScore = 0; // initial score
    int ghostEncounters = 0; // counter to track ghost encounters
    int hasKey = 0; // flag to identify whether player has key or not
    int trapEncounters = 0; // counter to track trap encounters
        
    // seed random number generator
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are starting in Room %d.\n", currentRoom);
    printf("Your current health is %d out of 20.\n", playerHealth);
    printf("Your current score is %d.\n\n", playerScore);
    
    // game loop
    while (currentRoom <= numRooms)
    {
        int encounterChance = rand() % 101; // random number to determine whether a ghost or trap is encountered
        
        // player moves to next room
        currentRoom++;
        
        printf("You have entered Room %d.\n", currentRoom);
        
        // ghost encounter
        if (encounterChance < 40 && ghostEncounters < 3)
        {
            printf("You have encountered a ghost!\n");
            int ghostHealth = rand() % 6 + 5; // random health for the ghost
            while (playerHealth > 0 && ghostHealth > 0)
            {
                int playerAttack = rand() % 3 + 1; // random player attack damage
                int ghostAttack = rand() % 4 + 1; // random ghost attack damage
                
                ghostHealth -= playerAttack;
                playerHealth -= ghostAttack;
                
                printf("You attacked the ghost and dealt %d damage! Ghost's health is now %d.\n", playerAttack, ghostHealth);
                printf("The ghost attacked you and dealt %d damage! Your health is now %d.\n", ghostAttack, playerHealth);
            }
            if (playerHealth <= 0)
            {
                printf("You have been killed by the ghost. Game over.\n");
                exit(0);
            }
            else
            {
                printf("You have defeated the ghost!\n");
                playerScore += 50;
                ghostEncounters++;
            }
        }
        // trap encounter
        else if (encounterChance >= 40 && encounterChance < 70 && trapEncounters < 2)
        {
            printf("You have encountered a trap!\n");
            playerHealth -= 5;
            printf("You have lost 5 health points. Your health is now %d out of 20.\n", playerHealth);
            trapEncounters++;
        }
        // key encounter
        else if (encounterChance >= 70 && encounterChance <= 100 && hasKey == 0)
        {
            printf("You have found a key!\n");
            hasKey = 1;
            playerScore += 10;
        }
        else
        {
            printf("No ghosts, traps, or keys in this room.\n");
        }
        
        printf("Your current score is %d.\n\n", playerScore);
    }
    
    // final room
    printf("You have entered the final room!\n");
    if (hasKey == 1)
    {
        printf("You have used the key to unlock the door and escape the haunted house!\n");
        playerScore += 100;
        printf("Your final score is %d.\n", playerScore);
    }
    else
    {
        printf("You do not have the key to unlock the door and escape. Game over.\n");
        printf("Your final score is %d.\n", playerScore);
    }
    
    return 0;
}