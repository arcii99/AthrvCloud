//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 10
#define MAX_CHOICES 5
#define MAX_CHARS 20

int get_random(int min, int max) {
    return rand() % (max - min + 1) + min;
}

struct Room {
    char name[MAX_CHARS];
    char description[MAX_CHARS * 2];
    int choices[MAX_CHOICES];
    int num_choices;
};

struct Room rooms[MAX_ROOMS];

void initialize_rooms() {
    strcpy(rooms[0].name, "Entrance");
    strcpy(rooms[0].description, "You are standing outside an old, creaky house. The door is slightly ajar, inviting you in.");
    rooms[0].num_choices = 1;
    rooms[0].choices[0] = 1;

    strcpy(rooms[1].name, "Foyer");
    strcpy(rooms[1].description, "You step inside the house and are greeted by a dark, musty foyer. There is a staircase leading up and a hallway leading to the right.");
    rooms[1].num_choices = 2;
    rooms[1].choices[0] = 2;
    rooms[1].choices[1] = 3;

    strcpy(rooms[2].name, "Staircase");
    strcpy(rooms[2].description, "You climb the creaky staircase, each step sending shivers down your spine. At the top of the stairs, there is a door to your left and a hallway to your right.");
    rooms[2].num_choices = 2;
    rooms[2].choices[0] = 4;
    rooms[2].choices[1] = 3;

    strcpy(rooms[3].name, "Hallway");
    strcpy(rooms[3].description, "You walk down the hallway, the walls lined with eerie paintings and the floors creaking underfoot. There is a door to your left and a door at the end of the hallway.");
    rooms[3].num_choices = 2;
    rooms[3].choices[0] = 5;
    rooms[3].choices[1] = 6;

    strcpy(rooms[4].name, "Empty Room");
    strcpy(rooms[4].description, "You enter a dark, empty room. Something rustles in the shadows.");
    rooms[4].num_choices = 1;
    rooms[4].choices[0] = 7;

    strcpy(rooms[5].name, "Library");
    strcpy(rooms[5].description, "You enter a large library, the shelves lined with ancient, dusty tomes. There is a desk in the center of the room.");
    rooms[5].num_choices = 1;
    rooms[5].choices[0] = 7;

    strcpy(rooms[6].name, "Bedroom");
    strcpy(rooms[6].description, "You enter a dark, ominous bedroom. There is a large, four-poster bed in the center of the room.");
    rooms[6].num_choices = 1;
    rooms[6].choices[0] = 7;

    strcpy(rooms[7].name, "Dining Room");
    strcpy(rooms[7].description, "You enter a large dining room, the table set with old, tarnished silverware and dusty plates. There is a fireplace in the corner.");
    rooms[7].num_choices = 1;
    rooms[7].choices[0] = -1;
}

int main() {
    srand(12345);
    initialize_rooms();
    int current_room = 0;

    printf("Welcome to the Haunted House Simulator!\n");
    printf("You are standing outside an old, creaky house. The door is slightly ajar, inviting you in.\n");

    int choice;
    while(1) {
        printf("\n%s\n", rooms[current_room].description);
        printf("What do you want to do?\n");
        for(int i = 0; i < rooms[current_room].num_choices; i++) {
            printf("%d: ", i+1);
            switch(rooms[current_room].choices[i]) {
                case 1:
                    printf("Enter the house\n");
                    break;
                case 2:
                    printf("Go up the stairs\n");
                    break;
                case 3:
                    printf("Go down the hallway\n");
                    break;
                case 4:
                    printf("Open the door to the left\n");
                    break;
                case 5:
                    printf("Open the door at the end of the hallway\n");
                    break;
                case 6:
                    printf("Enter the bedroom\n");
                    break;
                case 7:
                    printf("Explore the room\n");
                    break;
                default:
                    printf("Invalid choice\n");
            }
        }
        printf("Enter your choice (1-%d): ", rooms[current_room].num_choices);
        scanf("%d", &choice);

        if(choice <= 0 || choice > rooms[current_room].num_choices) {
            printf("Invalid choice\n");
            continue;
        }

        int next_room = rooms[current_room].choices[choice-1];

        if(next_room == -1) {
            printf("You have found your way out of the haunted house. Congratulations!\n");
            break;
        }
        else {
            current_room = next_room;
        }
    }
    return 0;
}