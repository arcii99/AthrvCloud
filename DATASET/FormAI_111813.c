//FormAI DATASET v1.0 Category: Smart home light control ; Style: curious
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_ROOMS 5
#define MAX_LIGHTS_PER_ROOM 3

typedef struct {
    int room_no;
    int light_no;
    char is_on[10];
} Light;

typedef struct {
    int room_no;
    char room_name[20];
    Light lights[MAX_LIGHTS_PER_ROOM];
} Room;

void printRooms(Room* rooms, int n) {
    printf("==============ALL ROOMS AND LIGHTS==============\n");
    for(int i=0; i<n; i++) {
        printf("Room %d: %s\n", rooms[i].room_no, rooms[i].room_name);
        for(int j=0; j<MAX_LIGHTS_PER_ROOM; j++) {
            printf("Light %d: %s\n", rooms[i].lights[j].light_no, rooms[i].lights[j].is_on);
        }
    }
    printf("================================================\n");
}

void turnOnOffLight(Room* rooms, int room_no, int light_no, int is_on) {
    if(is_on) {
        strcpy(rooms[room_no].lights[light_no].is_on, "ON");
        printf("Turned ON Light %d in Room %d!\n", light_no, room_no);
    }
    else {
        strcpy(rooms[room_no].lights[light_no].is_on, "OFF");
        printf("Turned OFF Light %d in Room %d!\n", light_no, room_no);
    }
}

int main() {
    Room rooms[MAX_ROOMS] = {
        {1, "Living Room", {{1, 1, "OFF"}, {1, 2, "OFF"}, {1, 3, "OFF"}}},
        {2, "Bedroom", {{2, 1, "OFF"}, {2, 2, "OFF"}, {2, 3, "OFF"}}},
        {3, "Kitchen", {{3, 1, "OFF"}, {3, 2, "OFF"}, {3, 3, "OFF"}}},
        {4, "Bathroom", {{4, 1, "OFF"}, {4, 2, "OFF"}, {4, 3, "OFF"}}},
        {5, "Garage", {{5, 1, "OFF"}, {5, 2, "OFF"}, {5, 3, "OFF"}}}
    };

    printRooms(rooms, MAX_ROOMS);

    // Turn on Light 1 in Living Room
    turnOnOffLight(rooms, 0, 0, 1);

    // Turn off Light 3 in Kitchen
    turnOnOffLight(rooms, 2, 2, 0);

    // Turn on all lights in Bedroom
    for(int i=0; i<MAX_LIGHTS_PER_ROOM; i++) {
        turnOnOffLight(rooms, 1, i, 1);
    }

    printRooms(rooms, MAX_ROOMS);

    return 0;
}