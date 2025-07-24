//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: asynchronous
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>
#include <ctype.h>

#define MAX_ROOMS 10
#define MAX_ITEMS 10

typedef struct {
    int id; // room identifier
    char name[20];
    char description[200];
    int items[MAX_ITEMS];
    int n_items;
    int connections[MAX_ROOMS];
    int n_connections;
} Room;

enum Item {
    NONE = 0,
    KEY,
    CANDLE,
    MATCHES,
    BOOK,
    SWORD,
    SHIELD,
    POTION,
    TREASURE,
    MAX_ITEM
};

enum Direction {
    NORTH,
    EAST,
    SOUTH,
    WEST,
    UNKNOWN
};

const char* DIRECTION_NAMES[] = {
    "north",
    "east",
    "south",
    "west"
};

const char* ITEM_NAMES[] = {
    "none",
    "key",
    "candle",
    "matches",
    "book",
    "sword",
    "shield",
    "potion"
};

Room rooms[MAX_ROOMS];
int n_rooms = 0;

int current_room = 0;
int inventory[MAX_ITEMS];
int n_inventory = 0;

char* to_lower(char* str) {
    char* p = str;
    while (*p) {
        *p = tolower(*p);
        p++;
    }
    return str;
}

int get_direction(char* str) {
    str = to_lower(str);
    for (int i = 0; i < 4; i++) {
        if (strcmp(str, DIRECTION_NAMES[i]) == 0) {
            return i;
        }
    }
    return UNKNOWN;
}

int get_item(char* str) {
    str = to_lower(str);
    for (int i = 1; i < MAX_ITEM; i++) {
        if (strcmp(str, ITEM_NAMES[i]) == 0) {
            return i;
        }
    }
    return NONE;
}

void add_item(Room* room, int item) {
    if (room->n_items < MAX_ITEMS) {
        room->items[room->n_items++] = item;
    }
}

void remove_item(Room* room, int item) {
    for (int i = 0; i < room->n_items; i++) {
        if (room->items[i] == item) {
            room->items[i] = NONE;
            for (int j = i + 1; j < room->n_items; j++) {
                room->items[j-1] = room->items[j];
            }
            room->n_items--;
            break;
        }
    }
}

int has_item(int item) {
    for (int i = 0; i < n_inventory; i++) {
        if (inventory[i] == item) {
            return 1;
        }
    }
    return 0;
}

void add_to_inventory(int item) {
    if (n_inventory < MAX_ITEMS) {
        inventory[n_inventory++] = item;
    }
}

void remove_from_inventory(int item) {
    for (int i = 0; i < n_inventory; i++) {
        if (inventory[i] == item) {
            inventory[i] = NONE;
            for (int j = i+1; j < n_inventory; j++) {
                inventory[j-1] = inventory[j];
            }
            n_inventory--;
            break;
        }
    }
}

void replace_n(char* str) {
    char* p;
    if ((p = strchr(str, '\n')) != NULL) {
        *p = '\0';
    }
}

int read_int() {
    int n;
    char line[100];
    fgets(line, 100, stdin);
    replace_n(line);
    sscanf(line, "%d", &n);
    return n;
}

void print_items(int* items, int n) {
    for (int i = 0; i < n; i++) {
        printf("  - %s\n", ITEM_NAMES[items[i]]);
    }
}

void print_room() {
    Room* room = &rooms[current_room];
    printf("You are in the %s.\n", room->name);
    printf("%s\n", room->description);
    if (room->n_items > 0) {
        printf("You see:\n");
        print_items(room->items, room->n_items);
    }
    if (room->n_connections == 1) {
        printf("There is a passage to the %s.\n", DIRECTION_NAMES[room->connections[0]]);
    } else {
        printf("There are passages to the ");
        for (int i = 0; i < room->n_connections; i++) {
            printf("%s", DIRECTION_NAMES[room->connections[i]]);
            if (i < room->n_connections - 1) {
                printf(", ");
            } else {
                printf(".\n");
            }
        }
    }
}

void print_inventory() {
    if (n_inventory == 0) {
        printf("Your inventory is empty.\n");
    } else {
        printf("You have:\n");
        print_items(inventory, n_inventory);
    }
}

void move(enum Direction direction) {
    Room* room = &rooms[current_room];
    for (int i = 0; i < room->n_connections; i++) {
        if (room->connections[i] == direction) {
            current_room = rooms[current_room].connections[i];
            print_room();
            return;
        }
    }
    printf("There is no passage to the %s.\n", DIRECTION_NAMES[direction]);
}

int take(char* str) {
    str = to_lower(str);
    Room* room = &rooms[current_room];
    for (int i = 0; i < room->n_items; i++) {
        if (strcmp(str, ITEM_NAMES[room->items[i]]) == 0) {
            int item = room->items[i];
            add_to_inventory(item);
            remove_item(room, item);
            printf("You take the %s.\n", ITEM_NAMES[item]);
            return 1;
        }
    }
    printf("There is no %s to take.\n", str);
    return 0;
}

int drop(char* str) {
    str = to_lower(str);
    Room* room = &rooms[current_room];
    int item = get_item(str);
    if (has_item(item)) {
        remove_from_inventory(item);
        add_item(room, item);
        printf("You drop the %s.\n", ITEM_NAMES[item]);
        return 1;
    } else {
        printf("You don't have a %s to drop.\n", str);
        return 0;
    }
}

void use(char* str) {
    str = to_lower(str);
    int item = get_item(str);
    if (item == KEY && current_room == 0) {
        printf("You unlock the door with the key. Congratulations, you have escaped!\n");
        exit(0);
    } else if (item == CANDLE) {
        printf("You light the candle. The room is now illuminated.\n");
    } else if (item == MATCHES) {
        printf("You use a match. It lights up for a few seconds and then extinguishes.\n");
    } else if (item == BOOK) {
        printf("You read the book. It contains some interesting stories and puzzles. You feel smarter.\n");
    } else if (item == SWORD || item == SHIELD) {
        Room* room = &rooms[current_room];
        for (int i = 0; i < room->n_items; i++) {
            if (room->items[i] == TREASURE) {
                printf("You use the %s to defeat the dragon and reach the treasure! Congratulations, you have won!\n", ITEM_NAMES[item]);
                exit(0);
            }
        }
        printf("There is no dragon here to fight with.\n");
    } else if (item == POTION) {
        printf("You drink the potion. You feel stronger and healthier.\n");
    } else {
        printf("You can't use that item here.\n");
    }
}

void init_game() {
    n_rooms = 0;
    current_room = 0;
    n_inventory = 0;

    // Create rooms
    rooms[n_rooms].id = n_rooms;
    strcpy(rooms[n_rooms].name, "cell");
    strcpy(rooms[n_rooms].description, "You are in a dark, damp cell. There is a door to the south, locked with a rusty key.");
    rooms[n_rooms].connections[0] = SOUTH;
    rooms[n_rooms].n_connections = 1;
    rooms[n_rooms].n_items = 1;
    rooms[n_rooms].items[0] = KEY;
    n_rooms++;

    rooms[n_rooms].id = n_rooms;
    strcpy(rooms[n_rooms].name, "hallway");
    strcpy(rooms[n_rooms].description, "You are in a long, narrow hallway. There are passages to the north, east, and west.");
    rooms[n_rooms].connections[0] = NORTH;
    rooms[n_rooms].connections[1] = EAST;
    rooms[n_rooms].connections[2] = WEST;
    rooms[n_rooms].n_connections = 3;
    n_rooms++;

    rooms[n_rooms].id = n_rooms;
    strcpy(rooms[n_rooms].name, "kitchen");
    strcpy(rooms[n_rooms].description, "You are in a small kitchen. There is a passage to the west and a table with a candle on it.");
    rooms[n_rooms].connections[0] = WEST;
    rooms[n_rooms].n_connections = 1;
    rooms[n_rooms].n_items = 1;
    rooms[n_rooms].items[0] = CANDLE;
    n_rooms++;

    rooms[n_rooms].id = n_rooms;
    strcpy(rooms[n_rooms].name, "library");
    strcpy(rooms[n_rooms].description, "You are in a large library. There are passages to the south and east and a book on the desk.");
    rooms[n_rooms].connections[0] = SOUTH;
    rooms[n_rooms].connections[1] = EAST;
    rooms[n_rooms].n_connections = 2;
    rooms[n_rooms].n_items = 1;
    rooms[n_rooms].items[0] = BOOK;
    n_rooms++;

    rooms[n_rooms].id = n_rooms;
    strcpy(rooms[n_rooms].name, "armory");
    strcpy(rooms[n_rooms].description, "You are in an armory. There is a passage to the north and a sword and a shield on the wall.");
    rooms[n_rooms].connections[0] = NORTH;
    rooms[n_rooms].n_connections = 1;
    rooms[n_rooms].n_items = 2;
    rooms[n_rooms].items[0] = SWORD;
    rooms[n_rooms].items[1] = SHIELD;
    n_rooms++;

    rooms[n_rooms].id = n_rooms;
    strcpy(rooms[n_rooms].name, "dungeon");
    strcpy(rooms[n_rooms].description, "You are in a creepy dungeon. There is a passage to the east and a chest near the wall.");
    rooms[n_rooms].connections[0] = EAST;
    rooms[n_rooms].n_connections = 1;
    rooms[n_rooms].n_items = 1;
    rooms[n_rooms].items[0] = TREASURE;
    n_rooms++;

    rooms[n_rooms].id = n_rooms;
    strcpy(rooms[n_rooms].name, "laboratory");
    strcpy(rooms[n_rooms].description, "You are in a strange laboratory. There is a passage to the north and a potion on the table.");
    rooms[n_rooms].connections[0] = NORTH;
    rooms[n_rooms].n_connections = 1;
    rooms[n_rooms].n_items = 1;
    rooms[n_rooms].items[0] = POTION;
    n_rooms++;
}

int main() {
    init_game();

    printf("Welcome to the dungeon escape game!\n");
    printf("You are trapped in a dungeon and you need to find the way out.\n");
    printf("You can move to the north, east, south, and west using the commands 'go north', 'go east', etc.\n");
    printf("You can take items using the command 'take <item>' and drop them using the command 'drop <item>'.\n");
    printf("You can use items in your inventory using the command 'use <item>'.\n");
    printf("Good luck!\n\n");

    while (1) {
        print_room();
        char line[100];
        fgets(line, 100, stdin);
        replace_n(line);
        char* p = strchr(line, ' ');
        if (p != NULL) {
            *p++ = '\0';
            while (isspace(*p)) {
                p++;
            }
        }
        if (strcmp(line, "go") == 0) {
            enum Direction direction = get_direction(p);
            move(direction);
        } else if (strcmp(line, "take") == 0) {
            take(p);
        } else if (strcmp(line, "drop") == 0) {
            drop(p);
        } else if (strcmp(line, "use") == 0) {
            use(p);
        } else if (strcmp(line, "inventory") == 0) {
            print_inventory();
        } else if (strcmp(line, "quit") == 0) {
            printf("Thanks for playing. Goodbye!\n");
            exit(0);
        } else {
            printf("I don't know what you mean.\n");
        }
    }

    return 0;
}