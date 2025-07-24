//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: interoperable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MIN_ROOMS 5
#define MAX_GHOSTS 3

int generateRandom(int minVal, int maxVal) {
    int num = 0;
    num = (rand() % (maxVal - minVal + 1)) + minVal;   
    return num;
}

int main() {
    srand(time(NULL));
    int numRooms = generateRandom(MIN_ROOMS, MAX_ROOMS);
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You have entered a haunted house with %d rooms.\n", numRooms);
    int currentRoom = 1;
    int ghostsRemaining = generateRandom(1, MAX_GHOSTS);
    printf("There are %d ghosts that haunt this house.\n", ghostsRemaining);

    while(currentRoom <= numRooms) {
        printf("You are currently in room %d.\n", currentRoom); 
        if(ghostsRemaining > 0) {
            printf("You sense a presence.\n");
            ghostsRemaining--;
            if(ghostsRemaining == 0) {
                printf("You have put the ghosts to rest.\n");
            }
            else {
                printf("%d ghosts remain.\n", ghostsRemaining);
            }
        }
        else {
            printf("This room is quiet.\n");
        }
        printf("Press enter to move to the next room.");
        getchar();
        currentRoom++;
    }

    printf("You have successfully explored all the rooms in the haunted house.\n");
    printf("Thank you for playing the Haunted House Simulator!");

    return 0;
}