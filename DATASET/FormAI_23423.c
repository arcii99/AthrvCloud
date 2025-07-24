//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: ultraprecise
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <time.h>

#define MAX_NAME_LEN 50
#define MAX_INVENTORY_ITEM_COUNT 10

struct Item {
    char name[MAX_NAME_LEN];
    char description[MAX_NAME_LEN*2];
};

struct Room {
    char name[MAX_NAME_LEN];
    char description[MAX_NAME_LEN*2];
    struct Room* north;
    struct Room* south;
    struct Room* east;
    struct Room* west;
    struct Item* items[MAX_INVENTORY_ITEM_COUNT];
    int item_count;
};

struct Game {
    struct Room* current_room;
    struct Room* start_room;
    struct Room* end_room;
};

void print_room_description(struct Room* room)
{
    printf("\nYou are in the %s.\n%s\n", room->name, room->description);
    if (room->item_count > 0) {
        printf("You see:\n");
        for (int i=0; i<room->item_count; i++) {
            printf("- %s\n", room->items[i]->name);
        }
    }
}

void print_inventory(struct Item** inventory, int item_count)
{
    if (item_count == 0) {
        printf("\nYou have no items.\n");
        return;
    }
    printf("\nYou have the following items in your inventory:\n");
    for (int i = 0; i < item_count; i++) {
        printf("- %s\n", inventory[i]->name);
    }
}

int take_item(struct Room* room, struct Item** inventory, int* item_count, char* item_name)
{
    for (int i=0; i<room->item_count; i++) {
        if (strcmp(room->items[i]->name, item_name) == 0) {
            if (*item_count >= MAX_INVENTORY_ITEM_COUNT) {
                printf("\nYou cannot pick up the %s. Your inventory is full!\n", item_name);
                return 0;
            }
            inventory[*item_count] = room->items[i];
            (*item_count)++;
            printf("\nYou pick up the %s.\n", item_name);
            for (int j=i; j<room->item_count-1; j++) {
                room->items[j] = room->items[j+1];
            }
            room->item_count--;
            return 1;
        }
    }
    printf("\nYou cannot find the %s in the current room.\n", item_name);
    return 0;
}

int drop_item(struct Room* room, struct Item** inventory, int* item_count, char* item_name)
{
    for (int i=0; i<*item_count; i++) {
        if (strcmp(inventory[i]->name, item_name) == 0) {
            room->items[room->item_count] = inventory[i];
            room->item_count++;
            printf("\nYou drop the %s.\n", item_name);
            for (int j=i; j<(*item_count)-1; j++) {
                inventory[j] = inventory[j+1];
            }
            (*item_count)--;
            return 1;
        }
    }
    printf("\nYou cannot find the %s in your inventory.\n", item_name);
    return 0;
}

int main()
{
    srand(time(NULL));
    struct Item items[5] = {
        {"key", "A shiny golden key."},
        {"flashlight", "A small but bright flashlight."},
        {"map", "A map of the area."},
        {"book", "A really thick book."},
        {"gun", "A loaded gun."},
    };
    struct Room rooms[6] = {
        {"Room 1", "A small room with one exit to the east."},
        {"Room 2", "A long corridor heading north-south."},
        {"Room 3", "A large room with exits to the north, south, and west. There is a table in the center of the room."},
        {"Room 4", "A dark room with no visible exits. You hear strange noises coming from the shadows."},
        {"Room 5", "A room with a sign that says 'End of Adventure'. Congratulations!"},
        {"Room 6", "A room with exits to the west and south."},
    };
    rooms[0].east = &rooms[1];
    rooms[1].north = &rooms[2];
    rooms[1].south = &rooms[5];
    rooms[2].north = &rooms[3];
    rooms[2].south = &rooms[1];
    rooms[2].west = &rooms[0];
    rooms[3].west = &rooms[4];
    rooms[3].south = &rooms[2];
    rooms[5].north = &rooms[1];
    rooms[5].west = &rooms[3];

    struct Game game = {&rooms[0], &rooms[0], &rooms[4]};

    printf("Welcome to the Text-Based Adventure Game!\n");

    int inventory_count = 0;
    struct Item* inventory[MAX_INVENTORY_ITEM_COUNT];

    while (1) {
        print_room_description(game.current_room);

        char input[100];
        printf("\n>Type 'help' for a list of commands.\nWhat do you want to do? ");
        scanf("%99[^\n]", input);
        getchar();

        if (strcmp(input, "help") == 0) {
            printf("\nCommands:\n");
            printf("go <direction>\n");
            printf("take <item>\n");
            printf("drop <item>\n");
            printf("inventory\n");
            printf("help\n");
            printf("quit\n");
        }
        else if (strcmp(input, "quit") == 0) {
            printf("\nThanks for playing!\n");
            break;
        }
        else if (strncmp(input, "go ", 3) == 0) {
            char* dir = input + 3;
            if (strcmp(dir, "north") == 0 && game.current_room->north != NULL) {
                game.current_room = game.current_room->north;
            }
            else if (strcmp(dir, "south") == 0 && game.current_room->south != NULL) {
                game.current_room = game.current_room->south;
            }
            else if (strcmp(dir, "east") == 0 && game.current_room->east != NULL) {
                game.current_room = game.current_room->east;
            }
            else if (strcmp(dir, "west") == 0 && game.current_room->west != NULL) {
                game.current_room = game.current_room->west;
            }
            else {
                printf("\nYou cannot go in that direction.\n");
            }
        }
        else if (strncmp(input, "take ", 5) == 0) {
            char* item_name = input + 5;
            take_item(game.current_room, inventory, &inventory_count, item_name);
        }
        else if (strncmp(input, "drop ", 5) == 0) {
            char* item_name = input + 5;
            drop_item(game.current_room, inventory, &inventory_count, item_name);
        }
        else if (strcmp(input, "inventory") == 0) {
            print_inventory(inventory, inventory_count);
        }
        else {
            printf("\nInvalid command.\n");
        }

        if (game.current_room == game.end_room) {
            printf("\nCongratulation! You have completed the adventure game!\n");
            break;
        }
    }

    return 0;
}