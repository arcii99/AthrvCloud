//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_ROOMS 10

// Room data structure
typedef struct room {
    int number;
    char description[50];
} Room;

// Function to generate a random number between min and max (inclusive)
int get_random_number(int min, int max) {
    return rand() % (max - min + 1) + min;
}

int main() {
    srand(time(NULL)); // Seed the random number generator

    Room rooms[MAX_ROOMS]; // Array to hold the rooms

    // Populate the rooms with random descriptions
    for (int i = 0; i < MAX_ROOMS; i++) {
        rooms[i].number = i+1;
        switch (get_random_number(1, 5)) {
            case 1:
                strcpy(rooms[i].description, "You enter a dimly lit room filled with cobwebs.");
                break;
            case 2:
                strcpy(rooms[i].description, "You step into a room that smells like musty old books.");
                break;
            case 3:
                strcpy(rooms[i].description, "You are surrounded by rusted chains and creaking gears.");
                break;
            case 4:
                strcpy(rooms[i].description, "You enter a room with a single candle flickering in the corner.");
                break;
            case 5:
                strcpy(rooms[i].description, "This room is filled with eerie glass jars full of strange specimens.");
                break;
        }
    }

    // Start the game loop
    int current_room = 0;
    int game_over = 0;

    printf("\nWelcome to the Haunted House Simulator!\n");
    printf("You find yourself in a dimly lit room with a single door in front of you.\n");

    while (!game_over) {
        printf("\n%s\n", rooms[current_room].description);

        // Offer the player a choice of which door to take
        int door_choice = 0;
        do {
            printf("Which door do you choose?\n");
            printf("1. North\n2. East\n3. South\n4. West\n");
            printf("Enter 1, 2, 3, or 4: ");
            scanf("%d", &door_choice);
        } while (door_choice < 1 || door_choice > 4);

        // Update the current room based on the door choice
        switch (door_choice) {
            case 1:
                if (current_room < 3) {
                    current_room += 7;
                } else {
                    current_room -= 3;
                }
                break;
            case 2:
                if (current_room % 3 != 2) {
                    current_room++;
                }
                break;
            case 3:
                if (current_room < 7) {
                    current_room += 3;
                } else {
                    current_room -= 7;
                }
                break;
            case 4:
                if (current_room % 3 != 0) {
                    current_room--;
                }
                break;
            default:
                printf("Invalid input. Try again.\n");
                continue;
        }

        printf("\nYou enter room %d.\n", rooms[current_room].number);

        // Check if the player has reached the end of the game
        if (rooms[current_room].number == MAX_ROOMS) {
            printf("Congratulations! You have made it through the haunted house alive!\n");
            game_over = 1;
        }
    }

    return 0;
}