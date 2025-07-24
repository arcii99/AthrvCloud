//FormAI DATASET v1.0 Category: Terminal Based Game ; Style: Sherlock Holmes
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

#define MAX_ROOMS 8
#define MAX_ITEMS 4
#define MAX_NAME_LENGTH 20
#define ITEM_LOCATION_NOT_FOUND -1
#define INPUT_BUFFER_SIZE 100

typedef struct{
    char name[MAX_NAME_LENGTH];
    int location;
} Item;

typedef struct{
    char name[MAX_NAME_LENGTH];
    int north, south, east, west;
    Item items[MAX_ITEMS];
    int num_items;
    char description[200];
} Room;

Room rooms[MAX_ROOMS];

// Initialize the game rooms
void initializeRooms(){
    strcpy(rooms[0].name, "Foyer");
    rooms[0].description[0] = '\0';
    rooms[0].north = -1;
    rooms[0].south = 1;
    rooms[0].west = -1;
    rooms[0].east = -1;
    rooms[0].num_items = 0;

    strcpy(rooms[1].name, "Ballroom");
    rooms[1].description[0] = '\0';
    rooms[1].north = 0;
    rooms[1].south = -1;
    rooms[1].west = 3;
    rooms[1].east = 2;
    rooms[1].num_items = 0;

    //... more rooms

    // Initialize items in rooms
    strcpy(rooms[0].items[0].name, "Candelabra");
    rooms[0].items[0].location = 0;
    rooms[0].num_items++;

    // ... more items
}

// Get the index of a room by name
int getRoomIndex(char* room_name){
    int i;
    for(i=0; i<MAX_ROOMS; i++){
        if(strcmp(rooms[i].name, room_name)==0){
            return i;
        }
    }
    return -1;
}

// Get the index of an item in a room by name
int getItemIndexInRoom(char* item_name, Room room){
    int i;
    for(i=0; i<room.num_items; i++){
        if(strcmp(room.items[i].name, item_name)==0){
            return i;
        }
    }
    return ITEM_LOCATION_NOT_FOUND;
}

// Print items in current room
void showItemsInRoom(Room current_room){
    int i;
    printf("The following items are in the room:\n");
    for(i=0; i<current_room.num_items; i++){
        printf("%s\n", current_room.items[i].name);
    }
}

// Helper function to get user input
char* getInput(){
    char* input = malloc(INPUT_BUFFER_SIZE*sizeof(char));
    fgets(input, INPUT_BUFFER_SIZE, stdin);
    return input;
}

int main(){

    // Initialize game
    initializeRooms();

    // Set starting point
    Room current_room = rooms[0];

    printf("Welcome to the Sherlock Holmes Adventure Game!\n");
    printf("You are in the foyer of a grand estate. You can see a ballroom to the south.\n");

    // Game loop
    while(1){
        printf("\nEnter a command (options: look, go, take, exit): ");
        char* command = getInput();

        // Remove trailing newline character
        int len = strlen(command);
        if(len>0 && command[len-1] == '\n'){
            command[len-1] = '\0';
        }

        // Handle user command
        if(strcmp(command, "look")==0){
            printf("%s\n", current_room.description);
            showItemsInRoom(current_room);
        }
        else if(strcmp(command, "go")==0){
            printf("Enter direction (north, south, east, west): ");
            char* dir = getInput();
            int new_room;
            if(strcmp(dir, "north")==0){
                new_room = current_room.north;
            }
            else if(strcmp(dir, "south")==0){
                new_room = current_room.south;
            }
            else if(strcmp(dir, "east")==0){
                new_room = current_room.east;
            }
            else if(strcmp(dir, "west")==0){
                new_room = current_room.west;
            }
            else{
                printf("Invalid direction.\n");
                continue;
            }

            if(new_room == -1){
                printf("There is no room in that direction.\n");
                continue;
            }

            current_room = rooms[new_room];
            printf("You are now in the %s.\n", current_room.name);
            printf("%s\n", current_room.description);
            showItemsInRoom(current_room);
        }
        else if(strcmp(command, "take")==0){
            printf("Enter item name: ");
            char* item_name = getInput();

            int item_index = getItemIndexInRoom(item_name, current_room);
            if(item_index == ITEM_LOCATION_NOT_FOUND){
                printf("%s does not exist in the current room.\n", item_name);
                continue;
            }

            Item item_to_take = current_room.items[item_index];
            printf("You have taken %s.\n", item_to_take.name);

            // Remove item from current room
            int i;
            for(i=item_index; i<current_room.num_items-1; i++){
                current_room.items[i] = current_room.items[i+1];
            }
            current_room.num_items--;

            // Add item to player inventory
            printf("Item added to inventory.\n");
        }
        else if(strcmp(command, "exit")==0){
            printf("Thanks for playing!\n");
            break;
        }
        else{
            printf("Invalid command!\n");
        }
    }

    return 0;
}