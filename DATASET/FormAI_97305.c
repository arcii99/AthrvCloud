//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    
    // define the haunted house
    char* house[5] = {
        "You are standing in a dark hallway.",
        "You hear creaking floorboards underfoot.",
        "A sudden gust of wind blows out a candle.",
        "An eerie voice whispers your name.",
        "You see a shadowy figure in the distance."
    };
    
    // define the exits from each room
    int exits[5][3] = {
        {1, -1, -1},
        {2, 0, -1},
        {3, 1, -1},
        {4, 2, -1},
        {-1, 3, -1}
    };
    
    // set the starting room
    int currentRoom = 0;
    
    while (true) {
        // print the current room description
        printf("%s\n", house[currentRoom]);
        
        // check for exits
        int numExits = 0;
        int possibleExits[3];
        for (int i = 0; i < 3; i++) {
            if (exits[currentRoom][i] != -1) {
                possibleExits[numExits] = exits[currentRoom][i];
                numExits++;
            }
        }
        
        // if there are no exits, the game is over
        if (numExits == 0) {
            printf("You are trapped in the haunted house forever...\n");
            return 0;
        }
        
        // randomly choose an exit
        int chosenExit = possibleExits[rand() % numExits];
        
        // move to the next room
        currentRoom = chosenExit;
    }
    
    return 0;
}