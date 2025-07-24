//FormAI DATASET v1.0 Category: Haunted House Simulator ; Style: grateful
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <time.h>

#define MAX_ITEMS 10
#define MAX_NAME 20
#define MAX_ROOMS 6
#define MAX_DESCRIPTION 100

struct Item {
    char name[MAX_NAME];
    char description[MAX_DESCRIPTION];
    int location;
};

void printRooms(void);
void createRoomDescriptions(void);
void printRoomDescription(int);
void createItems(void);
void printInventory(int);
void dropItem(int, int);
void takeItem(int, int);
void look(int);
void gameLoop(void);

char *roomDescriptions[MAX_ROOMS];

struct Item items[MAX_ITEMS];
char inventory[MAX_ITEMS][MAX_NAME];
int itemCount = 0;

const char *directions[] = {"north", "east", "south", "west"};
int currentRoom = 0;

int main()
{
    createRoomDescriptions();
    createItems();
    printRooms();
    printf("\nWelcome to the Haunted House simulator! You are in the %s room. Type 'help' for a list of commands.\n", roomDescriptions[currentRoom]);
    gameLoop();
}

void printRooms()
{
    printf("  _______\n");
    printf(" /       \\\n");
    printf("/    5    \\_____\n");
    printf("\\         /     \\\n");
    printf(" \\_______/   4   \\_____\n");
    printf(" /       \\         /   \\\n");
    printf("/    2    \\_______/  3  \\\n");
    printf("\\         /       \\     /\n");
    printf(" \\_______/    1    \\___/\n");
    printf("         \\         /\n");
    printf("          \\_______/\n\n");
    printf("Rooms:\n");
    printf("1. Entrance\n");
    printf("2. Kitchen\n");
    printf("3. Living Room\n");
    printf("4. Bedroom\n");
    printf("5. Bathroom\n");
}

void createRoomDescriptions()
{
    roomDescriptions[0] = "Entrance";
    roomDescriptions[1] = "Kitchen";
    roomDescriptions[2] = "Living Room";
    roomDescriptions[3] = "Bedroom";
    roomDescriptions[4] = "Bathroom";
}

void printRoomDescription(int room)
{
    printf("%s\n", roomDescriptions[room]);
    printf("--------------------\n");
    if (room == 1) {
        printf("You step into the kitchen. The counters are covered in a thick layer of dust, and the sink is piled high with dishes. The air smells of rotten food.\n");
    } else if (room == 2) {
        printf("You are now in the living room. There is a musty couch against the wall, and a broken TV flickers in the corner.\n");
    } else if (room == 3) {
        printf("You find yourself in a bedroom. The bed is unmade, and old clothes are strewn across the floor.\n");
    } else if (room == 4) {
        printf("You're in the bathroom. The air is humid and suffocating. The medicine cabinet is open and most bottles are empty. The sink is covered in old toothpaste blobs.\n");
    } else if (room == 5) {
        printf("You stand in the hallway outside the bathroom. The wallpaper is peeling, and the wood panelling is rotten. You feel like you're being watched...\n");
    }
}

void createItems()
{
    strcpy(items[0].name, "key");
    strcpy(items[0].description, "It's a small, rusty key.");
    items[0].location = 1;
    
    strcpy(items[1].name, "flashlight");
    strcpy(items[1].description, "A flashlight without batteries.");
    items[1].location = 2;
    
    strcpy(items[2].name, "knife");
    strcpy(items[2].description, "It's an old, rusted knife. Gives you chills down your spine.");
    items[2].location = 3;
    
    strcpy(items[3].name, "book");
    strcpy(items[3].description, "An old book with arcane drawings. Words written in unknown languages.");
    items[3].location = 4;
    
    strcpy(items[4].name, "mirror");
    strcpy(items[4].description, "A small mirror, the reflection of yourself seems distorted.");
    items[4].location = 5;
}

void printInventory(int location)
{
    printf("You are carrying:\n");
    int i;
    for (i = 0; i < itemCount; i++) {
        if (items[i].location == location) {
            printf("%s - %s\n", items[i].name, items[i].description);
        }
    }
}

void dropItem(int index, int location)
{
    strcpy(inventory[index], ""); // remove item from inventory
    items[index].location = location; // add item to room
    itemCount--;
}

void takeItem(int index, int location)
{
    strcpy(inventory[index], items[index].name); // add item to inventory
    items[index].location = -1; // mark item as being carried
    itemCount++;
}

void look(int location)
{
    printRoomDescription(location);
    printInventory(location);
}

void gameLoop()
{
    char input[100];
    while (1) {
        printf("\n> ");
        fgets(input, 100, stdin);
        input[strlen(input)-1] = '\0';
        
        if (strcmp(input, "help") == 0) {
            printf("Commands:\n");
            printf("  help - Show this list of commands\n");
            printf("  look - Look around the current room\n");
            printf("  inventory - List the items you're carrying\n");
            printf("  take <item> - Take an item\n");
            printf("  drop <item> - Drop an item\n");
            printf("  go <direction> - Move in a direction (north, east, south, or west)\n");
            printf("  quit - Quit the game\n");
        } else if (strcmp(input, "inventory") == 0) {
            printInventory(-1);
        } else if (strcmp(input, "look") == 0) {
            look(currentRoom);
        } else if (strncmp(input, "take ", 5) == 0) {
            char item[MAX_NAME];
            if (sscanf(input, "take %s", item) == 1) {
                int i;
                int found = 0;
                for (i = 0; i < MAX_ITEMS; i++) {
                    if (strcmp(items[i].name, item) == 0 && items[i].location == currentRoom) {
                        takeItem(i, -1);
                        found = 1;
                        printf("You take the %s.\n", item);
                        break;
                    }
                }
                if (!found) {
                    printf("I don't see a %s here.\n", item);
                }
            }
        } else if (strncmp(input, "drop ", 5) == 0) {
            char item[MAX_NAME];
            if (sscanf(input, "drop %s", item) == 1) {
                int i;
                int found = 0;
                for (i = 0; i < MAX_ITEMS; i++) {
                    if (strcmp(inventory[i], item) == 0) {
                        dropItem(i, currentRoom);
                        found = 1;
                        printf("You drop the %s.\n", item);
                        break;
                    }
                }
                if (!found) {
                    printf("You're not carrying a %s.\n", item);
                }
            }
        } else if (strncmp(input, "go ", 3) == 0) {
            char direction[MAX_NAME];
            if (sscanf(input, "go %s", direction) == 1) {
                int i;
                int found = 0;
                for (i = 0; i < 4; i++) {
                    if (strcmp(direction, directions[i]) == 0) {
                        found = 1;
                        break;
                    }
                }
                if (!found) {
                    printf("You can't go that way.\n");
                    continue;
                }
                
                int newRoom;
                if (strcmp(direction, "north") == 0) {
                    newRoom = currentRoom - 3;
                } else if (strcmp(direction, "east") == 0) {
                    newRoom = currentRoom + 1;
                } else if (strcmp(direction, "south") == 0) {
                    newRoom = currentRoom + 3;
                } else if (strcmp(direction, "west") == 0) {
                    newRoom = currentRoom - 1;
                }
                
                if (newRoom < 0 || newRoom > 5) {
                    printf("You can't go that way.\n");
                    continue;
                }
                
                currentRoom = newRoom;
                look(currentRoom);
            }
        } else if (strcmp(input, "quit") == 0) {
            printf("Thanks for playing!\n");
            break;
        } else {
            printf("I don't understand that command.\n");
        }
    }
}