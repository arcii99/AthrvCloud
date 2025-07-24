//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: statistical
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10
#define MAX_GHOSTS 5

int generateRandomNumber(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL));
    const char* rooms[MAX_ROOMS] = {"Living Room", "Dining Room", "Kitchen", "Bedroom", "Bathroom", "Attic", "Basement", "Study", "Library", "Drawing Room"};
    const char* ghosts[MAX_GHOSTS] = {"The Lady in White", "The Headless Knight", "The Screaming Child", "The Crying Widow", "The Murdered Butler"};

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You have just entered a creepy old house and you want to explore it. \n");
    printf("You should be warned though, there are ghosts in this house! \n\n");

    int currentRoom = 0;
    int ghostCount = 0;
    while (ghostCount < MAX_GHOSTS && currentRoom < MAX_ROOMS) {
        printf("You have entered the %s. ", rooms[currentRoom]);
        int random = generateRandomNumber(1, 10);
        if (random <= 3) {
            printf("Unfortunately, this room is haunted by %s!\n", ghosts[generateRandomNumber(0, MAX_GHOSTS-1)]);
            ghostCount++;
        } else {
            printf("This room seems to be safe for now. \n");
        }
        currentRoom++;
    }

    if (ghostCount == MAX_GHOSTS) {
        printf("\nYou have encountered all the ghosts! The house is too dangerous to explore any further...");
    } else {
        printf("\nYou have explored all the rooms and there are no more ghosts left...");
    }

    return 0;
}