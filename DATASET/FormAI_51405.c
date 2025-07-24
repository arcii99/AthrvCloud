//FormAI DATASET v1.0 Category: Smart home light control ; Style: multiplayer
#include <stdio.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_BULBS 3

// A structure to represent a room containing multiple bulbs
typedef struct {
    char name[20];
    int num_bulbs;
    int bulb_states[MAX_BULBS];  // 0 for OFF, 1 for ON
} Room;

// A structure to represent the entire Smart Home system
typedef struct {
    Room rooms[MAX_ROOMS];
    int num_rooms;
} SmartHome;

// Function to initialize a new Smart Home system
void initializeSmartHome(SmartHome* sh) {
    sh->num_rooms = 0;
}

// Function to add a new room to the Smart Home system
void addRoom(SmartHome* sh, char* name, int num_bulbs) {
    if (sh->num_rooms >= MAX_ROOMS) {
        printf("Error: Cannot add room. Maximum number of rooms reached.\n");
        return;
    }
    Room new_room;
    strncpy(new_room.name, name, 20);
    new_room.num_bulbs = num_bulbs;
    for (int i = 0; i < num_bulbs; i++) {
        new_room.bulb_states[i] = 0;  // Initially all bulbs are OFF
    }
    sh->rooms[sh->num_rooms++] = new_room;
}

// Function to toggle the state of a specific bulb in a specific room
void toggleBulb(SmartHome* sh, int room_index, int bulb_index) {
    if (room_index >= sh->num_rooms || bulb_index >= sh->rooms[room_index].num_bulbs) {
        printf("Error: Invalid room/bulb index.\n");
        return;
    }
    sh->rooms[room_index].bulb_states[bulb_index] = !sh->rooms[room_index].bulb_states[bulb_index];
}

// Function to print the state of each bulb in every room
void printSmartHomeState(SmartHome sh) {
    printf("Current Smart Home state:\n");
    for (int i = 0; i < sh.num_rooms; i++) {
        printf("%s: ", sh.rooms[i].name);
        for (int j = 0; j < sh.rooms[i].num_bulbs; j++) {
            printf("%s ", sh.rooms[i].bulb_states[j] ? "ON" : "OFF");
        }
        printf("\n");
    }
}

int main() {
    SmartHome my_home;
    initializeSmartHome(&my_home);
    addRoom(&my_home, "Living Room", 2);
    addRoom(&my_home, "Bedroom", 1);
    addRoom(&my_home, "Kitchen", 3);
    printSmartHomeState(my_home);
    toggleBulb(&my_home, 0, 0);
    toggleBulb(&my_home, 2, 1);
    printSmartHomeState(my_home);
    return 0;
}