//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: lively
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void pause() {
    printf("Press enter to continue...");
    getchar(); // consume the enter key
    getchar(); // wait for the user to press enter again
}

int main() {
    srand(time(NULL)); // seed the random number generator
    int scareCounter = 0;
    printf("You step up to the gate of the old Haunted Castle. Do you:\n");
    printf("a) Enter the castle\n");
    printf("b) Run away\n");
    printf("Enter your choice (a/b): ");
    char choice = getchar();
    getchar(); // consume the enter key
    if (choice == 'a') {
        // Proceed with the simulation
        printf("You push open the gate and step inside. The door slams shut behind you and you hear it lock.\n");
        pause();
        printf("You find yourself in a dark hallway, with several doors on either side. Do you:\n");
        printf("a) Open the first door\n");
        printf("b) Keep walking down the hallway\n");
        printf("Enter your choice (a/b): ");
        choice = getchar();
        getchar(); // consume the enter key
        if (choice == 'a') {
            // Enter the first room
            printf("You cautiously open the door and step inside. The room is dark, but you can see a faint glow in the corner.\n");
            pause();
            printf("As you approach, the glow gets brighter and brighter until you realize that you are standing in front of a ghostly apparition!\n");
            scareCounter++;
            printf("You have been scared %d times so far!\n", scareCounter);
            pause();
            printf("You quickly leave the room and continue down the hallway...\n");
            pause();
        }
        // Repeat for the other doors and hallway choices
        // ...
        // After exploring all the rooms, you reach the final door
        printf("You come to the end of the hallway and find a large wooden door. It's slightly ajar, and you can see a dim light coming from inside.\n");
        pause();
        printf("You push open the door and step inside. The room is a large hall, with a grand staircase leading up to a second floor. You can hear strange noises coming from upstairs.\n");
        pause();
        printf("Do you:\n");
        printf("a) Climb the stairs to the second floor\n");
        printf("b) Look around the first floor some more\n");
        printf("Enter your choice (a/b): ");
        choice = getchar();
        getchar(); // consume the enter key
        if (choice == 'a') {
            // Climb the stairs
            printf("You climb the stairs, feeling a sense of dread growing inside you with each step.\n");
            pause();
            printf("As you reach the top, you see a figure standing at the end of the hallway. It's tall and thin, with long arms and legs and glowing red eyes.\n");
            scareCounter++;
            printf("You have been scared %d times so far!\n", scareCounter);
            pause();
            printf("You turn and flee down the stairs, running as fast as you can back to the front door. You push against it with all your might and it finally gives way, sending you tumbling outside into the night.\n");
            pause();
            printf("You've made it out alive, but you're shaking and covered in sweat. You vow to never enter a haunted house again.\n");
            pause();
        } else {
            // Continue exploring the first floor
            printf("You decide to keep exploring the first floor. As you move deeper into the room, you hear a loud creaking noise coming from the floor.\n");
            pause();
            printf("Suddenly, the floor gives way beneath you and you fall into a dark, damp basement. You hear a door slam shut above you.\n");
            scareCounter++;
            printf("You have been scared %d times so far!\n", scareCounter);
            pause();
            printf("You look around frantically, searching for a way out. There's a dim light coming from across the room, and you can see a set of stairs leading up. You dash towards them and start climbing...\n");
            pause();
            printf("As you reach the top, you see a figure standing at the end of the hallway. It's tall and thin, with long arms and legs and glowing red eyes.\n");
            scareCounter++;
            printf("You have been scared %d times so far!\n", scareCounter);
            pause();
            printf("You turn and flee down the stairs, running as fast as you can back to the front door. You push against it with all your might and it finally gives way, sending you tumbling outside into the night.\n");
            pause();
            printf("You've made it out alive, but you're shaking and covered in sweat. You vow to never enter a haunted house again.\n");
            pause();
        }
    } else {
        printf("You turn and run as fast as you can from the Haunted Castle, never looking back. Coward.\n");
        return 0;
    }
    return 0;
}