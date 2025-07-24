//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: scientific
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    // Welcome message
    printf("Welcome to the Haunted House Simulator! You are about to enter a spooky place...\n");

    // List of scary sounds
    char* scarySounds[] = {
        "Creaking floorboards",
        "Whispers in the distance",
        "Ghosts moaning",
        "Eerie music",
        "Footsteps on the stairs"
    };

    // Random number generator
    srand(time(NULL));

    // Loop through the scary sounds and print one randomly
    for (int i = 0; i < 5; i++) {
        printf("%s\n", scarySounds[rand() % 5]);
    }

    // List of spooky rooms
    char* spookyRooms[] = {
        "The dark and creepy basement",
        "The dusty attic filled with cobwebs",
        "The eerie library with old books",
        "The abandoned bathroom with broken mirrors",
        "The haunted bedroom with a ghostly figure on the bed"
    };

    // Loop through the spooky rooms and print one randomly
    printf("You have entered %s...\n", spookyRooms[rand() % 5]);

    // Scary message
    printf("Suddenly, the door slams shut! You're trapped in the haunted house!\n");

    // List of scary events
    char* scaryEvents[] = {
        "A ghostly apparition appears before you!",
        "You hear the sound of ghostly laughter echoing through the halls!",
        "The lights flicker on and off...",
        "You feel a cold breeze and the hairs on the back of your neck stand up!",
        "You see a shadowy figure lurking in the darkness!"
    };

    // Loop through the scary events and print one randomly
    for (int i = 0; i < 5; i++) {
        printf("%s\n", scaryEvents[rand() % 5]);
    }

    // Final message
    printf("Can you escape the haunted house alive? Good luck...\n");

    return 0;
}