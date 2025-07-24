//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: portable
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL)); // Seed random number generator with system time

    // Define arrays of creepy objects
    char *rooms[] = {"Attic", "Basement", "Bedroom", "Kitchen", "Living Room", "Dining Room", "Bathroom"};
    char *objects[] = {"Ouija Board", "Coffin", "Spiderweb", "Skeleton", "Ghost", "Candlestick", "Grim Reaper"};

    // Generate random room and object
    int room_index = rand() % 7;
    int object_index = rand() % 7;

    // Print creepy message
    printf("You enter the %s and see a %s!\n", rooms[room_index], objects[object_index]);

    return 0;
}