//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: expert-level
#include <stdio.h>
#include <string.h>

int rooms[5][5] = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 0},
    {0, 1, 0, 0, 1},
    {0, 0, 0, 0, 1},
    {1, 0, 0, 1, 0}
};

char* room_names[5] = {
    "Entrance Hall",
    "Living Room",
    "Kitchen",
    "Bedroom",
    "Backyard"
};

int current_room = 0;

void print_room() {
    printf("You are currently in the %s.\n", room_names[current_room]);
}

void list_exits() {
    printf("Exits:\n");
    for (int i = 0; i < 5; i++) {
        if (rooms[current_room][i] == 1) {
            printf("- %s\n", room_names[i]);
        }
    }
}

void move(char* direction) {
    int room_index = -1;
    for (int i = 0; i < 5; i++) {
        if (strcmp(direction, room_names[i]) == 0) {
            room_index = i;
            break;
        }
    }
    if (room_index == -1) {
        printf("Invalid direction. Please try again.\n");
    } else if (rooms[current_room][room_index] == 0) {
        printf("You can't go that way. Please try again.\n");
    } else {
        printf("Moving to %s...\n", room_names[room_index]);
        current_room = room_index;
        print_room();
        list_exits();
    }
}

void process_input(char* input) {
    char* p = strtok(input, " \n");
    if (p != NULL) {
        if (strcmp(p, "move") == 0) {
            char* direction = strtok(NULL, " \n");
            if (direction != NULL) {
                move(direction);
            } else {
                printf("Please specify a direction. Valid directions are:\n");
                list_exits();
            }
        } else if (strcmp(p, "list") == 0) {
            list_exits();
        } else if (strcmp(p, "help") == 0) {
            printf("Instructions:\n");
            printf("- To move to another room, type 'move' followed by a valid direction.\n");
            printf("- To list the available exits, type 'list'.\n");
            printf("- To display this help message, type 'help'.\n");
        } else {
            printf("Invalid command. Type 'help' for instructions.\n");
        }
    }
}

int main() {
    printf("Welcome to the Text-Based Adventure Game!\n\n");
    print_room();
    list_exits();
    printf("\nTo display instructions, type 'help'.\n\n");
    char input[50];
    while (1) {
        printf("> ");
        fgets(input, 50, stdin);
        process_input(input);
    }
    return 0;
}