//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: thoughtful
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    // Initialize random number generator
    srand(time(NULL));

    // Introduction
    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("You are exploring an abandoned house known for its haunted past.\n");
    printf("Your objective is to find a way out while avoiding the ghosts and other dangers inside.\n");
    printf("Good luck!\n");

    // Initialize game variables
    int health = 100;
    int stamina = 100;
    int room = 1;

    // Game loop
    while(health > 0) {
        
        // Display current room and status
        printf("\nYou are in room %d.\n", room);
        printf("Current health: %d\n", health);
        printf("Current stamina: %d\n", stamina);
        
        // Determine room type randomly
        int room_type = rand() % 4;
        
        if(room_type == 0) {  // Empty room
            
            printf("The room is empty. Continue exploring.\n");
            
        } else if(room_type == 1) {  // Ghost room
            
            printf("You encounter a ghost!\n");
            
            // Determine outcome of ghost encounter
            int ghost_outcome = rand() % 2;

            if(ghost_outcome == 0) {  // Ghost attack
                
                printf("The ghost attacks you!\n");
                health -= 20;
                
            } else {  // Ghost flee
                
                printf("The ghost flees! Continue exploring.\n");
                
            }
            
        } else if(room_type == 2) {  // Trap room
            
            printf("You fall into a trap!\n");
            
            // Determine outcome of trap encounter
            int trap_outcome = rand() % 2;

            if(trap_outcome == 0) {  // Minor injury
                
                printf("You suffer a minor injury.\n");
                health -= 10;
                stamina -= 10;
                
            } else {  // Major injury
                
                printf("You suffer a major injury.\n");
                health -= 40;
                stamina -= 40;
                
            }
            
        } else {  // Treasure room
            
            printf("You find a treasure! Congrats!\n");
            printf("Your health and stamina are fully restored.\n");
            health = 100;
            stamina = 100;
            
        }
        
        // Check if player is still alive
        if(health <= 0) {
            
            printf("\nGame over. You died.\n");
            break;
            
        }
        
        // Decrease stamina and move to next room
        stamina -= 10;
        room++;
        
        // Check if player has run out of stamina
        if(stamina <= 0) {
            
            printf("\nGame over. You are too tired to continue.\n");
            break;
            
        }
        
    }

    return 0;
}