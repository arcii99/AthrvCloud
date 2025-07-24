//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: happy
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // to generate random numbers
    
    printf("Welcome to the Happy Haunted House Simulator!\n");
    printf("---------------------------------------------\n");
    
    int rooms[6][4] = { // matrix representing the haunted house layout
        {0, 1, 2, 3},
        {4, 5, 6, 7},
        {8, 9, 10, 11},
        {12, 13, 14, 15},
        {16, 17, 18, 19},
        {20, 21, 22, 23}
    };
    
    int currRoom = 0; // starting room
    int numGhosts = 0; // counter for number of ghosts encountered
    
    printf("\nYou are now in Room %d\n", currRoom);
    printf("The room is filled with decorations and spooky music!\n\n");
    
    while(currRoom != 23) { // loop until final room is reached
        int randVal = rand() % 4;
        int nextRoom = rooms[currRoom][randVal]; // randomly select next room
        
        printf("You walk into Room %d\n", nextRoom);
        
        if(nextRoom % 2 == 0) { // check if room number is even
            numGhosts++; // increment ghost counter
            printf("Oh no! You encountered a ghost! Boo!\n");
            printf("Number of ghosts encountered so far: %d\n", numGhosts);
        } else {
            printf("This room is safe. Phew!\n");
        }
        
        currRoom = nextRoom; // update current room
        printf("You are now in Room %d\n", currRoom);
        printf("\n");
    }
    
    printf("You have made it out of the Haunted House! Congratulations!\n");
    printf("Number of ghosts encountered: %d\n", numGhosts);
    
    return 0;
}