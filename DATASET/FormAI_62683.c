//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scalable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to randomly generate a number between min and max (inclusive)
int random_num(int min, int max) {
    return (rand() % (max - min + 1)) + min;
}

int main() {
    int health = 100; // Starting player health
    int damage = 0; // Damage taken by player
    int room = 1; // Starting room number
    
    srand(time(NULL)); // Seed the random number generator with current time
    
    // Print game title and instructions
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are now in the entrance of the haunted house.\n");
    printf("You need to reach the exit in room 10 without losing all your health.\n");
    printf("At each room, you will randomly encounter a ghost or a treasure.\n");
    printf("Good luck!\n\n");
    
    // Loop until player reaches room 10 or loses all their health
    while (room <= 10 && health > 0) {
        printf("You are in room %d\n", room);
        
        // Randomly determine encounter in room
        int encounter = random_num(0, 1); // 0 = Ghost, 1 = Treasure
        
        if (encounter == 0) {
            int ghost_health = random_num(20, 50); // Randomly generate ghost health
            printf("Oh no! You have encountered a ghost with %d health!\n", ghost_health);
            
            // Loop until player defeats ghost or loses all their health
            while (ghost_health > 0 && health > 0) {
                printf("You attack the ghost and deal %d damage!\n", random_num(5, 15));
                ghost_health -= random_num(10, 20); // Randomly generate ghost damage to player
                damage = random_num(5, 15); // Randomly generate player damage taken
                printf("The ghost attacks you and deals %d damage!\n", damage);
                health -= damage;
            }
            
            // Check result of ghost encounter and update room number
            if (health <= 0) {
                printf("Game over! You have lost all your health and failed to escape the haunted house.\n");
                break;
            } 
            else {
                printf("You have defeated the ghost and earned a treasure!\n");
                room++;
            }
        } 
        else {
            int treasure_value = random_num(10, 30); // Randomly generate treasure value
            printf("Congratulations! You have found a treasure worth %d!\n", treasure_value);
            room++;
        }
        printf("---------------------------------------------\n");
    }
    
    // Check if player won or lost the game
    if (health > 0) {
        printf("Congratulations! You have successfully escaped the haunted house!\n");
    } else {
        printf("Game over! You have lost all your health and failed to escape the haunted house.\n");
    }
    
    return 0;
}