//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: complex
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int playerChoice = 0;
    int ghostRoom = rand() % 5 + 1; // Generate random room for ghost to be in
    int playerRoom = 1; // Player starts in room 1
    int numMoves = 0;
    int isGameOver = 0;
    
    srand(time(NULL)); // Seed random number generator
    
    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You are trapped in a haunted house with a ghost.\n");
    printf("There are 5 rooms in the house.\n");
    printf("The ghost is hiding in one of the rooms.\n\n");
    
    while (!isGameOver) {
        printf("You are in room %d.\n", playerRoom);
        printf("Enter your next move (1-5): ");
        scanf("%d", &playerChoice);
        numMoves++;
        
        if (playerChoice == ghostRoom) {
            printf("\nYou found the ghost in room %d!\n", ghostRoom);
            printf("Game over. It took you %d moves to find the ghost.\n", numMoves);
            isGameOver = 1;
        } else {
            if (playerRoom == ghostRoom) {
                printf("\nYou hear creepy noises coming from the room you just left...\n");
            }
            playerRoom = playerChoice;
            printf("\nYou move to room %d.\n", playerRoom);
        }
    }
    
    return 0;
}