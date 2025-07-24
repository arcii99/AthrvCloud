//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: expert-level
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int room = 1;
    int choice;
    
    // Generate seed for randomization
    srand(time(NULL));
    
    printf("Welcome to the Haunted House Simulator!\n");
    
    while(room != 7) {
        printf("You are in room %d\n", room);
        
        // Generate a random number between 1 and 3 for room choices
        choice = rand() % 3 + 1;
        
        // Determine the room choices based on the current room
        if(room == 1) {
            printf("You can go to room 2 or room 3\n");
            
            if(choice == 1) {
                printf("You chose to go to room 2\n");
                room = 2;
            } else {
                printf("You chose to go to room 3\n");
                room = 3;
            }
        } else if(room == 2) {
            printf("You can go to room 1 or room 4\n");
            
            if(choice == 1) {
                printf("You chose to go to room 1\n");
                room = 1;
            } else {
                printf("You chose to go to room 4\n");
                room = 4;
            }
        } else if(room == 3) {
            printf("You can go to room 1 or room 5\n");
            
            if(choice == 1) {
                printf("You chose to go to room 1\n");
                room = 1;
            } else {
                printf("You chose to go to room 5\n");
                room = 5;
            }
        } else if(room == 4) {
            printf("You can go to room 2, room 5, or room 6\n");
            
            if(choice == 1) {
                printf("You chose to go to room 2\n");
                room = 2;
            } else if(choice == 2) {
                printf("You chose to go to room 5\n");
                room = 5;
            } else {
                printf("You chose to go to room 6\n");
                room = 6;
            }
        } else if(room == 5) {
            printf("You can go to room 3, room 4, or room 7\n");
            
            if(choice == 1) {
                printf("You chose to go to room 3\n");
                room = 3;
            } else if(choice == 2) {
                printf("You chose to go to room 4\n");
                room = 4;
            } else {
                printf("You chose to go to room 7\n");
                room = 7;
            }
        } else {
            printf("You can go to room 5 or room 6\n");
            
            if(choice == 1) {
                printf("You chose to go to room 5\n");
                room = 5;
            } else {
                printf("You chose to go to room 6\n");
                room = 6;
            }
        }
        
        printf("\n");
    }
    
    printf("Congratulations! You made it out of the haunted house alive!\n");
    
    return 0;
}