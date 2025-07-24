//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: imaginative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void) {
    //initialize random seed
    srand(time(NULL));

    //create an array with different room descriptions
    char *rooms[] = {"You are in a dark room with cobwebs covering the ceiling. You can hear something moving in the shadows.",
                    "You enter a dining room where a table is set for a feast but no one is there. Plates are scattered on the floor and there's an unsettling feeling in the air.",
                    "You step into a room with tattered curtains and a rocking chair in the corner. Every so often, the rocking chair creaks and moves on its own.",
                    "You walk up a narrow staircase and find yourself in a room with an old piano. You hear faint music playing, but no one is around to touch the keys.",
                    "You are in a room filled with mirrors. As you look into them, you see your reflection beginning to distort and change."};
    
    //set starting room to be the first room in the array
    int roomIndex = 0;
    printf("%s\n", rooms[roomIndex]); //print the starting room description

    //initialize game loop
    while (1) {
        //generate a random number between 1 and 3 to simulate player choices
        int choice = (rand() % 3) + 1;

        //based on the player's choice, modify the room index and print the next corresponding room description
        switch (choice) {
            case 1:
                if (roomIndex == 0) { //if already in the first room, player cannot go back any further
                    printf("You cannot go back any further.\n\n");
                } else {
                    roomIndex--; 
                    printf("%s\n", rooms[roomIndex]);
                }
                break;
            case 2:
                if (roomIndex == 4) { //if already in the last room, player cannot move forward any further
                    printf("You cannot go any further.\n\n");
                } else {
                    roomIndex++;
                    printf("%s\n", rooms[roomIndex]);
                }
                break;
            case 3:
                printf("You are too paralyzed with fear to make a choice.\n\n");
                break;
            default:
                break;
        }

        //if player reaches the last room, end the game loop
        if (roomIndex == 4) {
            printf("Congratulations, you made it out of the haunted house!\n");
            break;
        }
    }

    return 0;
}