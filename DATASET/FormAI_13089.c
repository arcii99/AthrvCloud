//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: irregular
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#define MAX_NAME_LEN 20
#define MAX_ITEMS 5
#define MAX_ROOMS 4

struct Item{
    char name[MAX_NAME_LEN];
    int value;
    int durability;
};

struct Room{
    int id;
    char name[MAX_NAME_LEN];
    char description[100];
    struct Item items[MAX_ITEMS];
};

void print_items(struct Item items[], int num_items);
void print_room(struct Room room);
int get_input(int max_input);
void get_new_item(struct Item *item);
void initialize_rooms(struct Room rooms[]);

int main(){
    srand(time(NULL));
    struct Room rooms[MAX_ROOMS];
    initialize_rooms(rooms);
    int curr_room = 0;
    int num_items_found = 0;
    struct Item inventory[MAX_ITEMS];
    printf("You find yourself in a strange room. Type 'help' for instructions.\n");
    while(1){
        print_room(rooms[curr_room]);
        int input = get_input(2);
        if(input == 1){
            printf("You try to leave the room, but the door is locked.\n");
        }
        else if(input == 2){
            int item_index = rand() % MAX_ITEMS;
            struct Item item = rooms[curr_room].items[item_index];
            printf("You found a %s!\n", item.name);
            if(num_items_found < MAX_ITEMS){
                inventory[num_items_found++] = item;
                printf("You put the %s in your inventory.\n", item.name);
            }
            else{
                printf("Your inventory is full. You leave the %s behind.\n", item.name);
            }
            rooms[curr_room].items[item_index] = (struct Item){"", 0, 0};
        }
        else if(input == 3){
            print_items(inventory, num_items_found);
        }
        else if(input == 4){
            printf("You try to use the item, but it's not clear how it would help you right now.\n");
        }
        else if(input == 5){
            printf("You try to use the item, but it's not clear how it would help you right now.\n");
        }
        else if(input == 6){
            printf("Goodbye!\n");
            break;
        }
        else{
            printf("Sorry, I didn't understand that. Type 'help' for instructions.\n");
        }
    }
    return 0;
}

void initialize_rooms(struct Room rooms[]){
    rooms[0] = (struct Room){0, "The Entrance", "You are in a small room with a single door.", 
                            {{"A key", 50, 2}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0}}};
    rooms[1] = (struct Room){1, "The Library", "You find yourself surrounded by books.", 
                            {{"A book", 30, 1}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0}}};
    rooms[2] = (struct Room){2, "The Laboratory", "There are strange machines and tubes everywhere.", 
                            {{"A flask", 20, 1}, {"A beaker", 10, 1}, {"A test tube", 5, 1}, {"", 0, 0}, {"", 0, 0}}};
    rooms[3] = (struct Room){3, "The Treasury", "Gold! Gold everywhere!", 
                            {{"A gold nugget", 100, 10}, {"A bag of diamonds", 200, 5}, {"", 0, 0}, {"", 0, 0}, {"", 0, 0}}};
}

void print_items(struct Item items[], int num_items){
    if(num_items == 0){
        printf("Your inventory is empty.\n");
    }
    else{
        printf("Inventory (%d items):\n", num_items);
        for(int i = 0; i < num_items; i++){
            printf("%d. %s (value: %d, durability: %d)\n", i+1, items[i].name, items[i].value, items[i].durability);
        }
    }
}

void print_room(struct Room room){
    printf("Room: %s\n", room.name);
    printf("%s\n", room.description);
    printf("Items here:\n");
    for(int i = 0; i < MAX_ITEMS; i++){
        if(strlen(room.items[i].name) > 0){
            printf("%s\n", room.items[i].name);
        }
    }
    printf("What do you want to do?\n");
    printf("1. Try to leave\n");
    printf("2. Search for items\n");
    printf("3. Check inventory\n");
    printf("4. Use item 1\n");
    printf("5. Use item 2\n");
    printf("6. Quit\n");
}

int get_input(int max_input){
    char input[20];
    while(1){
        fgets(input, sizeof(input), stdin);
        if(strcmp(input, "help\n") == 0){
            printf("Type the number of the action you want to take.\n");
            continue;
        }
        if(strspn(input, "0123456789\n") != strlen(input)){
            printf("Invalid input. Type 'help' for instructions.\n");
            continue;
        }
        int num = atoi(input);
        if(num < 1 || num > max_input){
            printf("Invalid input. Type 'help' for instructions.\n");
            continue;
        }
        return num;
    }
}