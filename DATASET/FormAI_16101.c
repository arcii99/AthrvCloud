//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: dynamic
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // seed the random number generator
    int room = 1; // start in the first room
    int correct_door = rand() % 3 + 1; // randomly select a door with the prize
    
    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are currently in the first room. You must choose a door to continue.\n\n");
    
    while (room <= 5) { // continue playing until all rooms are cleared
        printf("Room %d:\n", room);
        
        // present the 3 doors and ask for user input
        printf("Choose a door (1, 2, or 3): ");
        int user_choice;
        scanf("%d", &user_choice);
        
        // validate the user's input
        if (user_choice < 1 || user_choice > 3) {
            printf("Invalid choice. Please choose a door between 1 and 3.\n\n");
            continue; // skip to next iteration of while loop
        }
        
        // determine if the user chose the correct door
        if (user_choice == correct_door) {
            printf("Congratulations! You found the treasure! Move on to the next room.\n\n");
            correct_door = rand() % 3 + 1; // choose a new door for the next room
            room++; // increment to the next room
        } else {
            printf("Sorry, that door leads to a spooky ghost. Please choose again.\n\n");
        }
    }
    
    printf("Congratulations! You have escaped the haunted house!\n");
    
    return 0;
}