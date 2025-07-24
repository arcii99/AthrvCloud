//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: surrealist
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int rooms[5][5] = {{1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}, {1, 1, 1, 1, 1}};
    int current_room_x = 2;
    int current_room_y = 2;
    int num_ghosts = 0;
    int num_encounters = 0;
    int num_keys = 0;
    int has_door_key = 0;
    int has_stair_key = 0;

    srand(time(NULL));

    printf("Welcome to the Haunted House Simulator!\n\n");

    while (1) {
        printf("You are in Room (%d, %d).\n", current_room_x, current_room_y);

        // Check if there's a ghost
        int roll = rand() % 6;
        if (roll == 0) {
            printf("You've encountered a ghost! Run for your life!\n");
            num_ghosts++;
        }

        // Check if there's a key
        roll = rand() % 4;
        if (roll == 0) {
            printf("You've found a key! It looks like it might fit a door...\n");
            num_keys++;
        } else if (roll == 1) {
            printf("You've found a key! It looks like it might fit a stairway...\n");
            num_keys++;
        }

        // Check if there's a door
        if (current_room_x > 0 && rooms[current_room_y][current_room_x-1] == 1) {
            printf("There's a door to the west. ");
            if (has_door_key) {
                printf("You have the key, would you like to use it? (y/n) ");
                char input = getchar();
                getchar(); // consume newline
                if (input == 'y') {
                    printf("You use the key to unlock the door!\n");
                    has_door_key = 0;
                    rooms[current_room_y][current_room_x-1] = 0;
                    current_room_x--;
                    continue;
                }
            }
            printf("\n");
        }
        if (current_room_x < 4 && rooms[current_room_y][current_room_x+1] == 1) {
            printf("There's a door to the east. ");
            if (has_door_key) {
                printf("You have the key, would you like to use it? (y/n) ");
                char input = getchar();
                getchar(); // consume newline
                if (input == 'y') {
                    printf("You use the key to unlock the door!\n");
                    has_door_key = 0;
                    rooms[current_room_y][current_room_x+1] = 0;
                    current_room_x++;
                    continue;
                }
            }
            printf("\n");
        }
        if (current_room_y > 0 && rooms[current_room_y-1][current_room_x] == 1) {
            printf("There's a door to the north. ");
            if (has_door_key) {
                printf("You have the key, would you like to use it? (y/n) ");
                char input = getchar();
                getchar(); // consume newline
                if (input == 'y') {
                    printf("You use the key to unlock the door!\n");
                    has_door_key = 0;
                    rooms[current_room_y-1][current_room_x] = 0;
                    current_room_y--;
                    continue;
                }
            }
            printf("\n");
        }
        if (current_room_y < 4 && rooms[current_room_y+1][current_room_x] == 1) {
            printf("There's a door to the south. ");
            if (has_door_key) {
                printf("You have the key, would you like to use it? (y/n) ");
                char input = getchar();
                getchar(); // consume newline
                if (input == 'y') {
                    printf("You use the key to unlock the door!\n");
                    has_door_key = 0;
                    rooms[current_room_y+1][current_room_x] = 0;
                    current_room_y++;
                    continue;
                }
            }
            printf("\n");
        }

        // Check if there's a stairway
        if (rooms[current_room_y][current_room_x] == 2) {
            printf("There's a hidden stairway here! ");
            if (has_stair_key) {
                printf("You have the key, would you like to use it? (y/n) ");
                char input = getchar();
                getchar(); // consume newline
                if (input == 'y') {
                    printf("You use the key to unlock the stairway!\n");
                    has_stair_key = 0;
                    rooms[current_room_y][current_room_x] = 0;

                    printf("\nYou climb the stairs and find yourself in a new room at the top.\n");

                    // Move to a new random room
                    current_room_x = rand() % 5;
                    current_room_y = rand() % 5;

                    continue;
                }
            }
            printf("\n");
        }

        // Check if there's anything left to do
        if (num_keys == 2 && !has_door_key) {
            printf("You've collected both keys! You can now unlock any doors or stairways.\n");
            has_door_key = 1;
            has_stair_key = 1;
        }
        if (num_ghosts == 5) {
            printf("You've encountered too many ghosts and been scared to death! Game over.\n");
            break;
        }
        if (num_encounters == 20) {
            printf("You've explored all the rooms and found nothing else of interest. Game over.\n");
            break;
        }

        // Done with current room, move to a new random room
        current_room_x = rand() % 5;
        current_room_y = rand() % 5;
        num_encounters++;
    }

    printf("\nThank you for playing the Haunted House Simulator!\n");

    return 0;
}