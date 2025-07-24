//FormAI DATASET v1.0 Category: Text-Based Adventure Game ; Style: retro
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

// define game states
enum GameState {
    MENU,
    INTRO,
    BEDROOM,
    LIVING_ROOM,
    KITCHEN,
    END
};

// define game objects
struct Item {
    char name[20];
    char desc[100];
    bool inInventory;
};

// define game rooms
struct Room {
    char name[20];
    char desc[100];
    struct Item item;
    enum GameState state;
};

// define game functions
void printMenu();
void printIntro();
void printRoom(struct Room);
void printInventory(struct Item[], int);
void printEnd();
void getInput(char*, int);
void clearScreen();
void pause();

int main() {
    // initialize game variables
    bool running = true;
    enum GameState state = MENU;
    struct Item inventory[10];
    struct Room bedroom = {"Bedroom", "You are in your bedroom. There is a lamp on the nightstand.", {"Lamp", "A small lamp with a yellow shade.", false}, BEDROOM};
    struct Room livingRoom = {"Living Room", "You are in your living room. There is a sofa and a TV.", {"Key", "A small key with a red tag.", false}, LIVING_ROOM};
    struct Room kitchen = {"Kitchen", "You are in your kitchen. There is a fridge and a counter.", {"Knife", "A sharp kitchen knife.", false}, KITCHEN};
    
    // main game loop
    while(running) {
        switch(state) {
            case MENU:
                printMenu();
                char menuInput[10];
                getInput(menuInput, sizeof(menuInput));
                if(strcmp(menuInput, "1") == 0) {
                    state = INTRO;
                } else if (strcmp(menuInput, "2") == 0) {
                    running = false;
                }
                break;
            case INTRO:
                clearScreen();
                printIntro();
                pause();
                clearScreen();
                state = BEDROOM;
                break;
            case BEDROOM:
                printRoom(bedroom);
                char bedroomInput[10];
                getInput(bedroomInput, sizeof(bedroomInput));
                if(strcmp(bedroomInput, "look") == 0) {
                    printRoom(bedroom);
                } else if(strcmp(bedroomInput, "take lamp") == 0) {
                    bedroom.item.inInventory = true;
                    strcpy(inventory[0].name, bedroom.item.name);
                    strcpy(inventory[0].desc, bedroom.item.desc);
                    inventory[0].inInventory = true;
                    printf("You take the %s.\n", bedroom.item.name);
                } else if(strcmp(bedroomInput, "go to living room") == 0) {
                    clearScreen();
                    state = LIVING_ROOM;
                }
                break;
            case LIVING_ROOM:
                printRoom(livingRoom);
                char livingRoomInput[10];
                getInput(livingRoomInput, sizeof(livingRoomInput));
                if(strcmp(livingRoomInput, "look") == 0) {
                    printRoom(livingRoom);
                } else if(strcmp(livingRoomInput, "take key") == 0) {
                    livingRoom.item.inInventory = true;
                    strcpy(inventory[1].name, livingRoom.item.name);
                    strcpy(inventory[1].desc, livingRoom.item.desc);
                    inventory[1].inInventory = true;
                    printf("You take the %s.\n", livingRoom.item.name);
                } else if(strcmp(livingRoomInput, "go to kitchen") == 0 && livingRoom.item.inInventory == true) {
                    clearScreen();
                    state = KITCHEN;
                } else if(strcmp(livingRoomInput, "go to kitchen") == 0 && livingRoom.item.inInventory == false) {
                    printf("The door to the kitchen is locked.\n");
                }
                break;
            case KITCHEN:
                printRoom(kitchen);
                char kitchenInput[10];
                getInput(kitchenInput, sizeof(kitchenInput));
                if(strcmp(kitchenInput, "look") == 0) {
                    printRoom(kitchen);
                } else if(strcmp(kitchenInput, "take knife") == 0) {
                    kitchen.item.inInventory = true;
                    strcpy(inventory[2].name, kitchen.item.name);
                    strcpy(inventory[2].desc, kitchen.item.desc);
                    inventory[2].inInventory = true;
                    printf("You take the %s.\n", kitchen.item.name);
                } else if(strcmp(kitchenInput, "go to living room") == 0) {
                    clearScreen();
                    state = LIVING_ROOM;
                }
                break;
            case END:
                printEnd();
                running = false;
                break;
        }
    }
    
    return 0;
}

// print the game menu
void printMenu() {
    printf("Welcome to Retro Text Adventure!\n");
    printf("\t1. Start Game\n");
    printf("\t2. Exit\n");
}

// print the game introduction
void printIntro() {
    printf("It's the year 1985 and you wake up in your bed with a headache. You don't remember what happened last night. As you get out of bed, you notice that your apartment looks different than usual. You decide to investigate...\n");
}

// print a room's description
void printRoom(struct Room room) {
    printf("You are in the %s.\n\n", room.name);
    printf("%s\n\n", room.desc);
    
    if(room.item.inInventory == false) {
        printf("You see a %s.\n", room.item.name);
    }
    
    printf("What do you want to do?\n");
    printf("\t- Look around (type 'look')\n");
    if(room.item.inInventory == false) {
        printf("\t- Take the %s (type 'take %s')\n", room.item.name, room.item.name);
    }
    if(room.state == BEDROOM) {
        printf("\t- Go to the living room (type 'go to living room')\n");
    } else if(room.state == LIVING_ROOM) {
        if(room.item.inInventory == true) {
            printf("\t- Go to the kitchen (type 'go to kitchen')\n");
        } else {
            printf("\t- Try to open the door (type 'go to kitchen')\n");
        }
    } else if(room.state == KITCHEN) {
        printf("\t- Go to the living room (type 'go to living room')\n");
    }
    printf("\t- Check inventory (type 'inventory')\n");
}

// print the player's inventory
void printInventory(struct Item inventory[], int size) {
    printf("Your Inventory:\n");
    for(int i = 0; i < size; i++) {
        if(inventory[i].inInventory == true) {
            printf("\t- %s (%s)\n", inventory[i].name, inventory[i].desc);
        }
    }
}

// print the game end message
void printEnd() {
    printf("You've solved the mystery and won the game! Congratulations!\n");
}

// get user input
void getInput(char* input, int size) {
    fgets(input, size, stdin);
    input[strcspn(input, "\n")] = 0;
}

// clear the console screen
void clearScreen() {
    printf("\033[2J\033[1;1H");
}

// pause the game until the user presses enter
void pause() {
    printf("Press ENTER to continue.\n");
    char pauseInput[10];
    fgets(pauseInput, sizeof(pauseInput), stdin);
    fflush(stdout);
}