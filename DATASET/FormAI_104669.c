//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: creative
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    srand(time(NULL));
    int player_choice, room_number = 1, ghost_in_room, has_key = 0;

    printf("Welcome to the Haunted House Simulator!\n\n");
    printf("You wake up in a room with no memory of how you got there.\n");
    printf("The door is locked and a chill runs down your spine as you notice\n");
    printf("the cobwebs and spiders on the walls.\n\n");

    while(room_number < 6) {
        printf("You are in room %d. What would you like to do?\n", room_number);
        printf("1. Look for a key\n");
        printf("2. Check for ghosts\n");
        printf("3. Move to the next room\n");
        printf("Enter your choice (1-3): ");
        scanf("%d", &player_choice);

        switch(player_choice) {
            case 1:
                int key_chance = rand()%2;
                if(key_chance == 0) {
                    printf("\nYou found a key!\n\n");
                    has_key = 1;
                } else {
                    printf("\nYou did not find a key.\n\n");
                }
                break;
            case 2:
                ghost_in_room = rand()%2;
                if(ghost_in_room == 0) {
                    printf("\nYou hear the sound of chains rattling...\n");
                    printf("Suddenly, a ghost appears and you feel its icy breath on your neck!\n\n");
                } else {
                    printf("\nYou do not sense any ghosts in this room.\n\n");
                }
                break;
            case 3:
                if(room_number == 5 && has_key == 0) {
                    printf("\nYou cannot proceed without a key!\n\n");
                } else {
                    printf("\nYou move to the next room.\n\n");
                    room_number++;
                }
                break;
            default:
                printf("\nInvalid choice.\n\n");
                break;
        }
    }

    printf("Congratulations, you made it through all 5 rooms!\n");
    printf("You grab the door handle and turn. The door creaks open\n");
    printf("but there is nothing on the other side...only an eerie mist.\n");
    printf("You step through and the door slams shut.\n\n");
    printf("You wake up in your own bed, unsure if it was all just a nightmare...\n");

    return 0;
}