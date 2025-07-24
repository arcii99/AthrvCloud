//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: automated
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_INPUT 20
#define MAX_ROOMS 10
#define MAX_ITEMS 5

typedef struct {
    char name[MAX_INPUT];
    char description[MAX_INPUT];
    int visited;
    int locked;
    int connecting_rooms[MAX_ROOMS];
    int num_connecting_rooms;
    int items[MAX_ITEMS];
    int num_items;
} Room;

typedef struct {
    char name[MAX_INPUT];
    char description[MAX_INPUT];
    int room_location;
} Item;

int num_rooms;
Room rooms[MAX_ROOMS];
int num_items;
Item items[MAX_ITEMS];

void initialize_rooms();
void initialize_items();
void print_room(int room_num);
void print_item(int item_num);
void print_inventory();
void add_item_to_room(int item_num, int room_num);
void remove_item_from_room(int item_num, int room_num);
int get_item_location(int item_num);
void take_item(int item_num);
void drop_item(int item_num);
void play_game();
int main();

void initialize_rooms() {
    num_rooms = 4;

    strcpy(rooms[0].name, "Living Room");
    strcpy(rooms[0].description, "Cozy living room with a fireplace and a comfortable couch.");
    rooms[0].visited = 0;
    rooms[0].locked = 0;
    rooms[0].connecting_rooms[0] = 1;
    rooms[0].connecting_rooms[1] = 2;
    rooms[0].num_connecting_rooms = 2;
    rooms[0].items[0] = 0;
    rooms[0].num_items = 1;

    strcpy(rooms[1].name, "Kitchen");
    strcpy(rooms[1].description, "Spacious kitchen with stainless steel appliances and granite countertops.");
    rooms[1].visited = 0;
    rooms[1].locked = 1;
    rooms[1].connecting_rooms[0] = 0;
    rooms[1].connecting_rooms[1] = 3;
    rooms[1].num_connecting_rooms = 2;
    rooms[1].items[0] = 1;
    rooms[1].num_items = 1;

    strcpy(rooms[2].name, "Bedroom");
    strcpy(rooms[2].description, "Comfortable bedroom with a queen size bed and a large closet.");
    rooms[2].visited = 0;
    rooms[2].locked = 0;
    rooms[2].connecting_rooms[0] = 0;
    rooms[2].num_connecting_rooms = 1;
    rooms[2].items[0] = 2;
    rooms[2].items[1] = 3;
    rooms[2].num_items = 2;

    strcpy(rooms[3].name, "Bathroom");
    strcpy(rooms[3].description, "Clean bathroom with a bathtub and a shower.");
    rooms[3].visited = 0;
    rooms[3].locked = 0;
    rooms[3].connecting_rooms[0] = 1;
    rooms[3].num_connecting_rooms = 1;
    rooms[3].items[0] = 4;
    rooms[3].num_items = 1;
}

void initialize_items() {
    num_items = 5;

    strcpy(items[0].name, "Fireplace");
    strcpy(items[0].description, "A warm and cozy fireplace.");
    items[0].room_location = 0;

    strcpy(items[1].name, "Knife");
    strcpy(items[1].description, "A sharp kitchen knife.");
    items[1].room_location = 1;

    strcpy(items[2].name, "Lamp");
    strcpy(items[2].description, "A bright and modern lamp.");
    items[2].room_location = 2;

    strcpy(items[3].name, "Shoes");
    strcpy(items[3].description, "A pair of comfortable shoes.");
    items[3].room_location = 2;

    strcpy(items[4].name, "Towel");
    strcpy(items[4].description, "A soft and fluffy towel.");
    items[4].room_location = 3;
}

void print_room(int room_num) {
    printf("%s\n", rooms[room_num].name);
    printf("%s\n", rooms[room_num].description);

    if (!rooms[room_num].visited) {
        printf("This is your first time in this room.\n");
        rooms[room_num].visited = 1;
    }

    printf("You can go to: ");

    for (int i = 0; i < rooms[room_num].num_connecting_rooms; i++) {
        printf("%s", rooms[rooms[room_num].connecting_rooms[i]].name);

        if (i == rooms[room_num].num_connecting_rooms - 1) {
            printf(".\n");
        } else {
            printf(", ");
        }
    }

    printf("Items in this room: ");

    if (rooms[room_num].num_items == 0) {
        printf("none\n");
    } else {
        printf("\n");

        for (int i = 0; i < rooms[room_num].num_items; i++) {
            print_item(rooms[room_num].items[i]);
        }
    }
}

void print_item(int item_num) {
    printf("- %s (%s)\n", items[item_num].name, items[item_num].description);
}

void print_inventory() {
    printf("Inventory:\n");

    int num_items_in_inventory = 0;

    for (int i = 0; i < num_items; i++) {
        int item_location = get_item_location(i);

        if (item_location == -1) {
            continue;
        }

        num_items_in_inventory++;

        printf("%d. %s (%s) - in %s\n", num_items_in_inventory, items[i].name, items[i].description, rooms[item_location].name);
    }

    if (num_items_in_inventory == 0) {
        printf("Your inventory is empty.\n");
    }
}

void add_item_to_room(int item_num, int room_num) {
    rooms[room_num].items[rooms[room_num].num_items] = item_num;
    rooms[room_num].num_items++;
    items[item_num].room_location = room_num;
}

void remove_item_from_room(int item_num, int room_num) {
    int item_location = -1;

    for (int i = 0; i < rooms[room_num].num_items; i++) {
        if (rooms[room_num].items[i] == item_num) {
            item_location = i;
            break;
        }
    }

    if (item_location == -1) {
        return;
    }

    for (int i = item_location; i < rooms[room_num].num_items - 1; i++) {
        rooms[room_num].items[i] = rooms[room_num].items[i + 1];
    }

    rooms[room_num].num_items--;
    items[item_num].room_location = -1;
}

int get_item_location(int item_num) {
    for (int i = 0; i < num_rooms; i++) {
        for (int j = 0; j < rooms[i].num_items; j++) {
            if (rooms[i].items[j] == item_num) {
                return i;
            }
        }
    }

    return -1;
}

void take_item(int item_num) {
    int item_location = get_item_location(item_num);

    if (item_location == -1) {
        printf("This item is not in the room.\n");
        return;
    }

    if (rooms[item_location].locked) {
        printf("This room is locked. You need to find a key to unlock it.\n");
        return;
    }

    add_item_to_room(item_num, -1);
    printf("You have taken the %s.\n", items[item_num].name);
}

void drop_item(int item_num) {
    int item_location = get_item_location(item_num);

    if (item_location == -1) {
        printf("You do not have this item in your inventory.\n");
        return;
    }

    if (item_location == 1 && rooms[1].locked) {
        printf("This room is locked. You need to find a key to unlock it.\n");
        return;
    }

    remove_item_from_room(item_num, -1);
    add_item_to_room(item_num, num_rooms);
    printf("You have dropped the %s in %s.\n", items[item_num].name, rooms[num_rooms].name);
}

void play_game() {
    int current_room = 0;
    int game_over = 0;
    char user_input[MAX_INPUT];

    while (!game_over) {
        print_room(current_room);
        printf("What would you like to do? ");

        fgets(user_input, MAX_INPUT, stdin);
        user_input[strcspn(user_input, "\n")] = '\0';

        if (strcmp(user_input, "quit") == 0) {
            game_over = 1;
            printf("Thanks for playing!\n");
        } else if (strcmp(user_input, "help") == 0) {
            printf("Available commands: go <direction>, take <item>, drop <item>, inventory, quit.\n");
        } else if (strcmp(user_input, "inventory") == 0) {
            print_inventory();
        } else if (strncmp(user_input, "go ", 3) == 0) {
            char direction[MAX_INPUT];
            sscanf(user_input + 3, "%s", direction);

            int next_room = -1;

            for (int i = 0; i < rooms[current_room].num_connecting_rooms; i++) {
                if (strcmp(direction, rooms[rooms[current_room].connecting_rooms[i]].name) == 0) {
                    next_room = rooms[current_room].connecting_rooms[i];
                }
            }

            if (next_room == -1) {
                printf("You cannot go in that direction.\n");
            } else {
                current_room = next_room;
            }
        } else if (strncmp(user_input, "take ", 5) == 0) {
            char item_name[MAX_INPUT];
            sscanf(user_input + 5, "%s", item_name);

            int item_num = -1;

            for (int i = 0; i < num_items; i++) {
                if (strcmp(item_name, items[i].name) == 0) {
                    item_num = i;
                }
            }

            if (item_num == -1) {
                printf("This item is not in the room.\n");
            } else {
                take_item(item_num);
            }
        } else if (strncmp(user_input, "drop ", 5) == 0) {
            char item_name[MAX_INPUT];
            sscanf(user_input + 5, "%s", item_name);

            int item_num = -1;

            for (int i = 0; i < num_items; i++) {
                if (strcmp(item_name, items[i].name) == 0) {
                    item_num = i;
                }
            }

            if (item_num == -1) {
                printf("You do not have this item in your inventory.\n");
            } else {
                drop_item(item_num);
            }
        } else {
            printf("Invalid command. Type 'help' for a list of available commands.\n");
        }
    }
}

int main() {
    srand(time(NULL));

    initialize_rooms();
    initialize_items();

    printf("Welcome to Text-Based Adventure Game!\n");
    play_game();

    return 0;
}