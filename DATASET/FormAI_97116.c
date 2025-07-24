//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10 // Maximum number of rooms in the house
#define MIN_GHOSTS 1 // Minimum number of ghosts in each room
#define MAX_GHOSTS 5 // Maximum number of ghosts in each room

int main() {
    srand(time(NULL)); // Seed the random number generator
    
    char *rooms[MAX_ROOMS] = {"Living Room", "Kitchen", "Bedroom", "Bathroom", "Attic", "Basement", "Dining Room", "Study", "Library", "Pantry"}; // Array of room names
    
    int num_ghosts[MAX_ROOMS]; // Array to store number of ghosts in each room
    for (int i = 0; i < MAX_ROOMS; i++) {
        num_ghosts[i] = rand() % (MAX_GHOSTS - MIN_GHOSTS + 1) + MIN_GHOSTS; // Generate random number of ghosts for each room
    }
    
    printf("Welcome to the Haunted House Simulator! Your objective is to find all the ghosts in the house.\n");
    
    int current_room = rand() % MAX_ROOMS; // Choose a random starting room
    int num_ghosts_found = 0; // Initialize number of ghosts found to 0
    
    while (num_ghosts_found < MAX_ROOMS * MIN_GHOSTS) { // Continue until all ghosts have been found
        printf("You are currently in the %s.\n", rooms[current_room]);
        printf("There are %d ghost(s) in this room.\n", num_ghosts[current_room]);
        
        int num_ghosts_in_room_to_find = num_ghosts[current_room]; // Set number of ghosts in room to find
        
        while (num_ghosts_in_room_to_find > 0) { // Continue until all ghosts in room have been found
            int guess;
            printf("Guess how many ghosts are in the room: ");
            scanf("%d", &guess); // Prompt user for guess
            
            if (guess == num_ghosts[current_room]) { // Correct guess
                printf("You have found %d ghost(s) in the %s.\n", num_ghosts[current_room], rooms[current_room]);
                num_ghosts_found += num_ghosts[current_room];
                num_ghosts_in_room_to_find = 0;
            } else { // Incorrect guess
                printf("You did not find any ghosts.\n");
            }
        }
        
        if (num_ghosts_found < MAX_ROOMS * MIN_GHOSTS) { // Check if all ghosts have been found
            do {
                current_room = (current_room + 1) % MAX_ROOMS; // Choose a random adjacent room
            } while (current_room == (current_room + 1) % MAX_ROOMS);
        }
    }
    
    printf("Congratulations! You have found all the ghosts in the house.\n");
    
    return 0;
}