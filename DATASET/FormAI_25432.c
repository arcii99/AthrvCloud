//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: future-proof
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

const int NUMBER_OF_ROOMS = 10;

int main() {
    
    // set up random seed
    srand(time(NULL));
    
    // create array to store which rooms have been visited
    int visitedRooms[NUMBER_OF_ROOMS];
    for(int i = 0; i < NUMBER_OF_ROOMS; i++) {
        visitedRooms[i] = 0;
    }
    
    // initialize player location and health
    int playerLocation = rand() % NUMBER_OF_ROOMS;
    int playerHealth = 100;
    
    // print welcome message
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You wake up in a dark room with no memory of how you got here...\n");
    printf("Your objective is to find a way out of the haunted house before your health reaches 0.\n");
    printf("Be careful though, there may be dangers lurking around every corner...\n\n");
    
    // simulate game loop
    while(1) {
        
        // check if player is dead
        if(playerHealth <= 0) {
            printf("Your health has reached 0, and you have died. GAME OVER.\n");
            break;
        }
        
        // check if player is at exit
        if(playerLocation == NUMBER_OF_ROOMS-1) {
            printf("Congratulations, you have found the exit and escaped the haunted house! YOU WIN.\n");
            break;
        }
        
        // print current status
        printf("Current health: %d\n", playerHealth);
        printf("You are currently in room %d.\n", playerLocation+1);
        printf("You can see doors leading to the following rooms:\n");
        for(int i = 0; i < NUMBER_OF_ROOMS; i++) {
            if(i == playerLocation) {
                printf("- Room %d (You are here)\n", i+1);
            }
            else if(visitedRooms[i]) {
                printf("- Room %d (Visited)\n", i+1);
            }
            else {
                printf("- Room %d\n", i+1);
            }
        }
        
        // simulate player input
        int choice;
        do {
            printf("\nWhich room do you want to explore? (Enter room number): ");
            scanf("%d", &choice);
        } while(choice < 1 || choice > NUMBER_OF_ROOMS || choice == playerLocation+1);
        
        // mark room as visited
        visitedRooms[choice-1] = 1;
        
        // simulate room encounter
        int encounter = rand() % 3;
        switch(encounter) {
            case 0:
                printf("\nYou enter the room and find nothing of interest.\n");
                break;
            case 1:
                printf("\nYou enter the room and feel a cold breeze...the temperature drops rapidly!\n");
                printf("You take 15 damage from the cold.\n");
                playerHealth -= 15;
                break;
            case 2:
                printf("\nYou enter the room and suddenly hear a loud noise...a ghost appears!\n");
                printf("You must fight the ghost to continue...\n");
                int ghostHealth = 30;
                while(ghostHealth > 0) {
                    int attack = rand() % 6 + 1;
                    printf("\nYou attack the ghost with your weapon for %d damage.\n", attack);
                    ghostHealth -= attack;
                    if(ghostHealth <= 0) {
                        printf("\nYou have defeated the ghost and can continue on your journey.\n");
                    }
                    else {
                        printf("The ghost attacks you for 10 damage.\n");
                        playerHealth -= 10;
                        if(playerHealth <= 0) {
                            break;
                        }
                    }
                }
                break;
        }
        
        // move player to new room
        playerLocation = choice-1;
        
    }
    
    return 0;
}