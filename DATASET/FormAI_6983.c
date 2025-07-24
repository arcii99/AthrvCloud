//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: visionary
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int rooms_visited = 0;
    int total_rooms = 8;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You find yourself at the entrance of a spooky old mansion.\n");
    printf("You have %d rooms to explore before you can escape.\n\n", total_rooms);

    char command[25];

    while(rooms_visited < total_rooms) {
        printf("> ");
        scanf("%s", command);

        if (strcmp(command, "explore") == 0) {
            // Generate random number to determine if something spooky happens
            srand(time(NULL));
            int chance = rand() % 10 + 1;

            if (chance <= 3) { // 30% chance of something spooky happening
                printf("You hear an eerie whisper in your ear... but there's no one around.\n");
            } else {
                printf("You explore the room but find nothing of interest.\n");
            }

            rooms_visited++;
            printf("%d rooms visited. %d more to go.\n", rooms_visited, total_rooms - rooms_visited);
        } else if (strcmp(command, "escape") == 0) {
            printf("You try to escape but the door slams shut and won't budge.\n");
        } else {
            printf("Invalid command. Please try again.\n");
        }
    }

    printf("\nCongratulations, you escaped the haunted house!\n");
    printf("You explored all %d rooms and made it out alive.\n", total_rooms);

    return 0;
}